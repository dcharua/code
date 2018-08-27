/*
	Class implementation for a self balancing AVL tree
	Inherits from the BinarySearchTree class

	Gilberto Echeverria
	gilecheverria@yahoo.com
	02/11/2016
*/

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "BinarySearchTree.hpp"

template <class T>
class AVLTree : public BinarySearchTree<T> {
    private:
        // Recursive method overload for the insertion
        TreeNode<T> * insert(TreeNode<T> * _root, TreeNode<T> * new_node);
        TreeNode<T> * remove(TreeNode<T> * _root, T data);
        // Methods for rebalancing the tree
        int getBalanceFactor(TreeNode<T> * _root);
        void updateHeight(TreeNode<T> * _root);
        TreeNode<T> * balance(TreeNode<T> * _root);
        TreeNode<T> * rotateLeft(TreeNode<T> * _root);
        TreeNode<T> * rotateRight(TreeNode<T> * _root);

    public:
        // Use the same constructors as the parent class
        // Method overload for the insertion
        void insert(T data);
        void insert(TreeNode<T> * new_node);
        // Remove methods
        void remove(T data) { this->root = remove(this->root, data); }
};

// Find the height of a node, based on the heights of its children
template <class T>
void AVLTree<T>::updateHeight(TreeNode<T> * _root)
{
	int leftHeight = ( _root->getLeft() ? _root->getLeft()->getHeight() : 0 );
	int rightHeight = ( _root->getRight() ? _root->getRight()->getHeight() : 0 );

/*
    int leftHeight = 0;
    int rightHeight = 0;

	// Get the heights of the children
    if (_root->getLeft() != nullptr)
        leftHeight = _root->getLeft()->getHeight();
    if (_root->getRight() != nullptr)
        rightHeight = _root->getRight()->getHeight();
*/

	// Add 1 to the largest of the children's heights
    _root->setHeight( std::max(leftHeight, rightHeight) + 1 );
}

// Compute the balance factor as: left height - right height
template <class T>
int AVLTree<T>::getBalanceFactor(TreeNode<T> * _root)
{
	int leftHeight = ( _root->getLeft() ? _root->getLeft()->getHeight() : 0 );
	int rightHeight = ( _root->getRight() ? _root->getRight()->getHeight() : 0 );

/*
    int leftHeight = 0;
    int rightHeight = 0;

	// Get the heights of the children
    if (_root->getLeft() != nullptr)
        leftHeight = _root->getLeft()->getHeight();
    if (_root->getRight() != nullptr)
        rightHeight = _root->getRight()->getHeight();
*/

    return leftHeight - rightHeight;
}

// Rotate a subtree to the right
template <class T>
TreeNode<T> * AVLTree<T>::rotateRight(TreeNode<T> * _root)
{
    TreeNode<T> * child = _root->getLeft();
    _root->setLeft( child->getRight() );
    child->setRight( _root );
    // Update heights
    updateHeight(_root);
    updateHeight(child);
    return child;
}

// Rotate a subtree to the left
template <class T>
TreeNode<T> * AVLTree<T>::rotateLeft(TreeNode<T> * _root)
{
    TreeNode<T> * child = _root->getRight();
    _root->setRight( child->getLeft() );
    child->setLeft( _root );
    // Update heights
    updateHeight(_root);
    updateHeight(child);
    return child;
}

// Method to balance a subree, using rotations
template <class T>
TreeNode<T> * AVLTree<T>::balance(TreeNode<T> * _root)
{
    updateHeight(_root);
    int balance_factor = getBalanceFactor(_root);

    // Left is heavier
    if (balance_factor == 2)
    {
        if ( getBalanceFactor(_root->getLeft()) < 0 )
        {
            // LR case
            _root->setLeft( rotateLeft( _root->getLeft() ) );
        }
        // LL case
        _root = rotateRight(_root);
    }
    // Right is heavier
    else if (balance_factor == -2)
    {
        if ( getBalanceFactor(_root->getRight()) > 0 )
        {
            // RL case
            _root->setRight( rotateRight( _root->getRight() ) );
        }
        // RR case
        _root = rotateLeft(_root);
    }

    return _root;
}

// Overload of the public method in BinarySearchTree
template <class T>
void AVLTree<T>::insert(T data)
{
    TreeNode<T> * new_node = new TreeNode<T>(data);
    insert(new_node);
}

// Overload of the public method in BinarySearchTree
template <class T>
void AVLTree<T>::insert(TreeNode<T> * new_node)
{
    // Empty tree
    if (this->root == nullptr)
        this->root = new_node;
    else
        this->root = insert(this->root, new_node);
}

// Overload of the private recursive method in BinarySearchTree
template <class T>
TreeNode<T> * AVLTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node)
{
    // Check the subtree where the data must be inserted
    if (new_node->getData() < _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getLeft() == nullptr)
            _root->setLeft(new_node);
        else
            _root->setLeft( insert(_root->getLeft(), new_node) );
    }
    else if (new_node->getData() > _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getRight() == nullptr)
            _root->setRight(new_node);
        else
            _root->setRight( insert(_root->getRight(), new_node) );
    }
	// Do not insert duplicated data
    //else;

    return balance(_root);
}

// Private method to delete data from the tree recursively
template <class T>
TreeNode<T> * AVLTree<T>::remove(TreeNode<T> * _root, T data)
{
    if (_root == nullptr)
        return nullptr;
    // Search in the left subtree
    else if (data < _root->getData())
    {
        _root->setLeft( remove(_root->getLeft(), data) );
    }
    // Search in the right subtree
    else if (data > _root->getData())
    {
        _root->setRight( remove(_root->getRight(), data) );
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
        }
    }
    
    return balance(_root);
}

#endif
