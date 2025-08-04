//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.



#include "Truck.h"
#include <sstream>
#include <iomanip>

//Default constructor
Truck::Truck() : Vehicle(), loadWeight(0) {}

//Param constructor
Truck::Truck(string make,string model,int vin , int loadWeight)
    : Vehicle(make,model,vin), loadWeight(loadWeight) {}

//getter and setter
int Truck::getLoadWeight() const{
  return loadWeight;
}

void Truck::setLoadWeight(int lWeight){
  loadWeight = lWeight;
}

string Truck::toString() const {
    ostringstream out;
    out << Vehicle::toString() << " " << setw(9) << loadWeight;
    return out.str();
}
