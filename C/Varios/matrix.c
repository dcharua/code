//Daniel Charua Garcia    A01017419   Matrix

#include <stdio.h>
#define SIZE 2
int main ()
{
    int i, j;
    float matrix [SIZE][SIZE];
    float matrixb [SIZE][SIZE];
    float matrixc [SIZE][SIZE];
    //matrix1
    for (i=0; SIZE>i; i++)
    {
        for (j=0; SIZE>j; j++)
        {
            printf("Input numbers of the first matrix: ");
            scanf ("%f", &matrix[i][j]);
        }
//matrix2        
    }
    for (i=0; SIZE>i; i++)
    {
        for (j=0; SIZE>j; j++)
        {
            printf("Input numbers of the second matrix: ");
            scanf ("%f", &matrixb[i][j]);
        }
    }
//Adding the matrix
  printf("The addition of the matrix is:\n");

    for (i=0; SIZE>i; i++)
    {
        for (j=0; SIZE>j; j++)
        {
           matrixc[i][j]=matrix[i][j]+matrixb[i][j];
       
    
          printf("%6.2f ", matrixc[i][j]);
		}
		printf("\n");
	}
  
//looking for the 5
   for (i=0; SIZE>i; i++)
    {
        for (j=0; SIZE>j; j++)
        {
           matrixc[i][j]=matrix[i][j]+matrixb[i][j];
           if(matrixc[i][j]==5)
           {
        
    printf("5 was found in position: %i, %i\n", i, j);
    }  
        }
    }
 }