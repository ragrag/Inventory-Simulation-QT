#ifndef RESULT_H
#define RESULT_H
#include <iostream>
using namespace std;
class Result
{
public:
    float avgEndingShowroom;
    float avgEndingInventory;
    float shortageDays;
    float avgDemand;
    float avgLeadTime;
    Result();
    Result(float, float, float , float, float);
    void print();
    Result operator+(Result);
    Result operator/(int);
    float operator[] (int i);
};

#endif // RESULT_H
