#ifndef DBSERVICE_H
#define DBSERVICE_H
#include<QSqlDatabase>
#include"resultset.h"
class DBService
{


public:
    QSqlDatabase database;
    bool isValid;
    explicit DBService(const QString& dbName);
    ~DBService(){close();}

    bool open();
    void close();
    bool  exec(const QString& sqlInsert);
    ResultSet  query(const QString& sqlQuery);
};

#endif // DBSERVICE_H


