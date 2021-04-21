#ifndef PKGSENDER_H
#define PKGSENDER_H

#include <QObject>
#include "datapkg.h"

class MyTcpSocket;
class PkgSender : public QObject
{
    Q_OBJECT
public:
    explicit PkgSender(MyTcpSocket* socket);

public:
    void send1001(QString userName);
    void send1002(QString userName, QString fileName);
    void send1003(QString userName, quint64 fileID);

private:
    void send(DataPkg& pkg);

signals:
    void sendPkg(DataPkg& pkg);
};

#endif // PKGSENDER_H
