//Library with common sockets functions - Daniel Charua -20/09/2018

//including required libries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <netdb.h>
#include <arpa/inet.h>

#ifndef SOCKETS_H
#define SOCKETS_H

//Kill program for error handler
void kill (char reason[]);
// Receive a message and validate the return values
int receiveMessage(int connection_fd, char * buffer, int buff_length);
// Send a message and validate
int sendMessage(int connection_fd, char * buffer, int buff_length);
//Start the server in the port
int startServer(char * port);
#endif  /* not SOCKETS_H */
