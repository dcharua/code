#include <iostream>
#include <string>
#include "linkedList.h"
#include "Vector3D.h"

void listTest();
Vector3D vectorAddition(const LinkedList<Vector3D> & vector_list);

int main (){
  listTest();
  return 0;
}

void listTest(){
  Vector3D result;
  //Create the list that holds Vector3D objects
  LinkedList<Vector3D> vector_list;
  vector_list.insertTail(Vector3D(3.6, 7.2, 8.1));
  vector_list.insertTail(Vector3D(7.34, 83.1, 2.5));
  vector_list.insertTail(Vector3D(6.3, 7.1, 3.5));
  vector_list.insertTail(Vector3D(8.4, 1.7, 2.5));

  vector_list.printList();

  result = vectorAddition(vector_list);

  std::cout << "The addition of the vectors is: " << result <<std::endl;
}

Vector3D vectorAddition(const LinkedList<Vector3D> & vector_list){
  Vector3D result;
  /*
  int size= vector_list.getLength();
  for(int i=0; i<size; i++){
    result += vector_list.getDataAtPosition(i);
  }
  return result;
  */
  Node<Vector3D> *item = vector_list.getHead();
  while(item !=nullptr){
    result += item->getData();
    item = item->getNext();
  }
  return result;
}
