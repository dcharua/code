//Library with common sockets functions - Daniel Charua - 20/09/2018
#include "socketsLib.h"
#define MAX_QUEUE 5


//function to kill with error return
void kill (char reason[]){
  fprintf(stderr, "%s", reason);
  exit(EXIT_FAILURE);
}

// Receive a message and validate the return values
int receiveMessage(int connection_fd, char * buffer, int buff_length){
  int chars_read;
  // Clear the buffer
  memset(buffer, 0, buff_length);
  // Get an incomming message
  chars_read = recv(connection_fd, buffer, buff_length, 0);
  if (chars_read == -1)
    kill("recv error");
  if (chars_read == 0)
    printf("Client disconnected\n");
  return chars_read;
}

// Send a message and validate
int sendMessage(int connection_fd, char * buffer, int buff_length){
  if (send(connection_fd, buffer, strlen(buffer), 0) == -1)
    kill("send error");
}

// Initialize the server to be ready for connections
int startServer(char * port){
  struct addrinfo hints;
  struct addrinfo * server_info = NULL;
  int server_fd;
  // Prepare the information to determine the local address
  // Clear the structure
  memset(&hints, 0, sizeof hints);
  // Let the IP address be found automatically
  hints.ai_flags = AI_PASSIVE;
  // Use IPv4 address
  hints.ai_family = AF_INET;
  // Type of socket
  hints.ai_socktype = SOCK_STREAM;

  ///// GETADDRINFO
  // Get the actual address of this computer
  if ( getaddrinfo(NULL, port, &hints, &server_info) == -1)
    kill("getaddrinfo error");

  ///// SOCKET
  // Use the information obtained by getaddrinfo
  server_fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
  if (server_fd == -1)
    kill("socket error");

  //Allow instant connection in same port
  int reuse = 1;
  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse) == -1)
    kill("set socket");

  ///// BIND
  // Connect with the desired port
  if (bind(server_fd, server_info->ai_addr, server_info->ai_addrlen) == -1)
    kill("bind error");
  // Release the memory of the list of addrinfo
  freeaddrinfo(server_info);

  ///// LISTEN
  // Prepare for connections
  if (listen(server_fd, MAX_QUEUE) == -1)
    kill("listen error");
  return server_fd;
}
