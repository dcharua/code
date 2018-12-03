/*
Daniel Charua - A01017419 - 10/11/18
    Simulation of Conway's Game of Life using OpenMP
    Based on the explanations at:
        https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
    Online versions:
        http://pmav.eu/stuff/javascript-game-of-life-v3.1.1/
        https://bitstorm.org/gameoflife/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm_image.h"
// ADD YOUR EXTRA LIBRARIES HERE
#include <pthread.h>
#include <time.h>
#include <omp.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/time.h>


#define STRING_SIZE 50
// Constant value with the amount of threads to launch
#define NUM_THREADS 4

//Struct for thread data
typedef struct data_struct {
  int start;
  int steps;
  pgm_t * world;
  pgm_t * new_world;
} data_t;

///// Function declarations /////
void usage(const char * program);
void lifeSimulation(int iterations, char * start_file, int threads);
// ADD YOUR FUNCTION DECLARATIONS HERE
void readWorld(char * start_file,  pgm_t * world);
void copyWorld(pgm_t * world,  pgm_t * new_world);
void makeLife(pgm_t * world,  pgm_t * new_world);
void makeThreads(pgm_t * world,  pgm_t * new_world, int num_threads);
int checkForLife(pgm_t * world, int i, int j, int *gray, int *white);
void makeGif(char * name);
void * makeLifeThreads(void * arg);


int main(int argc, char * argv[]){
  char * start_file = "Boards/sample_4.txt";
  int iterations, threads = 0, gif = 0;

  printf("\n=== GAME OF LIFE ===\n");
  printf("{By: Daniel Charua}\n\n");

  // Parsing the arguments
  if (argc == 5){
    gif = 1;
  } if (argc >= 4){
    threads = atoi(argv[3]);
  } if (argc >= 3){
    iterations = atoi(argv[1]);
    start_file = argv[2];
  } else if (argc <= 2){
    usage(argv[0]);
    return 1;
  }

  if(threads){
    printf("Running the simulation with %d threads, board '%s' using %d iterations\n", threads, start_file, iterations);
  } else {
    printf("Running the simulation with OpenMP, board '%s' using %d iterations\n", start_file, iterations);
    printf("To run with threads pass number of threads as 3rd argument\n");
  }
  lifeSimulation(iterations, start_file, threads);
  printf("\n=============================\nImages saved in Images folder \n=============================\n");
  if (gif)
    makeGif(start_file);
  return 0;
}

// Print usage information for the program
void usage(const char * program){
  printf("Program terminated by lack of arguments:\n");
  printf("Usage:\n");
  printf("%s [iterations] [board file] [num threads] [make gif y/n]\n", program);
}

// Main loop for the simulation
void lifeSimulation(int iterations, char * start_file, int threads){
  //Declare the 2 worlds and read the file
  pgm_t world, new_world;
  readWorld(start_file, &world);
  //Change the start_file name for image writing
  start_file[strlen(start_file)-4] = '\0';
  start_file = &start_file[7];
  for(int i= 0; iterations > i; i++){
    char buffer[32] = { 0 };
    //Copy the info from the world to new world
    copyWorld(&world, &new_world);
    //Prepare image name and write it to Images folder
    sprintf(buffer, "Images/%s_%d.pgm", start_file, i);
    writePGMFile(buffer, &world);
    //Main functon to make life
    if (threads)
      makeThreads(&world, &new_world, threads);
    else
      makeLife(&world, &new_world);
    //free the old world, copy the new_world in world and free new_world
    freeImage(&world.image);
    copyWorld(&new_world, &world);
    copyPGM(&new_world, &world);
    freeImage(&new_world.image);
  }
}

//Function to read the world
void readWorld(char * start_file,  pgm_t * world){
  int value;
  FILE * file_ptr = NULL;
  file_ptr = fopen (start_file, "r");
  if (!file_ptr){
    printf("Unable to open the file '%s'\n", start_file);
    exit(EXIT_FAILURE);
  }
  //Add magic number and max value
  strcpy (world->magic_number, "P5");
  world->max_value = 255;
  // Get the data from the header
  fscanf (file_ptr, "%d", &world->image.height);
  fscanf (file_ptr, "%d", &world->image.width);

  //malloc memory and read the matrix
  allocateImage(&world->image);
  for (int i=0; i<world->image.height; i++){
    for (int j=0; j<world->image.width; j++){
      fscanf (file_ptr, "%d", &value);
      // if its 1 we use white color if its 2 we use gray, and black for 0
      if (value == 1)
        world->image.pixels[i][j].value = 255;
      else if (value == 2)
        world->image.pixels[i][j].value = 127;
      else
        world->image.pixels[i][j].value = 0;
    }
  }
}

//Main function to make life
void makeLife(pgm_t * world,  pgm_t * new_world){
  int neighbors = 0, gray = 0, white = 0;
  //OMP for parallel computation
  #pragma omp parallel for collapse(2) private(gray, white, neighbors)
  //Double loop to transverse the world
  for (int i=0; i<world->image.height; i++){
    for (int j=0; j<world->image.width; j++){
      // checking how many neighbors
      neighbors = checkForLife(world, i, j, &gray, &white);
      //If cell was alive
      if (world->image.pixels[i][j].value > 0){
        //if it has less than 2 neighbors or more than 3 the cell dies
        if(neighbors < 2 || neighbors > 3){
          new_world->image.pixels[i][j].value = 0;
        } else { //other wise copy the color from world to new world
          new_world->image.pixels[i][j].value = world->image.pixels[i][j].value;
        }
      } else if (world->image.pixels[i][j].value == 0){ //if cell was dead
        //if it has exactly 3 live neighbors
        if(neighbors == 3){
          //if it has more white than gray new cell is white
          if (white > gray){
            new_world->image.pixels[i][j].value = 255;
          }else{//otherwise its gray
            new_world->image.pixels[i][j].value = 127;
          }
        } else { // if its doesnt have 3 neighbors cell is dead
          new_world->image.pixels[i][j].value = 0;
        }
      }
    }
  }
}

//Main function to make life in threads
void makeThreads(pgm_t * world,  pgm_t * new_world, int num_threads){
  data_t * thread_data = NULL;
  pthread_t tid[NUM_THREADS];
  // calculating steps, we divde the rows with the number of threads
  int steps = world->image.height / num_threads;
  int remaining= world->image.height% num_threads;
  int start = 0;

  // loop to create threads
  for (int i=0; i<NUM_THREADS; i++){
     // Create an instance of the structure to pass
     thread_data = malloc(sizeof (data_t));
     // Fill in the data for the thread
     thread_data->start = start;
     thread_data->steps =  steps;
     thread_data->world = world;
     thread_data->new_world = new_world;
     // Distribute the remaining steps
     if (remaining > 0){
       thread_data->steps++;
       remaining--;
     }
     //printf("Thread %d is doing %d steps, %d start \n", i, thread_data->steps, thread_data->start );
     //create thread
     pthread_create(&tid[i], NULL, makeLifeThreads, (void *)thread_data);
     start += thread_data->steps;
   }

   // Wait for the threads to finish
   for (int i=0; i<num_threads; i++){
     pthread_join(tid[i], NULL);
   }
}

//Function for every thread
void * makeLifeThreads(void * arg){
   data_t * thread_data = (data_t *) arg;
   int neighbors = 0, gray = 0, white = 0;
   //loop the rows that were assigned to the thread
   for (int i=thread_data->start; i< thread_data->start + thread_data->steps; i++){
     for (int j=0; j<thread_data->world->image.width; j++){
       // checking how many neighbors
       neighbors = checkForLife(thread_data->world, i, j, &gray, &white);
       //If cell was alive
       if (thread_data->world->image.pixels[i][j].value > 0){
         //if it has less than 2 neighbors or more than 3 the cell dies
         if(neighbors < 2 || neighbors > 3){
           thread_data->new_world->image.pixels[i][j].value = 0;
         } else { //other wise copy the color from world to new world
           thread_data->new_world->image.pixels[i][j].value = thread_data->world->image.pixels[i][j].value;
         }
       } else if (thread_data->world->image.pixels[i][j].value == 0){ //if cell was dead
         //if it has exactly 3 live neighbors
         if(neighbors == 3){
           //if it has more white than gray new cell is white
           if (white > gray){
             thread_data->new_world->image.pixels[i][j].value = 255;
           }else{//otherwise its gray
             thread_data->new_world->image.pixels[i][j].value = 127;
           }
         } else { // if its doesnt have 3 neighbors cell is dead
           thread_data->new_world->image.pixels[i][j].value = 0;
         }
       }
     }
   }
}

//Function to check for live neighbors
int checkForLife(pgm_t * world, int i, int j, int *gray, int *white){
  int r, c, neighbors = 0, counter = 0; (*gray) = 0; (*white) = 0;
  // we go from 1 - rows and 1 - cols to 1 + rows and 1 + cols
  for (r = i - 1; r <= i + 1; r++) {
     for (c = j - 1; c <= j + 1; c++) {
       //if its the 4th iteration it is itself so we dont check
      if (counter != 4){
        // checking if cell is alive and what color it is
        if (world->image.pixels[(r +  world->image.height)% world->image.height][(c +  world->image.width)% world->image.width].value > 0) neighbors ++;
        if (world->image.pixels[(r +  world->image.height)% world->image.height][(c +  world->image.width)% world->image.width].value == 255) (*white)++;
        if (world->image.pixels[(r +  world->image.height)% world->image.height][(c +  world->image.width)% world->image.width].value == 127) (*gray)++;
        }
      counter++;
     }
  }
  return neighbors;
}

//Function to copy data from old world to new world and allocate memory
void copyWorld(pgm_t * world,  pgm_t * new_world){
  strcpy (new_world->magic_number, world->magic_number);
  new_world->max_value = world->max_value;
  new_world->image.width = world->image.width;
  new_world->image.height = world->image.height;
  allocateImage(&new_world->image);
}

//Function to make gif
void makeGif(char * name){
  char buffer[100];
  //Change the start_file name for gif writing
  name = &name[7];
  sprintf(buffer, "convert -delay 20 -loop 0 Images/%s_*.pgm Gif/%s.gif", name, name);
  //system call with bufferd command
  system(buffer);
  printf("\nGif saved in Gif folder\n");
}
