#include <iostream>
#include <pthread.h>
#include <fstream>
#include <sstream>
#include "md5.h"

static const int num_threads = 5;
using namespace std;
string code;
bool found;

void *lookInFile(void *threadid){
  string files[num_threads] = {"diccionario1.txt", "diccionario2.txt", "diccionario3.txt", "diccionario4.txt", "diccionario5.txt"};
  long tid;
  tid = (long)threadid;
  ifstream in;
  string line;
  in.open(files[tid]);
  if(in.fail()){
     cout<<"Error opening the file"<<endl;
  }

  while(!in.eof())
  {
    getline(in, line);
    if(!line.empty()){
      if (md5(line) == code){
        cout<<"The word "<<line<< " was found with your hash"<<endl;
        found = true;
      }
    }
  }
  in.close();
  pthread_exit(NULL);
}

int main() {
  pthread_t t[num_threads];
  found = false;
  std::cout << "Enter the hash you wish to look for:";
  std::cin >> code;
  for(long i=0; i<num_threads; i++)
    pthread_create(&t[i], NULL, lookInFile, (void *)i);
  pthread_exit(NULL);
  if (!found)
    std::cout << "The hash was not found!" << '\n';
  return 0;
}
