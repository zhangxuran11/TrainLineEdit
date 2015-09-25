#ifndef DBSERVICE_H
#define DBSERVICE_H
#include<QSqlDatabase>
#include"resultset.h"
class DBService
{
    bool isValid;
    QSqlDatabase database;
public:
    explicit DBService(const QString& dbName);

    bool  exec(const QString& sqlInsert);
    ResultSet  query(const QString& sqlQuery);
};

#endif // DBSERVICE_H


