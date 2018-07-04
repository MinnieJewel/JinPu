#ifndef MAINTAINANCEPAGE_H
#define MAINTAINANCEPAGE_H

#include "mybase.h"

namespace Ui {
    class MaintainancePage;
}

class MaintainancePage : public MyBase
{
    Q_OBJECT

public:
    explicit MaintainancePage(QWidget *parent = 0);
    ~MaintainancePage();

private:
    Ui::MaintainancePage *ui;

private slots:
    void on_btn_historyRecord_clicked();
    void on_btn_RunningRecord_clicked();
    void on_btn_setRecord_clicked();
    void on_btn_RunningRecordClear_clicked();
    void on_btn_test_clicked();
    void on_btn_paraSet_clicked();
    void on_btn_mainpage_clicked();
};

#endif // MAINTAINANCEPAGE_H
