#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    LLNode* current = head;
    while (current != nullptr) {
        LLNode* nextNode = current->next;
        delete current; // deletes node AND the Vehicle* inside LLNode
        current = nextNode;
    }
}

void LinkedList::addToTail(Vehicle* vehicle) {
    LLNode* newNode = new LLNode(vehicle);
    if (!tail) {  // empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::deleteNode(int vin) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (head->data->getVin() == vin) {
        LLNode* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        cout << "Deleted vehicle with VIN " << vin << " from head.\n";
        return;
    }
    LLNode* prev = head;
    LLNode* curr = head->next;
    while (curr) {
        if (curr->data->getVin() == vin) {
            prev->next = curr->next;
            if (curr == tail) tail = prev;
            delete curr;
            cout << "Deleted vehicle with VIN " << vin << ".\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Vehicle with VIN " << vin << " not found.\n";
}

Vehicle* LinkedList::search(int vin) {
    LLNode* curr = head;
    while (curr) {
        if (curr->data->getVin() == vin) {
            return curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}

void LinkedList::printList() {
    LLNode* curr = head;
    cout << "Vehicle List:\n";
    while (curr) {
        cout << curr->data->toString() << "\n";
        curr = curr->next;
    }
}

void LinkedList::printListTailRecursive() {
    printListTailRecursive(head);
    cout << endl;
}

void LinkedList::printListTailRecursive(LLNode* node) {
    if (!node) return;
    cout << node->data->toString() << "\n";
    printListTailRecursive(node->next);
}

void LinkedList::printListNonTailRecursive() {
    printListNonTailRecursive(head);
    cout << endl;
}

void LinkedList::printListNonTailRecursive(LLNode* node) {
    if (!node) return;
    printListNonTailRecursive(node->next);
    cout << node->data->toString() << "\n";
}
int LinkedList::countNodes() {
    int count = 0;
    LLNode* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}
