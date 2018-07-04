#ifndef BRAKESELFCHECKPAGE_H
#define BRAKESELFCHECKPAGE_H

#include "mybase.h"

namespace Ui {
    class BrakeSelfCheckPage;
}

class QLabel;
class QTimer;
class QButtonGroup;
class QPushButton;

class BrakeSelfCheckPage : public MyBase
{
    Q_OBJECT

public:
    explicit BrakeSelfCheckPage(QWidget *parent = 0);
    ~BrakeSelfCheckPage();
    void updatePage();
    void testState(QLabel *label, bool underWay, bool failure, bool succeed);

private:
    Ui::BrakeSelfCheckPage *ui;
    QTimer *timer;
   // QButtonGroup *vehicleNoGroup;
    QButtonGroup *detectModeGroup;
   // int vehicleNo;
    bool detectMode;
    int modeNo;

private slots:
    void on_btn_cease_clicked();
    void on_btn_start_clicked();
    void on_btn_exit_clicked();
    void setSelectedButton(int id);
    void setDetectFlag();
    void resetDetectFlag();
    void setToggleButton(bool checked);
};

#endif // BRAKESELFCHECKPAGE_H
