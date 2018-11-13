/*
    WRITE YOUR NAME HERE:
    Maurico Rico Zavala
    A01370874

    Simulation of Conway's Game of Life using OpenMP
    Based on the explanations at:
        https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
    Online versions:
        http://pmav.eu/stuff/javascript-game-of-life-v3.1.1/
        https://bitstorm.org/gameoflife/

    OpenMP method for game of life logic based on: https://github.com/serendependy/parallel-j/blob/master/OpenMP/game-of-life-omp.c

    Logic in calculateNeighbor based on adjacent_to function of: https://github.com/supperino/Game-of-Life-pthread/blob/master/gol.c

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
#include "threadConfig.c"

#define STRING_SIZE 50
#define THREADS_NUMBER 4 // Change this for multithreaded answer

// Board struct
typedef struct board_struct {
    int width;
    int height;
    int ** cell;
} board_t;

// Some global variables
int numberOfThreads;
int lines;
int rest;
int k;
//pthread_barrier_t barrier;
int iterations = 4;
// For the threads
board_t * lastBoard;
board_t * currentBoard;

//////////////////// FUNCTION DECLARATIONS ////////////////////

void usage(const char * program);
void lifeSimulationThread(int iterations, char * start_file);
void lifeSimulationOpenmp(int iterations, char * start_file);
void preparePGMImage(const void * board, pgm_t * board_image);
void saveAsPGM(const void * board, pgm_t * board_image, int iteration);
// ADD YOUR FUNCTION DECLARATIONS HERE
board_t * createNewBoard(int x, int y);
void updateBoardOMP(board_t * lastBoard, board_t * currentBoard);
void deleteBoard(board_t* board);
void printBoard(board_t* board);
void * updateBoardThread(void * temp);
void simulate(int start, int end, int tid, board_t * lastBoard, board_t * currentBoard);
double get_time();
int calculateNeighbor(board_t * board, int i, int j);


//////////////////// FUNCTION DEFINITIONS ////////////////////

// Main function
int main(int argc, char * argv[]){

    char * start_file = "Boards/pulsar.txt";
    int opt;

    printf("\n====== GAME OF LIFE =====\n");
    printf("{By: MAURICIO RICO ZAVALA}\n");
    printf("\n");

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
    // Menu to choose threads or OpenMP
    printf("Before starting the simulation, would you like to proceed with:\n");
    printf("1. Threads \n");
    printf("2. OpenMP \n");
    printf("----------> ");
    scanf("%d", &opt);

    if(opt == 1){
        // Run the simulation with the iterations specified
        printf("Running the simulation with file '%s' using %d iterations with Threads\n", start_file, iterations);
        //lifeSimulationThread(iterations, start_file);
    } else if(opt == 2){
        // Run the simulation with the iterations specified
        printf("Running the simulation with file '%s' using %d iterations with OpenMP\n", start_file, iterations);
        lifeSimulationOpenmp(iterations, start_file);
    }

    return 0;
}

// Print usage information for the program
void usage(const char * program){
    printf("Usage:\n");
    printf("%s [iterations] [board file]\n", program);
}

// // Main loop for the simulation (THREADS)
// void lifeSimulationThread(int iterations, char * start_file){
//
//     //pthread_barrier_t barrier;
//     pgm_t image; // First instance of a struct
//     readPGMFile(start_file, &image); // Read from file
//     // Declare variables
//     int width = image.image.width;
//     int height = image.image.height;
//
//     // Create board with the size specified from file
//     board_t * lastBoard = createNewBoard(width, height);
//
//     // Copy from board obtained from file to shiny new board
//     for(int i = 0; i < height; i++){
//         for(int j = 0; j < width; j++){
//             if(image.image.pixels[i][j].value == 0){
//                 lastBoard->cell[i][j] = 0;
//             } else if(image.image.pixels[i][j].value == 1){
//                 lastBoard->cell[i][j] = 1;
//             }
//         }
//     }
//     printf("Initial board: \n");
//     // Prints the board
//     for (int i = 0; i < height; i++) {
//         for (int j = 0; j < width; j++) {
//             printf(" %d ", lastBoard->cell[i][j]);
//         }
//         printf("\n");
//     }
//
//     printf("\n");
//
//     // Main loop for the iterations
//     for(int i = 0; i < iterations; i++){
//         // Variables
//         int i = 1;
//         char buffer[50];
//         sprintf(buffer, "Images/image%04i.pgm", i);
//         pgm_t imageTemp; // First instance of a struct
//         // Assign values for header
//         imageTemp.image.width = image.image.width;
//         imageTemp.image.height = image.image.height;
//         imageTemp.max_value = image.max_value;
//
//         allocateImage(&(imageTemp.image));
//
//         // Pass from one image to another
//         for(int i = 0; i < height; i++){
//             for(int j = 0; j < width; j++){
//                 if(lastBoard->cell[i][j] == 0){
//                     imageTemp.image.pixels[i][j].value = 0;
//                 } else if(lastBoard->cell[i][j] == 1){
//                     imageTemp.image.pixels[i][j].value = 1;
//                 }
//             }
//         }
//         //writePGMFile(buffer, &imageTemp); // Write to file
//
//         // Create new board
//         board_t * currentBoard = createNewBoard(lastBoard->width, lastBoard->height);
//
//         numberOfThreads = THREADS_NUMBER; // Number of threads
//
//         // Divide some of the work for the threads
//         lines = lastBoard->width / numberOfThreads;
//         rest = lastBoard->width % numberOfThreads;
//
//         // Initiate thread barrier
//         pthread_barrier_init(&barrier, NULL, numberOfThreads);
//         pthread_t threads[numberOfThreads]; // Threads
//
//         k = 0;
//
//         int * temp = malloc(sizeof(int));
//
//         pthread_create(&threads[i], NULL, updateBoardThread, temp);
//
//         pthread_join(threads[i], NULL);
//
//         pthread_barrier_destroy(&barrier);
//         deleteBoard(lastBoard);
//         deleteBoard(currentBoard);
//     }
// }

// Main loop for the simulation (OPENMP)
void lifeSimulationOpenmp(int iterations, char * start_file){

    pgm_t image; // First instance of a struct
    readPGMFile(start_file, &image); // Read from file
    // Declare variables
    int width = image.image.width;
    int height = image.image.height;
    int num_threads;
    double start_time;
    double end_time;

    // Create board with the size specified from file
    board_t * lastBoard = createNewBoard(width, height);

    // Copy from board obtained from file to shiny new board
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(image.image.pixels[i][j].value == 0){
                lastBoard->cell[i][j] = 0;
            } else if(image.image.pixels[i][j].value == 1){
                lastBoard->cell[i][j] = 1;
            }
        }
    }

    printf("Initial board: \n");

    // Prints the board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf(" %d ", lastBoard->cell[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Openmp
    #pragma omp parallel
	{
		#pragma omp master
		{
			num_threads = omp_get_num_threads();
		}
	}
    printf("Threads -> %d \n", num_threads);
    start_time = get_time(); // Timer

    // Main iteration loop
    for(int i = 1; i < iterations + 1; i++){

        char buffer[50];
        sprintf(buffer, "Images/image%04i.pgm", i);
        pgm_t imageTemp; // First instance of a struct
        // Assign values for header
        imageTemp.image.width = image.image.width;
        imageTemp.image.height = image.image.height;
        imageTemp.max_value = image.max_value;

        allocateImage(&(imageTemp.image));
        // Pass from one image to another
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(lastBoard->cell[i][j] == 0){
                    imageTemp.image.pixels[i][j].value = 0;
                } else if(lastBoard->cell[i][j] == 1){
                    imageTemp.image.pixels[i][j].value = 1;
                }
            }
        }
        writePGMFile(buffer, &imageTemp); // Write to file

        // Create new board
        board_t * currentBoard = createNewBoard(lastBoard->width, lastBoard->height);

        // Calls for the logic
        updateBoardOMP(lastBoard, currentBoard);

        // Destroy last
        deleteBoard(lastBoard);
        // Make current board the last
        lastBoard = currentBoard;
    }
    end_time = get_time();
    printf("Done writing the files!\n");
    fprintf(stderr, "\nTotal time %g s\n", end_time - start_time);
    printf("\n");
}

// // Get the memory necessary to store an image
// void preparePGMImage(const void * board, pgm_t * board_image){
//
// }
//
// // Save the contents of the board as a PGM image
// void saveAsPGM(const void * board, pgm_t * board_image, int iteration){
//
// }

board_t * createNewBoard(int width, int height){
    // New variables for the new board
    board_t * board = malloc(sizeof(board_t));
    board->width = width;
    board->height = height;
    board->cell = (int **) malloc(height * sizeof(int *));
    board->cell[0] = (int*)calloc(width * height, sizeof(int));

    for(int i = 0; i < board->height; i++){
        board->cell[i] = board->cell[0] + board->height * i;
    }
    // Fill with zeros
    for(int i = 0; i < (width * height); i++){
        board->cell[0][i] = 0;
    }

    // return board
    return board;
}
// Function that iterates through the transformations of the boards
// void * updateBoardThread(void * temp) {
//     // ASsign beginning and end
//     int tid = *((int *) temp);
//     int start = tid * lines;
//     int end = start + lines;
//
//     // Assigns the rest of the work to the last thead
//     if (tid == numberOfThreads - 1) {
//         end += rest;
//     }
//     simulate(start, end, tid, lastBoard, currentBoard);
//     return 0;
// }
// Assigns values based on logic from game
// void simulate(int start, int end, int tid, board_t * lastBoard, board_t * currentBoard) {
//     // Variable to watch neighbors
//     int adyacent;
//     // Loop through iterations
//     while (k < iterations) {
//         for (int i = start; i < end; i++) {
//             for (int j = 0; j < lastBoard->width; j++) {
//                 adyacent = calculateNeighbor(lastBoard, i, j); // counts the neighbors
//                 // Game logic
//                 if (adyacent == 2){
//                     currentBoard->cell[i][j] = lastBoard->cell[i][j];
//                 } else if(adyacent == 3){
//                     currentBoard->cell[i][j] = 1;
//                 } else if(adyacent < 2){
//                     currentBoard->cell[i][j] = 0;
//                 } else if(adyacent > 3){
//                     currentBoard->cell[i][j] = 0;
//                 }
//             }
//         }
//
//         // Barreira pra todas as threads terminarem de processar
//         pthread_barrier_wait(&barrier);
//
//         // Uma única thread executa o final do step
//         if(tid == 0) {
//             board_t * tmp = currentBoard;
//             currentBoard = lastBoard;
//             lastBoard = tmp;
//             k++;
//         }
//         // Barrier waits for the thread to finish
//         pthread_barrier_wait(&barrier);
//     }
//     pthread_exit(NULL); // Quit thread
// }
// Calculare how many neighbors active
int calculateNeighbor(board_t * board, int i, int j) {
    int k;
    int l;
    int count = 0;
    int sk = (i > 0) ? i - 1 : i;
    int ek = (i + 1 < board->width) ? i+1 : i;
    int sl = (j > 0) ? j - 1 : j;
    int el = (j + 1 < board->width) ? j+1 : j;
    for (k = sk; k <= ek; k++){
        for (l = sl; l <= el; l++){
            count += board->cell[k][l];
            count -= board->cell[i][j];
        }
    }
  return count;
}

// Function that iterates through the transformations of the boards
void updateBoardOMP(board_t * lastBoard, board_t * currentBoard) {
    // OpenMP
    #pragma omp parallel for schedule(static)
    // Loops through boards
    for (int i = 1; i <= lastBoard->width-2; i++){
        for (int j = 1; j <= lastBoard->height-2; ++j){
            // variables to use
            int neighbors = 1;
            int currentCell = lastBoard->cell[i][j];

            // Counts the neighbors from the cell
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (!(k == i && l == j) ) {
                        neighbors += lastBoard->cell[k][l];
                    }
                }
            }
            // Game logic
            if (currentCell) {
                if (!(neighbors == 2 || neighbors == 3)) {
                    currentCell = 0;
                }
            } else {
                if (neighbors == 3) {
                    currentCell = 1;
                }
            }
            currentBoard->cell[i][j] = currentCell; // Change the value
        }
    }
}
// Function to delete the board
void deleteBoard(board_t * board){
    // Free the memory from the board selected
    free(board->cell[0]);
    free(board->cell);
    free(board);
}
// Function to get time
// Obtained from https://github.com/serendependy/parallel-j/blob/master/OpenMP/timer.h
double get_time() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0)
        return (double) tv.tv_sec + ((double) tv.tv_usec / (double) 1000000);
    else
        return 0.0;
}
