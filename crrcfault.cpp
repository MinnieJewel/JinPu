#include <QFile>
#include <QStringList>
#include <QDateTime>
#include <stdlib.h>
#include "crrcfault.h"
#include <QDebug>

class Database;

#define _CRRC_FAULT_VERSION 1.2
#define _CRRC_MAX_HISTORY_FAULT_RECORD 1000
#define _CRRC_PORT_SIZE 32

CrrcFault::CrrcFault(QString faultListFilePath, QString historyFilePath)
        : faultListFilePath(faultListFilePath), historyFilePath(historyFilePath)
{
    this->readFaultTypeListFile();
    this->readHistoryFaultFile();
    this->historyFaultRecordChangeFlag = false;
}

void CrrcFault::synchronize(Database *database)
{
    //_LOG << "CrrcFault update";
    if (NULL == database)
    {
        qDebug() << "there is no database, please check it" << __FILE__ << __LINE__;
        return;
    }

    foreach (unsigned short int key, this->faultList.keys())
    {
        if (faultList[key].virtualValue == database->getBool(faultList[key].port, faultList[key].byte, faultList[key].bit))
        {
            if (this->checkItemExist(key) == false)
            {
                current_fault_type currentFaultType;
                history_fault_type historyFaultType;

                currentFaultType.key = key;
                currentFaultType.start = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                currentFaultType.name = faultList[key].name;
                currentFaultType.code = faultList[key].code;
                currentFaultType.position = faultList[key].position;
                currentFaultType.device = faultList[key].device;
                currentFaultType.description = faultList[key].description.trimmed();

                historyFaultType.start = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                historyFaultType.end = QString("");
                historyFaultType.code = faultList[key].code;
                historyFaultType.name = faultList[key].name;
                historyFaultType.position = faultList[key].position;
                historyFaultType.device = faultList[key].device;
                historyFaultType.description = faultList[key].description.trimmed();

                // edited by Deng Ran on the 24th of May 2017
                this->currentFaultList.push_front(currentFaultType);

                if (faultList[key].position.size() > 1)
                {
                    this->confirmFaultList.push_back(faultList[key].position + QString("车 ") +  faultList[key].device + QString(" ")
                                                     + faultList[key].name + QString(" ") + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                }
                else
                {
                    this->confirmFaultList.push_back(faultList[key].device + QString(" ")
                                                     + faultList[key].name + QString(" ") + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                }


                // changed by Deng Ran on the 13th of January 2017
                while (this->historyFaultList.size() >= _CRRC_MAX_HISTORY_FAULT_RECORD)
                {
                    this->historyFaultList.removeLast();
                }

                this->historyFaultList.push_front(historyFaultType);

                // changed by Deng Ran on the 13th of January 2017
                // this->writeHistoryFaultFile();
                this->historyFaultRecordChangeFlag = true;
            }
        }
        else if (this->checkItemExist(key) == true)
        {
            // changed by Deng Ran on the 22th of June 2017
            for (int i = 0; i < this->historyFaultList.size(); i ++)
            {
                // to find the error item in the history error list
                if (this->historyFaultList.at(i).code == this->faultList[key].code
                        && this->historyFaultList.at(i).position == this->faultList[key].position)
                {
                    history_fault_type historyFaultType;

                    historyFaultType.start = this->historyFaultList.at(i).start;
                    historyFaultType.end = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                    historyFaultType.name = this->historyFaultList.at(i).name;
                    historyFaultType.code = this->historyFaultList.at(i).code;
                    historyFaultType.device = this->historyFaultList.at(i).device;
                    historyFaultType.position = this->historyFaultList.at(i).position;
                    historyFaultType.description = this->historyFaultList.at(i).description;

                    this->historyFaultList.replace(i, historyFaultType);

                    // changed by Deng Ran on the 13th of January 2017
                    // this->writeHistoryFaultFile();
                    this->historyFaultRecordChangeFlag = true;

                    // added by Deng Ran on the 22th of June 2017
                    break;
                }
            }
            this->removeItem(key);
        }
    }
    // if a new fault appears, write the record file
    if (true == this->historyFaultRecordChangeFlag)
    {
        this->historyFaultRecordChangeFlag = false;
        this->writeHistoryFaultFile();
    }
}

void CrrcFault::confirmFault()
{
    if (this->confirmFaultList.isEmpty())
    {
        return;
    }
    else
    {
        this->confirmFaultList.removeFirst();
    }
}

QString CrrcFault::getCurrentConfirmFault()
{
    if (this->confirmFaultList.isEmpty())
    {
        return QString("");
    }
    else
    {
        return this->confirmFaultList.at(0);
    }
}

int CrrcFault::getConfirmFaultListSize() const
{
    return this->confirmFaultList.size();
}



QString CrrcFault::getCurrentFaultDate(unsigned short int index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        QDateTime dateTime = QDateTime::fromString(this->currentFaultList.at(index).start, QString("yyyy-MM-dd hh:mm:ss"));

        return dateTime.toString("yyyy-MM-dd");
    }
}

QString CrrcFault::getCurrentFaultTime(unsigned short int index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        QDateTime dateTime = QDateTime::fromString(this->currentFaultList.at(index).start, QString("yyyy-MM-dd hh:mm:ss"));

        return dateTime.toString("hh:mm:ss");
    }
}


