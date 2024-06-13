#include "mytcpserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("info.db");
    database.open();
    QSqlQuery use(database);

    use.exec("CREATE TABLE IF NOT EXISTS data (login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, status VARCHAR(20) NOT NULL)");

    use.prepare("INSERT INTO data (login, password, status) VALUES (:login, :password, :status)");
    use.bindValue(":login","admin");
    use.bindValue(":password","root");
    use.bindValue(":status","online");
    use.exec();

    use.prepare("INSERT INTO data (login, password, status) VALUES (:login, :password, :status)");
    use.bindValue(":login","user");
    use.bindValue(":password","12345");
    use.bindValue(":status","offline");
    use.exec();

    use.exec("SELECT * FROM data");
    QSqlRecord record = use.record();
    const int loginIndex = record.indexOf("login");
    const int passwordIndex = record.indexOf("password");
    const int statusIndex = record.indexOf("status");

    while (use.next()) 
    {
        qDebug()<<use.value(loginIndex).toString().toUtf8()
        <<" "<<use.value(passwordIndex).toString().toUtf8()
        <<" "<<use.value(statusIndex).toString().toUtf8()
        <<"\r\n";
    }

    use.exec("DROP TABLE data");
    database.close();

    MyTcpServer::getInstance();
    return application.exec();
}