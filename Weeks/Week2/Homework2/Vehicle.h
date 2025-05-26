//Oscar Alcantar
//Week1 Homework
//Description: Write a class and driver to implement functionality related to vehicles. Display a menu of
//options to the user, and implement the functionality to add, delete, and search for a
//vehicle, and to display all vehicles.

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;


class Vehicle {
    //Data memebers

private:
    string make;
    string model;
    int vin;
public:
    Vehicle();
    Vehicle(string make, string model, int vin);

    //setters
    void setMake(string make);
    void setModel(string model);
    void setVin(int vin);

    //getters
    string getMake() const;
    string getModel() const;
    int getVin() const;

    //Displays
    virtual string toString() const;
};



#endif //VEHICLE_H
