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

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>


class MyTcpServer : public QObject
{
    Q_OBJECT
    static MyTcpServer* instance;
    QTcpServer *TcpServer;
    QTcpSocket *TcpSocket;
public:
	explicit MyTcpServer();
    ~MyTcpServer();

	static MyTcpServer* getInstance();
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    MyTcpServer(const MyTcpServer& ) = delete;
	MyTcpServer& operator = (MyTcpServer &) = delete;
};

#endif
