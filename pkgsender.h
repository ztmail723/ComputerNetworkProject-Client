#ifndef PKGSENDER_H
#define PKGSENDER_H

#include <QObject>

class PkgSender : public QObject
{
    Q_OBJECT
public:
    explicit PkgSender(QObject *parent = nullptr);

signals:

};

#endif // PKGSENDER_H
