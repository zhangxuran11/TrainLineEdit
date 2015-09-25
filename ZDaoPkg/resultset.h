#ifndef RESULTSET_H
#define RESULTSET_H
#include<QList>
#include<QMap>
#include<QByteArray>
#include<QString>
class ResultRow
{
    QMap<QString,QByteArray> _resMap;

    friend class DBService;
    void insert(const QString& key,const QByteArray value);
public:
    const QByteArray getPara(const QString& paraName)const{return _resMap[paraName];}
    int count()const{return _resMap.count();}
    QByteArray getPara(int index)const{return _resMap[_resMap.keys()[index]];}
};
class ResultSet
{
    QList<ResultRow> resultList;
    friend class DBService;
public:
    ResultSet();
    int count()const{return resultList.count();}
    const ResultRow& operator [] (int i)const{return resultList[i];}

};

#endif // RESULTSET_H
