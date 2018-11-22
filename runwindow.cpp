#include "runwindow.h"
#include "ui_runwindow.h"

runwindow::runwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::runwindow)
{
    ui->setupUi(this);
}

runwindow::~runwindow()
{
    delete ui;
}
