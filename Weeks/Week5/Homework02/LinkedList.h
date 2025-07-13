//Oscar Alcantar
//Homework0501
//Description: Workingg with Linked Lists adding del


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LLNode.h"

class LinkedList {
private:
    LLNode* head;
    LLNode* tail;
public:
    LinkedList();
    //void addNode(); not listed??
    void addToHead(int value);
    void addToTail(int value);
    void deleteNode(int value); //delet added
    void printList() ;
};



#endif //LINKEDLIST_H
