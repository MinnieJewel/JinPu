#include "bcudefaultlist.h"
#include "database.h"
#include <QDebug>

BCUDefaultList::BCUDefaultList()
{
    this->database = NULL;
}


void BCUDefaultList::setSinkPort(QList<unsigned short> &ports)
{
    if (ports.size() != 4)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->hmiBCU11 = ports.at(0);
        this->hmiBCU12 = ports.at(1);
        this->hmiBCU13 = ports.at(2);
        this->hmiBCU14 = ports.at(3);
    }
}

void BCUDefaultList::setSourcePort(QList<unsigned short> &ports)
{
    if (ports.size() != 8)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->bcu11 = ports.at(0);
        this->bcu12 = ports.at(1);
        this->bcu13 = ports.at(2);
        this->bcu14 = ports.at(3);

        this->bcu21 = ports.at(4);
        this->bcu22 = ports.at(5);
        this->bcu23 = ports.at(6);
        this->bcu24 = ports.at(7);
    }
}

void BCUDefaultList::installDatabase(Database *database)
{
    this->database = database;
}

void BCUDefaultList::copyPort(unsigned short sink, unsigned short source)
{
    for (int i = 0; i < 32; i++)
    {
        this->database->setUnsignedChar(sink, i, this->database->getUnsignedChar(source, i));
    }
}

void BCUDefaultList::createList(bool bcu1Online, bool bcu2Online)
{
    if (!bcu1Online && !bcu2Online)
    {
        return;
    }
    else if (!bcu1Online && !this->database->getBool(this->bcu21, 28, 7))
    {
        return;
    }
    else if (!bcu2Online && !this->database->getBool(this->bcu11, 28, 7))
    {
        return;
    }

    //both bcu1 and bcu2 are master
    else if (this->database->getBool(this->bcu11, 28, 7) && this->database->getBool(this->bcu21, 28, 7))
    {
        if (this->database->getBool(this->bcu11, 26, 0) && bcu1Online)
        {
            this->copyPort(this->hmiBCU11, this->bcu11);
            this->copyPort(this->hmiBCU12, this->bcu12);
            this->copyPort(this->hmiBCU13, this->bcu13);
            this->copyPort(this->hmiBCU14, this->bcu14);
        }
        else if (this->database->getBool(this->bcu21, 26, 0) && bcu2Online)
        {
            this->copyPort(this->hmiBCU11, this->bcu21);
            this->copyPort(this->hmiBCU12, this->bcu22);
            this->copyPort(this->hmiBCU13, this->bcu23);
            this->copyPort(this->hmiBCU14, this->bcu24);
        }
    }
    else if (this->database->getBool(this->bcu11, 28, 7) && bcu1Online)
    {
        this->copyPort(this->hmiBCU11, this->bcu11);
        this->copyPort(this->hmiBCU12, this->bcu12);
        this->copyPort(this->hmiBCU13, this->bcu13);
        this->copyPort(this->hmiBCU14, this->bcu14);
    }
    else if (this->database->getBool(this->bcu21, 28, 7) && bcu2Online)
    {
        this->copyPort(this->hmiBCU11, this->bcu21);
        this->copyPort(this->hmiBCU12, this->bcu22);
        this->copyPort(this->hmiBCU13, this->bcu23);
        this->copyPort(this->hmiBCU14, this->bcu24);
    }
}
