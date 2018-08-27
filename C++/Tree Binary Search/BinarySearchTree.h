//Class template for a Binary Search Tree 19/10/2016
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

#define INCREMENT 5


template <class T>
class BinarySearchTree{
private:
  TreeNode<T> *root = nullptr;
  int increment = 5;
  //Recursive method, that takes the root of the subtree
  void clear(TreeNode<T> * _root);
  void insert(TreeNode<T> * _root, TreeNode<T> * new_node);
  void printInOrder(TreeNode<T> * _root);
  void printTree(TreeNode<T> * _root);
  void printTree(TreeNode<T> * _root, int indent, char icon);
  TreeNode <T> * getMin(TreeNode<T> * _root);
  bool search(TreeNode<T> *_root, T data);
  TreeNode <T> * remove(TreeNode<T> * _root, T data);
public:
  BinarySearchTree () {}
  BinarySearchTree (TreeNode<T> * node) { root = node; }
  ~BinarySearchTree () { clear(); }
  void clear();
  TreeNode<T> * getRoot(){return root;}
  void setRoot(TreeNode<T> * _root){root = _root;}
  void insert (T data);
  void insert(TreeNode<T> * new_node);
  void printInOrder(){printInOrder(root);}
  void printTree(){printTree(root, INCREMENT,  '-');}
  bool search( T data) { return search (root, data);}
  TreeNode <T> * getMin(){return getMin(root);}
  int countLeaves();
  void remove(T data){ root = remove(root, data);}
};


//Public method to delete all the nodes  in the tree
template <class T>
void BinarySearchTree<T>::clear(){
  clear(root);
}

//Private method to delete all the nodes  in the subtree specified
template <class T>
void BinarySearchTree<T>::clear(TreeNode<T> * _root){
  if (_root == nullptr) return;
  clear(_root->getLeft());
  clear(_root->getRight());
  delete _root;
}

//Public insertion method that gets data
template <class T>
void BinarySearchTree<T>::insert (T data){
  TreeNode<T> *new_node = new TreeNode<T>(data);
  insert(new_node);
}

//Public insertion method that gets a tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * new_node){
  if (root == nullptr)
    root = new_node;
  else
    insert(root, new_node);
}

//Private insertion method that gets a the root of the subtree to insert, and the new tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node){
 if (new_node->getData() < _root->getData()){
  if (_root->getLeft() == nullptr)
    _root->setLeft(new_node);
  else
    insert(_root->getLeft(), new_node);
 }
  else if (new_node->getData() > _root->getData()){
    if (_root->getRight() == nullptr)
      _root->setRight(new_node);
    else
     insert(_root->getRight(), new_node);
  }
  else
    return; // Do not insert duplicated data
}

template <class T>
bool BinarySearchTree<T>::search(TreeNode<T> *_root, T data){
// The data is not found in an empty tree
  if(_root == nullptr)
    return false;
  //Look into the left subtree
  else if( data< _root->getData())
    return search(_root->getLeft(), data);
     // Look in the right subtree
  else if( data> _root->getData())
    return search(_root->getRight(), data);
     // The data has been found
  else
    return true;
}


template <class T>
void BinarySearchTree<T>::printInOrder(TreeNode<T> * _root){
  if (_root != nullptr){
    printInOrder(_root->getLeft());
    std::cout << " " << _root->getData() << " ";
    printInOrder(_root->getRight());
  }
}

template <class T>
void BinarySearchTree<T>::printTree(TreeNode<T> * _root, int indent, char icon){
  if (_root != nullptr){
  printTree(_root->getRight(), indent+INCREMENT, '/');
  std::cout << std::setw(indent) << " " << icon << "- " << _root->getData() << std::endl;
  printTree(_root->getLeft(), indent+INCREMENT, '\\');
  }
}

template <class T>
TreeNode <T> *  BinarySearchTree<T>::getMin(TreeNode<T> * _root){
 //Keep looking for a node in the leftest of the tree
  if(_root->getLeft()!=nullptr)
    return getMin(_root->getLeft());
  //Return a node with no left subtree
    return _root;
}

template <class T>
int  BinarySearchTree<T>::countLeaves(){
  return 0;
}

template <class T>
TreeNode<T> *  BinarySearchTree<T>::remove(TreeNode<T> * _root, T data){
//If tree is empty
  if(_root == nullptr)
    return nullptr;
  else if(data < _root->getData()){
    _root->setLeft(remove(_root->getLeft(), data));
    // This node did not change
    return _root;
  }
  else if(data > _root->getData()){
    _root->setRight(remove(_root->getRight(), data));
    // This node did not change
    return _root;
  }
  //This is the node with the data to delate
  else {
    //Case 1: Leaf node
    if (_root->getLeft() == nullptr && _root->getRight() == nullptr){
      delete _root;
      return nullptr;
    }
    //Case 2: Only left child
    else if (_root->getRight()==nullptr){
      TreeNode<T> * tmp_node = _root->getLeft();
      delete _root;
      return tmp_node;
    }
    //Case 3: Only right child
    else if (_root->getLeft()==nullptr){
      TreeNode<T> * tmp_node = _root->getRight();
      delete _root;
      return tmp_node;
    }
    //Case 4: Two children
    else if (_root->getLeft() != nullptr && _root->getRight() != nullptr ){
      //Get the node with the smallest value on the right branch
      TreeNode<T> * tmp_node = getMin(root->getRight());
      //Change the value in the current node
      _root->setData(tmp_node->getData());
      //Delete the smallest data form the right subtree
      _root->setRight(remove(_root->getRight(), tmp_node->getData()));
      // This node did not change
      return _root;
    }
  }
}

#endif
