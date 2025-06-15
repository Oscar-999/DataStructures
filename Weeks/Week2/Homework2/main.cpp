//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.


#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#define SIZE 5
using namespace std;

Vehicle* vehicles[SIZE] = { nullptr };  // Initialize all to nullptr this allows you to check more efficent than 0 to avoid crash conflict

//prototypes
void displayMenu();
void addVehicle();
void deleteVehicle();
void searchForVehicle();
void displayAllVehicles();

int main() {
    int choice;
    do {
        displayMenu(); //calls displaymenu func
        cin >> choice;


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
    for (int i = 0; i < SIZE; i++) {
        delete vehicles[i];
        vehicles[i] = nullptr;
    }

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

    // Find an empty slot (nullptr)
    int index = -1;

    for (int i = 0; i < SIZE; i++) {
        // this allows me to add a vehicle to a viable space
        if (vehicles[i] == nullptr) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No space left in the array.\n";
        return;
    }

    if (type == 1) {
        string bodyStyle;
        cout << "Enter body style: ";
        getline(cin, bodyStyle);
        // adding car to the index we are on now
        vehicles[index] = new Car(make, model, vin, bodyStyle);
    }
    else if (type == 2) {
        int loadWeight;
        cout << "Enter load weight: ";
        cin >> loadWeight;
        cin.ignore();
        // adding truck to the index we are on by checking if null ptr
        vehicles[index] = new Truck(make, model, vin, loadWeight);
    }
    else {
        cout << "Invalid vehicle type.\n";
        return;
    }

    cout << "\nVehicle added:\n" << vehicles[index]->toString() << endl;
}

void deleteVehicle() {
    int vin;
    cout << "VIN to delete ";
    cin >> vin;
    cin.ignore();

    for (int i = 0; i < SIZE; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getVin() == vin) {
            delete vehicles[i];
            // new vechinle resets to 0
            vehicles[i] = new Vehicle();
            cout << "Vehicle not in inventory\n";
            return;
        }
    }
    cout << "Vehicle not found.\n";
}

void searchForVehicle() {
    int vin;
    cout << "VIN to display: ";
    cin >> vin;
    cin.ignore();

    for (int i = 0; i < SIZE; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getVin() == vin) {
            cout << vehicles[i]->toString() << endl;
            return;
        }
    }
    cout << "Vehicle not found.\n";
}

void displayAllVehicles() {
    cout << "\nAll Vehicles:\n";
    cout << left << setw(20) << "Make" << setw(15) << "Model"
    << setw(12) << "VIN" << setw(20) << "Body Style / Load Weight\n";
    for (int i = 0; i < SIZE; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getVin() != 0) { // Without checking if it is at a nullptr it crashes retrive non 0 vins only
            cout << vehicles[i]->toString() << endl;
        }
    }
}
