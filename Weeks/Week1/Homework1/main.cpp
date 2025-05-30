//Oscar Alcantar
//Week1 Homework
//Description: Write a class and driver to implement functionality related to vehicles. Display a menu of
//options to the user, and implement the functionality to add, delete, and search for a
//vehicle, and to display all vehicles.


#include "Vehicle.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void displayMenu();
void addVehicle(Vehicle[], int);
void deleteVehicle(Vehicle[], int);
void searchForVehicle(Vehicle[], int);
void displayAllVehicles(Vehicle[], int);

int main() {
    const int SIZE = 5;
    Vehicle vehicles[SIZE];
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: addVehicle(vehicles, SIZE); break;
            case 2: deleteVehicle(vehicles, SIZE); break;
            case 3: searchForVehicle(vehicles, SIZE); break;
            case 4: displayAllVehicles(vehicles, SIZE); break;
            case 5: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid Option.\n";


        }
    }while (choice != 5);

    return 0;
}

void displayMenu() {
    //Menu Prints
    cout << "\nWelcome to the Vehicle Management Program\n";
    cout << "\n1. Add a vehicle\n";
    cout << "2. Delete a vehicle\n";
    cout << "3. Search for a vehicle\n";
    cout << "4. Display all vehicles\n";
    cout << "5. Exit\n";
    cout << "\nYour choice: ";
}

void addVehicle(Vehicle vehicles[], int size) {
    string make,model;
    int vin;
    //Boolean to keep track if added
    bool added = false;
    //User prompts
    cout << "\nEnter make: ";
    cin >> make;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter vin: ";
    cin >> vin;

    for (int i = 0; i < size; i++) {
        if (vehicles[i].getVin() == 0) {
            // Sets an array to open element / vin = 0
            vehicles[i] = Vehicle(make, model, vin);
            cout << "\nVehicle Added.";
            added = true;
            break;
        }
    }
    if (!added) {
        cout << "No more space in Array";
    }
}

void deleteVehicle(Vehicle vehicles[], int size) {
    int vin;
    cout << "Enter vin to delete: ";
    cin >> vin;
    for (int i = 0; i < size; i++) {
        if (vehicles[i].getVin() == vin) {
            //Default constructor to reset to empty
            vehicles[i] = Vehicle();
            cout << "Vehicle Deleted.\n";
            return;
        }
    }
    cout << "Vehicle does not exist in inventory.\n";
}

void searchForVehicle(Vehicle vehicles[], int size) {
    int vin;
    cout << "Enter vin to search: ";
    cin >> vin;

    for (int i = 0; i < size; i++) {
        if (vehicles[i].getVin() == vin) {
            cout << "Make      Model      Vin\n";
            cout << vehicles[i].toString() << "\n";
            return;
        }
    }
}

void displayAllVehicles(Vehicle vehicles[], int size) {
    cout << "Make      Model     Vin\n";
    for (int i = 0; i < size; i++) {
        if (vehicles[i].getVin() != 0) {
            //Prints info
            cout << vehicles[i].toString() << "\n";
        }
    }
}
