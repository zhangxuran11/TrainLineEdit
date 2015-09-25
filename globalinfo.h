#ifndef GLOBALINFO_H
#define GLOBALINFO_H


#include"dbservice.h"
#include"bean.h"
class LineWin;
class DetailInfoWin;
class GlobalInfo
{
    static GlobalInfo* _instance;

    GlobalInfo();
public:
    DBService *db;
    static GlobalInfo* getInstance();

    LineWin* lineW;
    DetailInfoWin* detailW;

    LineInfoMap lineInfoMap;
    //StationMap stationMap;
};

#endif // GLOBALINFO_H
