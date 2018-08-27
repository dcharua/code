// Daniel Charua 13/08/18

#include <stdio.h>
#include <math.h>

int main(){
  float u,a,t,x,y;

  printf ("Input the lunch velocity:");
  scanf("%f", &u);
  printf ("\nInput the angle in degrees:");
  scanf("%f", &a);
  printf ("\nInput the time of fight:");
  scanf("%f", &t);

  x = u * t * cos(a);
  y = u * t * sin(a);
  printf("The x is: %f and the y is: %f \n", x, y);
}
