//Linked List class. Used node class to sort Data

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

template <class T>
class LinkedList{
  private:
    Node<T> * head = nullptr;
  public:
  //Constructors
  LinkedList(){}
  LinkedList (Node<T> * _data){head = _data;}
  //Destructor
  ~LinkedList();
  void clear();
  //Insertion methods
  void insertHead (T data);
  void insertHead (Node<T>* new_node);
  void insertTail (T data);
  void insertTail (Node<T>* new_node);
  void insertAtPosition (T data, int position);
  void insertAtPosition (Node<T>* new_node, int position);
  //Delete methods
  T delateHead();//Retruns the data and delates the head
  Node<T> *removeHead();
  Node<T> *removeTail();
  Node<T> *removeItem(T data);
  Node<T> *removeFromPosition(int position);
  //Search methods
  T getDataAtHead();//homework
  T getDataAtTail();//homework
  T getDataAtPosition(int position);//homework
  //Print methods
  void printList();
};

//Destructor
template <class T>
LinkedList<T>::~LinkedList(){
  clear();
}

template <class T>
void LinkedList<T>::clear(){
  Node<T> * item = head;
  while (item != nullptr){
    head = item->getNext();
    delete item;
    item = head;
  }
}


//Insertion Methods//
template <class T>
void LinkedList<T>::insertHead (T data){
  //Create a new node instance with the data provided
  Node<T> * new_node= new Node<T>(data);
  insertHead(new_node);
}

template <class T>
void LinkedList<T>::insertHead (Node<T> * new_node){
  new_node->setNext(head);
  head = new_node;
}
//Tail
template <class T>
void LinkedList<T>::insertTail (T data){
  //Create a new node instance with the data provided
  Node<T> * new_node= new Node<T>(data);
  insertTail(new_node);
}

template <class T>
void LinkedList<T>::insertTail (Node<T> * new_node){
  if(head==nullptr) insertHead(new_node); //Special case if list is empty
  else{
    Node <T> * item =head;
    while (item->getNext() != nullptr){
      item= item ->getNext();
    }
    item->setNext(new_node);
  }
}
//position
template <class T>
void LinkedList<T>::insertAtPosition (T data, int position){
  Node<T> * new_node= new Node<T>(data);
  insertAtPosition(new_node, position);
}

template <class T>
void LinkedList<T>::insertAtPosition (Node<T>* new_node, int position){
  if(head==nullptr || position==0) insertHead(new_node);  //Special case if list is empty or position is 0
  else{
    Node <T> * item =head;
    int i=0;
    while (i < position-1  && item->getNext() != nullptr){
      item = item->getNext();
      i++;
    }
    new_node->setNext(item->getNext());
    item->setNext(new_node);
  }
}




//Print Methods//
template <class T>
void LinkedList<T>::printList(){
  Node<T> * item = head;
  std::cout << "[ ";
  while(item != nullptr){
    std::cout << item->getData()<<" ";
    item =item->getNext();
  }
  std::cout << "]" << std::endl;
}




//Delete Methods//
template <class T>
T LinkedList<T>::delateHead(){
  T data = head->getData();
  Node<T> * item = head;
  //Update head of the list
  head = item->getNext();
  //Disconnect Node
  delete item;
  //return the node just removed
  return data;
}

template <class T>
Node<T> * LinkedList<T>::removeHead(){
  if(head==nullptr) return nullptr; //Retruns nothing if list is empty
  Node<T> *item =head;
  //Update head of the list
  head = item->getNext();
  //Disconnect Node
  item->setNext(nullptr);
  //return the node just removed
  return item;
}

template <class T>
Node<T> * LinkedList<T>::removeTail(){
  if(head==nullptr) return nullptr; //Retrunsn nothing if list is empty
  if(head->getNext()==nullptr){ //Only one element in the list
    Node<T> *item =head;
    head=nullptr;
    return item;
  }
  //More than one element in the list
  Node<T> *previous = head;
  Node<T> *item = previous->getNext();
  while (item->getNext() !=nullptr){
    previous= item;
    item = item->getNext();
  }
  //
  previous->setNext(nullptr);
  return item;
}

template <class T>
Node<T> * LinkedList<T>::removeItem(T data){

}

template <class T>
Node<T> * LinkedList<T>::removeFromPosition(int position){

}




//Get data Methods
template <class T>
T LinkedList<T>::getDataAtHead(){
  if(head==nullptr){
    std::cout << "The list is empty" << std::endl;
    return 0;
  }
  T data = head->getData();
  return data;
}

template <class T>
T LinkedList<T>::getDataAtTail(){
  if(head==nullptr){
    std::cout << "The list is empty" << std::endl;
    return 0;
  }
  Node <T> * item =head;
  while (item->getNext() != nullptr){
    item= item ->getNext();
  }
  T data = item->getData();
  return data;
}

template <class T>
T LinkedList<T>::getDataAtPosition(int position){
  if(head==nullptr){
    std::cout << "The list is empty" << std::endl;
    return 0;
  }
  Node <T> * item =head;
  int i=0;
  while (i < position  && item->getNext() != nullptr){
    item = item->getNext();
    i++;
  }
  T data = item->getData();
  return data;
}

#endif
