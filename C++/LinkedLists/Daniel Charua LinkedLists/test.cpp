#include <iostream>
#include "linkedList.h"
#include "node.h"

using namespace std;

/*
 *
 */
void printMenu()
{
    cout << "MENU:" << endl;
    cout << "1. Inserir element pel davant" << endl;
    cout << "2. Inserir element pel final" << endl;
    cout << "3. Eliminar element pel davant" << endl;
    cout << "4. Eliminar element pel final" << endl;
    cout << "5. Imprimir contingut de l’ArrayDEQUE" << endl;
    cout << "6. Sortir" << endl;
}

int main(int argc, char** argv)
{
    cout << "Welcome:" << endl;
    cout << "Insert queue size: ";
    int queueSize;
    cin >> queueSize;
    cout << "Mida: " << queueSize << "\n" << endl;

    LinkedList<int> queue;

    printMenu();
    int selection;
    cout << "Make a selection: ";
    cin >> selection;
    int temp = 0;
    while(selection != 6)
    {
        switch(selection)
        {
            case 1:
                cout << "Inserir element pel davant: ";
                cin >> temp;
                queue.insertHead(temp);
                break;
            case 2:
                cout << "Inserir element pel final:";
                cin >> temp;
                queue.insertTail(temp);
                break;
            case 3:
                queue.removeHead();
                break;
            case 4:
                queue.removeTail();
                break;
            case 5:
                queue.printList();
                break;
            default:
                cout << "Invalid option" << endl;
                printMenu();
                cin>>selection;
                cout << "Make a selection: ";
                break;
        }
        printMenu();
        cout << "Make a selection: ";
        cin>>selection;
    } cout << "Adeu!" << endl;

    return 0;
}
