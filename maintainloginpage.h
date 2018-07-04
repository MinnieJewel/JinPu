#ifndef MAINTAINLOGINPAGE_H
#define MAINTAINLOGINPAGE_H

#include "mybase.h"

namespace Ui {
    class MaintainLoginPage;
}

class MaintainLoginPage : public MyBase
{
    Q_OBJECT

public:
    explicit MaintainLoginPage(QWidget *parent = 0);
    ~MaintainLoginPage();
    void showEvent(QShowEvent *);
    void setPassword(QString password);

public slots:
    void keyboardEvent();


private:
    Ui::MaintainLoginPage *ui;
    QString password, input;
    int targetPage;
};

#endif // MAINTAINLOGINPAGE_H
