#ifndef BCUDEFAULTLIST_H
#define BCUDEFAULTLIST_H

#include <QList>
#include "global.h"
class Database;

class BCUDefaultList
{
public:
    BCUDefaultList();
    void setSinkPort(QList<unsigned short int> &ports);
    void setSourcePort(QList<unsigned short int> &ports);
    void installDatabase(Database *database);
    void createList(bool bcu1Online, bool bcu2Online);
    void copyPort(unsigned short int sink, unsigned short int source);

private:
    Database *database;
    unsigned short int hmiBCU11, hmiBCU12, hmiBCU13, hmiBCU14;
    unsigned short int bcu11, bcu12, bcu13, bcu14;
    unsigned short int bcu21, bcu22, bcu23, bcu24;
};

#endif // BCUDEFAULTLIST_H
