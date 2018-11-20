#include "system.h"


System::System(vector<int> demand,vector<double> demandProbability,vector<int> leadTime,vector<double> leadTimeProbability, int curLeadTime, int reviewPeriod)
{
    this->demand = demand;
    this->demandProbability = demandProbability;
    this->leadTime = leadTime;
    this->leadTimeProbability = leadTimeProbability;
    this->curLeadTime = curLeadTime;
    this->reviewPeriod = reviewPeriod;
    buildTables();
}

void System::buildTables() {
    cumulativeDemand.clear();
    cumulativeLeadTime.clear();
    for (int i = 0;i < max(demand.size(), leadTime.size());i++)
    {
        if (i <demand.size())
            cumulativeDemand.push_back(i == 0 ? demandProbability[0] * 100 : cumulativeDemand[i - 1] + demandProbability[i] * 100);
        if (i <leadTime.size())
            cumulativeLeadTime.push_back(i == 0 ? leadTimeProbability[0] * 100 : cumulativeLeadTime[i - 1] + leadTimeProbability[i] * 100);
    }
}

void System::buildSystem(int days, int carsShowRoomStart,int carsInventoryStart)
{





}
