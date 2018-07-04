#ifndef TIMESETPAGE_H
#define TIMESETPAGE_H

#include "mybase.h"

class QTimer;
class QButtonGroup;
namespace Ui {
    class TimeSetPage;
}

class TimeSetPage : public MyBase
{
    Q_OBJECT

public:
    explicit TimeSetPage(QWidget *parent = 0);
    ~TimeSetPage();
    void updatePage();
    void showEvent(QShowEvent *);


public slots:
    void mykeyPressEvent();
    void setSelectedButton(int index);
    void resetHmiSetTimeCommand();
    void setHmiSetTimeCommand();
    void setTimeCommand();
private:
    Ui::TimeSetPage *ui;
    int counter;
    int year, month, day, hour, minute, second;
    QTimer *timer, *counterTimer;
    QButtonGroup *pushButtonGroup;
};

#endif // TIMESETPAGE_H
