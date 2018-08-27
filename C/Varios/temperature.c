/* 
daniel charua
temperature convertion 


a++  is postfix operation, meaning the value of a input will get change after the evaluation of expression.

++a is prefix operation, meaning the value of a input will get change before the evaluation of expression.
*/

#include <stdio.h>

int main () 
{
    float celcius, fahrenheit;
    printf("Enter temperature in celcius to convert to fahrenheit: ");
    scanf("%f", &celcius);
    fahrenheit = (9*celcius/5)+32;
    printf("Temperature in fahrenheit is %.2f\n", fahrenheit);
    printf("Enter temperature in fahrenheit to convert to celcius: ");
    scanf("%f", &fahrenheit);
    celcius = (fahrenheit-32)*5/9;
    printf("Temperature in celcius is %.2f\n", celcius);
    printf("Thank you for using Daniel´s temperature convertor\n Hope it pleased you\n");
}