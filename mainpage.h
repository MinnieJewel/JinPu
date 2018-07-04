#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "mybase.h"

class VehicleLogo;
class Panel;
class QLabel;
namespace Ui {
    class MainPage;
}

class MainPage : public MyBase
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();
    void updatePage();
    Panel *speedPanel;
    void judgeIdle(QLabel *label, bool idle, bool ebSlide);
    void judgeSlide(QLabel *label, bool slide);
    void setMode(int mode);
    void setBHB(bool bhbState);

private:
    Ui::MainPage *ui;
    VehicleLogo *vehicleLogo;

private slots:
    void on_btn_EmergencyBroadcast_clicked();
};

#endif // MAINPAGE_H
