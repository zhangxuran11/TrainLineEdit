#include "resultset.h"

ResultSet::ResultSet()
{
}
void ResultRow::insert(const QString& key,const QByteArray value)
{
    _resMap.insert(key,value);
}
