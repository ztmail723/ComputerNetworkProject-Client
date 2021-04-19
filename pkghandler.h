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
};

#endif // PKGHANDLER_H
