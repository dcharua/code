//Library with common sockets functions - Daniel Charua -20/09/2018
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#ifndef SOCKETS_H
#define SOCKETS_H

// Receive a message and validate the return values
int receiveMessage(int connection_fd, char * buffer, int buff_length);
// Send a message and validate
int sendMessage(int connection_fd, char * buffer, int buff_length);
//Start the server in the port
int startServer(char * port);
#endif  /* not SOCKETS_H */
