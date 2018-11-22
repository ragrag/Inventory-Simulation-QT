#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <ctime>
using namespace std;

#include "system.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
