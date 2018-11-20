#include "day.h"

Day::Day(int demand,int cis,int css,int cie,int cse)
{
    this->demand=demand;
    this->carsInventoryStart = cis;
    this->carsShowroomStart = css;
    this->carsInventoryEnd = cie;
    this->carsShowroomEnd = cse;

}
