#include "pkghandler.h"

PkgHandler::PkgHandler(MyTcpSocket* socket)
    : socket(socket)
{
    connect(this, &PkgHandler::sendFileList, socket, &MyTcpSocket::sendFileList);
    connect(this, &PkgHandler::sendFileHeader, socket, &MyTcpSocket::sendFileHeader);
    connect(this, &PkgHandler::sendFileData, socket, &MyTcpSocket::sendFileData);
}

void PkgHandler::handle(DataPkg& pkg)
{
    switch (pkg.ID) {
    case 2001:
        handle2001(pkg);
        break;
    case 2002:
        handle2002(pkg);
        break;
    case 2003:
        handle2003(pkg);
        break;
    default:
        break;
    }
}

void PkgHandler::handle2001(DataPkg& pkg) //文件列表
{
    QStringList list;
    for (const auto& i : qAsConst(pkg.data)) {
        list.append(i.toString());
    }
    emit sendFileList(list);
}

void PkgHandler::handle2002(DataPkg& pkg) //文件头
{
    QString fileName = pkg.data[0].toString();
    quint64 fileCount = pkg.data[1].toUInt();
    emit sendFileHeader(fileName, fileCount);
}

void PkgHandler::handle2003(DataPkg& pkg)
{
    quint64 fileID = pkg.data[0].toUInt();
    QByteArray fileData = pkg.data[1].toByteArray();
    emit sendFileData(fileID, fileData);
}
