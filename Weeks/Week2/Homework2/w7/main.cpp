//Oscar Alcantar
//Week 7 Homework
//Description: Add functionality to the 03 – Polymorphism project that reads data from a plain text file
// and stores the data in objects of the appropriate class, which are then stored in an
// array

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

Vehicle** vehicles;  // declare pointer to pointer
int vehicleCount;

//prototypes
void displayMenu();
void addVehicle();
void deleteVehicle();
void searchForVehicle();
void displayAllVehicles();
int countData();
void readData(int vehicleCount);

int main() {
    vehicleCount = countData();


    vehicles = new Vehicle*[vehicleCount];
    for (int i = 0; i < vehicleCount; i++) {
        vehicles[i] = nullptr;
    }

    readData(vehicleCount);

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
    for (int i = 0; i < vehicleCount; i++) {
        delete vehicles[i];
        vehicles[i] = nullptr;
    }

    delete[] vehicles; // clean up the array itself

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

    for (int i = 0; i < vehicleCount; i++) {
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

    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getVin() == vin) {
            delete vehicles[i];
            // new vehicle resets to nullptr (empty slot)
            vehicles[i] = nullptr;
            cout << "Vehicle deleted from inventory.\n";
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

    for (int i = 0; i < vehicleCount; i++) {
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
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getVin() != 0) { // Without checking if it is at a nullptr it crashes retrive non 0 vins only
            cout << vehicles[i]->toString() << endl;
        }
    }
}

int countData() {
    //simple check to see if file exist comm practice
    fstream file("07_vehicle_data.txt");
    if (!file) {
        cout << "Error opening file\n";
        return 0;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    file.close();
    return count;
}


//Nessary comment
// This program reads the data file line by line and creates objects one at a time.
// It works fine for now, but it is not very fast or efficient it would take way to long the longer the file is.

void readData(int vehicleCount) {
    //simple check to see if file exist comm practice
    ifstream file("07_vehicle_data.txt");
    if (!file) {
        cout << "Error opening file for reading data\n";
        return;
    }


    string line;
    // will stop at the line count amount we got from countdata
    for (int i = 0; i < vehicleCount; i++) {
        getline(file, line);
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

        if (type == "Truck") {
            int loadWeight = stoi(extra); // load weight is an int like vin
            vehicles[i] = new Truck(make, model, vin, loadWeight);// create truck
        } else if (type == "Car") {
            vehicles[i] = new Car(make, model, vin, extra);
            // cout << " Added Car -> " << vehicles[i]->toString() << endl;
        } else {
            vehicles[i] = new Vehicle();
            //default case

        }
    }

    file.close();
}