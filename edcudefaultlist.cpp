#include "edcudefaultlist.h"
#include "database.h"
#include <QDebug>

enum doorMaster
{
    Master1 = 1,
    Master2
};

EdcuDefaultList::EdcuDefaultList()
{
    _LOG << "EdcuDefaultList constructor";

    this->database = NULL;
}

void EdcuDefaultList::setSinkPort(QList<unsigned short> &ports)
{
    if (ports.size() != 3)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->hmiEdcu11 = ports.at(0);
        this->hmiEdcu12 = ports.at(1);
        this->hmiEdcu13 = ports.at(2);
    }
}

void EdcuDefaultList::setSourcePort(QList<unsigned short> &ports)
{
    if (ports.size() != 6)
    {
        _LOG << "the size of the ports is not enough";
        return;
    }
    else
    {
        this->edcu11 = ports.at(0);
        this->edcu12 = ports.at(1);
        this->edcu13 = ports.at(2);
        this->edcu21 = ports.at(3);
        this->edcu22 = ports.at(4);
        this->edcu23 = ports.at(5);
    }
}

void EdcuDefaultList::installDatabase(Database *database)
{
    this->database = database;
}

void EdcuDefaultList::copyPort(unsigned short sink, unsigned short source)
{
    for (int i = 0; i < 32; i++)
    {
        this->database->setUnsignedChar(sink, i, this->database->getUnsignedChar(source, i));
    }
}

