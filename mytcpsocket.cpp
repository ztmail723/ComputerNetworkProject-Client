#include "mytcpsocket.h"
#include "pkghandler.h"
#include "pkgsender.h"
#include <QDataStream>
MyTcpSocket::MyTcpSocket(QObject* parent)
    : QTcpSocket(parent)
{
    this->handler = new PkgHandler(this);
    this->sender = new PkgSender(this);
    connect(this, &MyTcpSocket::connected, this, &MyTcpSocket::onConnected);
    connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReadyRead);
    connect(this, &MyTcpSocket::disconnected, this, &MyTcpSocket::onDisconnected);
    connect(this, &MyTcpSocket::newMessage, this, &MyTcpSocket::handleMsg);
}

bool MyTcpSocket::connectStart(QString ip, quint16 port)
{
    this->connectToHost(ip, port); //开始连接
    if (!this->waitForConnected(20000)) {
        qDebug() << "客户端连接失败" /*<< Qt::endl*/; //等待一段时间，如果连接失败则停止连接
        return false;
    }
    return true;
}

bool MyTcpSocket::sendMessage(DataPkg pkg)
{
    QByteArray arr;
    QDataStream dts(&arr, QIODevice::WriteOnly);
    dts << pkg;
    this->write(arr);
    return true;
}

void MyTcpSocket::onReadyRead()
{
    QByteArray array = this->readAll();
    QDataStream dts(&array, QIODevice::ReadOnly);
    DataPkg pkg;
    dts >> pkg;
    emit newMessage(pkg);
}

void MyTcpSocket::onConnected()
{
    qDebug() << "成功连接至服务器";
}

void MyTcpSocket::onDisconnected()
{
    qDebug() << "客户端与服务器断开连接";
}

void MyTcpSocket::handleMsg(DataPkg pkg)
{
    this->handler->handle(pkg);
}
