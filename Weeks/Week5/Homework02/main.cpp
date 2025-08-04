//Oscar Alcantar
//Homework0501
//Description: Workingg with Linked Lists

#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    cout << "Working with LinkedLists\n";
    LinkedList list;
    int choice,val;

    do {
        cout << "\nMenu\n";
        cout << "1. Add to head\n";
        cout << "2. Add to tail\n";
        cout << "3. Delete a node\n";
        cout << "4. Print List using Tail Recursion\n";
        cout << "5. Print List using Non-Tail Recursion\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to head: \n";
            cin >> val;
            list.addToHead(val);
            break;
            case 2:
                cout << "Enter value to add to tail: \n";
            cin >> val;
            list.addToTail(val);
            break;
            case 3:
                cout << "Enter value to delete: \n";
            cin >> val;
            list.deleteNode(val);
            break;
            case 4:
                cout << "Printing List (Tail-Recursion):\n";
            list.printListTailRecursive();
            break;
            case 5:
                cout << "Printing List(Non-Tail Recursion):\n";
            list.printListNonTailRecursive();
            break;
            case 6:
                cout << "Exiting!!!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice !=6);

    return 0;
}