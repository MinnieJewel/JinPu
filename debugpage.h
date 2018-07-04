#ifndef DEBUGPAGE_H
#define DEBUGPAGE_H

#include "mybase.h"

namespace Ui {
    class DebugPage;
}

class DebugPage : public MyBase
{
    Q_OBJECT

public:
    explicit DebugPage(QWidget *parent = 0);
    ~DebugPage();

private:
    Ui::DebugPage *ui;

private slots:
    void on_btn_DataMoniter_clicked();
    void on_btn_versionInfo_clicked();
    void on_btn_PublishSet_clicked();
    void on_btn_RIOMDebug_clicked();
    void on_btn_LifeSignal_clicked();
    void on_btn_RIOMDetailInfo_clicked();
    void on_btn_Back_clicked();
};

#endif // DEBUGPAGE_H
