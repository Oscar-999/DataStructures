//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.


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

void Car::setBodyStyle(string body) {
  bodyStyle = body;
}

string Car::getBodyStyle() const {
  return bodyStyle;
}

string Car::toString() const {
    ostringstream out;
    out << Vehicle::toString() << " " << setw(9) << bodyStyle;
    return out.str();
}