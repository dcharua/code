/*
Gilberto Echeverría

File Input and Output / Structures

File open modes:
	w	-	Write
	r	-	Read
	a	-	Append
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

#define ARRAY_SIZE 4

typedef struct patient
{
	char name[50];
	int telephone;
	float height;
	float weight;
} patient;

int write_file(char* filename);
int read_file(char* filename);
void print_ascii();

int main()
{
	char* filename = "test.txt";

	print_ascii();

	write_file(filename);
	read_file(filename);

	return 0;
}

void print_ascii()
{
	printf("  ( ^ | ^ )\n");
	printf("   )     (\n");

}


int write_file(char* filename)
{
	FILE* filePtr;
	char* name = "Gilberto";
	float height = 0;

	filePtr = fopen(filename, "w");
	if (filePtr == NULL)
	{
		printf("Could not open file '%s' for writing.\n", filename);
		return 1;
	}

	fprintf(filePtr, "%s\n", name);
	fprintf(filePtr, "%d\n", 789456123);
	fprintf(filePtr, "%f\n", 1.76);
	fprintf(filePtr, "%f\n", 72.5);

	fprintf(filePtr, "%s\n", "Andres");
	fprintf(filePtr, "%d\n", 4561859753);
	fprintf(filePtr, "%f\n", 1.69);
	fprintf(filePtr, "%f", 70.1);

	fclose(filePtr);

	return 0;
}

int read_file(char* filename)
{
	FILE* filePtr;
	patient patients[ARRAY_SIZE];
	int i = 0;

	filePtr = fopen(filename, "r");
	if (filePtr == NULL)
	{
		printf("Could not open file '%s' for reading.\n", filename);
		return 1;
	}

	while (1)
	{
		fscanf(filePtr, " %s", patients[i].name);
		printf("\nPatient name: %s\n", patients[i].name);	// No & when reading strings
		fscanf(filePtr, " %d", &patients[i].telephone);
		printf("Patient telephone: %d\n", patients[i].telephone);
		fscanf(filePtr, " %f", &patients[i].height);
		printf("Patient height: %.2f\n", patients[i].height);
		fscanf(filePtr, " %f", &patients[i].weight);
		printf("Patient weight: %.2f\n", patients[i].weight);
		i++;

		if (feof(filePtr) || i > ARRAY_SIZE)
			break;
	}

	fclose(filePtr);
	return 0;
}