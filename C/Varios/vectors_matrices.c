/*
Gilberto Echeverría

Arrays of 1 and 2 dimensions to represent vectors and matrices
*/

#include <stdio.h>

#define DIMENSION 3

int main()
{
	int i, j;
    // Declare the arrays
	float vector[DIMENSION] = { 88, 33, 55 };
	float matrix[DIMENSION][DIMENSION] = { { 1.5, 2.8, 3.0 }, { 4, 2, 4 }, { 5, 3, 1 } };

    // Print a vector
	printf("Vector:\n");
	for (i = 0; i < DIMENSION; i++)
	{
		printf("%6.2f ", vector[i]);
	}
	printf("\n\n");

    // Print a matrix
	printf("Matrix:\n");
	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			printf("%6.2f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

    // Change the matrix to be an identity matrix
	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}

    // Print a matrix. AGAIN!
	printf("Matrix:\n");
	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			printf("%6.2f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}
