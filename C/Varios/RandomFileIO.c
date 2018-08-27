/*
Gilberto Echeverria

Random access to a file, using binary files
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define STRING_SIZE 20
#define MAX_FRIENDS 10

typedef struct friend_struct
{
	char name[STRING_SIZE];
	int age;
	unsigned int telephone;
} friend;


FILE * open_and_check(char * file_name, char * mode)
{
	FILE * file_pointer = NULL;

	file_pointer = fopen(file_name, mode);
	if (file_pointer == NULL)
	{
		printf("Error opening file %s!\n", file_name);
	}
	return file_pointer;
}


void print_friend(friend one_friend)
{
	printf("Name: %s\n", one_friend.name);
	printf("Age: %d\n", one_friend.age);
	printf("Telephone: %u\n", one_friend.telephone);
}


void write_contact_file(friend my_friends[], int num_friends)
{
	FILE * file_pointer;
	char * file_name = "friends.txt";
	friend some_friend;

	file_pointer = open_and_check(file_name, "rb+");
	if (file_pointer != NULL)
	{
		printf("Writing to the file...\n");
		// Write all items of the array at once
		fwrite(my_friends, sizeof(friend), num_friends, file_pointer);

		// Jump to the position of the 3rd element (index 2)
		fseek(file_pointer, sizeof(friend) * 2, SEEK_SET);
		// Read the contents of a single friend from the file
		fread(&some_friend, sizeof(friend), 1, file_pointer);

		printf("The third friend is:\n");
		print_friend(some_friend);
	}
}


int main()
{
	// Initialize a single instance of a structure
	friend one_friend = {"Juan", 19, 123456};
	// Initialize an array of structures
	friend my_friends[MAX_FRIENDS] = { {"Martha", 30, 789456}, {"Jorge", 25, 456852} };
	int i;

	my_friends[2] = one_friend;

	printf("Enter the name of a friend: ");
	scanf("%s", my_friends[3].name);
	printf("Enter the age of a friend: ");
	scanf("%d", &my_friends[3].age);
	printf("Enter the telephone of a friend: ");
	scanf("%d", &my_friends[3].telephone);

	printf("Should have %zu bytes\n", sizeof(friend) * 4);

	for (i = 0; i < 4; i++)
	{
		print_friend(my_friends[i]);
	}

	write_contact_file(my_friends, 4);

	return 0;
}
