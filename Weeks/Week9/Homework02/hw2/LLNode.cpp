// Oscar Alcantar
// Homework0501
// Description: Node implementation


#include "LLNode.h"

LLNode::LLNode(Vehicle* vehicle) : data(vehicle), next(nullptr) {}

LLNode::~LLNode() {
    delete data;  // safely delete the Vehicle object
}