// Daniel Charua A01017419 - Any base to any base convertor - 09/08/18
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//Functions Declaration
void baseConvertion(char number[], int basei, int basef);
int charToInt(char num);
char intToChar(int num);
int power (int base, int power);
void printResult(char number[]);

int main (int argc, char *argv[]){
  //Initializing variables
  int input_base, output_base,  opt, args_counter = 5;
  //Loop to check for getopt arguments
  while (( opt = getopt(argc, argv, "i:o:")) != -1){
    switch(opt) {
      case 'i':
        input_base = atoi(optarg);
        break;
      case 'o':
        output_base = atoi(optarg);
        break;
      default:
        printf("Invalid option, program terminated\n");
        return 0;
    }
  }
  // Loop to convert the base of all the numbers provided in the console
  while(args_counter <= argc - 1)
    baseConvertion(argv[args_counter++], input_base, output_base);
  return 0;
}

// Function to convert the number from given base to new base
void baseConvertion(char number[], int basei, int basef){
  //Initialazig variables
  int len = strlen(number), pwd = 0, new_num = 0, index = 0;
  char res[50] = { '\0' };
  printf("Converting %s form base %d to base %d \n", number, basei, basef);
  // Loop to convert to base 10
  for (int i = len - 1; i >= 0; i--)
    new_num += charToInt(number[i]) * power(basei, pwd++);
  // Loop to convert from base 10 to new base
  while (new_num != 0){
    res[index++] = intToChar(new_num % basef);
	  new_num = new_num / basef;
  }
  printf("Converted to base %d: ", basef);
  printResult(res);
}

// Function to convert char to int for mathematic operations
int charToInt(char num){
  if (num >= '0' && num <= '9')
    return num - '0';
  else
    return num - 'A' + 10;
}

// Function to revert to char for printing
char intToChar(int num){
  if (num < 10)
    return num + '0';
  else
    return num -10 + 'A';
}

// Function to elevate number to the power
int power (int base, int power){
  int res = 1;
  for (int i=0; i<power; i++)
    res *= base;
  return res;
}

// Function to print number in reverse order
void printResult(char number[]){
  int len = strlen(number) - 1;
  for (int i = len; i >= 0; --i)
    printf("%c", number[i]);
  printf("\n\n");
}
