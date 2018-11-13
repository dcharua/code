//Daniel Charua A01017419 - 28/08/18 - Image Read

#include "imageRead.h"

int main(int argc, char *argv[]){
  //Initializing variables
  char *output = NULL, *input = NULL, *filter = NULL, opt;
  float scale = 0.0;
  int negative = 0;
  input = "ninja-icon.ppm";
  output = "thus.ppm";
  filter = "this.tt";
  //Loop to check for getopt arguments
  while (( opt = getopt(argc, argv, "i:o:f:ns:")) != -1){
    switch(opt) {
      case 'i':
        input = optarg;
        break;
      case 'o':
        output = optarg;
        break;
      case 'f':
        filter = optarg;
        break;
      case 'n':
        negative = 1;
        break;
      case 's':
        scale = atoi(optarg);
        break;
    }
  }
  //if user did not select scale or negative end program
  if(!scale && !negative && !filter){
    kill("Please select negative image with the flag -n, scale image with the flag -s 'number', or filter -f 'filter name'\n No action to do, program out\n");
  }

  //if user provided input and output proceed with execution
  if(input && output){
    //Checking that input and output are in .ppm extension otherwise kill it
    checkImageName(input);
    checkImageName(output);

    //image struct declaration, allocating memmory and reading
    image *img = (image *) malloc(sizeof(image));
    readImage(input, img);

    //scaling image
    if(scale){
      image *scaled_image = (image *) malloc(sizeof(image));
      scaleImage(output, scale, img, scaled_image);
      delete(scaled_image);
    }

    //negative image
    if(negative){
      negativeImage(output, img);
    }

    if(filter){
      image * new_image = (image *) malloc(sizeof(image));
      applyFilter(img, new_image, "blur.txt");
      delete(new_image);
    }

    //Delete image from heap
    delete(img);

    //if user did not provide input and output kill
  }else{
    kill("Please provide input image name as -i and output image name as -o as arguments\n");
  }
  return 0;
}

//function to kill with error return 1
void kill (char reason[]){
  fprintf(stderr, "%s", reason);
  exit(1);
}

//function to check for .ppm extension
void checkImageName(char filename[]){
  if(strcmp(".ppm", &filename[strlen(filename)-4]))
    kill("Wrong image extension name, should be .ppm\n");
}

//function to read image in PPM P6 format from file to memory
void readImage(char filename[], image *img){
  FILE *file;
  file = fopen( filename , "r");
  if (file){
    //if image was opend, read the magic number, img width, img height and img max_num, in that order from ppm format
    fscanf(file, "%s %d %d %d\n", img->magic_number, &img->width, &img->height, &img->max_number);
    //Check image format
    if(strcmp(img->magic_number, "P6")){
      free(img);
      kill("Wrong image format should be P6\n");
    }
    img->size = img->width * img->height * 3;
    //allocate the memory for the RGB pixels
    img->pix=malloc (img->size * sizeof(unsigned char));
    //memory allocation error handler
    if (img->pix == NULL){
      free(img);
      kill("Out of memory\n");
    }
  // read pixels
  fread (img->pix, sizeof(unsigned char), img->size , file);
  fclose(file);
  //if image could not be open finish program
  }else{
    kill("Error opening image, program out \n");
  }
}

//function to make new image for scaling
void newImage(image *img, image *newi, float scale){
  strcpy (newi->magic_number, img->magic_number);
  newi->width = (int)img->width * scale;
  //check if new image is a scale of 4, if not kill program
  if (newi->width%4){
    delete(img);
    free(newi);
    kill ("unsupported scale \n");
  }
  newi->height = (int)img->height * scale;
  newi->max_number = img->max_number;
  newi->size = newi->width * newi->height * 3;
  newi->pix=malloc (newi->size * sizeof(unsigned char));
  if (newi->pix == NULL)
    kill("Out of memory\n");
}

