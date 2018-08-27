/*
   Gilberto Echeverria

   Average of numbers
*/

#include <stdio.h>

#define SIZE 50

#define DEBUG

int main()
{
    float grade;
    float average;
    float sum = 0;
    float grades[SIZE];
    int counter = 0;
    int i;
    int higher = 0;
    int lower = 0;

    do
    {
        printf("Enter another grade: ");
        scanf("%f", &grade);
        if (grade != -1)
        {
            // Store the data in the array
            grades[counter] = grade;
            sum += grade;
            counter++;
#ifdef DEBUG
    printf("The current value of sum is %f\n", sum);
#endif
        }
      /*
      // Keep in the loop as long as:
      // 1. grade is different from -1
      // 2. counter is less than SIZE
      // When any of the two conditions is false, the loop finishes
      */
    } while(grade != -1 && counter < SIZE);

    average = sum / counter;
    printf("The avarage is: %.2f\n", average);

    for(i=0; i<counter; i++)
    {
        // Use the values stored in the array
        if (grades[i] > average)
        {
            higher++;
        }
        if (grades[i] < average)
        {
            lower++;
        }
    }

    printf("%d higher than average\n%d lower than average\n", higher, lower);

    printf("ALL %d ELEMENTS OF THE ARRA:\n", SIZE);
    for (i=0; i<SIZE;i++)
    {
       printf("%d: %f\n", i, grades[i]); 
    }
}
