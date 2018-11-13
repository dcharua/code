//Daniel Charua - A0101741 - 7/11/18

/*
   Sample program to test libraries.
   Uses images in PPM format:
    http://netpbm.sourceforge.net/doc/ppm.html

    Gilberto Echeverria
    gilecheverria@yahoo.com
    31/01/2018
*/

#include <unistd.h>
#include <getopt.h>
#include "string_functions.h"
#include "ppms.h"


void usage(char * program);
void parseOptions(int argc, char * argv[]);
void imageOperations(char * in_filename, char * out_filename, int doNegative, int rotationAngle, int newScale, char * filter_name);


int main(int argc, char * argv [])
{
    printf("\n=== PROGRAM TO TEST PPM READING AND WRITING ===\n");

    parseOptions(argc, argv);

    return 0;
}

void usage(char * program)
{
    printf("Usage:\n");
    printf("\t%s -i {input_file} -o {output_file} [-n] [-r {degrees}] [-s {percentage} -f {filter file}]\n", program);
    printf("Available operations:\n");
    printf("\t-n : Compute the negative of an image\n");
    printf("\t-r : Rotate the image the specified degrees (90, 180, 270)\n");
    printf("\t-s : Scale the image up or down a percentage (50, 200)\n");
    printf("\t-f : Apply a filter to an image\n");
    exit(EXIT_FAILURE);
}

void parseOptions(int argc, char * argv[])
{
    int opt;
    char * in_filename;
    char * out_filename;
    char * filter_name=NULL;
    int input_ok = 1;
    int output_ok = 1;
    int doNegative = 0;
    int rotationAngle = 0;
    int newScale = 0;
    // in_filename = "large.ppm";
    // out_filename = "large-ou.ppm";
    // filter_name = "blur.txt";
    while ( (opt = getopt(argc, argv, "i:o:f:nr:s:")) != -1 )
    {
        switch (opt)
        {
            case 'i':
                in_filename = optarg;
                input_ok = 1;
                break;
            case 'o':
                out_filename = optarg;
                output_ok = 1;
                break;
            case 'n':
                doNegative = 1;
                break;
            case 's':
                newScale = atoi(optarg);
                break;
            case 'r':
                rotationAngle = atoi(optarg);
                break;
            case 'f':
                filter_name = optarg;
                break;
            default:
                printf("Invalid option '%c'\n", opt);
                usage(argv[0]);
                break;
        }

    }

    if (input_ok && output_ok)
    {
        // Call the function to do image operations
        imageOperations(in_filename, out_filename, doNegative, rotationAngle, newScale, filter_name);
    }
    else
    {
        usage(argv[0]);
    }
}

void imageOperations(char * in_filename, char * out_filename, int doNegative, int rotationAngle, int newScale, char *filter_name)
{
    // Create the image variables and initialize to be empty
    ppm_t input_image = {"", 0, 0, 0, NULL};

    // Load the image into the program
    readImageFile(in_filename, &input_image);
    printf("Read file '%s' successfully\n", in_filename);
    //If filter name is true
    if (filter_name){
      //Create new image
      ppm_t destination = {"", 0, 0, 0, NULL};
      //copy data from original image
      strcpy (destination.magic_number, input_image.magic_number);
      destination.width= input_image.width;
      destination.height =input_image.height;
      destination.max_value = input_image.max_value;
      //Allocate memory and apply filter and free memory for sequential calculation
      allocateMemory(&destination);
      applyFilter(&input_image, &destination, filter_name, out_filename);
      freeMemory( &destination);
      printf("Wrote file '%s' successfully\n\n", out_filename);

      // add data again for parallel implementation
      strcpy (destination.magic_number, input_image.magic_number);
      destination.width= input_image.width;
      destination.height =input_image.height;
      destination.max_value = input_image.max_value;
      allocateMemory(&destination);
      applyFilterParallel(&input_image, &destination, filter_name, out_filename);
      freeMemory( &destination);
      printf("Wrote file '%s' successfully\n", out_filename);
    }


#ifdef DEBUG
    // The file just read
    printf("THESE ARE THE PIXELS\n");
    printPixels(&input_image);
#endif /* DEBUG */

    if (doNegative)
    {
        // Transform the image into a negative
        getNegativeImage(&input_image);
    }

    if (rotationAngle)
    {
        // Rotate the image
        rotateImage(&input_image, rotationAngle);
    }

    if (newScale)
    {
        // Scale down the image
        scaleImage(&input_image, newScale);
    }

    // Save the new image
    //writeImageFile(out_filename, &input_image);
    if (!filter_name)
      printf("Wrote file '%s' successfully\n", out_filename);

    // Liberate the memory used for the structure
    freeMemory( &input_image);
}
