#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket();
    bool connectStart(QString ip, quint16 port);
    bool sendMessage(QString msg);
signals:
    void newMessage(QString msg);
private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
};

#endif // MYTCPSOCKET_H
