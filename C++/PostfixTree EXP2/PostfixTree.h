//Class template for a Binary Search Tree 19/10/2016
//Daniel Charua A01017419

#ifndef POSTFIX_TREE_H
#define POSTFIX_TREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

#define INCREMENT 5


template <class T>
class PostfixTree{
private:
  TreeNode<T> *root = nullptr;
  int increment = 5;
  //Recursive method, that takes the root of the subtree
  void clear(TreeNode<T> * _root);
  void printInOrder(TreeNode<T> * _root);
  void printPostOrder(TreeNode<T> * _root);
  void printTree(TreeNode<T> * _root);
  void printTree(TreeNode<T> * _root, int indent, char icon);
public:
   PostfixTree () {}
   PostfixTree (TreeNode<T> * node) { root = node; }
  ~ PostfixTree () { clear(); }
  void clear();
  TreeNode<T> * getRoot(){return root;}
  void setRoot(TreeNode<T> * _root){root = _root;}
  void printInOrder(){printInOrder(root);}
  void printPostOrder(){printPostOrder(root);}
  void printTree(){printTree(root, INCREMENT,  '-');}
};

//Public method to delete all the nodes  in the tree
template <class T>
void  PostfixTree<T>::clear(){
  clear(root);
}

//Private method to delete all the nodes  in the subtree specified
template <class T>
void  PostfixTree<T>::clear(TreeNode<T> * _root){
  if (_root == nullptr) return;
  clear(_root->getLeft());
  clear(_root->getRight());
  delete _root;
}


template <class T>
void  PostfixTree<T>::printInOrder(TreeNode<T> * _root){
  if (_root != nullptr){
    printInOrder(_root->getLeft());
    std::cout << " " << _root->getData() << " ";
    printInOrder(_root->getRight());
  }
}

template <class T>
void  PostfixTree<T>::printPostOrder(TreeNode<T> * _root){
  if (_root != nullptr){
    printPostOrder(_root->getLeft());
    printPostOrder(_root->getRight());
    std::cout << " " << _root->getData() << " ";
  }
}

template <class T>
void  PostfixTree<T>::printTree(TreeNode<T> * _root, int indent, char icon){
  if (_root != nullptr){
  printTree(_root->getRight(), indent+INCREMENT, '/');
  std::cout << std::setw(indent) << " " << icon << "- " << _root->getData() << std::endl;
  printTree(_root->getLeft(), indent+INCREMENT, '\\');
  }
}


#endif
