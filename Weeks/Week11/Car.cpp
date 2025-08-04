//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.


#include "Car.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// default constructor
Car::Car() : Vehicle(), bodyStyle("") {}

// 4 param constructor
Car::Car(string make, string model, int vin, string bodyStyle)
    : Vehicle(make, model , vin), bodyStyle(bodyStyle) {}

//getter and setter
void Car::setBodyStyle(string body) {
  bodyStyle = body;
}

string Car::getBodyStyle() const {
  return bodyStyle;
}

string Car::toString() const {
    ostringstream out;
    out << Vehicle::toString() << " " << setw(10) << bodyStyle;
    return out.str();
}