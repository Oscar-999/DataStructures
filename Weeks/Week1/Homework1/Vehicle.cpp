//Oscar Alcantar
//Week1 Homework
//Description: Write a class and driver to implement functionality related to vehicles. Display a menu of
//options to the user, and implement the functionality to add, delete, and search for a
//vehicle, and to display all vehicles.


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
  ss << left << setw(10) << make
        << setw(10) << model
        << setw(5) << setfill('0') << vin;
  return ss.str();
}