QString CrrcFault::getCurrentFaultCode(unsigned short index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->currentFaultList.at(index).code;
    }
}

QString CrrcFault::getCurrentFaultName(unsigned short index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->currentFaultList.at(index).name;
    }
}

QString CrrcFault::getCurrentFaultDevice(unsigned short int index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->currentFaultList.at(index).device;
    }
}

QString CrrcFault::getCurrentFaultPosition(unsigned short int index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->currentFaultList.at(index).position;
    }
}

int CrrcFault::getCurrentFaultLevel(unsigned short index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return 0;
    }
    else if (this->getCurrentFaultCode(index).size() != 4)
    {
        qDebug() << "the size of the code is not 4, please check it" << __FILE__ << __LINE__;

        return 0;
    }
    else
    {
        return this->getCurrentFaultCode(index).toUInt(NULL, 16) / 256 % 16;
    }
}

int CrrcFault::getCurrentFaultLevel(QString &code) const
{
    if (code.size() != 4)
    {
        qDebug() << "the size of the code is not 4, please check it" << __FILE__ << __LINE__;

        return 0;
    }
    else
    {
        return code.toUInt(NULL, 16) / 256 % 16;
    }
}

QString CrrcFault::getCurrentFaultDescription(unsigned short index) const
{
    if (index >= this->currentFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->currentFaultList.at(index).description;
    }
}

QString CrrcFault::getHistoryFaultStartDate(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        QDateTime dateTime = QDateTime::fromString(this->historyFaultList.at(index).start, QString("yyyy-MM-dd hh:mm:ss"));

        return dateTime.toString("yyyy-MM-dd");
    }
}

QString CrrcFault::getHistoryFaultStartTime(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        QDateTime dateTime = QDateTime::fromString(this->historyFaultList.at(index).start, QString("yyyy-MM-dd hh:mm:ss"));

        return dateTime.toString("hh:mm:ss");
    }
}

QString CrrcFault::getHistoryFaultEndDate(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }

    QDateTime dateTime = QDateTime::fromString(this->historyFaultList.at(index).end, QString("yyyy-MM-dd hh:mm:ss"));

    if (dateTime.isValid())
    {
        return dateTime.toString("yyyy-MM-dd");
    }
    else
    {
        return QString("--");
    }
}

QString CrrcFault::getHistoryFaultEndTime(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }

    QDateTime dateTime = QDateTime::fromString(this->historyFaultList.at(index).end, QString("yyyy-MM-dd hh:mm:ss"));

    if (dateTime.isValid())
    {
        return dateTime.toString("hh:mm:ss");
    }
    else
    {
        return QString("--");
    }
}

int CrrcFault::getHistoryFaultLevel(unsigned short index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the current fault list, please check it" << __FILE__ << __LINE__;

        return 0;
    }
    else if (this->getHistoryFaultCode(index).size() != 4)
    {
        qDebug() << "the size of the code is not 4, please check it" << __FILE__ << __LINE__;

        return 0;
    }
    else
    {
        return this->getHistoryFaultCode(index).toUInt(NULL, 16) / 256 % 16;
    }
}

