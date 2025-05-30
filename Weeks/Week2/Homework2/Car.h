//Oscar Alcantar
//Week 2 Homework
//Description: Write a program that implements a simple inheritance hierarchy related to vehicles.



#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;
#include "Vehicle.h"


class Car : public Vehicle  {
private:
  string bodyStyle;
  public:

    //Default constructor
    Car();
    // 4parm constructor
    Car(string make, string model, int vin , string bodyStyle);
    //get and setters
    string getBodyStyle() const;
    void setBodyStyle(string bodyStyle);
    string toString() const override;
};



#endif //CAR_H
