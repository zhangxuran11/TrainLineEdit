#include "globalinfo.h"
#include"lineswin.h"
#include"detailinfowin.h"
GlobalInfo*  GlobalInfo::_instance = NULL;
GlobalInfo::GlobalInfo()
{
    db = new DBService("TrainLineDao.db");
}
GlobalInfo* GlobalInfo::getInstance()
{
    if(_instance == NULL)
        _instance = new GlobalInfo;
    return _instance;
}
