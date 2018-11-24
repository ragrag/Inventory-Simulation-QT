#include "chartwindow.h"
#include "ui_chartwindow.h"
#include <vector>
ChartWindow::ChartWindow(QWidget *parent,vector <System > runList) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);
    this->runList = runList;

}

ChartWindow::~ChartWindow()
{
    delete ui;
}









void ChartWindow::createHistogram(map<float,int> mp,string title) //Creating Histogram
{


    d_plot = new HistogramPlot( this,title ,mp );

    QWidget * chartWindow = new QWidget(0);
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(d_plot);
    setLayout(layout);
    layout->activate();

    chartWindow->resize(800,400);
    chartWindow->show();


}
   template<typename T> void ChartWindow::createPieChart(T mp,string title) //Creating Pie Chart
{

    QPieSeries *series = new QPieSeries();

    int maxN =-1;
    int idx;
    int it =0;
    for(auto v:mp)
    {
          series->append(QString::number(v.first), v.second);
        if(v.second > maxN)
        {
            maxN = v.second;
            idx = it;
        }
        it++;
    }



    QPieSlice *slice = series->slices().at(idx);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkRed, 2));
    slice->setBrush(Qt::darkRed);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString::fromStdString(title));
    //chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget * chartWindow = new QWidget(0);
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(chartView);
    setLayout(layout);
    layout->activate();

    chartWindow->resize(800,400);
    chartWindow->show();


}



template<typename T> void ChartWindow::createLineChart(T mp,string title) //Creating Line Chart
{
    QLineSeries *series = new QLineSeries();
    for(int i=0;i< mp.size();i++ )
    {
        series->append(i+1,mp[i]);
    }

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(1, mp.size());
    axisX->setTickCount(1);
    //axisX->setLabelFormat("%.2f");

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(QString::fromStdString(title));

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


template<typename T> void ChartWindow::createBarChart(T mp,string title) //Creating Bar Chart
{


    QBarSet *set0 = new QBarSet(QString::fromStdString(title));
    QStringList categories;


for (auto v:mp)
{
cout<<(float)v.first<<endl;
    *set0<<(float)v.second;
 categories<<QString::number((float)v.first);
}
QBarSeries *series = new QBarSeries();
   series->append(set0);

   QChart *chart = new QChart();
   chart->addSeries(series);
   chart->setTitle(QString::fromStdString(title));
   chart->setAnimationOptions(QChart::SeriesAnimations);


   QBarCategoryAxis *axis = new QBarCategoryAxis();
   axis->append(categories);
   chart->createDefaultAxes();
   chart->setAxisX(axis, series);
   chart->legend()->setVisible(true);
   chart->legend()->setAlignment(Qt::AlignBottom);
   QChartView *chartView = new QChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);


     QWidget * chartWindow = new QWidget(0);
     QVBoxLayout *layout = new QVBoxLayout(chartWindow);
     layout->addWidget(chartView);
     setLayout(layout);
     layout->activate();

     chartWindow->resize(800,400);
     chartWindow->show();


}




void ChartWindow::on_avgDemandHist_Btn_clicked()
{
    map <float,int> mp;
        for (auto v : runList)
        {
            mp[truncf(v.result.avgDemand*10)/10]++;
        }
        createHistogram(mp,"Demand");
}

void ChartWindow::on_avgLeadTimeHist_Btn_clicked()
{
    map <float,int> mp;
        for (auto v : runList)
        {
            mp[truncf(v.result.avgLeadTime*10)/10]++;
        }
        createHistogram(mp,"Order Lead Time");
}

void ChartWindow::on_avgShowroomHist_btn_clicked()
{
    map <float,int> mp;
        for (auto v : runList)
        {
            mp[v.result.avgEndingShowroom]++;
        }
        createHistogram(mp,"Ending Showroom");
}

void ChartWindow::on_avgInventoryHist_Btn_clicked()
{
    map <float,int> mp;
        for (auto v : runList)
        {
            mp[v.result.avgEndingInventory]++;
        }
        createHistogram(mp,"Ending Inventory");
}

void ChartWindow::on_shortageHist_Btn_clicked()
{
    map <float,int> mp;
        for (auto v : runList)
        {
            mp[v.result.shortageDays]++;
        }
        createHistogram(mp,"Shortage Days");
}





void ChartWindow::on_avgDemandBarBtn_clicked()
{
    map <float,int> mp;
    for (auto v : runList)
    {
        mp[truncf(v.result.avgDemand* 10) / 10]++;
    }
    createBarChart(mp,"Demand");
}

void ChartWindow::on_leadTimeBarBtn_clicked()
{
    map <float,int> mp;
    for (auto v : runList)
    {
        mp[truncf(v.result.avgLeadTime* 10) / 10]++;
    }
    createBarChart(mp,"Lead Time");
}

void ChartWindow::on_avgShowroomBarBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.avgEndingShowroom]++;
    }
    createBarChart(mp,"Ending Showroom");
}

void ChartWindow::on_avgInventoryHBarBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.avgEndingInventory]++;
    }
    createBarChart(mp,"Ending Inventory");
}

void ChartWindow::on_shortageBarBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.shortageDays]++;
    }
    createBarChart(mp,"Shortage Days");
}




void ChartWindow::on_avgDemandLine_Btn_clicked()
{

    vector <float> mp;
    for (auto v : runList)
    {
       mp.push_back(v.result.avgDemand);
    }

    createLineChart(mp,"Demand");
}


void ChartWindow::on_leadTimeLine_Btn_clicked()
{
    vector <float> mp;
    for (auto v : runList)
    {
       mp.push_back(v.result.avgLeadTime);
    }

    createLineChart(mp,"Order Lead Time");
}

void ChartWindow::on_avgShowroomLineBtn_clicked()
{
    vector <float> mp;
    for (auto v : runList)
    {
       mp.push_back(v.result.avgEndingShowroom);
    }

    createLineChart(mp,"Ending Show Room");
}

void ChartWindow::on_avgInventoryHLineBtn_clicked()
{
    vector <float> mp;
    for (auto v : runList)
    {
       mp.push_back(v.result.avgEndingInventory);
    }

    createLineChart(mp,"Ending Inventory");
}

void ChartWindow::on_shortageLineBtn_clicked()
{
    vector <float> mp;
    for (auto v : runList)
    {
       mp.push_back(v.result.shortageDays);
    }

    createLineChart(mp,"Shortage Days");
}




void ChartWindow::on_avgDemandPieBtn_clicked()
{
    map <float,int> mp;
     for (auto v : runList)
     {
         mp[truncf(v.result.avgDemand* 10) / 10]++;
     }
     createPieChart(mp,"Demand");
}

void ChartWindow::on_leadTimePieBtn_clicked()
{
    map <float,int> mp;
    for (auto v : runList)
    {
        mp[truncf(v.result.avgLeadTime* 10) / 10]++;
    }
    createPieChart(mp,"Lead Time");
}

void ChartWindow::on_avgShowroomPieBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.avgEndingShowroom]++;
    }
    createPieChart(mp,"Ending Showroom");
}

void ChartWindow::on_avgInventoryHPieBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.avgEndingInventory]++;
    }
    createPieChart(mp,"Ending Inventory");
}

void ChartWindow::on_shortagePieBtn_clicked()
{
    map <int,int> mp;
    for (auto v : runList)
    {
        mp[v.result.shortageDays]++;
    }
    createPieChart(mp,"Shortage Days");
}
