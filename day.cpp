#include "day.h"

Day::Day(int demand,int carsShowroomStart,int carsInventoryStart,int orderLeadTime, int fill)
{
    this->demand=demand;
    this->carsShowroomStart = carsShowroomStart+fill;
    this->carsInventoryStart = carsInventoryStart;
    this->orderLeadTime = orderLeadTime;
    this->shortage = false;
    offset();
    if(demand > carsShowroomStart+carsInventoryStart)
    {
        carsShowroomEnd = 0;
        carsInventoryEnd = 0;
        shortage = true;
    }
    else {
        if(carsInventoryStart >= demand )
        {
            carsShowroomEnd = carsShowroomStart;
            carsInventoryEnd = carsInventoryStart-demand;
        }
        else {
            carsShowroomEnd = demand - carsInventoryStart;
            carsInventoryEnd = 0;
        }
    }
}

void Day::offset(){

if(carsShowroomStart >4)
{
    carsInventoryStart+= carsShowroomStart-4;
    carsShowroomStart = 4;
}
if(carsInventoryStart > 8)
    carsInventoryStart = 8;
}

