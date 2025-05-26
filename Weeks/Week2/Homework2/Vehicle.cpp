//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.


#include "Vehicle.h"
#include <iomanip>
#include <sstream>
using namespace std;
#include <string>
//Default con

Vehicle::Vehicle() {vin = 0;}

//3 param
Vehicle::Vehicle(string m, string mod, int vi) {
    make = m;
    model = mod;
    vin = vi;
}

//setters
void Vehicle::setMake(string m) {
    make = m;
}
void Vehicle::setModel(string m) {
    model = m;
}
void Vehicle::setVin(int v) {
    vin = v;
}

//getter

string Vehicle::getMake() const{
    return make;
}

string Vehicle::getModel() const{
    return model;
}

int Vehicle::getVin() const{
    return vin;
}

//Format output
string Vehicle::toString() const {
    stringstream ss;
    ss << left << setw(20) << make
          << setw(15) << model
          << setw(5) << setfill('0') << vin;
    return ss.str();
}
