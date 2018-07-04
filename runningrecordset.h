#ifndef RUNNINGRECORDSET_H
#define RUNNINGRECORDSET_H

#include "mybase.h"

class QButtonGroup;
class QTimer;
namespace Ui {
    class RunningRecordSet;
}

class RunningRecordSet : public MyBase
{
    Q_OBJECT

public:
    explicit RunningRecordSet(QWidget *parent = 0);
    ~RunningRecordSet();

private:
    Ui::RunningRecordSet *ui;
    /*
    record which parameter to set
    setServiceKilometer:true;
    setRunningKilometer:false;
    */
    bool currentSet;
    QButtonGroup *buttonGroup, *buttonNoGroup, *buttonResetEnergyGroup;
    QTimer *timer, *resetTimer;
    QString serviceKilometers, runningKilometers;

private slots:
    void on_btn_back_clicked();
    void on_btn_confirm_clicked();
    void on_btn_clear_clicked();
    void onBtnClicked(int id);
    void onBtnNoClicked(int number);
    void resetFlag();
    void onResetEnergy(int number);
    void resetEngyFlag();
};

#endif // RUNNINGRECORDSET_H
