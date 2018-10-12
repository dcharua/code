ReadMe for PI SERVER - Daniel Charua - 12/10/2018

This is a client server PI Calulation program.
In order to compute PI the user must run the make command at the program directory
2 files will be created a server and a client program
The user must first run the server with the port to listen to ex: ./server 8989
In a new terminal the user must run the client program with the servers ip and port_number
the server is runnig at localhost ex: ./client localhost 8989
The server will ask the client for the number of iterations to calulate PI
If the number is too big the calculation could take a some time
The client can, at any time, press CTRL + C to terminate the program and get the current result from the server.
Likewise if the server needs to be shutdowns, if CTRL + C is pressed the current result will be sent to all clients before terminating
