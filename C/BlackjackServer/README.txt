ReadMe for BlackJack Game - Daniel Charua - 6/10/2018

This is a client server BlackJack game.
In order to play the user must run the make command at the program dirctory
2 files will be created a server and a client program
The user must first run the server with the port to listen to ex: ./server 8989
In a new terminal the user must run the client program with the servers ip and port_number
the server is runnig at localhost ex: ./client localhost 8989
The server will ask the client for a initial pot and a bet ammount for every hand
The server will act as the dealer and the client can play until he is out of money or decides to quit
The client must be careful when sending the actions, pot and bet amount since the server will NOT
validate the client inputs.

Best of Luck, Enjoy!
