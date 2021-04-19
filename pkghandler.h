#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include "datapkg.h"
#include "mytcpsocket.h"

class PkgHandler : public QObject {
    Q_OBJECT
public:
    PkgHandler(MyTcpSocket* socket);
    void handle(DataPkg& pkg);

private:
    void handle2001(DataPkg& pkg);
    void handle2002(DataPkg& pkg);
    void handle2003(DataPkg& pkg);

private:
    MyTcpSocket* socket;

signals:
    void sendFileList(QStringList list);
    void sendFileHeader(QString fileName, quint64 fileCount);
    void sendFileData(quint64 fileID, QByteArray fileData);
};

#endif // PKGHANDLER_H
