#ifndef ALLPORTS_H
#define ALLPORTS_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
    class AllPorts;
}

class QLabel;
class QTableWidget;
class QFont;

enum vehicle
{
    ubtnTc1,
    ubtnMp1,
    ubtnMp2,
    ubtnTc2
};

class AllPorts : public MyBase
{
    Q_OBJECT

public:
    explicit AllPorts(QWidget *parent = 0);
    ~AllPorts();

    void initialTableView(QTableWidget *table);
    void setTableView(QTableWidget *table, QList<QString> channelNoList, QList<QString> channelNameList);
    void setAXTableView();
    void hideAllTable();
    void cleanContent(QTableWidget *table);
    void updatePage();

    void updateDio(QTableWidget *table, QList<bool> &state);
    void updateAx(QTableWidget *table, QList<QString> &state);

    void initialView();
    void updateButton(int currentVehicle);
    int page;

private:
    Ui::AllPorts *ui;
    QTableWidget *riomDI1InfoTable;
    QTableWidget *riomDI2InfoTable;
    QTableWidget *riomDI3InfoTable;
    QTableWidget *riomDI4InfoTable;
    QTableWidget *riomDO1InfoTable;
    QTableWidget *riomAXInfoTable;
    QList<QString> listDI;
    QList<QString> listDO;
    QList<QString> listAX;
    QList<QString> a1DI1List;
    QList<QString> a1DI2List;
    QList<QString> a1DI3List;
    QList<QString> a1DI4List;
    QList<QString> a1DOList;
    QList<QString> a1AXList;

    QList<QString> b1DIList;
    QList<QString> b1DOList;

    QList<QString> c1DIList;
    QList<QString> c1DOList;
    enum vehicle currentVehicle;

private slots:
    void myKeyPress();
};

#endif // ALLPORTS_H
