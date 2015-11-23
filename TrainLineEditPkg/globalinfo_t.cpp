#include "globalinfo_t.h"
#include<QFile>
GlobalInfo_t*  GlobalInfo_t::_instance = NULL;
GlobalInfo_t::GlobalInfo_t()
{
    gps_send_flag = true;
#if defined(X86)
    db = new DBService("TrainLine.db");
#elif defined(ARM)
    db = new DBService("/srv/tftp/TrainLine.db");
#endif
}
GlobalInfo_t* GlobalInfo_t::getInstance()
{
    if(_instance == NULL)
        _instance = new GlobalInfo_t;
    return _instance;
}
int GlobalInfo_t::getCurrentLineIdFromLocalFile()
{
    QFile f("/appbin/curLineId.txt");
    f.open(QFile::ReadOnly);
    QString str = f.readAll();
    f.close();
    return str.toInt();
}
void GlobalInfo_t::saveCurrentLineIdToLocalFile(int lineId)
{
    QFile f("/appbin/curLineId.txt");
    f.open(QFile::Truncate|QFile::WriteOnly);
    f.write(QString::number(lineId).toAscii());
    f.close();
}
