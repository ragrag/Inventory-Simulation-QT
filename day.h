#ifndef DAY_H
#define DAY_H


class Day
{
public:
    int dayNumber;
    int demand;
    int carsInventoryStart;
    int carsShowroomStart;
    int carsInventoryEnd;
    int carsShowroomEnd;
    int orderLeadTime;
    bool shortage;
    Day(int,int,int,int,int,int);
    void offset();
    float operator[] (int i);
};

#endif // DAY_H
