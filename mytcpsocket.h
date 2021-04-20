#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "datapkg.h"
class PkgHandler;
class PkgSender;
#include <QTcpSocket>
class MyTcpSocket : public QTcpSocket {
    Q_OBJECT

public:
    MyTcpSocket(QObject* parent = nullptr);
    bool connectStart(QString ip, quint16 port);
    bool sendMessage(DataPkg msg);

private:
    PkgHandler* handler;
    PkgSender* sender;

signals:
    void newMessage(DataPkg msg);
    void sendFileList(QStringList list);
    void sendFileHeader(QString fileName, quint64 fileCount);
    void sendFileData(quint64 fileID, QByteArray fileData);
private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void handleMsg(DataPkg pkg);
};

#endif // MYTCPSOCKET_H
