#include <stdio.h>

#define STRING_SIZE 30

int main()
{
    //// WRITING ////
    // Open the file indicated by a name
    FILE * the_file = fopen("test.txt", "w");
    // Check that the file could be openend
    if (the_file == NULL)
    {
        printf("Error reading file\n");
        return 1;
    }
    // Write to the file
    printf("Hello world\n");
    fprintf(the_file, "Hello world\n");
    fprintf(the_file, "%d", 9876654);
    // Close the file
    fclose(the_file);


    //// READING ////
    the_file = fopen("test.txt", "r");
    // Check that the file could be openend
    if (the_file == NULL)
    {
        printf("Error reading file\n");
        return 1;
    }
    // Read strings
    char string[STRING_SIZE];
    fgets(string, STRING_SIZE, the_file);
    // Read numbers
    int x;
    fscanf(the_file, "%d", &x);
    // Close the file
    fclose(the_file);
}
