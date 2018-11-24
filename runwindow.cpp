#include "runwindow.h"
#include "ui_runwindow.h"

runwindow::runwindow(QWidget *parent,System sys) :
    QMainWindow(parent),
    ui(new Ui::runwindow)
{
    ui->setupUi(this);
    this->system = sys;



    QStringList lst;
    lst <<"Day"<<"Demand "<<"Lead Time"<<"Start Showroom"<<"Start Inventory"
       <<"End Showroom"<<"End Inventory"<<"Shortage";
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
     lstRes <<"Average Demand"<<"Average Order Lead Time"<<"Average Ending Showroom"<<"Average Ending Inventory"<<"Shortage Days";
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

void runwindow::on_demandLineBtn_clicked()
{


    QLineSeries *series = new QLineSeries();
    for(int i=0;i< system.days.size();i++ )
    {
        series->append(i+1,system.days[i].demand);
    }

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(1, system.days.size());
    axisX->setTickCount(1);
    //axisX->setLabelFormat("%.2f");

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Service Times");

    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setAxisX(axisX, series);
    chartView->chart()->removeAxis(axisX);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget * chartWindow = new QWidget(0);
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(chartView);
    setLayout(layout);
    layout->activate();

    chartWindow->resize(1000,400);
    chartWindow->show();

}

void runwindow::on_leadTimeBtn_clicked()
{


    QLineSeries *series = new QLineSeries();
    for(int i=0;i< system.days.size();i++ )
    {
        series->append(i+1,system.days[i].orderLeadTime);
    }

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(1, system.days.size());
    axisX->setTickCount(1);
    //axisX->setLabelFormat("%.2f");

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Service Times");

    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setAxisX(axisX, series);
    chartView->chart()->removeAxis(axisX);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget * chartWindow = new QWidget(0);
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(chartView);
    setLayout(layout);
    layout->activate();

    chartWindow->resize(1000,400);
    chartWindow->show();

}
