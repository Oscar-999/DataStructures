//Oscar Alcantar
//Homework 8 - BST Implementation
// Desciption: Working to implement binary search tree



#include <iostream>
#include "BSTree.h"
using namespace std;

int main() {
    BSTree tree;
    int num;

    cout << "Enter at least 10 integers to add to the binary search tree: \n";
    //standard loop of 10
    for (int i = 0; i < 10; i++) {
        cout << "Enter a number: ";
        cin >> num;
        //calls add node adding num
        tree.addNode(num);
    }
    //calls all the different Prints
    tree.printTree();
    return 0;
}