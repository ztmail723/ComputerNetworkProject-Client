#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include "datapkg.h"

class PkgHandler {
public:
    PkgHandler();
    void handle(DataPkg& pkg);
};

#endif // PKGHANDLER_H
