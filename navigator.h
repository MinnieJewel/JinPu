#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "mybase.h"

class QPushButton;
class QVector<QPushButton>;

namespace Ui {
    class Navigator;
}

class Navigator : public MyBase
{
    Q_OBJECT

public:
    explicit Navigator(QWidget *parent = 0);
    ~Navigator();
    bool eventFilter(QObject *target, QEvent *event);
    QVector<QPushButton *>buttons;
    void updatePage();
    void setButtonsDisplay(QList<QString> buttonsName, QList<int> pageNo);
    void allButtonsDisplay();
    QList<int> pageNoList;

private:
    Ui::Navigator *ui;
    bool ifFirePage;
};

#endif // NAVIGATOR_H
