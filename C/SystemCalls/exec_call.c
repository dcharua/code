/*
Program to test calling the 'exec' function

Gilberto Echeverria
30/08/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("In the main program\n");
    
    
    
    //execl("/bin/ls", "ls",  "-l",  "..", (char *) NULL); 
    system("date +%H:%M");
    char * command = "python3";
    char * parameters[] = {"python3", "../python_test.py", (char *) NULL};
    execvp(command, parameters);
    
    printf("Returning to my main\n");
    
    return 0;
}