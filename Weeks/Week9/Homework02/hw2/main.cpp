// Oscar Alcantar
// Week 7 Homework
// Description: Add functionality to the 03 – Polymorphism project that reads data from a plain text file
// and stores the data in objects of the appropriate class, which are then stored in an
// array
// Also tracks and displays BigO complexity for each algorithm operation

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "BigO.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

LinkedList vehicleList;  // global LinkedList object
BigO bigO;               // BigO object to track operations

//prototypes
void displayMenu();
void addVehicle();
void deleteVehicle();
void searchForVehicle();
void displayAllVehicles();
void readData();

int main() {
    readData();

    // Display BigO for reading and building the list
    cout << "BigO for reading and building list: " << bigO.getBigO(0) << endl;

    int choice;
    do {
        displayMenu(); //calls displaymenu func
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: deleteVehicle(); break;
            case 3: searchForVehicle(); break;
            case 4: displayAllVehicles(); break;
            case 5: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid option.\n";
        }
    } while (choice != 5);

    // Cleanup  conflict leaving cars
    // No manual deletion needed since LinkedList handles it

    return 0;
}

void displayMenu() {
    cout << "\nVehicle Management Program\n";
    cout << "\n1. Add a vehicle\n";
    cout << "2. Delete a vehicle\n";
    cout << "3. Search for a vehicle\n";
    cout << "4. Display all vehicles\n";
    cout << "5. Exit\n";
    cout << "\nYour choice: ";
}

void addVehicle() {
    int type;
    cout << "What kind of vehicle? 1 - Car, 2 - Truck: ";
    cin >> type;
    cin.ignore();

    string make, model;
    int vin;

    cout << "Enter make: ";
    getline(cin, make);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter vin: ";
    cin >> vin;
    cin.ignore();

    Vehicle* newVehicle = nullptr;

    if (type == 1) {
        string bodyStyle;
        cout << "Enter body style: ";
        getline(cin, bodyStyle);
        // adding car to the linked list tail
        newVehicle = new Car(make, model, vin, bodyStyle);
    }
    else if (type == 2) {
        int loadWeight;
        cout << "Enter load weight: ";
        cin >> loadWeight;
        cin.ignore();
        // adding truck to the linked list tail
        newVehicle = new Truck(make, model, vin, loadWeight);
    }
    else {
        cout << "Invalid vehicle type.\n";
        return;
    }

    // vehicleList.addToTail(newVehicle);
    // bigO.updateTotalOperations(4);  // count inputs and object creation
    //
    // cout << "\nVehicle added:\n" << newVehicle->toString() << endl;
    //
    // cout << "BigO for add operation: " << bigO.getBigO(0) << endl;
    vehicleList.addToTail(newVehicle);
    bigO.updateTotalOperations(4);  // count inputs and object creation

    cout << "\nVehicle added:\n" << newVehicle->toString() << endl;

    // Pass the current linked list size here:
    int size = vehicleList.countNodes();
    cout << "BigO for add operation: " << bigO.getBigO(size) << endl;
}

void deleteVehicle() {
    int vin;
    cout << "VIN to delete ";
    cin >> vin;
    cin.ignore();

    vehicleList.deleteNode(vin);

    // Pass the current linked list size here:
    int size = vehicleList.countNodes();
    cout << "BigO for delete operation: " << bigO.getBigO(size) << endl;
}

void searchForVehicle() {
    int vin;
    cout << "VIN to display: ";
    cin >> vin;
    cin.ignore();

    Vehicle* found = vehicleList.search(vin);
    if (found) {
        cout << found->toString() << endl;
    }
    else {
        cout << "Vehicle not found.\n";
    }

    cout << "BigO for search operation: " << bigO.getBigO(0) << endl;
}

void displayAllVehicles() {
    cout << "\nAll Vehicles:\n";
    cout << left << setw(20) << "Make" << setw(15) << "Model"
         << setw(12) << "VIN" << setw(20) << "Body Style / Load Weight\n";

    vehicleList.printList();
        int size = vehicleList.countNodes();

    cout << "BigO for display operation: " << bigO.getBigO(0) << endl;
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

        bigO.updateTotalOperations(1);  // count reading one line

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

        vehicleList.addToTail(vehiclePtr);
        bigO.updateTotalOperations(5);  // count parsing and object creation operations
    }

    file.close();
}
