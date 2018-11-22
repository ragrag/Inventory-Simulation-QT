#include "runwindow.h"
#include "ui_runwindow.h"

runwindow::runwindow(QWidget *parent,System sys) :
    QMainWindow(parent),
    ui(new Ui::runwindow)
{
    ui->setupUi(this);
    this->system = sys;



    QStringList lst;
    lst <<"Day"<<"Demand "<<"Lead Time"<<"Starting Cars Showroom"<<"Starting Cars Inventory"
       <<"Ending Cars Showroom"<<"Ending Cars Inventory"<<"Shortage";
     ui->calendarTable->setColumnCount(8);
     ui->calendarTable->setRowCount((int)system.days.size());
     ui->calendarTable->setHorizontalHeaderLabels(lst);
     ui->calendarTable->verticalHeader()->setVisible(false);



     for(int i=0;i<(int)system.days.size();i++)
     {
         for(int j=0;j<8;j++)
         {
            ui->calendarTable->setItem(i,j,new QTableWidgetItem(QString::number(system.days[i][j])));
         }

     }



     QStringList lstRes;
     lstRes <<"Average Demand"<<"Average Order Lead Time"<<"Average Ending Showroom"<<"Average Ending Inside"<<"Shortage Days";
      ui->resultsTable->setColumnCount(1);
      ui->resultsTable->setRowCount(5);
      ui->resultsTable->setVerticalHeaderLabels(lstRes);
      for(int i=0;i<5;i++)
      {
          ui->resultsTable->setItem(i,0,new QTableWidgetItem( QString::number(system.result[i]) ));
      }
      ui->resultsTable->horizontalHeader()->setVisible(false);








}

runwindow::~runwindow()
{
    delete ui;
}
