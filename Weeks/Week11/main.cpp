//Oscar Alcantar
//Homework 16 - Sorting
// Description: Implement a sorting algorithm

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Sorts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


const int SIZE = 12;
Vehicle* vehicleArray[SIZE]; // Global array of pointers to Vehicle
int vehicleCount = 0; // How many items read

//prototypes

void readData();
void printArray();


int main() {
    readData();
    cout << "\nBefore Sorting:\n";
    printArray();

    selectionsort(vehicleArray, SIZE); // Sort by VIN selectionSort

    cout << "\nAfter Sorting:\n";
    printArray();





    return 0;
}




void printArray() {
    cout << left << setw(20) << "Make" << setw(15) << "Model"
         << setw(12) << "VIN" << "BodyStyle / Load\n";
    cout << string(50, '-') << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << vehicleArray[i]->toString() << endl;
    }
}

void readData() {
    //simple check to see if file exist comm practice
    ifstream file("07_vehicle_data.txt");
    if (!file) {
        cout << "Error opening file for reading data\n";
        return;
    }

    string line;
    // will stop at EOF now, sentinel-controlled
    while (getline(file, line)) {
        if (line.empty()) continue;


        istringstream iss(line); // this allows you to treat the line as a string for simpler parsing

        string type, vinStr, make, model, extra;
        getline(iss, type, ','); // after type is a comma so thats the dlm for all except extra since its the end of line
        getline(iss, vinStr, ',');
        getline(iss, make, ',');
        getline(iss, model, ',');
        getline(iss, extra);  // last field no ,

        // Trim possible trailing '\r' since the file from canvas was created on windows it had a secret marker that i couldnt see on mac
        // this removes the carriage return
        if (!extra.empty() && extra.back() == '\r') extra.pop_back();

        int vin = stoi(vinStr); //string to intger needed for actual object creation

        Vehicle* vehiclePtr = nullptr;

        if (type == "Truck") {
            int loadWeight = stoi(extra); // load weight is an int like vin
            vehiclePtr = new Truck(make, model, vin, loadWeight);// create truck
        } else if (type == "Car") {
            vehiclePtr = new Car(make, model, vin, extra);
            // cout << " Added Car -> " << vehiclePtr->toString() << endl;
        } else {
            vehiclePtr = new Vehicle(make, model, vin);
            //default case
        }

        vehicleArray[vehicleCount++] = vehiclePtr;
    }

    file.close();
}
