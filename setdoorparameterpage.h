#ifndef SETDOORPARAMETERPAGE_H
#define SETDOORPARAMETERPAGE_H

#include <QWidget>

namespace Ui {
    class SetDoorParameterPage;
}

class SetDoorParameterPage : public QWidget
{
    Q_OBJECT

public:
    explicit SetDoorParameterPage(QWidget *parent = 0);
    ~SetDoorParameterPage();

private:
    Ui::SetDoorParameterPage *ui;
};

#endif // SETDOORPARAMETERPAGE_H
