//Daniel Charua A01017419


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


template <class T>
class Array {
private:
	int size;
	T *array;
	int binarySearchRecursive(T item, int start, int end);
public:
	//contructor
	Array(int s);
	//destructor
	~Array();

  void setElement(int index, T item);
  T getElement(int index);

	int linearSearch(T iteam);
	int binarySearchIterative(T item);
	int binarySearchRecursive(T item);
	void printRecursive(int index);
	void swap(T *a, T *b);
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void mergeSort(int low, int high);
	void mergeRecursive(int low, int high, int mid);
	void quickSort(int left, int right);
	bool checkIfSort();
  T & operator[] (const int index); //write array[i]=3;
  const T & operator[] (const int index) const; //read  cout<<array[i];
};

template <class T>
Array<T>::Array(int s) {
	size = s;
	array = new T[size];
	srand(time(NULL));
}

template <class T>
Array<T>::~Array() {
	delete [] array;
}

template <class T>
void Array<T>::setElement(int index, T item){
  if(index>=0 && index < size)
  array[index]=item;
}

template <class T>
T Array<T>::getElement(int index){
  if(index>=0 && index < size){
  return array[index];
  }
  else {
    std::cout << "Invalid Index" << std::endl;
    return array[0];
  }
}

template <class T>
void Array<T>::printRecursive(int index) {
	cout << array[index] << " ";
	if (index == size - 1) {
		cout << endl;
		return;
	}
	printRecursive(index + 1);
}

template <class T>
int Array<T>::linearSearch(T iteam) {
	for (int i = 0; i < size; i++) {
		if (array[i] == iteam) return i;
	}
	return -1;
}

template <class T>
int Array<T>::binarySearchIterative(T item) {
	int start = 0;
	int end = size - 1;
	int middle;

	while (start <= end)
	{
		middle = (start + end) / 2;
		if (item < array[middle])
			end = middle - 1;
		else if (item > array[middle])
			start = middle + 1;
		else return middle; //returns the index where it was found
	}
	return -1; //if number not found
}

template <class T>
int Array<T>::binarySearchRecursive(T item) {
	return binarySearchRecursive(item, 0, size - 1);
}

template <class T>
int Array<T>::binarySearchRecursive(T item, int start, int end) {
	if (start > end) return -1; //base case
	int middle = (start + end) / 2;
	if (item < array[middle])
		return binarySearchRecursive(item, start, middle - 1);
	else if (item > array[middle])
		return binarySearchRecursive(item, middle +1, end);
	else return middle; //returns the index where it was found
}

template <class T>
void Array<T>::swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void Array<T>::bubbleSort() {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (array[j] < array[j - 1]) {
				swap(&array[j], &array[j - 1]);
			}
		}
	}
}

template <class T>
void Array<T>::selectionSort() {
	int min_index;
	for (int i= 0; i < size; i++) {
		min_index = i;
		for (int j = i+1; j < size; j++) {
			if (array[j] < array[min_index]) min_index = j;
		}
		swap(&array[i], &array[min_index]);

	}
}

template <class T>
void Array<T>::insertionSort(){
	for (int i = 0; i< size; i++){
		int j=i;
		while (j > 0 && array[j]< array[j-1]){
			swap(&array[j], &array[j-1]);
			j--;
		}
	}
}

template <class T>
void Array<T>::mergeSort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        mergeRecursive(low,mid, high);
    }
    return;
}

template <class T>
void Array<T>::mergeRecursive(int low,int mid,int high)
{
T *array2;
array2 = new T[size];
 int h,i,j,k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(array[h]<=array[j])
  {
   array2[i]=array[h];
   h++;
  }
  else
  {
   array2[i]=array[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   array2[i]=array[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   array2[i]=array[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) array[k]=array2[k];
}

template <class T>
void Array<T>::quickSort(int low, int high) {
      int i = low;
			int j = high;
      int pivot = array[(low + high) / 2];
      /* partition of the array */
      while (i <= j) {
            while (array[i] < pivot)
                  i++;
            while (array[j] > pivot)
                  j--;
            if (i <= j) {
                swap(&array[i], &array[j]);
                  i++;
                  j--;
            }
      };
      if (low < j)
            quickSort(low, j);
      if (i < high)
            quickSort(i, high);
}

template <class T>
bool Array<T>::checkIfSort(){
	int counter=0;
	for (int i=1; i<size; i++){
	if (array[i-1]<=array[i]) counter++;
}
if (counter==size-1) return true;
else return false;
}

template <class T>
T & Array<T>::operator[] (const int index){
  if(index >=0 && index <size){
  return array[index];
}
else {
  std::cout << "Invalid Index" << std::endl;
  return array[0];
}
}


template <class T>
const T & Array<T>::operator[] (const int index) const{
  if(index >=0 && index <size){
  return array[index];
}
else {
  std::cout << "Invalid Index" << std::endl;
  return array[0];
}
}
