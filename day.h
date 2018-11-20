#ifndef DAY_H
#define DAY_H


class Day
{
public:
    int demand;
    int carsInventoryStart;
    int carsShowroomStart;
    int carsInventoryEnd;
    int carsShowroomEnd;
    int orderLeadTime;
    bool shortage;
    Day(int,int,int,int,int);
    void offset();
};

#endif // DAY_H
