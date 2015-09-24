#ifndef GLOBALINFO_H
#define GLOBALINFO_H


#include"domparser.h"
class LineWin;
class DetailInfoWin;
class GlobalInfo
{
    static GlobalInfo* _instance;

public:
    GlobalInfo();
    static GlobalInfo* getInstance();

    LineWin* lineW;
    DetailInfoWin* detailW;
    DomParser* domParser;
};

#endif // GLOBALINFO_H
