#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "system.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include "runwindow.h"
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display(int , int,int,int);
    void clear();

private slots:
    void on_beginSimulationBtn_clicked();

    void on_customRunsCheckbox_toggled(bool checked);


    void on_selectMinimumThreshold_clicked();

    void on_viewReviewPeriod_Btn_clicked();

    void on_viewRun_Btn_clicked();

private:
    Ui::MainWindow *ui;
    runwindow *runWindowObj;
    vector <vector < pair <int, pair <vector<System> ,Result> >  > > runList;
    vector <vector < pair <int, pair <vector<System> ,Result> >  > > runListUnsorted;
    int days;
    int runs;
    int minimumThreshold;
    int reviewPeriod;
};

#endif // MAINWINDOW_H
