#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include "system.h"
#include "histogramplot.h"

#include <map>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <string>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qcombobox.h>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class ChartWindow;
}

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr, vector < System > runList = vector <System> ());
    ~ChartWindow();
    template<typename T>  void createPieChart( T mp,string  );
    template<typename T> void createBarChart(T mp,string title);
    template<typename T> void ChartWindow::createLineChart(T mp,string title);
    void createHistogram(map<float,int> mp,string title);

private slots:


    void on_avgDemandHist_Btn_clicked();

    void on_avgLeadTimeHist_Btn_clicked();

    void on_avgShowroomHist_btn_clicked();

    void on_avgInventoryHist_Btn_clicked();

    void on_shortageHist_Btn_clicked();

    void on_avgDemandBarBtn_clicked();

    void on_leadTimeBarBtn_clicked();

    void on_avgShowroomBarBtn_clicked();

    void on_avgInventoryHBarBtn_clicked();

    void on_shortageBarBtn_clicked();

    void on_avgDemandLine_Btn_clicked();

    void on_leadTimeLine_Btn_clicked();

    void on_avgShowroomLineBtn_clicked();

    void on_avgInventoryHLineBtn_clicked();

    void on_shortageLineBtn_clicked();

    void on_avgDemandPieBtn_clicked();

    void on_leadTimePieBtn_clicked();

    void on_avgShowroomPieBtn_clicked();

    void on_avgInventoryHPieBtn_clicked();

    void on_shortagePieBtn_clicked();

private:
    Ui::ChartWindow *ui;
    vector < System > runList;
    HistogramPlot *d_plot;
};

#endif // CHARTWINDOW_H