//function to scale up or down an image using bilinear scaling
// Code adapted form https://stackoverflow.com/questions/21250099/c-bilinear-scaling-interpolation-byte-by-byte
void scaleImage(char filename[], float scale, image *img, image *scaled_image){
  int index1, index2, p1, p2;
  float x, y, p;
  scale /= 100.0;
  newImage(img, scaled_image, scale);
  p1 = img->width*3;
  p2 = scaled_image->width *3;
  //loop to get rows
  for(int i=0;i<scaled_image->height;i++){
    index2=i*p2;
    //Loop to get columns
    for(int j=0;j<scaled_image->width;j++){
      x=((float)(j))/scale;
      index1=(int)(x) * 3;
      x-=(int)(x);
      y=((float)(i))/scale;
      index1+=(int)(y) * p1;
      y-=(int)(y);
      //loop to get RBG pixels in the "matrix"
      for(int k=0;k<3;k++){
        p = (float)(img->pix[index1]) * (1.0-x)*(1.0-y);
        p += (float)(img->pix[index1+3]) * (x)*(1.0-y);
        p += (float)(img->pix[index1+p1]) * (1.0-x)*(y);
        p += (float)(img->pix[index1+p1+3]) * (x)*(y);
        scaled_image->pix[index2] = (unsigned char)(p);
        index1++;
        index2++;
      }
    }
  }
  writeImage(filename, scaled_image);
}

//function to convert image to its negative format
void negativeImage(char filename[], image *img){
  //loop the whole image and substract 255 to every pixel
  for (int i = 0; i < img->size ; i++){
    img->pix[i] = img->max_number - img->pix[i];
  }
  filename[strlen(filename)-4] = '\0';
  strcat(filename, "-negative.ppm");
  writeImage(filename, img);
}

void applyFilter(image *img, image * new_image, char filtername []){
  int index1, index2, a, b;
  filter filter;

  readFilter(&filter, "blur.txt");

  strcpy (new_image->magic_number, img->magic_number);
  new_image->width = img->width;
  new_image->height = img->height;
  new_image->max_number = img->max_number;
  new_image->size = new_image->width * new_image->height * 3;
  new_image->pix=malloc (new_image->size * sizeof(unsigned char));
  if (new_image->pix == NULL)
    kill("Out of memory\n");

  // for(int z = 0; z<new_image->width*new_image->height*3;++z)
  //   *(new_image->pix + z) = 0;

  clock_t begin = clock();

  for(int x=0;x<img->height;++x){
    for(int y=0;y<img->width;++y){
      for(int i=0;i<filter.height;++i){
        for(int j=0;j<filter.width;++j){
          a=x+i-filter.height/2;
          b=y+j-filter.width/2;
          if(a<0)
            index1=img->height+a;
          else if(a>img->height-1)
            index1=a-img->height;
          else
            index1=a;
          if(b<0)
            index2=img->width+b;
          else if(b>img->width-1)
            index2=b-img->width;
          else
            index2=b;
              for(int k=0;k<3;k++){
                new_image->pix[y+ k+(x*new_image->width)]+=img->pix[index2 +k+ (index1*new_image->width)]*filter.kernel[j + (i*filter.width)];
              }
        }
      }
    }
  }
  clock_t end = clock();
  printf("Sequential runtime = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
  writeImage("output.ppm", new_image);
}

void readFilter(filter * filter, char  filename []){
  FILE * file_ptr = NULL;
  file_ptr = fopen (filename, "r");
  if (!file_ptr){
    printf("Unable to open the file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
  // Get the data from the header
  fscanf (file_ptr, "%d", &filter->width);
  fscanf (file_ptr, "%d", &filter->height);
  filter->kernel =  malloc (filter->width * filter->height * sizeof(int));
  for (int i=0; i<filter->height; i++){
    for (int j=0; j<filter->width; j++){
      fscanf (file_ptr, "%d", &filter->kernel[i + (j * filter->width)]);
    }
  }
}


//function to write image to file in ppm P6 format
void writeImage(char filename[], image *img){
  FILE *file;
  file = fopen( filename , "w");
  if (file){
    //if image was open write data in P6 format
    fprintf(file, "%s\n%d %d\n%d\n", img->magic_number, img->width, img->height, img->max_number);
    fwrite (img->pix, sizeof(unsigned char), img->size, file);
    printf("Image %s saved to disk\n", filename);
  }else{
    //otherwise kill the program
    delete(img);
    kill("Error creating image, program out \n");
  }
}

//function to delete image form memory
void delete(image *img){
  free(img->pix);
  free(img);
}
