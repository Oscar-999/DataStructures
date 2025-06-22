// Oscar Alcantar
// Homework4 – Complexity Analysis Assignment
// Construct a program that computes the asymptotic complexity of an algorithm, using the
// technique of counting assignment and comparison statements
#include <iostream>
#include "BigO.h"

int main() {
    //P1
    BigO part1;
    int arr1[10] = {5,6,2};
    if (arr1[0]> arr1[1]) {}
    part1.updateTotalOperations(1);
    cout << "Part 1 – array size 10, comparison of first two values\n";
    cout << part1.getBigO(10) << "\n\n";


    //Part2 compute sum
    // Part 2 – Compute sum (size 10)
    BigO part2;
    int arr2[10] = {5,6,2,5,3,7,2,1,6,2};
    int sum2 = 0;
    part2.updateTotalOperations(1); // sum = 0
    for (int i = 0; i < 10; i++) {
        part2.updateTotalOperations(1); // loop comparison
        sum2 += arr2[i];
        part2.updateTotalOperations(1); // sum += arr2[i]
        part2.updateTotalOperations(1); // i++
    }
    cout << "Part 2 – array size 10, compute sum\n";
    cout << part2.getBigO(10) << "\n\n";

    //P3 compute sum of subarrays

    BigO part3;
    int arr3[10] = {5,6,2,5,3,7,2,1,6,2};
    int total3 = 0;
    part3.updateTotalOperations(1);
    for (int i = 0; i < 10; i++) {
        part3.updateTotalOperations(1); //outer loop com
        int sum = 0; // sum variable
        part3.updateTotalOperations(1); //sum =0
        part3.updateTotalOperations(1); //i++
        for (int j = 0; j <= i; j++) {
            part3.updateTotalOperations(1); // inner loop compar
            sum += arr3[j];
            part3.updateTotalOperations(1); // sum += arr[j]
            part3.updateTotalOperations(1); //i++
        }
        part3.updateTotalOperations(1); // inner loop final check
        total3 += sum;
        part3.updateTotalOperations(1); // total += sum
    }
    part3.updateTotalOperations(1); // outer loop check
    cout << "Part 3 – array size 10, compute sum of subarrays\n";
    cout << part3.getBigO(10) << "\n\n";

    //Part 4

    BigO part4;
    int arr4[100] = {5,6,2};
    if (arr4[0] != arr4[1]) {}
    part4.updateTotalOperations(1); //comparison
    cout << "Part 4 – array size 100, comparison of first two values\n";
    cout << part4.getBigO(100) << "\n\n";


    //Part5 compute sum

    BigO part5;
    int arr5[100] = {5,6,2,5,3,7,2,1,6,2};
    int sum5 = 0;
    part5.updateTotalOperations(1); // the sum assignment to 0
    for (int i = 0; i < 100; i++) {
        part5.updateTotalOperations(1); //loop comparison
        sum5 += arr5[i];
        part5.updateTotalOperations(1); // adding to sum
        part5.updateTotalOperations(1); //i++
    }
    cout << "Part 5 – array size 100, compute sum\n";
    cout << part5.getBigO(100) << "\n\n";

    //P6 compute sum of subarrays

    BigO part6;
    int arr6[100] = {5,6,2,5,3,7,2,1,6,2};
    int total6 = 0;
    part6.updateTotalOperations(1);
    for (int i = 0; i < 100; i++) {
        part6.updateTotalOperations(1); //outer loop com
        int sum = 0; // sum variable
        part6.updateTotalOperations(1); //sum =0
        part6.updateTotalOperations(1); //i++
        for (int j = 0; j <= i; j++) {
            part6.updateTotalOperations(1); // inner loop compar
            sum += arr6[j];
            part6.updateTotalOperations(1); // sum += arr[j]
            part6.updateTotalOperations(1); //i++
        }
        part6.updateTotalOperations(1); // inner loop final check
        total6 += sum;
        part6.updateTotalOperations(1); // total += sum
    }
    part6.updateTotalOperations(1); // outer loop check
    cout << "Part 6 – array size 100, compute sum of subarrays\n";
    cout << part6.getBigO(100) << "\n\n";



    return 0;
}