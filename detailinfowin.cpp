#include "detailinfowin.h"
#include "ui_detailinfowin.h"
#include<QListWidget>
#include"globalinfo.h"
#include"lineswin.h"
#include<QSqlRecord>
#include<QDebug>
DetailInfoWin::DetailInfoWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailInfoWin)
{
    GlobalInfo::getInstance()->detailW = this;
    ui->setupUi(this);
    model = new QSqlTableModel(0,GlobalInfo::getInstance()->db->database);
    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

DetailInfoWin::~DetailInfoWin()
{
    delete ui;
}

void DetailInfoWin::showDetail(const QModelIndex& index)
{

    model->setTable("tb_station_info");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(model->record().indexOf("line_id"));
    ui->tableView->hideColumn(model->record().indexOf("station_id"));

    line_id = GlobalInfo::getInstance()->lineW->model->record(index.row()).value("line_id").toInt();
    model->setFilter(QObject::tr("line_id=%1").arg(line_id));
    model->submitAll();
    show();
}

void DetailInfoWin::on_add_btn_clicked()
{
    model->insertRow(model->rowCount());
    model->setData(model->index(model->rowCount()-1,model->record().indexOf("line_id")),line_id);
    model->submitAll();
}


void DetailInfoWin::on_ok_btn_clicked()
{
    model->submitAll();
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}

void DetailInfoWin::on_cancel_btn_clicked()
{
    this->hide();
    GlobalInfo::getInstance()->lineW->show();
}
