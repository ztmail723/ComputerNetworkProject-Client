#include "pkghandler.h"
#include "mytcpsocket.h"

PkgHandler::PkgHandler(MyTcpSocket* socket)
    : QObject(socket)
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

quint64 PkgHandler::getFileCnt()
{
    return this->nowFileCount;
}

void PkgHandler::handle2001(DataPkg& pkg) //文件列表
{
    QStringList list;
    for (QVariant& i : pkg.data) {
        list.append(i.toString());
    }
    emit sendFileList(list);
}

void PkgHandler::handle2002(DataPkg& pkg) //文件头
{
    QString fileName = pkg.data[0].toString();
    quint64 fileCount = pkg.data[1].toUInt();
    this->nowFile = new QFile(fileName);
    this->nowFileCount = fileCount;
    this->nowFile->open(QIODevice::WriteOnly);
    emit sendFileHeader(fileName, fileCount);
}

void PkgHandler::handle2003(DataPkg& pkg)
{
    quint64 fileID = pkg.data[0].toUInt();
    QByteArray fileData = pkg.data[1].toByteArray();
    bool isFinished = false;
    this->nowFile->write(fileData);
    if (fileID == nowFileCount) {
        this->nowFile->close();
        delete this->nowFile;
        isFinished = true;
    }
    emit sendFileData(fileID + 1, fileData, isFinished);
}
