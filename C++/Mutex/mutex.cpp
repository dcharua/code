#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "md5.h"
#define MAX 10 /* cuántos números debe producir */

using namespace std;

pthread_mutex_t el_mutex;
pthread_cond_t condc,condp;
string bufer[MAX] = {"0","0","0","0","0","0","0","0","0","0"}; /* búfer utilizado entre productor y consumidor */
string code;

bool bufferEmpty(string b[]){
  for (int i = 0; i<MAX; i++){
    if (b[i]== "0")
      return false;
    }
  return true;
}

bool bufferFull(string b[]){
  for (int i = 0; i<MAX; i++){
    if (b[i]!= "0")
      return false;
    }
  return true;
}
string generatePssw(){
  string pwd;
  char alphanum[] ="0123456789""!@#$%^&*""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz";
  int stringLength = sizeof(alphanum) - 1;
  for (int i=0; i<8; i++)
    pwd.push_back(alphanum[rand() % stringLength]);
  return pwd;
}
/* produce datos */
void *productor(void *ptr){
  int i;
  for (i=1; i<=MAX; i++) {
    int index = i%MAX;
    pthread_mutex_lock(&el_mutex); /* obtiene acceso exclusivo al búfer */
    while (bufferEmpty(bufer)) pthread_cond_wait(&condp, &el_mutex);
    bufer[index] = generatePssw(); /* coloca elemento en el búfer */
    pthread_cond_signal(&condc); /* despierta al consumidor */
    pthread_mutex_unlock(&el_mutex); /* libera el acceso al búfer */
  }
  pthread_exit(0);
}

/* consume datos */
void *consumidor(void *ptr) {
  int i;
  bool found = false;
  for (i=1; i<=MAX; i++) {
    int index = i%MAX;
    pthread_mutex_lock(&el_mutex); /* obtiene acceso exclusivo al búfer */
    while (bufferFull(bufer)) pthread_cond_wait(&condc, &el_mutex);
    if (md5(bufer[index]) == code){
      cout<<"The word "<< bufer[index]<< " was found with your hash"<<endl;
      found = true;
    }
    bufer[index] = "0"; /* saca elemento del búfer */
    if(!found)
      cout<<"The hash was not found in consumer number "<<i<<endl;
    pthread_cond_signal(&condp); /* despierta al productor */
    pthread_mutex_unlock(&el_mutex); /* libera el acceso al búfer */
  }
pthread_exit(0);
}


int main(int argc, char **argv){
  std::cout << "Enter the hash you wish to look for:";
  std::cin >> code;
  pthread_t pro, con;
  pthread_mutex_init(&el_mutex, 0);
  pthread_cond_init(&condc, 0);
  pthread_cond_init(&condp, 0);
  pthread_create(&con, 0, consumidor, 0);
  pthread_create(&pro, 0, productor, 0);
  pthread_join(pro, 0);
  pthread_join(con, 0);
  pthread_cond_destroy(&condc);
  pthread_cond_destroy(&condp);
  pthread_mutex_destroy(&el_mutex);
}
