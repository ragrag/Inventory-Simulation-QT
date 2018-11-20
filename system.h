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
    int curLeadTime;
    int reviewPeriod;
    Result result;

    System(vector<int>,vector<double>,vector<int>,vector<double>,int ,int,int carsShowroomStart = 4,int carsInventoryStart=8);
    void buildTables();
};

#endif // SYSTEM_H
