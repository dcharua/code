//Daniel Charua A01017419

#include "Stack.h"

Stack::Stack(int s) {
	size = s;
	array = new int[size];
	index=0;
}
Stack::~Stack() {
	delete [] array;
}
void Stack::push(int item){
	if (index<size){ //checks is stack is full
  array[index]=item;
	index++;
	std::cout << "The item "<< item << " was pushed " << std::endl;}
	else std::cout << "The stack is full, pop an item" << std::endl;
}
void Stack::print(){
  for( int i=0; i<size; i++){
    std::cout << array[i] << std::endl;
  }
}
int Stack::top(){
		return array[index-1];
}
int Stack::pop(){
int item;
item=array[index-1];
array[index-1]=0;
index--;
return item;
}
