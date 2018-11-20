#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

#include "system.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    vector <int > d ={0,1,2,3,4} ;
    vector <double> dp = {0.05, 0.28, 0.37, 0.20, 0.10};
    vector <int> l = {1,2,3};
    vector <double> lp = {0.55 , 0.35, 0.10};

    System sys = System(d,dp,l,lp,make_pair(2,5),1);

    Result res= Result();

for(int i=0;i<30;i++)
{
    sys.buildSystem(100,4,2);

    res = res+sys.calculateSystem();
}
res = res/30;
res.print();

    MainWindow w;
    w.show();

    return a.exec();
}
