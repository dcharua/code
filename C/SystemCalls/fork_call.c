/*
Program to test calling the 'fork' function

Gilberto Echeverria
30/08/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    //char nothing; 


    printf("In the main program with PID: %d\n", getpid());
    
    pid = fork();
    
    if (pid > 0)    // The parent process
    {
        int status;
        printf("PARENT PID: %d, with parent %d\n", getpid(), getppid());
        printf("The parent received pid: %d\n", pid);
        wait(&status);
        printf("My child returned with %p\n", status);
        if (WIFEXITED(status))
        {
            printf("My child returned a %d\n", WEXITSTATUS(status));
        }
    }
    else if (pid == 0)      // The child process 
    {
        printf("\tCHILD PID: %d, with parent %d\n", getpid(), getppid());
        printf("\tFork returned %d in the child\n", pid);
        return 10;
    }
    else
    {
        printf("Fork failed");
    }
    
    //nothing = getchar();
   
    printf("Returning to my main\n");
    
    return 0;
}
