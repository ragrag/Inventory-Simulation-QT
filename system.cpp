#include "system.h"


System::System()
{

}


System::System(vector<int> demand,vector<double> demandProbability,vector<int> leadTime,vector<double> leadTimeProbability, pair<int,int> initialOrder)
{
    this->demand = demand;
    this->demandProbability = demandProbability;
    this->leadTime = leadTime;
    this->leadTimeProbability = leadTimeProbability;
    memset(fill,0,sizeof(fill));
    this->initialOrder = initialOrder;
    fill[initialOrder.first]=initialOrder.second;
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

void System::buildSystem(int days, int carsShowroomStart,int carsInventoryStart,int reviewPeriod,int minimumInventory)
{
    this->days.clear();
     int reviewCounter = reviewPeriod;
     int currentLeadTime;
     memset(fill,0,sizeof(fill));
     fill[initialOrder.first]=initialOrder.second;
  for (int curDay=0;curDay<days;curDay++)
  {
        int carsShowroomCurrent =   curDay==0? carsShowroomStart : this->days.back().carsShowroomEnd;
        int carsInventoryCurrent = curDay==0? carsInventoryStart : this->days.back().carsInventoryEnd;
        currentLeadTime = 0;
        if(--reviewCounter==0)
        {
        reviewCounter = reviewPeriod;

        currentLeadTime = getLeadTime();
        this->days.push_back( Day((curDay+1),getDemand(),carsShowroomCurrent,carsInventoryCurrent,currentLeadTime,fill[curDay]));

        if(this->days.back().carsInventoryEnd<=minimumInventory)
            fill[curDay+currentLeadTime+1] = (4-this->days.back().carsShowroomEnd )+ (8-this->days.back().carsInventoryEnd);
        else this->days.back().orderLeadTime = 0;
        }
        else
            this->days.push_back( Day((curDay+1),getDemand(),carsShowroomCurrent,carsInventoryCurrent,currentLeadTime,fill[curDay]));
  }

}



int System::getDemand()
{
    int random = rand() % 100 + 1; //random number generation
    //Checking ranges and returning appropriate number
    for (int i = 0;i < cumulativeDemand.size();i++)
    {
        if (i == 0)
        {
            if (random >= 1 && random <= cumulativeDemand[i])
                return demand[i];
        }
        else if (random >cumulativeDemand[i-1] && random <= cumulativeDemand[i] ) {
            return demand[i];
        }
    }
    return -1;
}


int System::getLeadTime()
{

    int random = rand() % 100 + 1; //random number generation


    //checking ranges and returning appropriate number
    for (int i = 0;i < cumulativeLeadTime.size();i++)
    {
        if (i == 0)
        {
            if (random >= 1 && random <= cumulativeLeadTime[i])
            {
                return leadTime[i];
            }
        }
        else if (random >cumulativeLeadTime[i - 1] && random <= cumulativeLeadTime[i]) {
            return leadTime[i];
        }
    }
    return -1;
}

Result System::calculateSystem(){

    float endingShowroom = 0;
    float endingInventory =0;
    float shortageDays = 0;
    float demand =0;
    float leadTime = 0;
    int numberOfOrders = 0;
    for(auto day:days)
    {
        endingShowroom += day.carsShowroomEnd;
        endingInventory += day.carsInventoryEnd;
        shortageDays += (day.shortage? 1:0);
        demand+=day.demand;
        leadTime+=day.orderLeadTime;
        numberOfOrders += (day.orderLeadTime>0? 1:0);
    }



return result = Result(endingShowroom/days.size(),endingInventory/days.size(),shortageDays,demand/days.size(),leadTime/numberOfOrders);
}


