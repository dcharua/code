#include <iostream>
#include "BinarySearchTree.h"

void menu();

int main()
{
    std::cout << "BINARY SEARCH TREE TEST" << std::endl;
    menu();

    return 0;
}

void menu()
{
    BinarySearchTree<int> tree;
    TreeNode<int> * node;
    int number;
    char ans = 'a';
    bool found = false;
    int preset_data[] = {9, 2, 5, 12, 7, 18, 13, 14, 1, 29, 16};
    int preset_size = sizeof preset_data / sizeof preset_data[0];

    while (ans != 'q')
    {
        std::cout << "\n== Binary Search Tree Test Menu ==\n";
        std::cout << "\tf. Fill the tree with preset data\n";
        std::cout << "\ti. Insert a new number to the tree\n";
        std::cout << "\ts. Search for a number in the tree\n";
        std::cout << "\tr. Remove a number from the tree\n";
        std::cout << "\tc. Clear the tree\n";
        std::cout << "\tp. Print the data in the tree In-order\n";
        std::cout << "\tt. Print the data as a tree\n";
        std::cout << "\tm. Get the smallest number in the tree\n";
        std::cout << "\tl. Get the number of leaves in the tree\n";
        std::cout << "\tq. Quit the program\n";
        std::cout << "Enter your selection: ";
        std::cin >> ans;

        switch (ans)
        {
            // Fill with preset values
            case 'f':
                std::cout << "\tInserting: ";
                for (int i=0; i<preset_size; i++)
                {
                    std::cout << preset_data[i] << " ";
                    tree.insert(preset_data[i]);
                }
                std::cout << std::endl;
                break;
            // Insert a new data node
            case 'i':
                std::cout << "\tEnter the new number to insert: ";
                std::cin >> number;
                tree.insert(number);
                break;
            // Search for data in the tree
            case 's':
                std::cout << "\tEnter the number to search for: ";
                std::cin >> number;
                found = tree.search(number);
                std::cout << "\tNumber: " << number << " was " << (found ? "found" : "NOT found") << " in the tree" << std::endl;
                break;
            // Remove an element from the tree
            case 'r':
                std::cout << "\tEnter the new number to remove: ";
                std::cin >> number;
                tree.remove(number);
                break;
            // Clear the contents of the tree
            case 'c':
                tree.clear();
                break;
            // Print the tree in order
            case 'p':
                tree.printInOrder();
                break;
            // Print the tree "graphically"
            case 't':
                tree.printTree();
                break;
            // Get the smallest value stored in the tree
            case 'm':
                node = tree.getMin();
                if (node)
                    std::cout << "\tSmallest number: " << node->getData() << std::endl;
                else
                    std::cout << "\tApparently the tree is empty" << std::endl;
                break;
            // Count the number of leaves in the tree
            case 'l':
                number = tree.countLeaves();
                std::cout << "\tNumber of leaves: " << number << std::endl;
                break;
            // Quit the program
            case 'q':
                std::cout << "See you later" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Try again ..." << std::endl;
                break;
        }
    }
}
