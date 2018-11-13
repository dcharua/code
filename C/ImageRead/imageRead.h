//Daniel Charua A01017419 - 28/08/18 - Image Read

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct image{
  int width, height, max_number, size;
  char magic_number[2];
  unsigned char *pix;
} image;

typedef struct filter {
  int width;
  int height;
  int* kernel;
} filter;

void kill (char reason[]);
void checkImageName(char filename[]);
void readImage(char filename[], image *img);
void newImage(image *original, image *newi, float scale);
void scaleImage(char filename[], float scale, image *img, image *scaled_image);
void negativeImage(char filename[], image *img);
void applyFilter(image *img, image *new_image, char filtername []);
void readFilter(filter * filter, char  filename []);
void writeImage(char filename[], image *img);
void delete(image *img);
