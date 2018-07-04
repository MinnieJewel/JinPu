#ifndef EDCUDEFAULTLIST_H
#define EDCUDEFAULTLIST_H
#include <QList>
#include "global.h"
class Database;

class EdcuDefaultList
{
public:

    EdcuDefaultList();
    void setSinkPort(QList<unsigned short int> &ports);
    void setSourcePort(QList<unsigned short int> &ports);
    void installDatabase(Database *database);
    void createList(bool edcu1Online, bool edcu2Online, QList<int> &doorsOnLine);
    void copyPort(unsigned short int sink, unsigned short int source);

private:
    Database *database;
    unsigned short int hmiEdcu11, hmiEdcu12, hmiEdcu13;
    unsigned short int edcu11, edcu12, edcu13;
    unsigned short int edcu21, edcu22, edcu23;
};

#endif // EDCUDEFAULTLIST_H
