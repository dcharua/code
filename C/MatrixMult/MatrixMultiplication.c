//Daniel Charua A01017419 - 16/08/18 - Matrix Multiplication
#include <stdio.h>
#include <stdlib.h>

//matrix struct with rows, columns and data
typedef struct matrix{
  int r;
  int c;
  float *data;
}matrix;

//Funcion Declaration
float get(matrix *matrix, int i, int j);
void set(matrix *matrix, int i, int j, float num);
void delete(matrix *matrix);
void readData(char filename[], matrix *matrix);
void multiply(matrix *matrixA, matrix *matrixB, matrix *result);
void print(matrix *result, char name[]);
void write(char filename[], matrix *matrix);

int main(int argc, char *argv[]){
  //matrices declarations and allocating memmory
  matrix *matrixA = (matrix *) malloc(sizeof(matrix));
  matrix *matrixB = (matrix *) malloc(sizeof(matrix));
  matrix *result = (matrix *) malloc(sizeof(matrix));
  char opt;
  //Reading matrix content from files declared in the console at execution
  if (argc == 3){
    readData(argv[1], matrixA);
    readData(argv[2], matrixB);
  }else{
    //Reading matrix content from defualt files
    printf("Default files Matrix_A.txt and Matrix_B.txt used \nfor different files please provide them as 2 arguments in the console\n\n");
    readData("Matrix_A.txt", matrixA);
    readData("Matrix_B.txt", matrixB);
  }
  //Print the matrices after reading
  print(matrixA, "MatrixA");
  print(matrixB, "MatrixB");
  //Ask user for multiplication
  do{
    printf("1.- MatrixA * MatrixB\n2.- MatrixB * MatrixA\nPlease select a number:");
    scanf("%c", &opt);
    if (opt == '1')
      multiply(matrixA, matrixB, result);
    else if (opt == '2')
      multiply(matrixB, matrixA, result);
    else
      printf("Invalid option, try again\n\n");
  } while(opt != '1' && opt != '2');
  //print the Result
  print(result, "Result");
  //Write to file
  write("Result.txt", result);
  //Delete matrices from memory
  delete(matrixA);
  delete(matrixB);
  delete(result);
  return 0;
}

//Function to get matrix data
float get(matrix *matrix, int i, int j){
  return matrix->data[i + (j * matrix->r)];
}

//Function to set matrix data
void set(matrix *matrix, int i, int j, float num){
   matrix->data[i + (j * matrix->r)] = num;
}

//Function to delete memory from heap
void delete(matrix *matrix){
  free(matrix->data);
  free(matrix);
}

//Function to read data form file
void readData(char filename[], matrix *matrix){ //open file to read it
  FILE *file;
  float num;
  file = fopen( filename , "r");
  if (file){
    //if file was opend, read the first 2 numbers for col and row size
    fscanf(file, "%d", &matrix->r);
    fscanf(file, "%d", &matrix->c);
    matrix->data=(float *) malloc(matrix->r * matrix->c * sizeof(float));
    //memory allocation error handler
    if (matrix->data == NULL) {
      fprintf(stderr, "Out-of-memory");
      exit(0);
    }
    //double loop to set the data as a matrix correctly in the struct
    for (int i = 0; i < matrix->r; i++){
      for (int j = 0; j < matrix->c; j++){
        fscanf(file, "%f", &num);
        set(matrix, i, j, num);
      }
    }
  fclose(file);
  //if file could not be open finish program
  }else{
    printf("Error opening file, program out \n");
    exit(0);
  }
}

//Function to print matrix content
void print(matrix *matrix, char name[]){
  printf("%s\n", name);
  for (int i = 0; i < matrix->r; i++){
    for (int j = 0; j < matrix->c; j++){
      printf("%.2f ", get(matrix, i, j));
    }
    printf("\n");
  }
  printf("\n");
}


//Function to multipy matrices
void multiply(matrix *matrixA, matrix *matrixB, matrix *result){
  // check if the dimensions are correct for operation
  if (matrixA->c == matrixB->r){
   //if they are set the size and allocate the memory for the resulting matrix
  result->r =  matrixA->r;
  result->c =  matrixB->c;
  result->data=(float *) malloc(result->r * result->c * sizeof(float));
  //memory allocation error handler
  if (result->data == NULL) {
    fprintf(stderr, "Out-of-memory");
    exit(0);
  }
  //triple loop to oparate matrices -- based on code form  https://www.programiz.com/c-programming/examples/matrix-multiplication
  for (int i = 0; i < matrixA->r; i++){
    for (int j = 0; j < matrixB->c; j++){
      float res= 0.0;
      for (int k = 0; k < matrixA->c; k++){
          res += get(matrixA ,i ,k) * get(matrixB, k, j);
        }
       set(result, i, j, res);
      }
    }
  //if matrices dimensions are not compatible end program
  }else{
    printf("The matrices can NOT be multiply, program out!\n");
    exit(0);
  }
}

//Function to write result in file
void write(char filename[], matrix *result){
  FILE *file;
  file = fopen( filename , "w");
  //if file could be created
  if (file){
    for (int i = 0; i < result->r; i++){
      for (int j = 0; j < result->c; j++){
        fprintf(file, "%.2f ", get(result, i, j));
      }
      fprintf(file,"%s","\n");
    }
    fclose(file);
    printf("Result written in file Result.txt, program out\n");
  //if file could not be created
  }else{
    printf("Error writing file \n");
  }
}
