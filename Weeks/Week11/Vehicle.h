//Oscar Alcantar
//Homework 16 - Sorting
// Description: Implement a sorting algorithm

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