void EdcuDefaultList::createList(bool edcu1Online, bool edcu2Online, QList<int> &doorsOnLine)
{
    if(this->database->DR1CT_D1Version)
        _LOG << this->database->DR1CT_D1Version;

    if ((1 != this->database->getUnsignedInt(this->edcu12, 20)) && (1 != this->database->getUnsignedInt(this->edcu22, 20)))
    {
        for (int bitNo = 0; bitNo < doorsOnLine.length(); bitNo ++)
        {
            doorsOnLine[bitNo] = 0;
        }
    }

    if(!edcu1Online && !edcu2Online)
    {
        //_LOG << "neither edcu1 and edcu2 is online !";
        return;
    }
    else if(!edcu1Online && (1 != this->database->getUnsignedInt(this->edcu22, 20)))
    {
       // _LOG << "edcu1 is not online !";
        return;
    }
    else if((1 != this->database->getUnsignedInt(this->edcu12, 20)) && !edcu2Online)
    {
        //_LOG << "edcu2 is not online !";
        return;
    }

    else
    if (1 == this->database->getUnsignedInt(this->edcu12, 20) && edcu1Online)
    {
        this->copyPort(this->hmiEdcu11, this->edcu11);
        this->copyPort(this->hmiEdcu12, this->edcu12);
        this->copyPort(this->hmiEdcu13, this->edcu13);

        for(int bitNo = 0; bitNo < doorsOnLine.length(); bitNo++)
        {
            doorsOnLine[bitNo] = Master1;
        }
    }

    else if(1 == this->database->getUnsignedInt(this->edcu22, 20) && edcu2Online)
    {
        this->copyPort(this->hmiEdcu11, this->edcu21);
        this->copyPort(this->hmiEdcu12, this->edcu22);
        this->copyPort(this->hmiEdcu13, this->edcu23);
        for(int bitNo = 0; bitNo <doorsOnLine.length(); bitNo++)
        {
            doorsOnLine[bitNo] = Master2;
        }
    }
     else
    {
        // copy the port
        this->copyPort(this->hmiEdcu11, this->edcu11);
        this->copyPort(this->hmiEdcu12, this->edcu12);
        this->copyPort(this->hmiEdcu13, this->edcu13);

        // can fault
        this->database->setBool(this->hmiEdcu12, 28, 0, this->database->getBool(this->edcu12, 28, 0) || this->database->getBool(this->edcu21, 28, 0));

        //door1
        if (this->database->getBool(this->edcu12, 22, 0))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 0, this->database->getUnsignedChar(this->edcu11, 0));
            this->database->setUnsignedChar(this->hmiEdcu11, 1, this->database->getUnsignedChar(this->edcu11, 1));
            this->database->setUnsignedChar(this->hmiEdcu11, 2, this->database->getUnsignedChar(this->edcu11, 2));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 0, this->database->getUnsignedChar(this->edcu12, 0));
            this->database->setUnsignedChar(this->hmiEdcu12, 1, this->database->getUnsignedChar(this->edcu12, 1));
            this->database->setUnsignedInt(this->hmiEdcu13, 0, this->database->getUnsignedInt(this->edcu13, 0));

            // doorsMaster
            doorsOnLine[0] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 0))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 0, this->database->getUnsignedChar(this->edcu21, 0));
            this->database->setUnsignedChar(this->hmiEdcu11, 1, this->database->getUnsignedChar(this->edcu21, 1));
            this->database->setUnsignedChar(this->hmiEdcu11, 2, this->database->getUnsignedChar(this->edcu21, 2));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 0, this->database->getUnsignedChar(this->edcu22, 0));
            this->database->setUnsignedChar(this->hmiEdcu12, 1, this->database->getUnsignedChar(this->edcu22, 1));
            this->database->setUnsignedInt(this->hmiEdcu13, 0, this->database->getUnsignedInt(this->edcu23, 0));
            doorsOnLine[0] = Master2;
        }

        //door2
        if (this->database->getBool(this->edcu12, 22, 1))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 4, this->database->getUnsignedChar(this->edcu11, 4));
            this->database->setUnsignedChar(this->hmiEdcu11, 5, this->database->getUnsignedChar(this->edcu11, 5));
            this->database->setUnsignedChar(this->hmiEdcu11, 6, this->database->getUnsignedChar(this->edcu11, 6));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 2, this->database->getUnsignedChar(this->edcu12, 2));
            this->database->setUnsignedChar(this->hmiEdcu12, 3, this->database->getUnsignedChar(this->edcu12, 3));
            this->database->setUnsignedInt(this->hmiEdcu13, 2, this->database->getUnsignedInt(this->edcu13, 2));

            // doorsMaster
            doorsOnLine[1] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 1))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 4, this->database->getUnsignedChar(this->edcu21, 4));
            this->database->setUnsignedChar(this->hmiEdcu11, 5, this->database->getUnsignedChar(this->edcu21, 5));
            this->database->setUnsignedChar(this->hmiEdcu11, 6, this->database->getUnsignedChar(this->edcu21, 6));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 2, this->database->getUnsignedChar(this->edcu22, 2));
            this->database->setUnsignedChar(this->hmiEdcu12, 3, this->database->getUnsignedChar(this->edcu22, 3));
            this->database->setUnsignedInt(this->hmiEdcu13, 2, this->database->getUnsignedInt(this->edcu23, 2));

            // doorsMaster
            doorsOnLine[1] = Master2;
        }

        //door3
        if(this->database->getBool(this->edcu12, 22, 2))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 8, this->database->getUnsignedChar(this->edcu11, 8));
            this->database->setUnsignedChar(this->hmiEdcu11, 9, this->database->getUnsignedChar(this->edcu11, 9));
            this->database->setUnsignedChar(this->hmiEdcu11, 10, this->database->getUnsignedChar(this->edcu11, 10));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 4, this->database->getUnsignedChar(this->edcu12, 4));
            this->database->setUnsignedChar(this->hmiEdcu12, 5, this->database->getUnsignedChar(this->edcu12, 5));
            this->database->setUnsignedInt(this->hmiEdcu13, 4, this->database->getUnsignedInt(this->edcu13, 4));

            // doorsMaster
            doorsOnLine[2] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 2))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 8, this->database->getUnsignedChar(this->edcu21, 8));
            this->database->setUnsignedChar(this->hmiEdcu11, 9, this->database->getUnsignedChar(this->edcu21, 9));
            this->database->setUnsignedChar(this->hmiEdcu11, 10, this->database->getUnsignedChar(this->edcu21, 10));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 4, this->database->getUnsignedChar(this->edcu22, 4));
            this->database->setUnsignedChar(this->hmiEdcu12, 5, this->database->getUnsignedChar(this->edcu22, 5));
            this->database->setUnsignedInt(this->hmiEdcu13, 4, this->database->getUnsignedInt(this->edcu23, 4));

            // doorsMaster
            doorsOnLine[2] = Master2;
        }

        //door4
        if(this->database->getBool(this->edcu12, 22, 3))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 12, this->database->getUnsignedChar(this->edcu11, 12));
            this->database->setUnsignedChar(this->hmiEdcu11, 13, this->database->getUnsignedChar(this->edcu11, 13));
            this->database->setUnsignedChar(this->hmiEdcu11, 14, this->database->getUnsignedChar(this->edcu11, 14));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 6, this->database->getUnsignedChar(this->edcu12, 6));
            this->database->setUnsignedChar(this->hmiEdcu12, 7, this->database->getUnsignedChar(this->edcu12, 7));
            this->database->setUnsignedInt(this->hmiEdcu13, 6, this->database->getUnsignedInt(this->edcu13, 6));

            // doorsMaster
            doorsOnLine[3] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 3))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 12, this->database->getUnsignedChar(this->edcu21, 12));
            this->database->setUnsignedChar(this->hmiEdcu11, 13, this->database->getUnsignedChar(this->edcu21, 13));
            this->database->setUnsignedChar(this->hmiEdcu11, 14, this->database->getUnsignedChar(this->edcu21, 14));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 6, this->database->getUnsignedChar(this->edcu22, 6));
            this->database->setUnsignedChar(this->hmiEdcu12, 7, this->database->getUnsignedChar(this->edcu22, 7));
            this->database->setUnsignedInt(this->hmiEdcu13, 6, this->database->getUnsignedInt(this->edcu23, 6));

            // doorsMaster
            doorsOnLine[3] = Master2;
        }

        //door5
        if(this->database->getBool(this->edcu12, 22, 4))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 16, this->database->getUnsignedChar(this->edcu11, 16));
            this->database->setUnsignedChar(this->hmiEdcu11, 17, this->database->getUnsignedChar(this->edcu11, 17));
            this->database->setUnsignedChar(this->hmiEdcu11, 18, this->database->getUnsignedChar(this->edcu11, 18));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 8, this->database->getUnsignedChar(this->edcu12, 8));
            this->database->setUnsignedChar(this->hmiEdcu12, 9, this->database->getUnsignedChar(this->edcu12, 9));
            this->database->setUnsignedInt(this->hmiEdcu13, 8, this->database->getUnsignedInt(this->edcu13, 8));

            // doorsMaster
            doorsOnLine[4] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 4))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 16, this->database->getUnsignedChar(this->edcu21, 16));
            this->database->setUnsignedChar(this->hmiEdcu11, 17, this->database->getUnsignedChar(this->edcu21, 17));
            this->database->setUnsignedChar(this->hmiEdcu11, 18, this->database->getUnsignedChar(this->edcu21, 18));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 8, this->database->getUnsignedChar(this->edcu22, 8));
            this->database->setUnsignedChar(this->hmiEdcu12, 9, this->database->getUnsignedChar(this->edcu22, 9));
            this->database->setUnsignedInt(this->hmiEdcu13, 8, this->database->getUnsignedInt(this->edcu23, 8));

            // doorsMaster
            doorsOnLine[4] = Master2;
        }

        //door6
        if(this->database->getBool(this->edcu12, 22, 5))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 20, this->database->getUnsignedChar(this->edcu11, 20));
            this->database->setUnsignedChar(this->hmiEdcu11, 21, this->database->getUnsignedChar(this->edcu11, 21));
            this->database->setUnsignedChar(this->hmiEdcu11, 22, this->database->getUnsignedChar(this->edcu11, 22));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 10, this->database->getUnsignedChar(this->edcu12, 10));
            this->database->setUnsignedChar(this->hmiEdcu12, 11, this->database->getUnsignedChar(this->edcu12, 11));
            this->database->setUnsignedInt(this->hmiEdcu13, 10, this->database->getUnsignedInt(this->edcu13, 10));

            // doorsMaster
            doorsOnLine[5] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 5))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 20, this->database->getUnsignedChar(this->edcu21, 20));
            this->database->setUnsignedChar(this->hmiEdcu11, 21, this->database->getUnsignedChar(this->edcu21, 21));
            this->database->setUnsignedChar(this->hmiEdcu11, 22, this->database->getUnsignedChar(this->edcu21, 22));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 10, this->database->getUnsignedChar(this->edcu22, 10));
            this->database->setUnsignedChar(this->hmiEdcu12, 11, this->database->getUnsignedChar(this->edcu22, 11));
            this->database->setUnsignedInt(this->hmiEdcu13, 10, this->database->getUnsignedInt(this->edcu23, 10));

            // doorsMaster
            doorsOnLine[5] = Master2;
        }

        //door7
        if(this->database->getBool(this->edcu12, 22, 6))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 24, this->database->getUnsignedChar(this->edcu11, 24));
            this->database->setUnsignedChar(this->hmiEdcu11, 25, this->database->getUnsignedChar(this->edcu11, 25));
            this->database->setUnsignedChar(this->hmiEdcu11, 26, this->database->getUnsignedChar(this->edcu11, 26));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 12, this->database->getUnsignedChar(this->edcu12, 12));
            this->database->setUnsignedChar(this->hmiEdcu12, 13, this->database->getUnsignedChar(this->edcu12, 13));
            this->database->setUnsignedInt(this->hmiEdcu13, 12, this->database->getUnsignedInt(this->edcu13, 12));

            // doorsMaster
            doorsOnLine[6] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 6))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 24, this->database->getUnsignedChar(this->edcu21, 24));
            this->database->setUnsignedChar(this->hmiEdcu11, 25, this->database->getUnsignedChar(this->edcu21, 25));
            this->database->setUnsignedChar(this->hmiEdcu11, 26, this->database->getUnsignedChar(this->edcu21, 26));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 12, this->database->getUnsignedChar(this->edcu22, 12));
            this->database->setUnsignedChar(this->hmiEdcu12, 13, this->database->getUnsignedChar(this->edcu22, 13));
            this->database->setUnsignedInt(this->hmiEdcu13, 12, this->database->getUnsignedInt(this->edcu23, 12));

            // doorsMaster
            doorsOnLine[6] = Master2;
        }

        //door8
        if(this->database->getBool(this->edcu12, 22, 7))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 28, this->database->getUnsignedChar(this->edcu11, 28));
            this->database->setUnsignedChar(this->hmiEdcu11, 29, this->database->getUnsignedChar(this->edcu11, 29));
            this->database->setUnsignedChar(this->hmiEdcu11, 30, this->database->getUnsignedChar(this->edcu11, 30));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 14, this->database->getUnsignedChar(this->edcu12, 14));
            this->database->setUnsignedChar(this->hmiEdcu12, 15, this->database->getUnsignedChar(this->edcu12, 15));
            this->database->setUnsignedInt(this->hmiEdcu13, 14, this->database->getUnsignedInt(this->edcu13, 14));

            // doorsMaster
            //doorsOnLine[7] = Master1;
        }
        else if(this->database->getBool(this->edcu22, 22, 7))
        {
            // fault
            this->database->setUnsignedChar(this->hmiEdcu11, 28, this->database->getUnsignedChar(this->edcu21, 28));
            this->database->setUnsignedChar(this->hmiEdcu11, 29, this->database->getUnsignedChar(this->edcu21, 29));
            this->database->setUnsignedChar(this->hmiEdcu11, 30, this->database->getUnsignedChar(this->edcu21, 30));

            // state
            this->database->setUnsignedChar(this->hmiEdcu12, 14, this->database->getUnsignedChar(this->edcu22, 14));
            this->database->setUnsignedChar(this->hmiEdcu12, 15, this->database->getUnsignedChar(this->edcu22, 15));
            this->database->setUnsignedInt(this->hmiEdcu13, 14, this->database->getUnsignedInt(this->edcu23, 14));

            // doorsMaster
            doorsOnLine[7] = Master2;
        }
    }
}


