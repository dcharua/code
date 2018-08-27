//Daniel Charua A01017419


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;



class Array {
private:
	int size;
	int *array;
	int binarySearchRecursive(int item, int start, int end);
public:
	//contructor
	Array(int s);
	//destructor
	~Array();

	void fillOrdered();
	void fillRandom();

	int linearSearch(int iteam);
	int binarySearchIterative(int item);
	int binarySearchRecursive(int item);

	void printRecursive(int index);

	void swap(int *a, int *b);
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void mergeSort(int low, int high);
	void mergeRecursive(int low, int high, int mid);
	void quickSort(int left, int right);
	bool checkIfSort();


};
