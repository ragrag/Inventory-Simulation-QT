#include "probabilitytable.h"
#include "ui_probabilitytable.h"

probabilityTable::probabilityTable(QWidget *parent,System sys) :
    QMainWindow(parent),
    ui(new Ui::probabilityTable)
{
    ui->setupUi(this);



    this->system = sys;

     for(int i=0;i< max((int) system.demand.size(),(int)system.leadTime.size());i++)
     {
         for(int j=0;j<4;j++)
         {
             if(i<(int)system.demand.size()){
                 if(j==0)
                   ui->demandTable->setItem(i,j,new QTableWidgetItem(QString::number(system.demand[i])));
                 else if(j==1)
                    ui->demandTable->setItem(i,j,new QTableWidgetItem(QString::number(system.demandProbability[i])));
                 else if(j==2)
                    ui->demandTable->setItem(i,j,new QTableWidgetItem(QString::number(system.cumulativeDemand[i]/100)));

                 else
                        ui->demandTable->setItem(i,j,new QTableWidgetItem( i == 0 ?  "1 - " + QString::number(system.cumulativeDemand[i])  :  QString::number(system.cumulativeDemand[i - 1] + 1) + " - " + (i!=(system.demand.size()-1) ? QString::number(system.cumulativeDemand[i]) :"00")));
             }


             if(i<(int)system.leadTime.size()){
                 if(j==0)
                   ui->leadTimeTable->setItem(i,j,new QTableWidgetItem(QString::number(system.leadTime[i])));
                 else if(j==1)
                    ui->leadTimeTable->setItem(i,j,new QTableWidgetItem(QString::number(system.leadTimeProbability[i])));
                 else if(j==2)
                    ui->leadTimeTable->setItem(i,j,new QTableWidgetItem(QString::number(system.cumulativeLeadTime[i]/100)));

                 else
                        ui->leadTimeTable->setItem(i,j,new QTableWidgetItem( i == 0 ?  "1 - " + QString::number(system.cumulativeLeadTime[i])  :  QString::number(system.cumulativeLeadTime[i - 1] + 1) + " - " +( i!=(system.leadTime.size()-1) ? QString::number(system.cumulativeLeadTime[i]) : "00" )));
             }

         }

     }


}

probabilityTable::~probabilityTable()
{
    delete ui;
}
