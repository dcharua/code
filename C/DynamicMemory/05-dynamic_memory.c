/*
Gilberto Echeverria

Dynamic memory
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int size;
    int items;
    int years;
    int * array_ptr = NULL;
    float ** stock = NULL;
    float * stock1d = NULL;
    
    ///////////////////////////////////////////
    // Create a one-dimensional array of ints
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    
    array_ptr = (int *) malloc(sizeof(int) * size);
     
    for (i=0; i<size; i++)
    {
        array_ptr[i] = i * i;
        printf("array[%d] = %d\n", i, array_ptr[i]);
    }
    
    free(array_ptr);
    
    
    ///////////////////////////////////////////
    // Create a bi-dimensional array of floats
    printf("Enter the items: ");
    scanf("%d", &items);
    printf("Enter the years: ");
    scanf("%d", &years);
    
    stock = (float**) malloc(sizeof(float**) * items);
    for (i=0; i<items; i++)
    {
        stock[i] = (float*) malloc(sizeof(float*) * years);
    }
    
    for(i=0; i<items; i++)
    {
        for(j=0; j<years; j++)
        {
            stock[i][j] = (i+1) * (j+1);
            printf("stock[%d][%d] = %f\n", i, j, stock[i][j]);
        }
    }
    
    for(i=0; i<items; i++)
    {
        free(stock[i]);
    }
    free(stock);
    
    ///////////////////////////////////////////
    // Create a bi-dimensional array of floats
    printf("Enter the items: ");
    scanf("%d", &items);
    printf("Enter the years: ");
    scanf("%d", &years);
    
    stock1d = (float*) malloc(sizeof(float) * items * years);
    
    for(i=0; i<items; i++)
    {
        for(j=0; j<years; j++)
        {
            stock1d[i * years + j] = (i+1) * (j+1);
            printf("stock[%d][%d] = %f\n", i, j, stock1d[i * years + j]);
        }
    }
            
    free(stock1d);
    
    return 0;
}
