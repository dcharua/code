/*
Nombre: Gilbert Echeverria
Matricula: L01479899

Second Partial Exam
Program to register the cars that enter and exit a parking lot
Use an array for parking places and store the license plates of the cars parked in each place.
Empty parking places will be indicated by a 0 in the array.
License plates are positive integers of up to 3 digits. The number can NOT be 0.

Questions:
1. Complete the function "register_car".
It receives as a parameter the array of the parking
It will return nothing.
It will ask for the license plates of the car to register (you can use the "input_license" function)
It will look for the next available space (one containing 0) and change the value for the license plate of the car
If the car is already in the parking (you can use the "search_car" function), or if there are no more places,
print a warning message
2. Complete the "search_car" function.
It receives three parameters: the array, an int with the license number to search for and a pointer to int
It will return 1 if the car was found, 0 if it was NOT found.
The current location of the car (the index of the array) is returned via reference, using the third parameter to the function
This function should not print anything. Other functions may print messages depending on the results from this one
3. Create the function "remove_car".
It will return nothing.
It receives the array of the parking places
It will ask for the license plates of the car to remove (you can use the "input_license" function)
Once the license plate is found, it will be replaced by 0 and print a message indicating which place has been freed.
If the car is not found, print a warning message.

HINT: Read the code provided. If you understand it, answering the questions will be much easier!

*/

#define _CRT_SECURE_NO_DEPRECATE	// Stop the complaining from MS VS
// http://www.cplusplus.com/forum/beginner/2300/

#include <stdio.h>

#define PARKING_PLACES 10


void parking_loop(void);
void query_car(int* parking_array);
int input_license(void);
void print_parking_array(int* parking_array);
// These are the functions you must create
void register_car(int* parking_array);
int search_car(int* parking_array, int license, int* location);
void remove_car(int* parking_array);


int main()
{
	printf("PARKING REGISTRY PROGRAM\n");
	printf("========================\n");
	parking_loop();

	return 0;
}

/*
Main loop for the program. It shows the user menu.
*/
void parking_loop(void)
{
	char option = 'a';
	// An array with some places already in use
	int parking_places[PARKING_PLACES] = { 123, 456, 873, 390 };
	// An array with all places empty
	//int parking_places[PARKING_PLACES] = { 0 };

	while (option != 'q')
	{
		printf("\nUser menu:\n");
		printf("\tc. Enter a new car in the parking lot\n");
		printf("\tr. Remove a car from the parking lot\n");
		printf("\ts. Search the parking lot for a car and print the place it uses\n");
		printf("\tp. Print all cars in the parking lot\n");
		printf("\tq. Exit the program\n");
		printf("Choose an option according to the action to take: ");
		scanf(" %c", &option);
		switch (option)
		{
		case 'c':
			register_car(parking_places);
			break;
		case 'r':
			remove_car(parking_places);
			break;
		case 's':
			query_car(parking_places);
			break;
		case 'p':
			print_parking_array(parking_places);
			break;
		case 'q':
			printf("Thanks for using the system\n");
			break;
		default:
			printf("Invalid option. Try again\n");
			break;
		}
	}
}

/*
Ask for a license plate to search, and print the status of that car
*/
void query_car(int* parking_array)
{
	int location;
	int license;

	printf("Search of a registered car ->\n");
	license = input_license();
	if (license)
	{
		if (search_car(parking_array, license, &location))
		{
			printf("The car is parked in box number [%3d]\n", location);
		}
		else
		{
			printf("That car is not registered in this parking lot. Sorry!\n");
		}
	}
}

/*
Ask for a license number and check that it is valid
Valid licenses are positive 3 digit integers, different from 0
Returns the license number or 0 if it is an invalid number
*/
int input_license()
{
	int license;

	printf("Enter the license plate number of the car (3 digits, different from 0): ");
	scanf("%d", &license);

	if (license > 0 && license < 1000)
	{
		return license;
	}
	else
	{
		printf("That is not a valid license number! Try again.\n");
		return 0;
	}
}

/*
Utility function to print the contents of the array.
Can be used to debug the program during development.
*/
void print_parking_array(int* parking_array)
{
	int i;

	for (i = 0; i < PARKING_PLACES; i++)
	{
		printf("Place: [%3d] -> Car license: '%03d'\n", i, parking_array[i]);
	}
}

/////////////////////////////////////////////////////////
/////////// WRITE YOUR FUNCTIONS BELOW //////////////////
/////////////////////////////////////////////////////////

/*
Find the next free parking place and register a car in that place
First ask for the license plate of the car. Use the "input_license" function.
If the car is already in the parking, print a warning message and DO NOT register it again.
If there are no more free places, print a warning message
*/
void register_car(int* parking_array)
{
	int location;
	int license;
	int i;

	printf("Register a new car ->\n");
	license = input_license();
	if (license)
	{
		if (search_car(parking_array, license, &location))
		{
			printf("Car already in the parking lot at position %d\n", location);
		}
		else
		{
			for (i = 0; i < PARKING_PLACES; i++)
			{
				if (parking_array[i] == 0)
				{
					printf("Inserting car at position: %d\n", i);
					parking_array[i] = license;
					return;
				}
			}
			printf("There were no free spaces\n");
		}
	}
}

/*
Look for the box number where a car is parked.
Returns 1 if the car was found, 0 if it was not.
The box number is returned by reference in the third parameter (location)
*/
int search_car(int* parking_array, int license, int* location)
{
	int i;
	for (i = 0; i < PARKING_PLACES; i++)
	{
		if (parking_array[i] == license)
		{
			*location = i;
			return 1;
		}
	}
	return 0;
}

/*
MYSTERY FUNCTION GOES HERE
*/
void remove_car(int parking_array[])
{
	int location;
	int license;

	printf("Remove a registered car ->\n");
	license = input_license();
	if (license)
	{
		if (search_car(parking_array, license, &location))
		{
			parking_array[location] = 0;
			printf("Car removed from space %d\n", location);
		}
		else
		{
			printf("That car is not registered in this parking lot. Sorry!\n");
		}
	}
}


