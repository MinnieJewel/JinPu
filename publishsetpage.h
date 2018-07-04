#ifndef PUBLISHSETPAGE_H
#define PUBLISHSETPAGE_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
    class PublishSetPage;
}

class PublishSetPage : public MyBase
{
    Q_OBJECT

public:
    explicit PublishSetPage(QWidget *parent = 0);
    ~PublishSetPage();

private:
    Ui::PublishSetPage *ui;



private slots:
    void on_btn_Back_clicked();
    void on_btn_Restart_clicked();
    void on_btn_Tc2_clicked();
    void on_btn_Tc1_clicked();

public:
    void showEvent(QShowEvent *);
};

#endif // PUBLISHSETPAGE_H
