// Oscar Alcantar
// Homework4 – Complexity Analysis Assignment
// Construct a program that computes the asymptotic complexity of an algorithm, using the
// technique of counting assignment and comparison statements

#include "BigO.h"
#include <cmath>
#include <string>
using namespace std;
BigO::BigO() {
  totalOperations = 0;
 }

 void BigO::updateTotalOperations(int value) {
   totalOperations += value;
 }

 string BigO::getBigO(int n) const {
   //invalid inputs
   if (n <= 1 || totalOperations <= 0) {
     return "Asymptotic complexity is O(n^0)";
     }// This is 0(1) if there is only one input or if there are no operatioms

   int exponent = (int) round(log10(totalOperations)/ log10(n));
   return "Asymptotic complexity is O(n^" + to_string(exponent) + ")";
 }

