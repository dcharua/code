/*
Daniel Charua Garcia
A01017419
Elevate number to the power..
i left it with two decimals in case the user enters decimal number
*/


#include <stdio.h>

int main()
{
    float n, p, i, x, a;
    a=1;
    i=1;
    if (a=1)
    { 
        printf ("Enter number: ");
    scanf("%f", &n);
    printf ("Enter the power: ");
    scanf ("%f", &p);
    x=n;
    while (p>i)
    { 
    
        x=x*n;
        p=p-1;
    }
    printf ("the result is: %.2f\n", x);
    printf ("if you would like to try again press 1: ");
    scanf("%f", &a);
    }
   else
   {
       printf ("thank you\n");
   }
}

