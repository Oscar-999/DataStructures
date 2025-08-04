//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.


#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"


class Truck : public Vehicle {
  private:
    int loadWeight = 0;
    public:

    Truck();
    Truck(string make, string model, int vin, int loadWeight);

    int getLoadWeight() const;
    void setLoadWeight(int loadWeight);

    string toString() const override;



};



#endif //TRUCK_H
