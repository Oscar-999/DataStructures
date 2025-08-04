//Oscar Alcantar
//Homework 8 - BST Implementation
// Desciption: Working to implement binary search tree


#ifndef BSTNODE_H
#define BSTNODE_H



class BSTNode {
public:
  int data; //Node integer data
  BSTNode *left; //pointer to left child
  BSTNode *right; // pointer to right child

  BSTNode(int val); //Constructor
};



#endif //BSTNODE_H
