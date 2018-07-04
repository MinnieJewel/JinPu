#ifndef HEADER_H
#define HEADER_H

#include "mybase.h"
class QTimer;
class CrrcFault;

namespace Ui {
    class Header;
}

class Header : public MyBase
{
    Q_OBJECT

public:
    explicit Header(QWidget *parent = 0);
    ~Header();


    void updatePage();
    void setDirection(bool direction);
    void setNetVoltage(int voltage);
    void setNetCurrent(int current);
    void setSpeed(double speed);
    void setLevel(int level);
    void setPageName(QString name);
    void setCurrentStation(unsigned char station);
    void installCrrcFault(CrrcFault *crrcFault);

private:
    Ui::Header *ui;
    CrrcFault *crrcFault;
    QList<QString> levelList;


private slots:
    void on_faultButton_clicked();
};

#endif // HEADER_H
