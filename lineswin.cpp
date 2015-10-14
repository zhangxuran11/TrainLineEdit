#include "lineswin.h"
#include<QDebug>
#include"detailinfowin.h"
#include<QApplication>
#include"resultset.h"
#include"bean.h"
#include"globalinfo.h"
#include<QSqlRecord>
#include<QTimer>
LineWin::LineWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineWin)
{
    ui->setupUi(this);
    GlobalInfo::getInstance()->lineW = this;
    QTimer::singleShot(1,this,SLOT(init()));

}
void LineWin::init()
{
    model = new QSqlTableModel(0,GlobalInfo::getInstance()->db->database);
    connect(model, SIGNAL(dataChanged(const QModelIndex&,const QModelIndex&)), this, SLOT(onItemChanged(const QModelIndex&,const QModelIndex&)));

    model->setTable("tb_lines_info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setSort(model->record().indexOf("line_id"), Qt::AscendingOrder);
    model->select();
    model->database().transaction();
    ui->listView->setModel(model);
    ui->listView->setModelColumn(model->record().indexOf("line_name"));
}

LineWin::~LineWin()
{
    delete ui;
}

void LineWin::on_create_btn_clicked()
{
    model->insertRow(model->rowCount());
    model->submitAll();
    int column = model->record().indexOf("line_name");
    QModelIndex index = model->index(model->rowCount()-1, column);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);

    ui->create_btn->setDisabled(true);
    ui->edit_btn->setDisabled(true);
}





void LineWin::onItemChanged(const QModelIndex& topLeft,const QModelIndex&)
{
    if(isRepeat_listView(topLeft))
    {
        ui->create_btn->setDisabled(true);
        ui->edit_btn->setDisabled(true);
        ui->listView->setCurrentIndex(topLeft);
        ui->listView->edit(topLeft);
        ui->label->setText("Line has existed,please input a valid line.");
    }
    else
    {
        ui->label->setText("");
        ui->create_btn->setDisabled(false);
        ui->edit_btn->setDisabled(false);
        model->submitAll();

    }
}
bool LineWin::isRepeat_listView(const QModelIndex& index)
{
    for(int i = 0;i < model->rowCount();i++)
    {
        if(i == index.row())
            continue;
        if(model->record(i).value("line_name").toString() == model->data(index).toString())
            return true;
    }
    return false;
}
void LineWin::on_save_btn_clicked()
{
    model->database().commit();
    model->database().transaction();

}

void LineWin::on_close_btn_clicked()
{
    model->database().rollback();
    QString sqlStr = QString("delete from tb_station_info where line_id not in (select line_id from tb_lines_info )");
    GlobalInfo::getInstance()->db->exec(sqlStr);
     QApplication::quit();
}

void LineWin::on_edit_btn_clicked()
{
    if(model->rowCount() == 0)
        return;
    this->hide();
    GlobalInfo::getInstance()->detailW->showDetail(ui->listView->currentIndex());
}

void LineWin::on_delete_btn_clicked()
{
    int curRow = ui->listView->currentIndex().row();
    model->removeRow(curRow);
    model->submitAll();
}
