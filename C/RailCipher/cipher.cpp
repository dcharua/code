//Daniel Charua A01017419 - 9/09/18 - Rail Cipher

#include "cipher.h"
#define MAXFILENAME 50

int main(int argc, char *argv[]){
  //Variable declaration
  int key;
  char input_file[MAXFILENAME], output_file[MAXFILENAME], opt;
  //Displaying the menu and handling user input error
  do{
    printf("\n----------Rails Fance Cipher ----------\n");
    printf("-- 1.- Encode--------------------------\n");
    printf("-- 2.- Decode--------------------------\n");
    printf("-- Please select a number:");
    scanf("%c",&opt);
    while ((getchar()) != '\n');
  }while (opt != '1' && opt != '2');
  //Getting user input and cleaning buffer to prevent errors
  printf("\nEnter the name of the file to read from: ");
  scanf("%s", input_file );
  while ((getchar()) != '\n');
  printf("\nEnter the key: ");
  scanf("%d", &key);
  while ((getchar()) != '\n');
  // calculating and storing output filename
  strcpy(output_file, input_file);
  output_file[strlen(output_file)-4] = '\0';
  if(opt == '1'){
    strcat(output_file, "-encoded.txt");
  } else {
    strcat(output_file, "-decoded.txt");
  }
  //forking process
  forkProcess(input_file, key, output_file, opt);
  return 0;
}

//function to kill with error return 1
void kill (char const *reason){
  fprintf(stderr, "%s", reason);
  exit(EXIT_FAILURE);
}

//function to fork porcess
void forkProcess(char *input_file, int key, char *output_file, char opt){
  //file descriptor and pid variables
  int fd[2];
  pid_t pid;
  //file descriptor error handler
  if (pipe(fd) == -1){
    kill("Pipe failed\n");
  }
  //forking
  pid = fork();
  // The parent process reads fd
  if (pid > 0){
    //close writing file and read from the other end
    close(fd[1]);
    readPipe(fd);
  }
  // The child process encodes or decodes and writes result in fd
  else if (pid == 0){
    //close reading file
    close(fd[0]);
    //read file to encode or decode
    readFile(input_file, key, output_file, opt);
    //write in file descriptor the name of the encoded or decodede file
    writePipe(fd, output_file);
  }
  //fork error handeler
  else{
    printf("fork failed\n");
  }
}

//Function to read form file descirptor
void readPipe(int fd[]){
  FILE * file_ptr = NULL;
  char buffer[MAXFILENAME];
  // Open the actual file pointer
  file_ptr = fdopen(fd[0], "r");
  // Get the data from the stream
  while ( fgets(buffer,MAXFILENAME, file_ptr) ){
    printf("The child proccess wrote file: %s\nEnjoy it program out!\n", buffer);
  }
  // Close the file pointer
  fclose(file_ptr);
  // Close the file descriptor
  close(fd[0]);
}

//Function to write to file descriptor
void writePipe(int fd[], char *output_file){
  FILE * file_ptr = NULL;
  // Open the actual file pointer
  file_ptr = fdopen(fd[1], "w");
  // Get the data from the stream
  fputs(output_file, file_ptr);
  // Close the file pointer
  fclose(file_ptr);
  // Close the file descriptor
  close(fd[1]);
}

//Function to read file
void readFile(char *input_file, int key, char *output_file, char opt){
  FILE * file;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  //open file
  file = fopen(input_file , "r");
  //if file was opened
  if (file) {
    while ((getline(&line, &len, file)) != -1){
      // for every line in the file encode or decode
      if (opt == '1'){
        encode(line, output_file, key);
      } else {
        decode(line, output_file, key);
      }
    }
    //file opening error handeler
  }else{
    kill("Could not open input file\n");
  }
  // delete line variable from memory
  free(line);
}

//Function to encode text
void encode(char *text, char *output, int key){
  int text_size = strlen(text) - 1;
  char encoded_rail[key][text_size];
  //fill rail matrix with an unused character |
  for(int i = 0; i < key; ++i){
    for(int  j= 0; j < text_size; ++j){
      encoded_rail[i][j] = '|';
    }
  }
  int i = 0, k = 0, c = 0;
  bool direction_control = true;
  // loop to fill matrix with caracters in the correct matrix position
  while (i<text_size){
    encoded_rail[k][i] = text[i++];
    // handling row counter based on direction switch
    if(direction_control){
      k++;
    }else{
      k--;
    }
    // switch to go up and down the rows
    if (k == key -1 || k == 0){
      direction_control = !direction_control;
    }
  }
  //reading the matrix avoiding empty caracters marked with |
  for(i = 0; i < key; ++i){
    for(int j = 0; j < text_size; j++){
      if(encoded_rail[i][j] != '|'){
        text[c++] = encoded_rail[i][j];
      }
    }
  }
  text[c] = '\n';
  // wrting result to a file
  writeFile(output, text);
}

//function to decode
void decode(char *text, char *output, int key){
  int text_size = strlen(text)-1;
  char decoded_rail[key][text_size];
  //Filling matrix
  for (int i=0; i < key; i++){
    for (int j=0; j < text_size; j++){
      decoded_rail[i][j] = '\n';
    }
  }
  int i = 0, k = 0, c = 0;
  bool direction_control = true;
  //loop to fill matrix with a mark where caracters will be
  while (i<text_size){
    decoded_rail[k][i++] = '|';
    // handling row counter based on direction switch
    if(direction_control){
      k++;
    }else{
      k--;
    }
    //switch to go up and down the rows
    if (k == key -1 || k == 0){
      direction_control = !direction_control;
    }
  }
  //double loop to fill the matrix where a | mark was inserted before
  for(i = 0; i < key; ++i){
    for(int j = 0; j < text_size; j++ ){
      if(decoded_rail[i][j] == '|' && c < text_size){
        decoded_rail[i][j] = text[c++];
      }
    }
  }
  i = 0, k = 0, c = 0;
  direction_control = true;
  //loop to read the resulting matrix
  while (i<text_size){
    text[c++] = decoded_rail[k][i++];
    // handling row counter based on direction switch
    if(direction_control){
      k++;
    }else{
      k--;
    }
    if (k == key -1 || k == 0){
      direction_control = !direction_control;
    }
  }
  text[i] = '\n';
  //writing result to a file
  writeFile(output, text);
}

//function to append line result to the file
void writeFile(char *output, char *text){
  FILE * file;
  //open file with append command
  file = fopen(output , "a");
  //if file was opend append line
  if (file) {
    fwrite(text, sizeof(unsigned char), strlen(text), file);
    fclose(file);
    //error opening file handler
  }else{
    kill("Could not open output file\n");
  }
}
