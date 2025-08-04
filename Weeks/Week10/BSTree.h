//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.


#ifndef BSTREE_H
#define BSTREE_H

#include "BSTNode.h"
#include "Vehicle.h"

class BSTree {
  public:
    BSTNode* root{ nullptr };

    BSTree();

    void addNode(Vehicle* val);
    void printTree(); //calls all 3 traversal

    void inorderPrint(BSTNode* node);
    Vehicle* search(int vin);


};



#endif //BSTREE_H
