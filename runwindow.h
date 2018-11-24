#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QMainWindow>
#include "system.h"
#include <vector>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>


QT_CHARTS_USE_NAMESPACE
namespace Ui {
class runwindow;
}

class runwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit runwindow(QWidget *parent = nullptr,System system = System());
    ~runwindow();

private slots:
    void on_demandLineBtn_clicked();

    void on_leadTimeBtn_clicked();

private:
    Ui::runwindow *ui;
    System system;
};

#endif // RUNWINDOW_H
