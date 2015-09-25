#include "detailinfowin.h"
#include "ui_detailinfowin.h"
#include<QListWidget>
#include"globalinfo.h"
#include"lineswin.h"
DetailInfoWin::DetailInfoWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailInfoWin)
{
    GlobalInfo::getInstance()->detailW = this;
    ui->setupUi(this);
}

DetailInfoWin::~DetailInfoWin()
{
    delete ui;
}
void DetailInfoWin::loadTable(QListWidgetItem* listItem)
{
    QTableWidget* tableWidget = ui->tableWidget;
    tableWidget->setRowCount(0);
    QString sql = QString("select * from tb_station_info where line_id=(select line_id from tb_lines_info where line_name=%1)").arg(listItem->text());
    ResultSet set = GlobalInfo::getInstance()->db->query(sql);
    for(int i = 0;i < set.count();i++)
    {
        tableWidget->insertRow(tableWidget->rowCount());
        QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("station_id")));
        tableWidget->setItem(tableWidget->rowCount() - 1,0,newItem);
        newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("station_name")));
        tableWidget->setItem(tableWidget->rowCount() - 1,1,newItem);
        newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("start_time")));
        tableWidget->setItem(tableWidget->rowCount() - 1,2,newItem);
        newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("arrive_time")));
        tableWidget->setItem(tableWidget->rowCount() - 1,3,newItem);
        newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("lat")));
        tableWidget->setItem(tableWidget->rowCount() - 1,4,newItem);
        newItem = new QTableWidgetItem(QString::fromUtf8(set[i].getPara("lng")));
        tableWidget->setItem(tableWidget->rowCount() - 1,5,newItem);
    }
}
void DetailInfoWin::showDetail(QListWidgetItem* item)
{
    loadTable(item);
    show();
}

void DetailInfoWin::on_add_btn_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    for(int i = 0;i < ui->tableWidget->columnCount();i++)
    {
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,i,new QTableWidgetItem);
    }
}


void DetailInfoWin::on_ok_btn_clicked()
{
    for(int i = 0;i< ui->tableWidget->rowCount();i++)
    {
        QString sql = QString("update tb_station_info set line_name='%1' where station_id=%2").arg(ui->tableWidget->item(i,1)->text()).arg(ui->tableWidget->item(i,0)->text());
        GlobalInfo::getInstance()->db->exec(sql);
        sql = QString("insert into tb_station_info (line_name,start_time,arrive_time,lat,lng) where %1 not in (select station_id from tb_station_info)").arg(ui->tableWidget->item(i,0)->text());
        GlobalInfo::getInstance()->db->exec(sql);
    }
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}

void DetailInfoWin::on_cancel_btn_clicked()
{
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}
