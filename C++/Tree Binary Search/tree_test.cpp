#include <iostream>
#include "BinarySearchTree.h"

void treeMenu();

int main(){
  std::cout << "BINARY SEARCH TREE TEST" << std::endl;
  treeMenu();

  return 0;
}

void treeMenu(){
  BinarySearchTree<char> charTree;

  charTree.insert('g');
  charTree.insert('j');
  charTree.insert('T');
  charTree.insert('3');
  charTree.insert('y');
  charTree.insert('n');
  charTree.insert('B');
  charTree.insert('8');
  charTree.insert('a');
  charTree.insert('b');
  charTree.insert('o');

  charTree.printInOrder();
  std::cout << std::endl;
  charTree.printTree();
}
