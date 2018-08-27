/*
   Gilberto Echeverria

   Simple user interface
*/

#include <stdio.h>

int main()
{
    char option = 'a';
    int i;

    while(option != 'q')
    {
        printf("Welcome!\nChoose an option:\n");
        printf("\ta. Say hello\n");
        printf("\tb. Say goodbye\n");
        printf("\tc. Say nothing\n");
        printf("\tq. Quit\n");
        printf("Your choice: ");
        scanf(" %c", &option);

        switch(option)
        {
            case 'a':
            case 'A':
                for (i=0; i<5; i++)
                    printf("HELLO!\n");
                break;
            case 'b':
            case 'B':
                printf("GOODBYE!\n");
                break;
            case 'c':
            case 'C':
                printf("......\n");
                break;
            default:
                printf("Incorrect option, try again!\n");
                break;
        }
    }
}
