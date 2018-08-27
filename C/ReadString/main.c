#include "readString.h"

#define STRING_SIZE 50

int main ()
{
    char name[STRING_SIZE];

    printf("Enter your name: ");
    readString(name, STRING_SIZE);

    printf("name: '%s'\n", name);

    return 0;
}
