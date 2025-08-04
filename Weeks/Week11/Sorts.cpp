

#include "sorts.h"
#include <iostream>
using namespace std;

// Swap helper for Vehicle* pointers
void swap(Vehicle*& a, Vehicle*& b) {
    Vehicle* temp = a;
    a = b;
    b = temp;
}

// Selection Sort by VIN
void selectionsort(Vehicle* data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int least = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j]->getVin() < data[least]->getVin()) {
                least = j;
            }
        }
        if (least != i) {
            swap(data[i], data[least]);
        }
    }
    cout << "\nSelection Sort completed. Big-O Complexity: O(n^2)\n";
}
