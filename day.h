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
    bool shortage;
    Day(int,int,int,int,int);
};

#endif // DAY_H
