#include "pkghandler.h"

PkgHandler::PkgHandler(MyTcpSocket* socket)
    : socket(socket)
{
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
}

void PkgHandler::handle2002(DataPkg& pkg)
{
}

void PkgHandler::handle2003(DataPkg& pkg)
{
}
