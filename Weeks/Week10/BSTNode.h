//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.



#ifndef BSTNODE_H
#define BSTNODE_H

#include "Vehicle.h"

class BSTNode {
public:
  Vehicle* data; //Pointer to Vechicle object
  BSTNode *left; //pointer to left child
  BSTNode *right; // pointer to right child

  BSTNode(Vehicle* v); //Constructor
};



#endif //BSTNODE_H
