#ifndef GLOBALINFO_T_H
#define GLOBALINFO_T_H


#include"dbservice.h"
class LineWin;
class DetailInfoWin;
class GlobalInfo_t
{
    static GlobalInfo_t* _instance;

    GlobalInfo_t();
public:
    bool gps_send_flag;
    DBService *db;
    static GlobalInfo_t* getInstance();
    static void saveCurrentLineIdToLocalFile(int lineId);
    static int getCurrentLineIdFromLocalFile();
    LineWin* lineW;
    DetailInfoWin* detailW;

    //StationMap stationMap;
};

#endif // GLOBALINFO_T_H
