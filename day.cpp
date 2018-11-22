#include "day.h"

Day::Day(int dayNumber,int demand,int carsShowroomStart,int carsInventoryStart,int orderLeadTime, int fill)
{
    this->dayNumber = dayNumber;
    this->demand=demand;
    this->carsShowroomStart = carsShowroomStart+fill;
    this->carsInventoryStart = carsInventoryStart;
    this->orderLeadTime = orderLeadTime;
    this->shortage = false;
    offset();
    if(demand > (this->carsShowroomStart+this->carsInventoryStart))
    {
        this->carsShowroomEnd = 0;
        this->carsInventoryEnd = 0;
        shortage = true;
    }
    else {
        if(this->carsInventoryStart >= demand )
        {
            this->carsShowroomEnd = this->carsShowroomStart;
            this->carsInventoryEnd = this->carsInventoryStart-demand;
        }
        else {
            this->carsShowroomEnd = this->carsShowroomStart - (demand - this->carsInventoryStart);
            this->carsInventoryEnd = 0;
        }
    }
}

void Day::offset(){

if(carsShowroomStart >4)
{
    carsInventoryStart+= (carsShowroomStart-4);
    carsShowroomStart = 4;
}
if(carsInventoryStart > 8)
    carsInventoryStart = 8;
}


//Return value by order
float Day::operator[] (int i)
{
  switch (i) {
    case 0: return dayNumber;
    case 1: return demand;
    case 2: return orderLeadTime;
    case 3: return carsShowroomStart;
    case 4: return carsInventoryStart;
    case 5: return carsShowroomEnd;
    case 6: return carsInventoryEnd;
    case 7: return shortage;
    default: return -1;
  }
}
