// Oscar Alcantar
// Homework4 – Complexity Analysis Assignment
// Construct a program that computes the asymptotic complexity of an algorithm, using the
// technique of counting assignment and comparison statements

#ifndef BIGO_H
#define BIGO_H
#include <string>
using namespace std;


class BigO {
  private:
    int totalOperations; //t operation count
  public:
    BigO();
    void updateTotalOperations(int value); //add to total opeations
    string getBigO(int n) const; //return Big0 as string
    void reset();

};



#endif
