//Oscar Alcantar
//Homework0501
//Description: Workingg with Linked Lists

#include "LinkedList.h"
#include <iostream>
using namespace std;

//default constructor
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
};

void LinkedList::addToHead(int value) {
    LLNode* newNode = new LLNode(value);
    if (head == nullptr) {
        head = tail = newNode; //sets both head and tail to be the new node if the linked list is empty
    }
    else {
        newNode->next = head; // set the newNodes next to point at head
        head = newNode; // sets head to = newNode
    }
}

void LinkedList::addToTail(int value) {
    LLNode* newNode = new LLNode(value);
    if (head == nullptr) {
        head = tail = newNode; //sets both head and tail to be the new node if the linked list is empty
    }
    else {
        tail->next = newNode; //sets the last node to point at the new node
        tail = newNode; //sets tail to be at new node
    }
}

void LinkedList::deleteNode(int val) {
  if (head == nullptr) {
    cout << "List is empty \n";
    return;
  }

  //if head is the node being deleted
  if(head->data == val) {
    LLNode* temp = head;
    head = head->next;
    delete temp;

    //if list becomes empty
    if (head == nullptr) {
      head == tail;
    }
      cout << "Deleted " << val << " from head.\n";
      return;
  }
  //search for node to delete
  LLNode* prev = head;
  LLNode* curr = head->next;

    while (curr != nullptr) {
        if (curr->data == val) {
            prev->next = curr->next;

            if (curr == tail) {
                tail = prev;
            }

            delete curr;
            cout << "Deleted " << val << " from list.\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Value " << val << " not found.\n";


}

void LinkedList::printList() {
    LLNode* current = head; //loop control variable

    while (current != nullptr) { //this will end when it is at the tail
        cout << current->data << " " ; //print the data of the node we are at
        current = current->next; //iterating forward
    }

}
