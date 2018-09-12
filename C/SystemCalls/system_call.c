/*
Program to test calling the 'system' function

Gilberto Echeverria
30/08/2018
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("In the main program\n");
    
    system("ls -l .."); 
    system("date +%H:%M");
    system("python3 ../python_test.py");
    
    printf("Returning to my main\n");
    
    return 0;
}