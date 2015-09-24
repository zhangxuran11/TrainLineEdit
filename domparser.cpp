#include "domparser.h"
#include<QFile>
#include<QDebug>
#include"globalinfo.h"
DomParser::DomParser()
{
    GlobalInfo::getInstance()->domParser = this;
}
void DomParser::saveToFile(QListWidget* listWidget,const QString& fileName)
{
    QDomElement newElem = document.createElement("TrainLines");
    document.replaceChild(newElem,root);
    for(int i = 0;i < listWidget->count();i++)
    {
        if(!hash.contains(listWidget->item(i)))
        {
            QDomElement tmpElem = document.createElement("LineInfo");
            hash.insert(listWidget->item(i),tmpElem);
        }
        hash[listWidget->item(i)].setAttribute("LineName",listWidget->item(i)->text());
        newElem.appendChild(hash[listWidget->item(i)]);
    }
    QFile f(fileName);
    f.open(QFile::WriteOnly);
    QTextStream out(&f);
    document.save(out,4);
    root = newElem;
}
bool DomParser::loadList(QListWidget* listWidget,const QString& fileName)
{
    listWidget->clear();
    hash.clear();
    QString errorMsg;
    int errorLine,errorColumn;
    QFile f(fileName);
    if(!f.exists())
    {
        f.open(QFile::WriteOnly);
        QDomProcessingInstruction instruction = document.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
        document.appendChild( instruction);
        document.appendChild(document.createElement("TrainLines"));
        QTextStream out(&f);
        document.save(out,4);
        f.close();
    }
    if(!document.setContent(&f,false,&errorMsg,&errorLine,&errorColumn))
    {
        qDebug()<<"error : "<<errorMsg<<" at : "<<errorLine<<"row. "<<errorColumn<<" column. ";
        return false;
    }
    root = document.documentElement();
    if(root.tagName()!="TrainLines")
    {
        qDebug()<<"Error: Not a train lines file";
        return false;
    }
    QDomElement domElement = root.firstChildElement();
    while(!domElement.isNull()&&domElement.tagName() == "LineInfo")
    {
        QListWidgetItem* newItem = new QListWidgetItem(domElement.attribute("LineName"));
        newItem->setFlags (newItem->flags () |Qt::ItemIsEditable);
        listWidget->addItem(newItem);
        hash.insert(newItem,domElement);
        domElement = domElement.nextSiblingElement();
    }
    return true;
}
bool DomParser::loadTable(QTableWidget* tableWidget,QListWidgetItem* listItem)
{
    tableWidget->setRowCount(0);
    if(!hash.contains(listItem))
    {
        QDomElement elem = document.createElement("LineInfo");
        elem.setAttribute("LineName",listItem->text());
        hash.insert(listItem,elem);
    }
    QDomElement domElement = hash[listItem];
    domElement = domElement.firstChildElement();
    while(!domElement.isNull()&&domElement.tagName() == "DetailInfo")
    {
        tableWidget->insertRow(tableWidget->rowCount());
        QTableWidgetItem* newItem = new QTableWidgetItem(domElement.attribute("StationNo"));
        tableWidget->setItem(tableWidget->rowCount() - 1,0,newItem);
        newItem = new QTableWidgetItem(domElement.attribute("StationName"));
        tableWidget->setItem(tableWidget->rowCount() - 1,1,newItem);
        newItem = new QTableWidgetItem(domElement.attribute("Time"));
        tableWidget->setItem(tableWidget->rowCount() - 1,2,newItem);
        newItem = new QTableWidgetItem(domElement.attribute("LngAndLat"));
        tableWidget->setItem(tableWidget->rowCount() - 1,3,newItem);
        domElement = domElement.nextSiblingElement();
    }
    return true;
}
void DomParser::updateFromTable(QTableWidget* table,QListWidgetItem* listItem)
{
    QDomElement domElem = document.createElement("LineInfo");
    domElem.setAttribute("LineName",listItem->text());
    for(int i = 0;i < table->rowCount();i++)
    {
        QDomElement elem = document.createElement("DetailInfo");
        elem.setAttribute("StationNo",table->item(i,0)->text());
        elem.setAttribute("StationName",table->item(i,1)->text());
        elem.setAttribute("Time",table->item(i,2)->text());
        elem.setAttribute("LngAndLat",table->item(i,3)->text());
        domElem.appendChild(elem);
    }
    hash.insert(listItem,domElem);
}
