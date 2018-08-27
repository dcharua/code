/*
    Show the size of the data that can be stored in different variable types
    
    Gilberto Echeverria
    06/08/2018
*/

#include <stdio.h>
#include <limits.h>

#define NUMBER 15

int main ()
{
    printf("Hello %d\n", NUMBER);
    
    #ifdef DEBUG
    printf("The temp value is: \n");
    #endif
    
    printf("INT MIN: %d - MAX: %d\n", INT_MIN, INT_MAX);
    printf("LONG MIN: %ld - MAX: %ld\n", LONG_MIN, LONG_MAX);

    return 0;    
}

