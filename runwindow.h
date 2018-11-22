#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QMainWindow>

namespace Ui {
class runwindow;
}

class runwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit runwindow(QWidget *parent = nullptr);
    ~runwindow();

private:
    Ui::runwindow *ui;
};

#endif // RUNWINDOW_H
