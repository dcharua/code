/*
Node Class for use in Linked Lists and similar structures

Daniel Charua
14/09/2016
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node{
  private:
    T data;
    Node * next = nullptr;
  public:
    //Constructors
    Node() {}
    Node(T _data) {data = _data;}
    //Destructor
    ~Node() {next=nullptr;}
    //Access methods
    void setData(T _data) {data = _data;}
    void setNext(Node *_next){next= _next;};
    T getData(){return data;}
    Node *getNext(){return next;}

    //method that doesnt belong to this class, but its a friend
    template <class S>
    friend std::ostream & operator << (std::ostream & stream, const Node<S> & node);
};

template <class T>
std::ostream & operator << (std::ostream & stream, const Node<T> & node){
  stream << " -" << node.data << "-";
  return stream;
}
#endif
