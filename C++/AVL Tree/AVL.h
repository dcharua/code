//Class for AVL Tree 02/11/06 Daniel Charua A01017419

#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "BinarySearchTree.h"

template <class T>
class AVLTree : public BinarySearchTree<T>{
protected:
  //Method overload for the insertion
  TreeNode<T> * insert(TreeNode<T> * _root, TreeNode<T> * new_node);
  //Method for rebalancing the tree
  int getBalanceFactor(TreeNode<T> * _root);
  void updateHeight(TreeNode<T> * _root);
  TreeNode<T> * balance(TreeNode<T> * _root);
  TreeNode<T> * rotateLeft(TreeNode<T> * _root);
  TreeNode<T> * rotateRight(TreeNode<T> * _root);
public:
  AVLTree(){}
  AVLTree(TreeNode<T> * node){root = node;}
  //Method overload for the insertion
  void insert(TreeNode<T> * new_node);
};

//Function to rootate tree to the Left
template <class T>
TreeNode<T> * AVLTree<T>::rotateRight(TreeNode<T> * _root){
  TreeNode<T> * child = _root->getLeft();
  _root->setLeft(child->getRight());
  child->setRight(_root);
  //Upadte the heights
  updateHeight(_root);
  updateHeight(child);
  return child;
}

//Function to rootate tree to the Right
template <class T>
TreeNode<T> * AVLTree<T>::rotateLeft(TreeNode<T> * _root){
  TreeNode<T> * child = _root->getRight();
  _root->setRight(child->getLeft());
  child->setLeft(_root);
  //Upadte the heights
  updateHeight(_root);
  updateHeight(child);
  return child;
}


//Function to update heights
template <class T>
void AVLTree<T>::updateHeight(TreeNode<T> * _root){
//Empty root case
  if(!_root)
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if(_root->getLeft() != nullptr)
    leftHeight = _root->getLeft()->getHeight();
  if(_root->getRight() != nullptr)
    rightHeight = _root->getRight()->getHeight();
  _root->setHeight(std::max(leftHeight, rightHeight) + 1);
}

//get the difference in the childern heights
template <class T>
int AVLTree<T>::getBalanceFactor(TreeNode<T> * _root){
//Empty root case
  if(!_root)
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if(_root->getLeft() != nullptr)
    leftHeight = _root->getLeft()->getHeight();
  if(_root->getRight() != nullptr)
    rightHeight = _root->getRight()->getHeight();
  return leftHeight - rightHeight;
}

template <class T>
TreeNode<T> * AVLTree<T>::balance(TreeNode<T> * _root){
  updateHeight(_root);
  int balance_factor = getBalanceFactor(_root);
  //Left is heavier
  if (balance_factor == 2){
    //LeftRight Case
    if(getBalanceFactor(_root->getLeft())<0){
      _root->setLeft(rotateLeft(_root->getLeft()));
    }
    //Leftleft case
    _root = rotateRight(_root);
  }

  //Right is heavier
  if (balance_factor == -2){
    //RightLeft Case
    if(getBalanceFactor(_root->geRight())>0){
      _root->setRight(rotateRight(_root->getRight()));
    }
    //Rightright case
    _root = rotateLeft(_root);
  }
  return _root;
}

//Private insartion method
template <class T>
TreeNode<T> * AVLTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node){
  insert(_root, new_node);
  balance (_root);
}

//Public insertion method
template <class T>
void AVLTree<T>::insert(TreeNode<T> * new_node){
  if (root == nullptr)
    root = new_node;
  else
    root = insert(root, new_node);
}
#endif
