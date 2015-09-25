#include "dbservice.h"
#include<QFile>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QDebug>
#include<QSqlError>
DBService::DBService(const QString& dbName )
{
    isValid = true;
    database = QSqlDatabase::addDatabase("QSQLITE");
    if(!QFile::exists(dbName))
    {
        qDebug()<<"db "<<dbName<<" is not exists!!";
        isValid = false;
        return;
    }
    database.setDatabaseName(dbName);
}
ResultSet  DBService::query(const QString& sqlQuery)
{
    ResultSet results;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        isValid = false;
        return results;
    }
    QSqlQuery sql_query(database);
    sql_query.prepare(sqlQuery);
    if(!sql_query.exec())
    {
        isValid = false;
        qDebug()<<sql_query.lastError();
        return results;
    }
    else
    {
        QSqlRecord record = sql_query.record();
        while(sql_query.next())
        {
            ResultRow resMap;
            for(int i = 0;i < record.count();i++)
            {
                resMap.insert(record.fieldName(i),sql_query.value(i).toByteArray());
            }
            results.resultList.append(resMap);
        }

    }
    database.close();
    return results;
}
bool  DBService::exec(const QString& sqlInsert)
{
    bool res = false;
    if(!database.open())
    {
        qDebug()<<database.lastError();
        return res;
    }
    else
    {
        QSqlQuery sql_query(database);
        sql_query.prepare(sqlInsert);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"inserted!";
            sql_query.exec("VACUUM");
            res = true;
        }

    }

    database.close();
    return res;
}

