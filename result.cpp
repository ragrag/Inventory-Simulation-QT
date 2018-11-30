#include "result.h"
//This class has all the results along wtth over loaded operators to sum and devide to get the average

//Constructor 1
Result::Result()
{
    this->avgDemand=0;
    this->avgEndingInventory=0;
    this->avgEndingShowroom=0;
    this->avgLeadTime= 0;
    this->shortageDays = 0;
}


//Constructor 2
Result::Result( float avgEndingShowroom, float avgEndingInventory,float shortageDays,float avgDemand ,float avgLeadTime)
{
    this->avgDemand=avgDemand;
    this->avgEndingInventory=avgEndingInventory;
    this->avgEndingShowroom=avgEndingShowroom;
    this->avgLeadTime = avgLeadTime;
    this->shortageDays= shortageDays;
}



//Printing the results
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
  case 0: return avgDemand;
  case 1: return avgLeadTime;
  case 2: return avgEndingShowroom;
  case 3: return avgEndingInventory;
  case 4: return  shortageDays;
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


