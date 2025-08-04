//Oscar Alcantar
//Homework 8 - BST Implementation
// Desciption: Working to implement binary search tree


#ifndef BSTREE_H
#define BSTREE_H

#include "BSTNode.h"

class BSTree {
  public:
    BSTNode* root{ nullptr };

    BSTree();

    void addNode(int val);
    void printTree(); //calls all 3 traversal

    void preorderPrint(BSTNode* node);
    void inorderPrint(BSTNode* node);
    void postorderPrint(BSTNode* node);

};



#endif //BSTREE_H
