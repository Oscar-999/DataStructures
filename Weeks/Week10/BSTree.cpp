//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.



#include "BSTree.h"
#include <iostream>
using namespace std;


//constructor sets root to nullptr
BSTree::BSTree() {
  root = nullptr;
}

// Adds a Vehicle* to the BST based on VIN number
void BSTree::addNode(Vehicle* v) {
  BSTNode* newNode = new BSTNode(v);  // create a new BST node

  if (!root) {
    root = newNode;  // if tree is empty, new node becomes root
    return;
  }

  BSTNode* current = root;

  while (true) {
    if (v->getVin() < current->data->getVin()) {
      // go left
      if (!current->left) {
        current->left = newNode;
        return;
      }
      current = current->left;
    } else {
      // go right
      if (!current->right) {
        current->right = newNode;
        return;
      }
      current = current->right;
    }
  }
}

// Public function to print the tree in-order
void BSTree::printTree() {
  inorderPrint(root);
}



// Recursive in-order traversal
void BSTree::inorderPrint(BSTNode* node) {
  if (!node) return;

  inorderPrint(node->left);                     // left subtree
  cout << node->data->toString() << endl;       // current node
  inorderPrint(node->right);                    // right subtree
}

// Searches for a Vehicle by VIN number
Vehicle* BSTree::search(int vin) {
  BSTNode* current = root;

  while (current) {
    if (vin == current->data->getVin()) {
      return current->data;  // found
    } else if (vin < current->data->getVin()) {
      current = current->left;  // go left
    } else {
      current = current->right; // go right
    }
  }

  return nullptr;  // not found
}