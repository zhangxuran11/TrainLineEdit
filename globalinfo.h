#ifndef GLOBALINFO_H
#define GLOBALINFO_H


#include"dbservice.h"
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

    //StationMap stationMap;
};

#endif // GLOBALINFO_H
