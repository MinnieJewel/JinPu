#ifndef CRRCFAULT_H
#define CRRCFAULT_H

#include <QString>
#include <QList>
#include <QMap>
#include "database.h"

struct fault_type
{
    unsigned short int port;
    unsigned char byte, bit;
    bool virtualValue;
    QString code, name, device, position, description;
};

struct current_fault_type
{
    unsigned short int key;
    QString start, code, name, position, device, description;
};

struct history_fault_type
{
    QString start, end, code, name, position, device, description;
};

class CrrcFault
{
public:
    CrrcFault(QString faultListFilePath, QString historyFilePath);
    void synchronize(Database *database);
    QString getCurrentFaultDate(unsigned short int index) const;
    QString getCurrentFaultTime(unsigned short int index) const;
    QString getCurrentFaultCode(unsigned short int index) const;
    QString getCurrentFaultName(unsigned short int index) const;
    QString getCurrentFaultDevice(unsigned short int index) const;
    QString getCurrentFaultPosition(unsigned short int index) const;
    QString getCurrentFaultDescription(unsigned short int index) const;
    bool judgeDeviceFault(QString position, QString device) const;
    int getCurrentFaultLevel(unsigned short int index) const;
    int getCurrentFaultLevel(QString &code) const;
    int getCurrentFaultListSize() const;
    QString getHistoryFaultStartDate(unsigned short int index) const;
    QString getHistoryFaultStartTime(unsigned short int index) const;
    QString getHistoryFaultEndDate(unsigned short int index) const;
    QString getHistoryFaultEndTime(unsigned short int index) const;
    QString getHistoryFaultCode(unsigned short int index) const;
    QString getHistoryFaultName(unsigned short int index) const;
    QString getHistoryFaultDevice(unsigned short int index) const;
    QString getHistoryFaultPosition(unsigned short int index) const;
    QString getHistoryFaultDescription(unsigned short int index) const;
    int getHistoryFaultLevel(unsigned short int index) const;
    int getHistoryFaultListSize() const;
    QString getFaultListFileVersion() const;
    QString getCrrcFaultVersion();
    QString getCurrentConfirmFault();
    int getConfirmFaultListSize() const;
    bool deviceFault(QString position, QString device);

    void printAllFaultType() const;
    int getFaultTypeSize() const;
    void confirmFault();

private:
    bool historyFaultRecordChangeFlag;
    QList<current_fault_type> currentFaultList;
//    QList<current_fault_type> currentFaultTc1;
//    QList<current_fault_type> currentFaultTc2;
//    QList<current_fault_type> currentFaultTc1;
//    QList<current_fault_type> currentFaultTc1;
    QList<history_fault_type> historyFaultList;
    QList<QString> confirmFaultList;
    const QString faultListFilePath, historyFilePath;
    QString faultListFileVersion;
    QMap<unsigned short int, fault_type> faultList;

    void readFaultTypeListFile();
    void readHistoryFaultFile();
    void writeHistoryFaultFile() const;
    bool checkItemExist(unsigned short int key) const;
    void removeItem(unsigned short int key);
};

#endif // CRRCFAULT_H
