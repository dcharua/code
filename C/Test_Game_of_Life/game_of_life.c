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

///// Function declarations /////
void usage(const char * program);
void lifeSimulation(int iterations, char * start_file);
// ADD YOUR FUNCTION DECLARATIONS HERE
void readWorld(char * start_file,  pgm_t * world);
void copyWorld(pgm_t * world,  pgm_t * new_world);
void makeLife(pgm_t * world,  pgm_t * new_world);
int checkForLife(pgm_t * world, int i, int j, int *gray, int *white);



int main(int argc, char * argv[]){
  char * start_file = "Boards/sample_4.txt";
  char opt;
  int iterations = 5;

  printf("\n=== GAME OF LIFE ===\n");
  printf("{By: Daniel Charua}\n");

  // Parsing the arguments
  if (argc == 2){
    iterations = atoi(argv[1]);
  } else if (argc == 3){
    iterations = atoi(argv[1]);
    start_file = argv[2];
  } else if (argc != 1){
    usage(argv[0]);
    return 1;
  }

  printf("===== CHOOSE A METHOD OF BREADING ======\n");
  printf("1. Use threads \n");
  printf("2. Use openMP \n");
  printf("----------> ");
  scanf("%c", &opt);

  switch(opt) {
   case '1':
    // Run the simulation with the iterations specified
    printf("Running the simulation with file '%s' using %d iterations with Threads\n", start_file, iterations);
    //lifeSimulationThread(iterations, start_file);
    break;

   case '2' :
     // Run the simulation with the iterations specified
     printf("Running the simulation with file '%s' using %d iterations\n", start_file, iterations);
     lifeSimulation(iterations, start_file);
     break;

   default :
     printf("Invalid option, try again\n");
  }

  return 0;
}

// Print usage information for the program
void usage(const char * program){
  printf("Usage:\n");
  printf("%s [iterations] [board file]\n", program);
}

// Main loop for the simulation
void lifeSimulation(int iterations, char * start_file){
  pgm_t world, new_world;
  readWorld(start_file, &world);
  start_file[strlen(start_file)-4] = '\0';
  start_file = &start_file[7];
  double start = omp_get_wtime();
  for(int i= 0; iterations > i; i++){
    char buffer[32] = { 0 };
    copyWorld(&world, &new_world);
    sprintf(buffer, "Images/%s_%d.pgm", start_file, i);
    writePGMFile(buffer, &world);
    makeLife(&world, &new_world);
    freeImage(&world.image);
    copyWorld(&new_world, &world);
    copyPGM(&new_world, &world);
    freeImage(&new_world.image);
  }
  printf("Parallel computation time = %f seconds\n", omp_get_wtime()-start);
}

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
      if (value == 1)
        world->image.pixels[i][j].value = 255;
      else if (value == 2)
        world->image.pixels[i][j].value = 127;
      else
        world->image.pixels[i][j].value = 0;
    }
  }
}


void makeLife(pgm_t * world,  pgm_t * new_world){
  int neighbors = 0, gray = 0, white = 0;
  #pragma omp parallel for collapse(2) private(gray, white, neighbors)
  for (int i=0; i<world->image.height; i++){
    for (int j=0; j<world->image.width; j++){
      neighbors = checkForLife(world, i, j, &gray, &white);
      if (world->image.pixels[i][j].value > 0){
        if(neighbors < 2 || neighbors > 3){
          new_world->image.pixels[i][j].value = 0;
        } else {
          new_world->image.pixels[i][j].value = world->image.pixels[i][j].value;
        }
      } else if (world->image.pixels[i][j].value == 0){
        if(neighbors == 3){
          if (white > gray){
            new_world->image.pixels[i][j].value = 255;
          }else{
            new_world->image.pixels[i][j].value = 127;
          }
        } else {
          new_world->image.pixels[i][j].value = 0;
        }
      }
    }
  }
}

