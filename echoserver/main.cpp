#include "mytcpserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);
    MyTcpServer server;

    return application.exec();
}