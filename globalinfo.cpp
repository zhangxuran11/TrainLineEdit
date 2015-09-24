#include "globalinfo.h"
#include"linewin.h"
#include"detailinfowin.h"
GlobalInfo*  GlobalInfo::_instance = NULL;
GlobalInfo::GlobalInfo()
{
}
GlobalInfo* GlobalInfo::getInstance()
{
    if(_instance == NULL)
        _instance = new GlobalInfo;
    return _instance;
}
