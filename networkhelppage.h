#ifndef NETWORKHELPPAGE_H
#define NETWORKHELPPAGE_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
    class NetworkHelpPage;
}

class NetworkHelpPage : public MyBase
{
    Q_OBJECT

public:
    explicit NetworkHelpPage(QWidget *parent = 0);
    ~NetworkHelpPage();

private:
    Ui::NetworkHelpPage *ui;

private slots:


private slots:
    void on_btn_Back_clicked();
};

#endif // NETWORKHELPPAGE_H
