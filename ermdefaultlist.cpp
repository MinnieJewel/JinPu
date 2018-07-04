#include "ermdefaultlist.h"
#include "database.h"
#include <QDebug>

ErmDefaultList::ErmDefaultList()
{
    this->database = NULL;
}

void ErmDefaultList::installDatabase(Database *database)
{
    this->database = database;
}

void ErmDefaultList::setSinkPort(QList<unsigned short> &ports)
{
    if (ports.size() != 4)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->hmiERM1 = ports.at(0);
        this->hmiERM2 = ports.at(1);
        this->hmiERM3 = ports.at(2);
        this->hmiERM4 = ports.at(3);
    }
}

void ErmDefaultList::setSourcePort(QList<unsigned short> &ports)
{
    if (ports.size() != 8)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->erm11 = ports.at(0);
        this->erm12 = ports.at(1);
        this->erm13 = ports.at(2);
        this->erm14 = ports.at(3);
        this->erm21 = ports.at(4);
        this->erm22 = ports.at(5);
        this->erm23 = ports.at(6);
        this->erm24 = ports.at(7);
    }
}

void ErmDefaultList::copyPort(unsigned short sink, unsigned short source)
{
    for (int i = 0; i < 32; i++)
    {
        this->database->setUnsignedChar(sink, i, this->database->getUnsignedChar(source, i));
    }
}

void ErmDefaultList::createList()
{
    if (this->database->getBool(0x308, 0, 2))
    {
        this->copyPort(this->hmiERM1, this->erm11);
        this->copyPort(this->hmiERM2, this->erm12);
        this->copyPort(this->hmiERM3, this->erm13);
        this->copyPort(this->hmiERM4, this->erm14);
    }
    else if (this->database->getBool(0x308, 0, 3))
    {
        this->copyPort(this->hmiERM1, this->erm21);
        this->copyPort(this->hmiERM2, this->erm22);
        this->copyPort(this->hmiERM3, this->erm23);
        this->copyPort(this->hmiERM4, this->erm24);
    }

    else return;
}
