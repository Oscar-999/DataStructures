#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LLNode.h"

class LinkedList {
private:
    LLNode* head;
    LLNode* tail;

    void printListTailRecursive(LLNode* node);
    void printListNonTailRecursive(LLNode* node);

public:
    LinkedList();
    ~LinkedList();

    // Add node to tail using Vehicle pointer
    void addToTail(Vehicle* vehicle);
    int countNodes(); // fix incorrect big0

    void deleteNode(int vin);
    Vehicle* search(int vin);

    void printList();
    void printListTailRecursive();
    void printListNonTailRecursive();
};

#endif // LINKEDLIST_H