int checkForLife(pgm_t * world, int i, int j, int *gray, int *white){
  int r, c;
  int neighbors = 0, counter = 0;
  (*gray) = 0; (*white) = 0;
  for (r = i - 1; r <= i + 1; r++) {
     for (c = j - 1; c <= j + 1; c++) {
      if (counter != 4){
        //printf("r=%d  %d, c=%d  %d, co=%d\n",(r +  world->image.width)% world->image.width ,r,(c +  world->image.height)% world->image.height,c, counter);
        if (world->image.pixels[(r +  world->image.width)% world->image.width][(c +  world->image.height)% world->image.height].value > 0) neighbors ++;
        if (world->image.pixels[(r +  world->image.width)% world->image.width][(c +  world->image.height)% world->image.height].value == 255) (*white)++;
        if (world->image.pixels[(r +  world->image.width)% world->image.width][(c +  world->image.height)% world->image.height].value == 127) (*gray)++;
        }
      counter++;
     }
  }
  return neighbors;
  // int counter = 0;
  // int neighbors = 0;
  // int r, c;
  // int enter = 0;
  //
  // if (i == 0 )
  //   i = world->image.height;
  // for (r = i -1; r < i+1; r++){
  //   if (j == 0 || enter )
  //     j = world->image.width;
  //   for (c = j -1; c < j+1; c++){
  //     if (counter != 4){
  //       printf("r=%d, c=%d co=%d\n",r,c,counter);
  //       if (world->image.pixels[r][c].value > 0){
  //         neighbors++;
  //       }
  //     }
  //     counter++;
  //     if (c == world->image.width-1){
  //       c = -1;
  //       j = 1;
  //       enter = 1;
  //     }
  //   }
  //   if (r == world->image.height-1){
  //     r = -1;
  //     i = 0;
  //   }
  // }
  // return neighbors;
  // if (i == 0 && j == 0){
  //    if (world->image.pixels[world->image.height-1][ world->image.width-1].value > 0) counter++;
  //    if (world->image.pixels[i][ world->image.width-1].value > 0) counter++;
  //    if (world->image.pixels[i+1][ world->image.width-1].value > 0) counter++;
  //    if (world->image.pixels[world->image.height-1][j].value > 0) counter++;
  //    if (world->image.pixels[i+1][j].value > 0) counter++;
  //    if (world->image.pixels[world->image.height-1][j + 1].value > 0) counter++;
  //    if (world->image.pixels[i+1][j].value > 0) counter++;
  //    if (world->image.pixels[i+1][j + 1].value > 0) counter++;
  //    return counter++;
  // } else if (i == 0){
  //   if (world->image.pixels[world->image.height-1][j-1].value > 0) counter++;
  //   if (world->image.pixels[i][j-1].value > 0) counter++;
  //   if (world->image.pixels[i+1][ j-1].value > 0) counter++;
  //   if (world->image.pixels[world->image.height-1][j].value > 0) counter++;
  //   if (world->image.pixels[i+1][j].value > 0) counter++;
  //   if (world->image.pixels[world->image.height-1][j + 1].value > 0) counter++;
  //   if (world->image.pixels[i][j+1].value > 0) counter++;
  //   if (world->image.pixels[i+1][j+ 1].value > 0) counter++;
  //   return counter++;
  // } else if (j == 0){
  //   if (world->image.pixels[i-1][ world->image.width-1].value > 0) counter++;
  //   if (world->image.pixels[i][ world->image.width-1].value > 0) counter++;
  //   if (world->image.pixels[i+1][world->image.width-1].value > 0) counter++;
  //   if (world->image.pixels[i-1][j].value > 0) counter++;
  //   if (world->image.pixels[i+1][j].value > 0) counter++;
  //   if (world->image.pixels[i-1][j - 1].value > 0) counter++;
  //   if (world->image.pixels[i][j+1].value > 0) counter++;
  //   if (world->image.pixels[i+1][j+ 1].value > 0) counter++;
  //   return counter++;
  // } else {
  //   if (world->image.pixels[i-1][j-1].value > 0) counter++;
  //   if (world->image.pixels[i][ j-1].value > 0) counter++;
  //   if (world->image.pixels[i+1][j-1].value > 0) counter++;
  //   if (world->image.pixels[i-1][j].value > 0) counter++;
  //   if (world->image.pixels[i+1][j].value > 0) counter++;
  //   if (world->image.pixels[i-1][j-1].value > 0) counter++;
  //   if (world->image.pixels[i][j+1].value > 0) counter++;
  //   if (world->image.pixels[i+1][j+ 1].value > 0) counter++;
  //   return counter++;
  // }
}

void copyWorld(pgm_t * world,  pgm_t * new_world){
  //Add magic number and max value
  strcpy (new_world->magic_number, world->magic_number);
  new_world->max_value = world->max_value;
  new_world->image.width = world->image.width;
  new_world->image.height = world->image.height;
  allocateImage(&new_world->image);

  //copyPGM(world, new_world);
}
