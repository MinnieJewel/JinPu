#ifndef TESTPAGE_H
#define TESTPAGE_H

#include "mybase.h"

namespace Ui {
    class TestPage;
}

class TestPage : public MyBase
{
    Q_OBJECT

public:
    explicit TestPage(QWidget *parent = 0);
    ~TestPage();

private:
    Ui::TestPage *ui;

private slots:
    void on_btn_speedTest_clicked();
    void on_btn_driverTest_clicked();
    void on_btn_back_clicked();
    void on_btn_breakTest_clicked();
    void on_btn_tractionTest_clicked();
};

#endif // TESTPAGE_H
