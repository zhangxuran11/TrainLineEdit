#ifndef BEAN_H
#define BEAN_H
#include<QString>
#include<QMap>
#include<QListWidget>

class LineInfo
{
public:
    LineInfo(const QString& _line_id,const QString& _line_name,const QString& _start_station_id,const QString& _end_station_id,bool _isNew);
    int line_id;
    QString line_name;
    int start_station_id;
    int end_station_id;

    bool isNew;

};
typedef QMap<QListWidgetItem*,LineInfo> LineInfoMap;
/*class StationInfo
{
 public:
    StationInfo(const QString& _station_id,const QString& _station_name_en,const QString& _station_name_th,
                const QString& _start_time,const QString& _arrive_time,const QString& _lat,const QString& _lng,bool _isNew);
    int station_id;
    QString station_name_en;
    QString station_name_th;
    QString start_time;
    QString arrive_time;
    double lat;
    double lng;
   // bool _isNew;
};
typedef QMap<QString,StationInfo> StationMap; */  //以line_name为key

#endif // BEAN_H
