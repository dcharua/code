//Modify by Daniel Charua A01017419

/*
    Client program to get the value of PI
    This program connects to the server using sockets

    Gilberto Echeverria
    gilecheverria@yahoo.com
    21/02/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <poll.h>
#include <errno.h>
// Sockets libraries
#include <netdb.h>
#include <arpa/inet.h>

#include <ifaddrs.h>

#define BUFFER_SIZE 1024

///// FUNCTION DECLARATIONS
void usage(char * program);
int openSocket(char * address, char * port);
void requestPI();
void setupHandlers();
void catchInterrupt(int signal);
void fatalError(const char * message);
void printPI();
//Golbal Variables
int interrupted = 0;
int connection_fd;
unsigned long int iterations = 0;
///// MAIN FUNCTION
int main(int argc, char * argv[]){
  printf("\n=== CLIENT FOR COMPUTING THE VALUE OF pi ===\n");

  // Check the correct arguments
  if (argc != 3){
    usage(argv[0]);
  }

  // Start the server
  connection_fd = openSocket(argv[1], argv[2]);
  //set signal handler
  setupHandlers();
  // Request PI value from server
  requestPI(connection_fd);
  // Close the socket
  close(connection_fd);

  return 0;
}

///// FUNCTION DEFINITIONS

/*
    Explanation to the user of the parameters required to run the program
*/
void usage(char * program){
  printf("Usage:\n");
  printf("\t%s {server_adds} {port_number}\n", program);
  exit(EXIT_FAILURE);
}

/*
    Open the socket to the server
    Returns the file descriptor for the socket
    Remember to close the socket when finished
*/
int openSocket(char * adds, char * port){
  struct addrinfo hints;
  struct addrinfo * server_info = NULL;

  // Prepare the hints structure
  // Clear the structure for the server configuration
  bzero(&hints, sizeof hints);
  // Set to use IPV4
  hints.ai_family = AF_INET;
  // Use stream sockets
  hints.ai_socktype = SOCK_STREAM;
  // Get the local IP adds automatically
  hints.ai_flags = AI_PASSIVE;

  // GETADDRINFO
  // Use the pets to get the actual information for the socket
  // The ult is stored in 'server_info'
  if (getaddrinfo(adds, port, &hints, &server_info) == -1){
    fatalError("getaddrinfo");
  }

  // SOCKET
  // Open the socket using the information obtained
  connection_fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
  if (connection_fd == -1){
    close(connection_fd);
    fatalError("socket");
  }

  // CONNECT
  // Connect to the server
  if (connect(connection_fd, server_info->ai_addr, server_info->ai_addrlen) == -1){
    fatalError("connect");
  }

  // FREEADDRINFO
  // Free the memory used for the adds info
  freeaddrinfo(server_info);

  return connection_fd;
}

void requestPI(){
  char buffer[BUFFER_SIZE];

  printf("Enter the number of iterations for PI: ");
  scanf("%lu", &iterations);

  // Prepare the response to the client
  sprintf(buffer, "%lu", iterations);
  // SEND
  // Send the response
  if (send(connection_fd, buffer, strlen(buffer)+1, 0) == -1){
    fatalError("send");
  }
  printPI();
}

//Function get result from server and print it
void printPI(){
  char buffer[BUFFER_SIZE];
  int chars_read;
  double result;
  //Read Result from client
  chars_read = recv(connection_fd, buffer, BUFFER_SIZE, 0);
  if (chars_read == -1){
    fatalError("recv");
  }
  sscanf(buffer, "%lf", &result);
  // Print the result and send IT (iteration) request
  printf("The value for PI is: %.20lf\n", result);
  bzero(buffer, BUFFER_SIZE);
  sprintf(buffer, "IT");
  if (send(connection_fd, buffer, strlen(buffer)+1, 0) == -1){
    fatalError("send");
  }
  //Read iteration and print it
  chars_read = recv(connection_fd, buffer, BUFFER_SIZE, 0);
  if (chars_read == -1){
    fatalError("recv");
  }
  sscanf(buffer, "%lu", &iterations);
  printf("After %lu iterations\n",  iterations);
}

//Function to set the handler for CNTL C
void setupHandlers(){
  struct sigaction new_action;

  new_action.sa_handler = catchInterrupt;
  sigfillset(&new_action.sa_mask);

  //Define the signal to handle
  sigaction(SIGINT, &new_action, NULL);
}

//Function to act on CNTL C and send exit message to server
void catchInterrupt(int signal){
  char buffer[BUFFER_SIZE];
  printf("exit signal recived\n");
  //Send EXIT message to server
  sprintf(buffer, "EXIT");
  if (send(connection_fd, buffer, strlen(buffer)+1, 0) == -1){
    fatalError("send");
  }
  //Print result, check if iteration is higher than 0 in order ro avoid double PrintPi function call
  if (iterations>0)
    printPI();
}

//Function to Kill Program
void fatalError(const char * message){
  perror(message);
  exit(EXIT_FAILURE);
}
