//Daniel Charua A01017419


#include <iostream>
#include <stdlib.h>

using namespace std;


class Stack{
private:
	int index;
	int size;
	int *array;

public:
	//contructor
	Stack(int s);
	//destructor
	~Stack();
  void push(int item);
	int top();
	int pop();
  void print();
};
