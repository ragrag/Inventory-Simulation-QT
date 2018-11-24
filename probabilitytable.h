#ifndef PROBABILITYTABLE_H
#define PROBABILITYTABLE_H

#include <QMainWindow>
#include "system.h"
namespace Ui {
class probabilityTable;
}

class probabilityTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit probabilityTable(QWidget *parent = nullptr,System sys=System());
    ~probabilityTable();

private:
    Ui::probabilityTable *ui;
    System system;
};

#endif // PROBABILITYTABLE_H
