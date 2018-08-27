/*
    Class template for a Binary Search Tree
    Inherits from Binary Tree
    
    Gilberto Echeverria
    gilecheverria@yahoo.com
    01/11/2016
*/

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "BinaryTree.hpp"

template <class T>
class BinarySearchTree : public BinaryTree<T> {
    private:
        // Recursive methods, that take the root of the subtree
        void insert(TreeNode<T> * _root, TreeNode<T> * new_node);
        bool search(TreeNode<T> * _root, T data);
        TreeNode<T> * remove(TreeNode<T> * _root, T data);
        
    public:
        // Use the same constructors as the parent class
        // Insertion methods
        void insert(T data);
        void insert(TreeNode<T> * new_node);
        // Search method
        bool search(T data) { return search(this->root, data); }
        // Remove methods
        void remove(T data) { this->root = remove(this->root, data); }
};

// Public insertion method that gets the data
template <class T>
void BinarySearchTree<T>::insert(T data)
{
    TreeNode<T> * new_node = new TreeNode<T>(data);
    insert(new_node);
}

// Public insertion method that gets a tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * new_node)
{
    // Empty tree
    if (this->root == nullptr)
        this->root = new_node;
    else
        insert(this->root, new_node);
}

// Private insertion method that gets the root of the subtree
//  to insert, and the new tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node)
{
    // Check the subtree where the data must be inserted
    if (new_node->getData() < _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getLeft() == nullptr)
            _root->setLeft(new_node);
        else
            insert(_root->getLeft(), new_node);
    }
    else if (new_node->getData() > _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getRight() == nullptr)
            _root->setRight(new_node);
        else
            insert(_root->getRight(), new_node);
    }
    else
        return; // Do not insert duplicated data
}

// Private method to search recursively
template <class T>
bool BinarySearchTree<T>::search(TreeNode<T> * _root, T data)
{
    // If we reach an empty subtree, the element was not found
    if (_root == nullptr)
        return false;
    // Look in the left subtree
    else if (data < _root->getData())
        return search(_root->getLeft(), data);
    // Look in the right subtree
    else if (data > _root->getData())
        return search(_root->getRight(), data);
    // The element was found (relies on operator overloads)
    else
        return true;
}

// Private method to delete data from the tree recursively
template <class T>
TreeNode<T> * BinarySearchTree<T>::remove(TreeNode<T> * _root, T data)
{
    if (_root == nullptr)
        return nullptr;
    // Search in the left subtree
    else if (data < _root->getData())
    {
        _root->setLeft( remove(_root->getLeft(), data) );
        return _root;
    }
    // Search in the right subtree
    else if (data > _root->getData())
    {
        _root->setRight( remove(_root->getRight(), data) );
        return _root;
    }
    // The data is in the current root
    else
    {
        // Case 1: No children
        if ( !_root->getLeft() && !_root->getRight() )
        {
            delete _root;
            return nullptr;
        }
        // Case 2: Only left child
        else if ( !_root->getRight() )
        {
            // Get the left child
            TreeNode<T> * tmp_node = _root->getLeft();
            // Delete this node
            delete _root;
            // Return the left child
            return tmp_node;
        }
        // Case 3: Only right child
        else if ( !_root->getLeft() )
        {
            // Get the right child
            TreeNode<T> * tmp_node = _root->getRight();
            // Delete this node
            delete _root;
            // Return the right child
            return tmp_node;
        }
        // Case 4: Both subtrees exist
        else
        {
            // Get the smallest value on the right branch
            TreeNode<T> * tmp_node = this->getMin(_root->getRight());
            // Change the data in this node to the smallest value in the right subtree
            _root->setData( tmp_node->getData() );
            // Remove the smallest value from the right subtree
            _root->setRight( remove(_root->getRight(), tmp_node->getData()) );
            // Return this same root (it only changed its data)
            return _root;
        }
    }
}

#endif
