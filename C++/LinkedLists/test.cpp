#include <iostream>
#include "linkedList.h"
#include "node.h"

int main(){
  LinkedList<float> testlist;
  Node<float> * loner=nullptr;
  testlist.insertTail(23.12);
  testlist.insertHead(34.123);
  testlist.insertHead(78.347);
  testlist.insertTail(93.12);
  testlist.insertHead(12.258);
  testlist.insertTail(73.12);
  testlist.insertAtPosition(223.4, 3);
  testlist.printList();
  std::cout <<"The data in the head: "<< testlist.getDataAtHead()<<std::endl;
  std::cout << "The data in the tail: " <<testlist.getDataAtTail()<<std::endl;
  std::cout << "The data in position 3 : " <<testlist.getDataAtPosition(3)<<std::endl;

/*
//Insert a pointer to node
  loner= new Node <float>(3.1415);
  testlist.insertHead(loner);
  testlist.printList();
  //clears the list
  testlist.clear();

  testlist.insertHead(44);
  testlist.insertHead(55);
  testlist.insertHead(66);
  testlist.insertHead(77);
  testlist.insertHead(88);
  testlist.insertTail(99);
  testlist.printList();

  loner = testlist.removeTail();
  std::cout << "Node removed" << *loner << std::endl;
  delete loner;
  testlist.printList();
  */

  return 0;
}
