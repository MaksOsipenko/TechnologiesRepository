#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H 

#include <QCoreApplication>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include<QString>


class MyTcpServer : public QObject
{
    Q_OBJECT
    QTcpServer *TcpServer;
    QTcpSocket *TcpSocket;
public:
    explicit MyTcpServer();
    ~MyTcpServer();

    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
};

#endif
