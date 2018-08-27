//Daniel Charua A01017419


#include <iostream>
#include <stdlib.h>

using namespace std;


class Queue{
private:
	int index;
  int counter;
	int size;
	int *array;

public:
	//contructor
  Queue(int s);
	//destructor
	~Queue();
  void push(int item);
	int top();
	int pop();
  void print();
};
