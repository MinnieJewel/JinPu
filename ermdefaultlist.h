#ifndef ERMDEFAULTLIST_H
#define ERMDEFAULTLIST_H
#include <QList>
#include "global.h"

class Database;
class ErmDefaultList
{
public:
    ErmDefaultList();
    void setSinkPort(QList<unsigned short int> &ports);
    void setSourcePort(QList<unsigned short int> &ports);
    void installDatabase(Database *database);
    void createList();
    void copyPort(unsigned short int sink, unsigned short int source);

private:
    Database *database;
    unsigned short int hmiERM1, hmiERM2, hmiERM3, hmiERM4;
    unsigned short int erm11, erm12, erm13, erm14, erm21, erm22, erm23, erm24;
};

#endif // ERMDEFAULTLIST_H
