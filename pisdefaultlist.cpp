#include "pisdefaultlist.h"
#include "database.h"
#include <QDebug>


PISDefaultList::PISDefaultList()
{
    this->database = NULL;
}

void PISDefaultList::setSinkPort(QList<unsigned short> &ports)
{
    if (ports.size() != 2)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->hmiPIS1 = ports.at(0);
        this->hmiPIS2 = ports.at(1);
    }
}

void PISDefaultList::setSourcePort(QList<unsigned short> &ports)
{
    if (ports.size() != 4)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->pis11 = ports.at(0);
        this->pis12 = ports.at(1);
        this->pis21 = ports.at(2);
        this->pis22 = ports.at(3);
    }
}

void PISDefaultList::installDatabase(Database *database)
{
    this->database = database;
}

void PISDefaultList::copyPort(unsigned short sink, unsigned short source)
{
    for (int i = 0; i < 32; i++)
    {
        this->database->setUnsignedChar(sink, i, this->database->getUnsignedChar(source, i));
    }
}

void PISDefaultList::createList(bool pis1Online, bool pis2Online)
{    
    if (this->database->getBool(0x810, 11, 0) && pis1Online)
    {
        this->copyPort(this->hmiPIS1, this->pis11);
        this->copyPort(this->hmiPIS2, this->pis12);
    }

    else if (this->database->getBool(0x820, 11, 0) && pis2Online)
    {
        this->copyPort(this->hmiPIS1, this->pis21);
        this->copyPort(this->hmiPIS2, this->pis22);
    }

    else if (pis1Online)
    {
        this->copyPort(this->hmiPIS1, this->pis11);
        this->copyPort(this->hmiPIS2, this->pis12);
    }
    else return;
}