QString CrrcFault::getHistoryFaultCode(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->historyFaultList.at(index).code;
    }
}

QString CrrcFault::getHistoryFaultName(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->historyFaultList.at(index).name;
    }
}

QString CrrcFault::getHistoryFaultDevice(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->historyFaultList.at(index).device;
    }
}

QString CrrcFault::getHistoryFaultPosition(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->historyFaultList.at(index).position;
    }
}


QString CrrcFault::getHistoryFaultDescription(unsigned short int index) const
{
    if (index >= this->historyFaultList.size())
    {
        qDebug() << "the index is larger than the history fault list, please check it" << __FILE__ << __LINE__;

        return QString("");
    }
    else
    {
        return this->historyFaultList.at(index).description;
    }
}

void CrrcFault::readFaultTypeListFile()
{
    if (false == QFile::exists(this->faultListFilePath))
    {
        qDebug() << "there is no fault list file, please check it, please check it" << __FILE__ << __LINE__;

        return;
    }

    QFile file(faultListFilePath);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int counter = -1;
    unsigned short int key = 0;

    stream.setCodec("GBK");

    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        QStringList stringList = line.split("--");
        struct fault_type faultType;

        counter ++;

        // the fault list version
        if (0 == counter && stringList.size() == 2)
        {
            this->faultListFileVersion = stringList.at(1).trimmed();

            qDebug() << "the version of the fault list file is" << this->faultListFileVersion << __FILE__ << __LINE__;

            continue;
        }
        else if (0 == counter)
        {
            qDebug() << "fail to read the version of the fault list file" << __FILE__ << __LINE__;

            continue;
        }

        // line 1 and line 2 are not fault type, so skip them
        if (counter == 0 || counter == 1)
        {
            continue;
        }
        else if (stringList.size() != 9)
        {
            qDebug() << "fail to read the fault list at line" << counter + 1 << ", please check it" << __FILE__ << __LINE__;

            continue;
        }

        faultType.name = stringList.at(0).trimmed();
        faultType.position = stringList.at(1).trimmed();
        faultType.device = stringList.at(2).trimmed();
        faultType.code = stringList.at(3).trimmed();

        unsigned short int portTemp = stringList.at(4).trimmed().toUShort(NULL, 16);

        if (portTemp <= 0xFFFF)
        {
            faultType.port = portTemp;
        }
        else
        {
            qDebug() << "invalid port address in line" << counter + 1 << "of the fault list file, please check it" << __FILE__ << __LINE__;
            continue;
        }

        unsigned char byteTemp = stringList.at(5).trimmed().toUShort();

        if (byteTemp < _CRRC_PORT_SIZE)
        {
            faultType.byte = byteTemp;
        }
        else
        {
            qDebug() << "invalid byte address in line " << counter + 1 << "of the fault list file, please check it" << __FILE__ << __LINE__;
            continue;
        }

        unsigned char bitTemp = stringList.at(6).trimmed().toUShort();

        if (bitTemp <= 7)
        {
            faultType.bit = bitTemp;
        }
        else
        {
            qDebug() << "invalid bit address in line " << counter + 1 << "of the fault list file, please check it" << __FILE__ << __LINE__;

            continue;
        }

        unsigned short int virtualValueTemp = stringList.at(7).trimmed().toUShort();

        if (0 == virtualValueTemp)
        {
            faultType.virtualValue = false;
        }
        else if (1 == virtualValueTemp)
        {
            faultType.virtualValue = true;
        }
        else
        {
            qDebug() << "fail to read the the virtual value in line" << counter + 1 << "of the fault list file, please check it" << __FILE__ << __LINE__;

            continue;
        }

        faultType.description = stringList.at(8).trimmed();

        this->faultList.insert(key, faultType);

        key ++;
    }

    qDebug() << "there are" << this->faultList.size() << "in the fault list";
}

