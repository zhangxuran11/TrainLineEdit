#include "globalinfo.h"
GlobalInfo*  GlobalInfo::_instance = NULL;
GlobalInfo::GlobalInfo()
{
#if defined(X86)
    db = new DBService("TrainLine.db");
#elif defined(ARM)
    db = new DBService("/srv/tftp/TrainLine.db");
#endif
}
GlobalInfo* GlobalInfo::getInstance()
{
    if(_instance == NULL)
        _instance = new GlobalInfo;
    return _instance;
}
