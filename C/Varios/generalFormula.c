/*
Gilberto Echeverria

Solver for quadratic equations of the form:
	ax2 + bx + c = 0
Uses the 'math' library to compute square roots and powers
*/

#define _CRT_SECURE_NO_DEPRECATE	// Stop the complaining from MS VS
// http://www.cplusplus.com/forum/beginner/2300/

#include <stdio.h>
#include <math.h>

int main()
{
	float a;
	float b;
	float c;
	float x1;
	float x2;

	float det;

	printf("Enter the coefficients\n");
	printf("A: ");
	scanf("%f", &a);
	printf("B: ");
	scanf("%f", &b);
	printf("C: ");
	scanf("%f", &c);

	// Find the determinant
	det = b*b - 4 * a * c;

	// Avoid square roots of negative numbers
	if (det < 0)
	{
		printf("Complex numbers are not supported\n");
		printf("Finishing\n");
		//return 1;
	}
	else
	{
		x1 = (-b + sqrtf(det)) / (2 * a);
		x2 = (-b - sqrtf(det)) / (2 * a);

		printf("X1 = %.4f\n", x1);
		printf("X2 = %.4f\n", x2);
	}

	return 0;
}
