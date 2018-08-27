//Daniel Charua A01017419

#include "Queue.h"

Queue::Queue(int s) {
	size = s;
	array = new int[size];
	index=0;
  counter=0;
}
Queue::~Queue() {
	delete [] array;
}
void Queue::push(int item){
if (index < size && array[index]==0){//checks if the queue is not full
  array[index]=item;
	index++;
	std::cout << "The item " <<item <<" is now on queue" << std::endl;
}
	else std::cout << "Queue is full pop an item" << std::endl;
}
void Queue::print(){
  for( int i=0; i<size; i++){
    std::cout << array[i] << std::endl;
  }
}
int Queue::top(){
		return array[counter];
}
int Queue::pop(){
int item;
item=array[counter];
array[counter]=0;
counter++;
if ( index==size){
index=0;
}
if (counter==size){
	counter=0;
}
return item;
}
