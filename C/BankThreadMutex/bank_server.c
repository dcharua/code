//Modify by Daniel Charua - A01017419 - 17/10/18

/*
    Program for a simple bank server
    It uses sockets and threads
    The server will process simple transactions on a limited number of accounts

    Gilberto Echeverria
    gilecheverria@yahoo.com
    29/03/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Signals library
#include <errno.h>
#include <signal.h>
#include <poll.h>
// Sockets libraries
#include <netdb.h>
#include <sys/poll.h>
// Posix threads library
#include <pthread.h>

// Custom libraries
#include "bank_codes.h"
#include "sockets.h"
#include "fatal_error.h"

#define NUM_ACCOUNTS 4
#define BUFFER_SIZE 1024
#define MAX_QUEUE 5

///// Structure definitions
int interrupted = 0;
int session_transations = 0;
// Data for a single bank account
typedef struct account_struct {
  int id;
  float balance;
} account_t;

// Data for the bank operations
typedef struct bank_struct {
  // Store the total number of operations performed
  int total_transactions;
  // An array of the accounts
  account_t * account_array;
} bank_t;

// Structure for the mutexes to keep the data consistent
typedef struct locks_struct {
  // Mutex for the number of transactions variable
  pthread_mutex_t transactions_mutex;
  // Mutex array for the operations on the accounts
  pthread_mutex_t * account_mutex;
} locks_t;

// Data that will be sent to each structure
typedef struct data_struct {
  // The file descriptor for the socket
  int connection_fd;
  // A pointer to a bank data structure
  bank_t * bank_data;
  // A pointer to a locks structure
  locks_t * data_locks;
} thread_data_t;



///// FUNCTION DECLARATIONS
void usage(char * program);
void setupHandlers();
void initBank(bank_t * bank_data, locks_t * data_locks);
void waitForConnections(int server_fd, bank_t * bank_data, locks_t * data_locks);
void * attentionThread(void * arg);
int checkValidAccount(int account);
void closeBank(bank_t * bank_data, locks_t * data_locks);
/*
    EXAM: Add your function declarations here
*/
void catchInterrupt(int signal);


///// MAIN FUNCTION
int main(int argc, char * argv[]){
  int server_fd;
  bank_t bank_data;
  locks_t data_locks;

  printf("\n=== SIMPLE BANK SERVER ===\n");

  // Check the correct arguments
  if (argc != 2)
    usage(argv[0]);

  // Configure the handler to catch SIGINT
  setupHandlers();

  // Initialize the data structures
  initBank(&bank_data, &data_locks);

  // Show the IPs assigned to this computer
  printLocalIPs();
  // Start the server
  server_fd = initServer(argv[1], MAX_QUEUE);
  // Listen for connections from the clients
  waitForConnections(server_fd, &bank_data, &data_locks);
  // Close the socket
  close(server_fd);

  // Clean the memory used
  closeBank(&bank_data, &data_locks);

  // Finish the main thread
  pthread_exit(NULL);

  return 0;
}

///// FUNCTION DEFINITIONS

/*
    Explanation to the user of the parameters required to run the program
*/
void usage(char * program){
  printf("Usage:\n");
  printf("\t%s {port_number}\n", program);
  exit(EXIT_FAILURE);
}

/*
    Modify the signal handlers for specific events
*/
void setupHandlers(){
  struct sigaction new_action;

  new_action.sa_handler = catchInterrupt;
  sigfillset(&new_action.sa_mask);

  //Define the signal to handle
  sigaction(SIGINT, &new_action, NULL);
}

//Function to act on CNTL C and send exit message to server
void catchInterrupt(int signal){
  //A sessions_transitions is used and not the bank data struct transitions in case program is modified to read data from file
  printf("Exit signal recived, total succesfull transations in this server session %d\n", session_transations);
  interrupted = 1;
}


/*
    Function to initialize all the information necessary
    This will allocate memory for the accounts, and for the mutexes
*/
void initBank(bank_t * bank_data, locks_t * data_locks){
  // Set the number of transactions
  bank_data->total_transactions = 0;

  // Allocate the arrays in the structures
  bank_data->account_array = malloc(NUM_ACCOUNTS * sizeof (account_t));
  // Allocate the arrays for the mutexes
  data_locks->account_mutex = malloc(NUM_ACCOUNTS * sizeof (pthread_mutex_t));

  // Initialize the mutexes, using a different method for dynamically created ones
  //data_locks->transactions_mutex = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_init(&data_locks->transactions_mutex, NULL);
  for (int i=0; i<NUM_ACCOUNTS; i++){
    //data_locks->account_mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_init(&data_locks->account_mutex[i], NULL);
  }
}

