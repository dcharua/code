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
public:
	//contructor
	Array(int s);
	//destructor
	~Array();


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
