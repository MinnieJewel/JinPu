#ifndef NAVIGATORINNER_H
#define NAVIGATORINNER_H

#include <QWidget>

namespace Ui {
    class NavigatorInner;
}

class NavigatorInner : public QWidget
{
    Q_OBJECT

public:
    explicit NavigatorInner(QWidget *parent = 0);
    ~NavigatorInner();

private:
    Ui::NavigatorInner *ui;
};

#endif // NAVIGATORINNER_H
