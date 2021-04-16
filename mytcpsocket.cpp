#include "mytcpsocket.h"
#include <QDataStream>
MyTcpSocket::MyTcpSocket()
{
    connect(this, &MyTcpSocket::connected, this, &MyTcpSocket::onConnected);
    connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReadyRead);
    connect(this, &MyTcpSocket::disconnected, this, &MyTcpSocket::onDisconnected);
    //connectStart(); //开始连接
}

bool MyTcpSocket::connectStart(QString ip, quint16 port)
{
    this->connectToHost(ip, port);//开始连接
    if (!this->waitForConnected(20000))
    {
        qDebug() << "客户端连接失败" /*<< Qt::endl*/; //等待一段时间，如果连接失败则停止连接
        return false;
    }
    return true;
}

bool MyTcpSocket::sendMessage(QString msg)
{
    QByteArray arr;
    QDataStream dts(&arr, QIODevice::WriteOnly);
    dts << msg;
    this->write(arr);
    qDebug() << "消息" << msg << "发送成功" /*<< Qt::endl*/;
    return true;
}

void MyTcpSocket::onReadyRead()
{
    QByteArray array = readAll();
    QDataStream dts(&array, QIODevice::ReadOnly);
    QString msg;
    dts >> msg;
    emit newMessage(msg);
}

void MyTcpSocket::onConnected()
{
    qDebug() << "成功连接至服务器";
}

void MyTcpSocket::onDisconnected()
{
    qDebug() << "客户端与服务器断开连接";
}
