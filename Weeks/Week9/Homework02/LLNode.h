// Oscar Alcantar
// Homework0501
// Description: Node for linked list storing Vehicle objects

#ifndef LLNODE_H
#define LLNODE_H

#include "Vehicle.h"

class LLNode {
public:
    Vehicle* data; //had to set this to a pointer since polymorphism is how we implemented the other data fields
    LLNode* next;

    // One-argument constructor takes Vehicle pointer , next initialized to nullptr
    LLNode(Vehicle* vehicle);

    ~LLNode(); //destructor
};

#endif // LLNODE_H
