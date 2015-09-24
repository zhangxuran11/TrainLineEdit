#include "detailinfowin.h"
#include "ui_detailinfowin.h"
#include<QListWidget>
#include"globalinfo.h"
#include"linewin.h"
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
void DetailInfoWin::showDetail(QListWidgetItem* item)
{
    listItem = item;
    GlobalInfo::getInstance()->domParser->loadTable(ui->tableWidget,item);
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
    GlobalInfo::getInstance()->domParser->updateFromTable(ui->tableWidget,listItem);
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}

void DetailInfoWin::on_cancel_btn_clicked()
{
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}
