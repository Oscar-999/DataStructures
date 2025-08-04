//Oscar Alcantar
//Homework 10 -©raph Implementation
// Desciption: In this project, the data will still be read from a file. Instead of storing the objects in a linked
//list, they will be stored in a binary search tree.

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
