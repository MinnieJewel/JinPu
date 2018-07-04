#ifndef MVBDRIVER_H
#define MVBDRIVER_H

#include <QMap>
class Database;

class MvbDriver
{
public:
    MvbDriver();
    bool initialMvb(int position);
    bool setMvbOperation();
    bool setMvbStop();
    bool setMvbConfigure();
    void addPorts(const QList<struct port *> &ports) const;
    void testInitial() const;
    void testGetData() const;

public:
    void synchronizeMvbData(const QList<struct port *> &allPorts,
                            QMap<unsigned short int, struct port_data *> &ports);
};

#endif // MVBDRIVER_H
