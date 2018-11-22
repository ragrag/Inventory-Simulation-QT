#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <ctime>
using namespace std;

#include "system.h"



bool cmp( pair <int, pair <vector<System> ,Result> >   a ,pair <int, pair <vector<System> ,Result>   > b)
{
return a.second.second.shortageDays < b.second.second.shortageDays;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 srand(1);

    vector <int > d ={0,1,2,3,4} ;
    vector <double> dp = {0.05, 0.28, 0.37, 0.20, 0.10};
    vector <int> l = {1,2,3};
    vector <double> lp = {0.55 , 0.35, 0.10};

    System sys = System(d,dp,l,lp,make_pair(2,5));


    int days ,runs;
    days = 100;
    runs = 30;
vector <vector < pair <int, pair <vector<System> ,Result> >  > > runList(9);


    Result res;
    vector <System> systems;
    float shortage = 10e5;
    int minimumInventory;
for(int i=1;i<=8;i++)
{
    for(int j=1;j<=days;j++)
    {
        res =  Result();
        systems.clear();
        for(int i=0;i<runs;i++)
        {
            sys.buildSystem(days,4,2,j,i);
            systems.push_back(sys);
            res = res+sys.calculateSystem();
        }
        res = res/runs;
        if(res.shortageDays<shortage)
        {
            shortage = res.shortageDays;
            minimumInventory = i;
        }
        runList[i].push_back(make_pair(j,make_pair(systems,res)));
    }
    sort(runList[i].begin(),runList[i].end(),cmp);
}

cout<<"Shortage : "<<shortage<<endl<<"Min inventory threshold : "<<minimumInventory<<endl<<"Minimum Review Period : "<<runList[minimumInventory][0].first<<endl;
runList[minimumInventory][0].second.second.print();
cout<<endl;

cout<<"ALL "<<endl;

for(int i=1;i<=8;i++)
{
    cout<<"Min Threshold: "<<i<<endl;
for(int j=0;j<3;j++)
{
cout<<j+1<<" : "<<runList[i][j].second.second.shortageDays<<" When review period is "<<runList[i][j].first<<endl;
}

}
    MainWindow w;
    w.show();

    return a.exec();
}
