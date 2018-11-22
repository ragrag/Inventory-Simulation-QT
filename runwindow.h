#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QMainWindow>
#include "system.h"
namespace Ui {
class runwindow;
}

class runwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit runwindow(QWidget *parent = nullptr,System system = System());
    ~runwindow();

private:
    Ui::runwindow *ui;
    System system;
};

#endif // RUNWINDOW_H
