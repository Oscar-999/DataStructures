//Oscar Alcantar
//Homework 8 - BST Implementation
// Desciption: Working to implement binary search tree


#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree() {
  root = nullptr;
}


void BSTree::addNode(int val) {
  BSTNode* newNode = new BSTNode(val); // creages new node

  if (root == nullptr) {
    root = newNode;  //sets the root to the newely created node if root is null ptr
    return;
  }

  BSTNode* current = root; //sets current pointer to the root
  bool inserted = false; // checks if inserted

  while (!inserted) {
    if (val < current->data) {
      // Go left if the new value is smaller
      if (current->left == nullptr) {
        current->left = newNode; // Insert if spot is empty
        inserted = true;
      } else {
        current = current->left; // Keep going left
      }
    }
    else { // Go right if the new value is equal or greater
      if (current->right == nullptr) {
        current->right = newNode;
        inserted = true;
      } else {
        current = current->right; //keep going right
      }
    }
  }
}

void BSTree::printTree() {
  cout << "Preorder Traversal: ";
  preorderPrint(root);
  cout << endl;

  cout << "Inorder Traversal: ";
  inorderPrint(root); //call indorder
  cout << endl;

  cout << "Postorder Traversal: "; //call post order
  postorderPrint(root);
  cout << endl;
}

void BSTree::preorderPrint(BSTNode* node) {
  if (node == nullptr) return;

  cout << node->data << " "; //print root
  preorderPrint(node->left); //visit leftsubtree
  preorderPrint(node->right); //visit right tree
}

void BSTree::inorderPrint(BSTNode* node) {
  if (node == nullptr) return;

  inorderPrint(node->left);  //visit left subtree
  cout << node->data << " "; //visit root print root
  inorderPrint(node->right);  //visit right subtree
}

void BSTree::postorderPrint(BSTNode* node) {
  if (node == nullptr) return;

  postorderPrint(node->left); //visit left subtree
  postorderPrint(node->right); // visit right subtree
  cout << node->data << " "; // print the root
}