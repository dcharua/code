//Daniel Charua A01017419

#include "Array.h"

Array::Array(int s) {
	size = s;
	array = new int[size];
	srand(time(NULL));
}
Array::~Array() {
	delete [] array;
}


void Array::fillOrdered() {
	int *array2;
	array2 = new int[size];
	int a = 10000;
	for (int i = 0; i < size; i++) {
		array2[i] = rand() % 10000;
	}
	for (int i = 0; i < size; i++) {
		a = 10000;
		for (int e = 0; e < size; e++) {
			if (array2[e]<a) {
				a = array2[e];
			}
		}
		for (int e = 0; e < size; e++) {
			if (array2[e] == a) {
				array2[e] = 10000;
			}
		}
		array[i] = a;
	}
}
void Array::fillRandom() {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000;
	}
}

void Array::printRecursive(int index) {
	cout << array[index] << " ";
	if (index == size - 1) {
		cout << endl;
		return;
	}
	printRecursive(index + 1);
}

int Array::linearSearch(int iteam) {
	for (int i = 0; i < size; i++) {
		if (array[i] == iteam) return i;
	}
	return -1;
}

int Array::binarySearchIterative(int item) {
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

int Array::binarySearchRecursive(int item) {
	return binarySearchRecursive(item, 0, size - 1);
}

int Array::binarySearchRecursive(int item, int start, int end) {
	if (start > end) return -1; //base case
	int middle = (start + end) / 2;
	if (item < array[middle])
		return binarySearchRecursive(item, start, middle - 1);
	else if (item > array[middle])
		return binarySearchRecursive(item, middle +1, end);
	else return middle; //returns the index where it was found
}

void Array::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Array::bubbleSort() {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (array[j] < array[j - 1]) {
				swap(&array[j], &array[j - 1]);
			}
		}
	}
}

void Array::selectionSort() {
	int min_index;
	for (int i= 0; i < size; i++) {
		min_index = i;
		for (int j = i+1; j < size; j++) {
			if (array[j] < array[min_index]) min_index = j;
		}
		swap(&array[i], &array[min_index]);

	}
}

//AIzaSyARwppiAbDCm722nOnZTbPOYSE4bF4hbz8
void Array::insertionSort(){
	for (int i = 0; i< size; i++){
		int j=i;
		while (j > 0 && array[j]< array[j-1]){
			swap(&array[j], &array[j-1]);
			j--;
		}
	}
}

void Array::mergeSort(int low, int high)
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
void Array::mergeRecursive(int low,int mid,int high)
{
int *array2;
array2 = new int[size];
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
void Array::quickSort(int low, int high) {
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


bool Array::checkIfSort(){
	int counter=0;
	for (int i=1; i<size; i++){
	if (array[i-1]<=array[i]) counter++;
}
if (counter==size-1) return true;
else return false;
}
