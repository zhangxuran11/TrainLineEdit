#ifndef DOMPARSER_H
#define DOMPARSER_H
#include <QDomDocument>
#include<QDomElement>
#include<QListWidget>
#include<QTableWidget>
#include<QHash>
class DomParser
{
    QHash<QListWidgetItem*,QDomElement> hash;
    QDomDocument document;
    QDomElement root;
public:
    DomParser();
    bool loadList(QListWidget* listWidget,const QString& fileName);
    bool loadTable(QTableWidget* tableWidget,QListWidgetItem* listItem);
    void updateFromTable(QTableWidget* table,QListWidgetItem* listItem);
    void saveToFile(QListWidget* listWidget,const QString& fileName);
};

#endif // DOMPARSER_H
