#include "linewin.h"
#include<QDebug>
#include"detailinfowin.h"
#include<QApplication>
LineWin::LineWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineWin)
{
    GlobalInfo::getInstance()->lineW = this;
    ui->setupUi(this);
    domParser.loadList(ui->listWidget,"trainlines.xml");
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
    GlobalInfo::getInstance()->domParser->saveToFile(ui->listWidget,"trainlines.xml");
}

void LineWin::on_close_btn_clicked()
{
     QApplication::quit();
}

void LineWin::on_edit_btn_clicked()
{
    if(ui->listWidget->count() == 0)
        return;
    this->hide();
    GlobalInfo::getInstance()->detailW->showDetail(ui->listWidget->currentItem());
}

void LineWin::on_delete_btn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->count() - 1);
}
