//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.



#include "BSTNode.h"

BSTNode::BSTNode(Vehicle* v){
  data = v;
  left = nullptr;
  right = nullptr;
  }
