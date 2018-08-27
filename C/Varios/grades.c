/*
Name:Daniel Charua Garcia A01017419


School grades system using arrays and functions
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STUDENTS 20


// WRITE YOUR FUNCTION PROTOTYPES HERE
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

void fill_grades (int grades[MAX_STUDENTS]);
void print_grades (int grades[MAX_STUDENTS]);
float find_average (int grades[MAX_STUDENTS]);
int get_passed (int grades[MAX_STUDENTS]);
int get_failed (int grades[MAX_STUDENTS]);



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
void fill_grades (int grades[MAX_STUDENTS])
{
    int i;
    srand(time(NULL));

	for (i = 0; i <MAX_STUDENTS; i++)
	{
		
		grades[i] = rand() % 100 + 1;
	}
}

void print_grades(int grades[MAX_STUDENTS])
{
	int i;
	for (i = 0; i <MAX_STUDENTS; i++)
	{
		
		printf("The grade is: %d\n", grades[i]);
		
	}
}

float find_average(int grades[MAX_STUDENTS])

{
	int i;
	int num;
	num=0;
		for (i = 0; i <MAX_STUDENTS; i++)
	{
		num=grades[i]+num;
	}	

num=num/MAX_STUDENTS; 
return num;
}
int get_passed(int grades [MAX_STUDENTS])
{
	int num, i;
	num=0;
		for (i = 0; i <MAX_STUDENTS; i++)
		if (grades[i]>=70)
		{
		num++;
		}
		return num;
}
int get_failed(int grades[MAX_STUDENTS])
{
	int num, i;
	num=0;
	for (i = 0; i <MAX_STUDENTS; i++)
		if (grades[i]<70)
		{
			num++;
		}
		return num;
}	

	



// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ALL FUNCTIONS SHOULD BE ABOVE