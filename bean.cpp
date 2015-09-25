#include "bean.h"


//StationInfo::StationInfo(const QString& _station_id,const QString& _station_name_en,const QString& _station_name_th,
//            const QString& _start_time,const QString& _arrive_time,const QString& _lat,const QString& _lng)
//{
//    station_id = _station_id == "null"?-1:_station_id.toInt();
//    station_name_en = _station_name_en;
//    station_name_th = _station_name_th;
//    start_time = _start_time;
//    arrive_time = _arrive_time;
//    lat = _lat == "null"?-1:_lat.toDouble();
//    lng = _lng == "null"?-1:_lng.toDouble();
//}
LineInfo::LineInfo(const QString& _line_id,const QString& _line_name,const QString& _start_station_id,const QString& _end_station_id,bool _isNew)
{
    line_id = _line_id == "null"?-1:_line_id.toInt();
    line_name = _line_name;
    start_station_id = _line_id == "null"?-1:_start_station_id.toInt();
    end_station_id = _line_id == "null"?-1:_end_station_id.toInt();
    isNew =  _isNew ;
}
