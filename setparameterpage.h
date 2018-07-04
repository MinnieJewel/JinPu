#ifndef SETPARAMETERPAGE_H
#define SETPARAMETERPAGE_H

#include "mybase.h"

namespace Ui {
    class SetParameterPage;
}

class SetParameterPage : public MyBase
{
    Q_OBJECT

public:
    explicit SetParameterPage(QWidget *parent = 0);
    ~SetParameterPage();

private:
    Ui::SetParameterPage *ui;

private slots:
    void on_btn_tractionIsolate_clicked();
    void on_btn_setVehicleNo_clicked();
    void on_pushButton_3_clicked();
    void on_btn_setTime_clicked();
    void on_btn_Back_clicked();
    void on_btn_wheelDia_clicked();
};

#endif // SETPARAMETERPAGE_H
