#include "lineswin.h"
#include<QDebug>
#include"detailinfowin.h"
#include<QApplication>
#include"resultset.h"
#include"bean.h"
LineWin::LineWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineWin)
{
    GlobalInfo::getInstance()->lineW = this;
    ui->setupUi(this);
    loadListWidget();
}
void LineWin::loadListWidget()
{
    QListWidget* listWidget = ui->listWidget;
    listWidget->clear();
    ResultSet set = GlobalInfo::getInstance()->db->query("select * form tb_lines_info");
    for(int i = 0;i < set.count();i++)
    {
        QListWidgetItem* newItem = new QListWidgetItem(set[i].getPara("line_name"));
        newItem->setFlags (newItem->flags () |Qt::ItemIsEditable);
        listWidget->addItem(newItem);

        GlobalInfo::getInstance()->lineInfoMap.insert(newItem,LineInfo(set[i].getPara("line_id"),set[i].getPara("line_name"),set[i].getPara("start_station_id"),set[i].getPara("end_station_id"),false));
    }
}
LineWin::~LineWin()
{
    delete ui;
}

void LineWin::on_create_btn_clicked()
{
    QListWidgetItem* newItem = new QListWidgetItem("please input line name...");
    newItem->setFlags (newItem->flags () |Qt::ItemIsEditable);
    ui->listWidget->addItem(newItem);
    ui->listWidget->editItem(newItem);
    ui->listWidget->setCurrentItem(newItem);
    ui->create_btn->setDisabled(true);
    ui->edit_btn->setDisabled(true);
}





void LineWin::on_listWidget_itemChanged(QListWidgetItem *item)
{
    if(isRepeat_listWidget(item))
    {
        ui->label->setText("Line has existed,please input a valid line.");
        ui->listWidget->editItem(item);
    }
    else
    {
        ui->create_btn->setDisabled(false);
        ui->edit_btn->setDisabled(false);
        QString sql = QString("inser into tb_lines_info (line_name) values(%1)").arg(item->text());
        if(!GlobalInfo::getInstance()->db->exec(sql))
        {
            qDebug("insert  failed !!");
        }
        sql = QString("select * from tb_lines_info where line_name=%1 ").arg(item->text());
        ResultSet set = GlobalInfo::getInstance()->db->query(sql);
        GlobalInfo::getInstance()->lineInfoMap.insert(item,LineInfo(set[0].getPara("line_id"),item->text(),set[0].getPara("start_station_id"),set[0].getPara("end_station_id"),true));
    }
}
bool LineWin::isRepeat_listWidget(QListWidgetItem* item)
{
    for(int i = 0;i < ui->listWidget->count();i++)
    {
        if(ui->listWidget->item(i)->text() == item->text() && ui->listWidget->item(i) != item)
            return true;
    }
    return false;
}
void LineWin::on_save_btn_clicked()
{
    GlobalInfo::getInstance()->db->exec("update tb_lines_info set isNew=false where isNew=true");
    GlobalInfo::getInstance()->db->exec("update tb_station_info set isNew=false where isNew=true");
}

void LineWin::on_close_btn_clicked()
{
     GlobalInfo::getInstance()->db->exec("delete from tb_lines_info where isNew=true");
     GlobalInfo::getInstance()->db->exec("delete from tb_station_info where isNew=true");
     QApplication::quit();
}

void LineWin::on_edit_btn_clicked()
{
    if(ui->listWidget->count() == 0)
        return;
    this->hide();

}

void LineWin::on_delete_btn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->count() - 1);
}
