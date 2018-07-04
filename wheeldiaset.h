#ifndef WHEELDIASET_H
#define WHEELDIASET_H

#include "mybase.h"

class QButtonGroup;
class QTimer;
namespace Ui {
    class WheelDiaSet;
}

class WheelDiaSet : public MyBase
{
    Q_OBJECT

public:
    explicit WheelDiaSet(QWidget *parent = 0);
    ~WheelDiaSet();
    void showEvent(QShowEvent *);
    void updatePage();

private:
    Ui::WheelDiaSet *ui;
    QButtonGroup *buttonGroup;
    int counter;
    QList<bool> modifyButtonNos;
    QTimer *timer;
    void setWheelDiameter();
    bool checkValue();

public slots:
    void setSelectedButton(int index);
    void mykeyPressEvent();
    void resetHmiSetWheelDiaCommand();
};

#endif // WHEELDIASET_H
