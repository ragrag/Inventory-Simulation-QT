#ifndef SYSTEM_H
#define SYSTEM_H


#include <vector>
#include <algorithm>
#include "day.h"
#include "result.h"

using namespace std;


class System
{
public:
    vector <int> demand;
    vector <double> demandProbability;
    vector <int> leadTime;
    vector <double> leadTimeProbability;
    vector <double> cumulativeDemand;
    vector <double> cumulativeLeadTime;
    vector <Day> days;
    pair<int,int> initialOrder;
    int fill[101];


    Result result;

    System();
    System(vector<int>,vector<double>,vector<int>,vector<double>,pair<int,int>);
    void buildTables();
    void buildSystem(int, int carsShowroomStart = 4,int carsInventoryStart=8,int reviewPeriod=0,int minimumInventoru = 0);
    int getDemand();
    int getLeadTime();
    Result calculateSystem();
};

#endif // SYSTEM_H
