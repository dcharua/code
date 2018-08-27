/*
Program to test the Stack and Queue implementations with arrays
Daniel Charua A01017419

*/
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

void user_menu();

int main()
{
    std::cout << "TEST FOR QUEUES AND STACKS" << std::endl;
    user_menu();
    return 0;
}

void user_menu()
{
    char option = 'a';
    int item;

    Stack the_stack(10);
    Queue the_queue(4);

    while (option != 'q')
    {
        std::cout << "\nUser Menu" << std::endl;
        // Stack options
        std::cout << "  a. Print stack" << std::endl;
        std::cout << "  b. Push into stack" << std::endl;
        std::cout << "  c. Top of the stack" << std::endl;
        std::cout << "  d. Pop from the stack" << std::endl;
        // Queue options
        std::cout << "  f. Print queue" << std::endl;
        std::cout << "  g. Push into queue" << std::endl;
        std::cout << "  h. Top of the queue" << std::endl;
        std::cout << "  i. Pop from the queue" << std::endl;
        // Finish the program
        std::cout << "  q. Quit program" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 'a')
        {
            the_stack.print();
        }
        if (option == 'b')
        {
            std::cout << "Enter the new item (different form 0): ";
            std::cin >> item;
            the_stack.push(item);
        }
        if (option == 'c')
        {
            item = the_stack.top();
            std::cout << "Item at the top of the stack: " << item << std::endl;
        }
        if (option == 'd')
        {
            item = the_stack.pop();
            std::cout << "Item previously at the top of the stack: " << item << std::endl;
        }

        if (option == 'f')
        {
            the_queue.print();
        }
        if (option == 'g')
        {
            std::cout << "Enter the new item (different form 0): ";
            std::cin >> item;
            the_queue.push(item);
        }
        if (option == 'h')
        {
            item = the_queue.top();
            std::cout << "Item at the end of the queue: " << item << std::endl;
        }
        if (option == 'i')
        {
            item = the_queue.pop();
            std::cout << "Item previously at the end of the queue: " << item << std::endl;
        }
    }
}
