/*
Name:


School grades system using arrays and functions
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STUDENTS 20

// WRITE YOUR FUNCTION PROTOTYPES HERE
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv







// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ALL FUNCTION PROTOTYPES SHOULD BE ABOVE

int main()
{
	int grades[MAX_STUDENTS];
	int passed, failed;

	// Initialize the random numbers
	srand(time(NULL));

	fill_grades(grades);
	print_grades(grades);
	printf("The average grade is: %.2f\n", find_average(grades));
	passed = get_passed(grades);
	failed = get_failed(grades);
	printf("%d students passed and %d students failed\n", passed, failed);

	return 0;
}

// WRITE YOUR FUNCTIONS HERE
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv







// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ALL FUNCTIONS SHOULD BE ABOVE