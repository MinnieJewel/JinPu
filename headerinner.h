#ifndef HEADERINNER_H
#define HEADERINNER_H

#include "mybase.h"
class QTimer;
namespace Ui {
    class HeaderInner;
}

class HeaderInner :public MyBase
{
    Q_OBJECT

public:
    explicit HeaderInner(QWidget *parent = 0);
    ~HeaderInner();
    void updatePage();
    void setPageName(QString name);

private:
    Ui::HeaderInner *ui;
};

#endif // HEADERINNER_H