/*
    Main loop to wait for incomming connections
*/
void waitForConnections(int server_fd, bank_t * bank_data, locks_t * data_locks){
  struct sockaddr_in client_address;
  socklen_t client_address_size;
  char client_presentation[INET_ADDRSTRLEN];
  int client_fd;
  pthread_t new_tid;
  thread_data_t * connection_data = NULL;
  int poll_response;
  int timeout = 500;		// Time in milliseconds (0.5 seconds)

  // Get the size of the structure to store client information
  client_address_size = sizeof client_address;

  while (!interrupted){
	//// POLL
    // Create a structure array to hold the file descriptors to poll
    struct pollfd test_fds[1];
    // Fill in the structure
    test_fds[0].fd = server_fd;
    test_fds[0].events = POLLIN;    // Check for incomming data
    // Check if there is any incomming communication
    poll_response = poll(test_fds, 1, timeout);

     // Error when polling
    if (poll_response == -1){
      // Test if the error was caused by an interruption
      if (errno == EINTR){
        //printf("Poll did not finish. The program was interrupted\n");
      }
      else{
        fatalError("ERROR: poll");
      }
    }
	// Timeout finished without reading anything
    else if (poll_response == 0){
      //printf("No response after %d seconds\n", timeout);
    }
	// There is something ready at the socket
    else{
      // Check the type of event detected
      if (test_fds[0].revents & POLLIN){
        // ACCEPT
        // Wait for a client connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size);
        if (client_fd == -1)
        	fatalError("ERROR: accept");


        // Get the data from the client
        inet_ntop(client_address.sin_family, &client_address.sin_addr, client_presentation, sizeof client_presentation);
        printf("Received incomming connection from %s on port %d\n", client_presentation, client_address.sin_port);

        // Prepare the structure to send to the thread
        connection_data = malloc(sizeof (thread_data_t));
        connection_data->connection_fd = client_fd;
        connection_data->bank_data = bank_data;
        connection_data->data_locks = data_locks;

  			//CREATE A THREAD
        int result = pthread_create(&new_tid, NULL, attentionThread, (void*)connection_data);
        if (result == -1){
          perror("pthread_create");
          exit(EXIT_FAILURE);
        }
      }
    }
  }
}

/*
  Hear the request from the client and send an answer
*/
void * attentionThread(void * arg){
  // Receive the data for the bank, mutexes and socket file descriptor
  thread_data_t * connection_data = (thread_data_t *) arg;
  int account, transitions;
  float amount;
  int operation = OK;
  response_t response;
  char buffer[BUFFER_SIZE];
  // Loop to listen for messages from the client
  while(!interrupted && operation != EXIT){
    // Receive the request
    //if massage was not recived succesfully from client exit
    if (!recvString(connection_data->connection_fd, buffer, BUFFER_SIZE)){
      perror("Message recive");
      exit(EXIT_FAILURE);
    }
    // Process the request being careful of data consistency
    sscanf(buffer, "%d %d %f", &operation, &account, &amount);
    printf("Request recived for operation %d in account %d for $%f\n", operation, account, amount);
    //If operation is Exit, send Bye and break
    if (operation == EXIT){
      response = BYE;
      sprintf(buffer, "%d %f", response, 0.0);
      sendString(connection_data->connection_fd, buffer);
      break;
    }
    //If account does not exists send NO_ACCOUNT and break
    if(!checkValidAccount(account)){
      response = NO_ACCOUNT;
      sprintf(buffer, "%d %f", response, 0.0);
      sendString(connection_data->connection_fd, buffer);
      continue;
    }
    //else check the operation
    switch(operation){
      // Check balance
      case CHECK:
        //Lock the account data send Ok, balance and unlock
        pthread_mutex_lock(&connection_data->data_locks->account_mutex[account]);
          response = OK;
          sprintf(buffer, "%d %f", response, connection_data->bank_data->account_array[account].balance);
          sendString(connection_data->connection_fd, buffer);
        pthread_mutex_unlock(&connection_data->data_locks->account_mutex[account]);
        break;
      // Deposit into account
      case DEPOSIT:
        //Lock the account data send OK,update balance and unlock
        pthread_mutex_lock(&connection_data->data_locks->account_mutex[account]);
          connection_data->bank_data->account_array[account].balance += amount;
          response = OK;
          sprintf(buffer, "%d %f", response, connection_data->bank_data->account_array[account].balance);
          sendString(connection_data->connection_fd, buffer);
        pthread_mutex_unlock(&connection_data->data_locks->account_mutex[account]);
        break;
      // Withdraw from account
      case  WITHDRAW:
        //lock the account date, check if there is enough balance
        pthread_mutex_lock(&connection_data->data_locks->account_mutex[account]);
          //if there is enough balance, update it and send it with OK
          if (amount < connection_data->bank_data->account_array[account].balance){
            connection_data->bank_data->account_array[account].balance -= amount;
            response = OK;
            sprintf(buffer, "%d %f", response, connection_data->bank_data->account_array[account].balance);
            sendString(connection_data->connection_fd, buffer);
            //if there is not enough balance send INSUFFICIENT
          } else{
            response = INSUFFICIENT;
            sprintf(buffer, "%d %f", response, connection_data->bank_data->account_array[account].balance);
            sendString(connection_data->connection_fd, buffer);
          }
        pthread_mutex_unlock(&connection_data->data_locks->account_mutex[account]);
        break;
      // Incorrect option, send ERROR message
      default:
        response = ERROR;
        sprintf(buffer, "%d %f", response, 0.0);
        sendString(connection_data->connection_fd, buffer);
        break;
    }
    if (response == OK){
      //Lock the transitions ammount and update it
      pthread_mutex_lock(&connection_data->data_locks->transactions_mutex);
        connection_data->bank_data->total_transactions++;
        session_transations++;
        transitions++;
      pthread_mutex_unlock(&connection_data->data_locks->transactions_mutex);
    }
  }
  // Print the total number of transactions performed for this client
  printf("Client left, Total successful transations for this client: %d\n\n", transitions);
  //free connection memory
  free(connection_data);
  //close the thread
  pthread_exit(NULL);
}

/*
    Free all the memory used for the bank data
*/
void closeBank(bank_t * bank_data, locks_t * data_locks){
  printf("DEBUG: Clearing the memory for the thread\n");
  free(bank_data->account_array);
  free(data_locks->account_mutex);
}

/*
    Return true if the account provided is within the valid range,
    return false otherwise
*/
int checkValidAccount(int account){
  return (account >= 0 && account < NUM_ACCOUNTS);
}
