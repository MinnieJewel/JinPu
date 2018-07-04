#ifndef BROADCASTPAGE_H
#define BROADCASTPAGE_H

#include <mybase.h>

namespace Ui {
    class BroadCastPage;
}

class BroadCastPage : public MyBase
{
    Q_OBJECT

public:
    explicit BroadCastPage(QWidget *parent = 0);
    ~BroadCastPage();

private:
    Ui::BroadCastPage *ui;
};

#endif // BROADCASTPAGE_H
