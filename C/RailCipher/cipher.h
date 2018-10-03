//Daniel Charua A01017419 - 28/08/18 - Rail Cipher

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void kill (char const *reason);
void forkProcess(char *input_file, int key, char *output_file, char opt);
void readPipe(int fd[]);
void writePipe(int fd[], char *output_file);
void readFile(char *input_file, int key, char *output_file, char opt);
void encode(char *text, char *output, int key);
void decode(char *cipher, char *output, int key);
void writeFile(char *output, char *text);
