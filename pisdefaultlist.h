#ifndef PISDEFAULTLIST_H
#define PISDEFAULTLIST_H

#include <QList>
#include "global.h"

class Database;
class PISDefaultList
{
public:
    PISDefaultList();
    void setSinkPort(QList<unsigned short int> &ports);
    void setSourcePort(QList<unsigned short int> &ports);
    void installDatabase(Database *database);
    void createList(bool pis1Online, bool pis2Online);
    void copyPort(unsigned short int sink, unsigned short int source);

private:
    Database *database;
    unsigned short int hmiPIS1, hmiPIS2;
    unsigned short int pis11, pis12, pis21, pis22;
};

#endif // PISDEFAULTLIST_H
