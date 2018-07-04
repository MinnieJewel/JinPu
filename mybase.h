#ifndef MYBASE_H
#define MYBASE_H
#include <QWidget>
#include <global.h>
#include "database.h"
class MyBase : public QWidget
{
    Q_OBJECT
public:
    explicit MyBase(QWidget *parent = 0);
    virtual void updatePage();
    static int currentPage;
    static Database *database;
    QString name;

    //display navigator dynamically
    QList <QString> navigatorList;
    QList <int> navigatorPageNo;

    //for header and navigator pages
    void setMyBase(enum pagePosition position, QString name);
    //for other pages
    void setMyBase(QString name,QList<QString> navigatorList, QList<int> navigatorPageNo);

    void setFullScreen();
    bool getFullScreen();

    void setInnerHeader();
    bool getInnerHeader();

    void setNoneNavigator();
    bool getNoneNavigator();

public slots:
signals:
    void changePage(int);

private:
        bool ifFullScreen;
        bool ifInnerHeader;
        bool ifNoneNavigator;
};

#endif // MYBASE_H
