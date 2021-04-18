#include "pkghandler.h"

PkgHandler::PkgHandler()
{
}

void PkgHandler::handle(DataPkg& pkg)
{
    switch (pkg.ID) {
    case 2001:
        break;
    case 2002:
        break;
    case 2003:
        break;
    default:
        break;
    }
}
