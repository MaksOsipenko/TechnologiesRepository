#include "mytcpserver.h"


MyTcpServer* MyTcpServer::instance = nullptr;
MyTcpServer* MyTcpServer::getInstance()
{
    if (instance == nullptr) {instance = new MyTcpServer();}
    return instance;
}


MyTcpServer::MyTcpServer()
{
    TcpServer = new QTcpServer(this);

    connect(TcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!TcpServer->listen(QHostAddress::Any, 54321)) {qDebug() << "Server is NOT started.";} 
    else {qDebug() << "Server is started.";}
}

MyTcpServer::~MyTcpServer() 
{
    TcpServer->close();
    delete TcpServer;
    if (instance != nullptr) 
    { 
        delete instance;
        instance = nullptr; 
    }
}


void MyTcpServer::slotNewConnection()
{
    TcpSocket = TcpServer->nextPendingConnection();
    TcpSocket->write("The connection to the server was successful!\r\n");
    connect(TcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(TcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QString buffer = "";
    while(TcpSocket->bytesAvailable()>0)
    {
        QByteArray array = TcpSocket->readAll();
        qDebug()<<array<<"\n";
        if(array=="\x01")
        {
            TcpSocket->write(buffer.toUtf8());
            buffer = "";
        }
        else {buffer.append(array);}
    }
    TcpSocket->write(buffer.toUtf8());
}

void MyTcpServer::slotClientDisconnected() 
{
    TcpSocket->close();
    delete TcpSocket;
}