/*
    Initial program using threads

    Gilberto Echeverria
    11/10/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread entry function
void * threadEntry (void * arg);

int main(int argc, char * argv[])
{
    int num_threads;

    if (argc == 2)
    {
        num_threads = atoi(argv[1]);
    }

    // Prepare an array for the thread id's
    pthread_t tid[num_threads];

    int result;

    // Create the number of threads specified
    for (long i=0; i<num_threads; i++)
    {
        result = pthread_create(&tid[i], NULL, threadEntry, (void*)i);
        if (result == -1)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for the threads to finish
    for (int i=0; i<num_threads; i++)
    {
        pthread_join(tid[i], NULL);
    }

    //pthread_exit(NULL);
    return 0;
}

void * threadEntry (void * arg)
{
    long index = (long)arg;
    printf("This is a thread %ld, with tid %d\n", index, (int)pthread_self());

    pthread_exit(NULL);
}
