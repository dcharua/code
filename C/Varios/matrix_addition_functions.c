/*
Gilberto Echeverria

Adding matrices and searching them, using functions
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSION 4
#define RANGE 10

// Function prototypes (function declarations)
void fill_random_matrix(float matrix[][DIMENSION]);
void add_matrices(float matrix_1[][DIMENSION], float matrix_2[][DIMENSION], float matrix_r[][DIMENSION]);
void print_matrix(float matrix[][DIMENSION]);
int find_in_matrix(float matrix[][DIMENSION], float search);


int main()
{
	float matrix1[DIMENSION][DIMENSION];
	float matrix2[DIMENSION][DIMENSION];
	float matrix3[DIMENSION][DIMENSION];
	int found = 0;

    // Initialize the random seed, based on the current time in seconds
	srand(time(NULL));

	// Fill the matrices with random numbers
    fill_random_matrix(matrix1);
    fill_random_matrix(matrix2);

	// Print matrix 1
	printf("\nMATRIX 1\n");
    print_matrix(matrix1);
	
	// Print matrix 2
	printf("\nMATRIX 2\n"); 
    print_matrix(matrix2);

	// Add the matrices
    add_matrices(matrix1, matrix2, matrix3);

	// Print the resulting matrix
	printf("\nMATRIX 3\n");
    print_matrix(matrix3);

	// Find the number 5 in the matrix
    found = find_in_matrix(matrix3, 5);
    if (found)
        printf("Found what I was looking for\n");
    else
        printf("Did not find anything\n");

	return 0;
}

// Function definitions

/*
Generate random numbers to fill in a matix
*/
void fill_random_matrix(float matrix[][DIMENSION])
{
    int i, j;

	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
            // Use the constants defined to generate random numbers in the range desired
            // In this case, numbers from -5 to 5
			matrix[i][j] = rand() % RANGE - (RANGE / 2);
		}
	}
}

/*
Add the elements in matrices matrix_1 and matrix_2, and store the result in matrix_r
*/
void add_matrices(float matrix_1[][DIMENSION], float matrix_2[][DIMENSION], float matrix_r[][DIMENSION])
{
    int i, j;

	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			matrix_r[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}
}

/*
Print the contents of a matrix, in a nicely formatted way
*/
void print_matrix(float matrix[][DIMENSION])
{
    int i, j;

    for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			printf("% 7.2f ", matrix[i][j]);
		}
		printf("\n");
	}
}

/*
Detect whether the given element 'search' can be found inside the matrix
Returns 1 if found, 0 if not found
*/
int find_in_matrix(float matrix[][DIMENSION], float search)
{
    int i, j;
    int found = 0;

	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			if (matrix[i][j] == search)
			{
				found = 1;
				printf("Found a %.2f at indices %d, %d\n", search, i, j);
			}
		}
	}
	if (!found)
	{
		printf("Did not find any %.2f in the matrix\n", search);
	}
    return found;
}
