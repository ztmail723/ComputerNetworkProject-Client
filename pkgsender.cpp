#include "pkgsender.h"
#include "mytcpsocket.h"
PkgSender::PkgSender(MyTcpSocket* socket) : QObject(socket)
{
    connect(this, &PkgSender::sendPkg, socket, &MyTcpSocket::sendMessage);
}

void PkgSender::send1001(QString userName)
{
    DataPkg pkg;
    pkg.ID = 1001;
    pkg.data.append(userName);
    this->send(pkg);
}

void PkgSender::send1002(QString userName, QString fileName)
{
    DataPkg pkg;
    pkg.ID = 1002;
    pkg.data.append(userName);
    pkg.data.append(fileName);
    this->send(pkg);
}

void PkgSender::send1003(QString userName, quint64 fileID)
{
    DataPkg pkg;
    pkg.ID = 1003;
    pkg.data.append(userName);
    pkg.data.append(fileID);
    this->send(pkg);
}

void PkgSender::send(DataPkg& pkg)
{
    emit sendPkg(pkg);
}
