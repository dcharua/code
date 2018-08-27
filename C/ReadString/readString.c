#include "readString.h"

void readString(char * string, int size){
  fgets(string, size, stdin);
  string[strlen(string)-1] = '\0';
}
