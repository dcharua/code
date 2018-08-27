//Daniel Charua A01017419


#include <iostream>
#include "template.h"

#define SIZE 20

int main(){
/*
	int search;
	int location;
*/
	Array<float> test_array(SIZE);
  test_array.setElement(1, 43.54);
  test_array[2]=15;
  std::cout << test_array[2] << std::endl;
	/*
	test_array.fillOrdered();
	std::cout << "Ordered array data:" << std::endl;
	test_array.printRecursive(0);


	std::cout << "Enter number to search" << std::endl;
	std::cin >> search;

	std::cout << "Binary Iterative: " << std::endl;
	location = test_array.binarySearchIterative(search);
	std::cout << "The element was " << (location > -1 ? "found" : "NOT found") << std::endl;

	std::cout << "Binary Recursive: " << std::endl;
	location = test_array.binarySearchRecursive(search);
	std::cout << "The element was " << (location > -1 ? "found" : "NOT found") << std::endl;


	test_array.fillRandom();
	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	std::cout <<endl;


	test_array.bubbleSort();
	std::cout << "Sorted with bubbleSort" << std::endl;
	test_array.printRecursive(0);
	if (test_array.checkIfSort()) std::cout << "checkIfSort PASSED" <<endl;
	if(!test_array.checkIfSort()) std::cout << "checkIfSort FAIELD" <<endl;
	std::cout<<"----------------------------------------------------"<<endl <<endl;
  */
//end bubbleSort


	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	std::cout <<endl;

	test_array.insertionSort();
	std::cout << "Sorted with insertionSort: " << std::endl;
	test_array.printRecursive(0);
	if (test_array.checkIfSort()) std::cout << "checkIfSort PASSED" <<endl;
	if(!test_array.checkIfSort()) std::cout << "checkIfSort FAIELD" <<endl;
	std::cout<<"----------------------------------------------------"<<endl <<endl;
//ends insertionSort

	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	std::cout <<endl;

	test_array.selectionSort();
	std::cout << "Sorted with selectionSort: " << std::endl;
	test_array.printRecursive(0);
	if (test_array.checkIfSort()) std::cout << "checkIfSort PASSED" <<endl;
	if(!test_array.checkIfSort()) std::cout << "checkIfSort FAIELD" <<endl;
	std::cout<<"----------------------------------------------------"<<endl <<endl;;
//ends selectionSort

	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	std::cout <<endl;

	test_array.quickSort(0, SIZE-1);
	std::cout << "Sorted with quickSort: " << std::endl;
	test_array.printRecursive(0);
	if (test_array.checkIfSort()) std::cout << "checkIfSort PASSED" <<endl;
	if(!test_array.checkIfSort()) std::cout << "checkIfSort FAIELD" <<endl;
	std::cout<<"----------------------------------------------------"<<endl <<endl;
//ends quickSort

	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	std::cout <<endl;

	test_array.mergeSort(0, SIZE-1);
	std::cout << "Sorted with mergeSort: " << std::endl;
	test_array.printRecursive(0);
	if (test_array.checkIfSort()) std::cout << "checkIfSort PASSED" <<endl;
	if(!test_array.checkIfSort()) std::cout << "checkIfSort FAIELD" <<endl;
	std::cout<<"----------------------------------------------------"<<endl <<endl;
//ends mergeSort

	return 0;
}
