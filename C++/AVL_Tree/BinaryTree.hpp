/*
    Class template for a generic Binary Tree
    
    Gilberto Echeverria
    gilecheverria@yahoo.com
    01/11/2016
*/

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <iomanip>
#include "TreeNode.hpp"

#define INCREMENT 5

template <class T>
class BinaryTree {
    protected:
        TreeNode<T> * root = nullptr;

        // Recursive methods, that take the root of the subtree
        void clear(TreeNode<T> * _root);
        TreeNode<T> * getMin(TreeNode<T> * _root);
        int countLeaves(TreeNode<T> * _root);
        void printInOrder(TreeNode<T> * _root);
        void printPostOrder(TreeNode<T> * _root);
        void printTree(TreeNode<T> * _root, int indent, char branch);
        
    public:
        BinaryTree () {}
        BinaryTree (TreeNode<T> * node) { root = node; }
        ~BinaryTree () { clear(); }
        void clear();
        TreeNode<T> * getRoot() { return root; }
        void setRoot(TreeNode<T> * _root) { root = _root; }
        // Counting methods
        TreeNode<T> * getMin() { return getMin(root); }
        int countLeaves() { return countLeaves(root); }
        // Print methods
        void printInOrder() { printInOrder(root); }
        void printPostOrder() { printPostOrder(root); }
        void printTree() { printTree(root, INCREMENT, '-'); }
};

// Public method to delete all the nodes in the tree
template <class T>
void BinaryTree<T>::clear ()
{
    clear(root);
    // Indicate that this is an empty tree
    root = nullptr;
}

// Private method to delete all the nodes in the subtree specified
template <class T>
void BinaryTree<T>::clear (TreeNode<T> * _root)
{
    // Only delete if there is a node
    if (_root)
    {
        // Clear the subtrees free
        clear(_root->getLeft());
        clear(_root->getRight());
        // Free the memory for this node
        delete _root;
    }
}

// Return the node with the smalles value found in the subtree
template <class T>
TreeNode<T> * BinaryTree<T>::getMin(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return nullptr;
    // If there are not left subtrees, this is the smallest value
    if (!_root->getLeft())
        return _root;
    // Return the result from searching in the left subtree
    return getMin(_root->getLeft());
}

template <class T>
int BinaryTree<T>::countLeaves(TreeNode<T> * _root)
{
    // An empty tree has no leaves
    if (_root == nullptr)
        return 0;
    // If there are not children, this is a leaf node
    else if (!_root->getLeft() && !_root->getRight())
        return 1;
    // Add the leaves in the right and left subtrees
    else
        return countLeaves(_root->getLeft()) + countLeaves(_root->getRight());
}

template <class T>
void BinaryTree<T>::printInOrder(TreeNode<T> * _root)
{
    if (_root != nullptr)
    {
        // Print left branch first
        printInOrder(_root->getLeft());
        // Print the root node of this subtree
        std::cout << " " << _root->getData() << " ";
        // Print the right branch
        printInOrder(_root->getRight());
    }
}

template <class T>
void BinaryTree<T>::printPostOrder(TreeNode<T> * _root)
{
    if (_root != nullptr)
    {
        // Print left branch first
        printPostOrder(_root->getLeft());
        // Print the right branch
        printPostOrder(_root->getRight());
        // Print the root node of this subtree
        std::cout << " " << _root->getData() << " ";
    }
}

// Private method to print the tree in a semi graphical form in the terminal
// The tree will appear rotated 90 degrees counter clock-wise
template <class T>
void BinaryTree<T>::printTree(TreeNode<T> * _root, int indent, char branch)
{
    // Print only if the tree is not empty
    if (_root != nullptr)
    {
        // Print right branch first (at the top)
        printTree(_root->getRight(), indent+INCREMENT, '/');
        // Print the root node of this subtree
        std::cout << std::setw(indent) << branch << "== " << _root->getData() << std::endl;
        // Print the left branch
        printTree(_root->getLeft(), indent+INCREMENT, '\\');
    }
}

#endif
