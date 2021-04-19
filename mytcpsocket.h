#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "datapkg.h"
#include <QTcpSocket>
class MyTcpSocket : public QTcpSocket {
    Q_OBJECT
public:
    MyTcpSocket(QObject* parent = nullptr);
    bool connectStart(QString ip, quint16 port);
    bool sendMessage(DataPkg msg);
signals:
    void newMessage(DataPkg msg);
private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void handleMsg(DataPkg pkg);
};

#endif // MYTCPSOCKET_H
