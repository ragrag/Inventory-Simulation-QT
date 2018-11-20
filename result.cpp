#include "result.h"

Result::Result()
{
    this->avgDemand=0;
    this->avgEndingInventory=0;
    this->avgEndingShowroom=0;
    this->avgLeadTime= 0;
    this->shortageDays = 0;
}


Result::Result( float avgEndingShowroom, float avgEndingInventory,float shortageDays,float avgDemand ,float avgLeadTime)
{
    this->avgDemand=avgDemand;
    this->avgEndingInventory=avgEndingInventory;
    this->avgEndingShowroom=avgEndingShowroom;
    this->avgLeadTime = avgLeadTime;
    this->shortageDays= shortageDays;
}


void Result::print()
{
   cout<< this->avgEndingShowroom<<endl<<
    this->avgEndingInventory<<endl<<
    this->shortageDays<<endl<<
    this->avgDemand<<endl<<
    this->avgLeadTime<<endl;
}



//Get by order
float Result::operator[] (int i)
{
  switch (i) {
  case 0: return avgEndingShowroom;
  case 1: return  avgEndingInventory;
  case 2: return shortageDays;
  case 3: return avgDemand;
  case 4: return avgLeadTime;
  default: return -1;
  }
}

//Overloaded + operator for adding results together
Result Result::operator+(Result other)
{

    return Result(   avgEndingShowroom+other.avgEndingShowroom ,
                     avgEndingInventory+other.avgEndingInventory ,shortageDays +other.shortageDays
                     , avgDemand+other.avgDemand , avgLeadTime+other.avgLeadTime );

}

//Overloaded / operator for deviding a result by a number
Result Result::operator/(int n)
{
    return Result(avgEndingShowroom/n , avgEndingInventory/n, shortageDays / n, avgDemand / n, avgLeadTime/n);
}