void CrrcFault::readHistoryFaultFile()
{
    if (QFile::exists(this->historyFilePath))
    {
        QFile file(this->historyFilePath);
        file.open(QIODevice::ReadOnly);
        QTextStream stream(&file);
        int counter = 0;

        stream.setCodec("GBK");

        while (stream.atEnd() == false)
        {
            QString line = stream.readLine();
            QStringList stringList = line.split("--");

            counter ++;

            if (stringList.size() != 7)
            {
                qDebug() << "fail to read the history record in line" << counter << __FILE__ << __LINE__;

                continue;
            }

            history_fault_type historyFaultType;

            historyFaultType.start = stringList.at(0).trimmed();
            historyFaultType.end = stringList.at(1).trimmed();
            historyFaultType.name = stringList.at(2).trimmed();
            historyFaultType.code = stringList.at(3).trimmed();
            historyFaultType.position = stringList.at(4).trimmed();
            historyFaultType.device = stringList.at(5).trimmed();
            historyFaultType.description = stringList.at(6).trimmed();

            this->historyFaultList.append(historyFaultType);
        }

        file.close();

        qDebug() << "there are" << this->historyFaultList.size() << "record in the history fault list file" << __FILE__ << __LINE__;
    }
    else
    {
        qDebug() << "there is no history fault list file, please check it" << __FILE__ << __LINE__;
    }
}
void CrrcFault::writeHistoryFaultFile() const
{
    QFile file(this->historyFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream stream(&file);

    stream.setCodec("GBK");

    foreach (history_fault_type historyFaultType, this->historyFaultList)
    {
        QString line("");

        line += historyFaultType.start + QString(" -- ");
        line += historyFaultType.end + QString(" -- ");
        line += historyFaultType.name + QString(" -- ");
        line += historyFaultType.code + QString(" -- ");
        line += historyFaultType.position + QString(" -- ");
        line += historyFaultType.device + QString(" -- ");
        line += historyFaultType.description + QString("\n");

        stream << line;
    }

    file.close();
}
/*
param:
    key: the key in the faultList but not sure in the currentFaultList
function:
    judge if the new fault is in the currentFaultList
return:
    ture: the given key is in the currentFaultList
    false:the given key is not in the currentFaultList
*/
bool CrrcFault::checkItemExist(unsigned short key) const
{
    bool value = false;
    foreach (current_fault_type temp, this->currentFaultList)
    {
        if (temp.key == key)
        {
            value = true;
            break;
        }
    }
    return value;
}


/*
param:
    position, device: the item with the given position and device
function:
    judge the item with position and device if in the currentFaultList
return:
    ture: the given key is in the currentFaultList
    false:the given key is not in the currentFaultList
*/
bool CrrcFault::judgeDeviceFault(QString position, QString device) const
{
    bool value = false;
    QString positionTemp, deviceTemp;
    positionTemp = position.trimmed();
    deviceTemp = device.trimmed();
    foreach (current_fault_type temp, this->currentFaultList)
    {
        if (!(QString::compare(temp.position, positionTemp) || QString::compare(temp.device , deviceTemp)))
        {
            value = true;
            break;
        }
    }
    return value;
}

void CrrcFault::removeItem(unsigned short int key)
{
    for (int i = 0; i < this->currentFaultList.size(); i ++)
    {
        if (this->currentFaultList.at(i).key == key)
        {
            this->currentFaultList.removeAt(i);
            break;
        }
    }
}

void CrrcFault::printAllFaultType() const
{
    unsigned short int counter = 0;

    foreach (fault_type temp, this->faultList)
    {
        qDebug() << "item" << counter ++ << temp.name << temp.code << QString::number(temp.port, 16)
                    << temp.byte << temp.bit << temp.device << temp.virtualValue << temp.description;
    }
}

int CrrcFault::getCurrentFaultListSize() const
{
    return this->currentFaultList.size();
}

int CrrcFault::getHistoryFaultListSize() const
{
    return this->historyFaultList.size();
}

int CrrcFault::getFaultTypeSize() const
{
    return this->faultList.size();
}
/*
function:judge if devices in networkPage are fault
parameters:
position:device of which vehicle
device:device name
author:ZhuMM
*/
bool CrrcFault::deviceFault(QString position, QString device)
{
    for (int i = 0; i < this->currentFaultList.size(); i ++)
    {
        if (position == this->currentFaultList.at(i).position)
        {
            if (device == this->currentFaultList.at(i).device)
                return true;
        }
    }
    return false;
}
