#include "trainlinepanel.h"
#include "ui_trainlinepanel.h"
#include"soft_keyboard.h"
#include<QListWidget>
#include"dbservice.h"
#include<stdio.h>
#include<QTimer>
#include<QStringList>
#include"globalinfo_t.h"
#include<QColor>
//#include"ui_lineswin.h"
//#include"ui_detailinfowin.h"
TrainLinePanel::TrainLinePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainLinePanel)
{
    setWindowFlags(Qt::FramelessWindowHint|(windowFlags() & (~Qt::WindowCloseButtonHint)));
    ui->setupUi(this);
    keyboard = new Soft_Keyboard;

    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    connect(ui->train_id_lineEdit,SIGNAL(clicked()),keyboard,SLOT(show()));
    connect(ui->line_name_lineEdit,SIGNAL(clicked()),keyboard,SLOT(show()));
    //connect(ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    //ui->tableWidget->setColumnHidden(0,true);
    int lineId = GlobalInfo_t::getCurrentLineIdFromLocalFile();
    QString sql = QString("select line_name from tb_lines_info where line_id=%1").arg(lineId);
    ResultSet set = GlobalInfo_t::getInstance()->db->query(sql);
    if(set.count()!=0)
    {
        QString lineName = set[0].getPara("line_name");
        ui->currentLineLabel->setText(lineName);
    }
    init();

    ui->stackedWidget->setCurrentIndex(1);


}

void TrainLinePanel::init()
{
    list_table_map.clear();
    for(int i = 2; i < ui->stackedWidget->count();i++)
    {
        QWidget* widget = ui->stackedWidget->widget(i);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }

    ui->listWidget->clear();
    ResultSet set = GlobalInfo_t::getInstance()->db->query("select line_id,train_id,line_name  from tb_lines_info");
    for(int i = 0; i < set.count();i++)
    {
        char tmp[5];
        int i_train_id = set[i].getPara("train_id").toInt();
        sprintf(tmp,"%02d",i_train_id);
        QListWidgetItem* listItem = new QListWidgetItem(QString::fromAscii(tmp)+":"+set[i].getPara("line_name"),ui->listWidget);
        //item->(Qt::white);
        //listItem->setBackgroundColor(QColor(0, 255, 255));

        ui->listWidget->addItem(listItem);

        {
            //add station info table
            QTableWidget *tableWidget = new QTableWidget;
            tableWidget->setAlternatingRowColors(true);
            tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
            tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

            connect(tableWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));

            //tableWidget->setStyleSheet("font: 900 14pt \"Ubuntu\";color: rgb(0, 0, 0);border-style:solid;border-color: rgb(170, 170, 255);border-width:2px;");
            //tableWidget->horizontalHeader()->setHidden(true);
    //        tableWidget->setStyleSheet("background-color: rgb(170, 255, 0);"
    //        "alternate-background-color: rgb(217, 79, 255);");
            tableWidget->verticalHeader()->setHidden(true);
            list_table_map.insert(listItem->text(),tableWidget);
            //ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count()-1);
            ui->stackedWidget->addWidget(tableWidget);

            QString sql = QString("select station_id,station_name_en,station_name_th,start_time,arrive_time,lat,lng  from tb_station_info where line_id=%1").arg(set[i].getPara("line_id"));
            ResultSet rowSet = GlobalInfo_t::getInstance()->db->query(sql);
            tableWidget->setColumnCount(8);
            tableWidget->setRowCount(rowSet.count());
            tableWidget->setColumnHidden(0,true);
            tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
            tableWidget->horizontalHeader()->setMinimumHeight(30);
            tableWidget->horizontalHeader()->setMinimumSectionSize(140);

            QTableWidgetItem* item = new QTableWidgetItem("station id");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(0,item);
            item = new QTableWidgetItem("name en");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(1,item);
            item = new QTableWidgetItem("name th");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(2,item);
            item = new QTableWidgetItem("start time");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(3,item);
            item = new QTableWidgetItem("arrive time");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(4,item);
            item = new QTableWidgetItem("lat");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(5,item);
            item = new QTableWidgetItem("lng");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(6,item);
            item = new QTableWidgetItem("sea level");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(7,item);

            for(int i = 0;i < rowSet.count();i++)
            {
                QTableWidgetItem* item = new QTableWidgetItem(rowSet[i].getPara("station_id"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,0,item);
                item = new QTableWidgetItem(rowSet[i].getPara("station_name_en"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,1,item);
                item = new QTableWidgetItem(rowSet[i].getPara("station_name_th"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,2,item);
                item = new QTableWidgetItem(rowSet[i].getPara("start_time"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,3,item);
                item = new QTableWidgetItem(rowSet[i].getPara("arrive_time"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,4,item);
                item = new QTableWidgetItem(rowSet[i].getPara("lat"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,5,item);
                item = new QTableWidgetItem(rowSet[i].getPara("lng"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,6,item);
                item = new QTableWidgetItem(rowSet[i].getPara("sea_level"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,7,item);

            }
            connect(tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(updateDatabase(QTableWidgetItem*)));
        }
qDebug("2222");
        {
            //add railway info table
            QTableWidget *tableWidget = new QTableWidget;
            tableWidget->setAlternatingRowColors(true);
            tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
            tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

            connect(tableWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));


            tableWidget->verticalHeader()->setHidden(true);
            list_table_map.insert(listItem->text()+"_railway",tableWidget);
            ui->stackedWidget->addWidget(tableWidget);

            QString sql = QString("select sample_id,line_id,lng,lat,sea_level  from tb_station_info where line_id=%1").arg(set[i].getPara("line_id"));
            ResultSet rowSet = GlobalInfo_t::getInstance()->db->query(sql);

            tableWidget->setColumnCount(5);
            tableWidget->setRowCount(rowSet.count());

            tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
            tableWidget->horizontalHeader()->setMinimumHeight(30);
            tableWidget->horizontalHeader()->setMinimumSectionSize(140);

            QTableWidgetItem* item = new QTableWidgetItem("sample id");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(0,item);
            item = new QTableWidgetItem("line id");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(1,item);
            item = new QTableWidgetItem("lng");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(2,item);
            item = new QTableWidgetItem("lat");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(3,item);
            item = new QTableWidgetItem("sea level");
            item->setTextAlignment(Qt::AlignHCenter);
            tableWidget->setHorizontalHeaderItem(4,item);


            for(int i = 0;i < rowSet.count();i++)
            {
                QTableWidgetItem* item = new QTableWidgetItem(rowSet[i].getPara("sample_id"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,0,item);
                item = new QTableWidgetItem(rowSet[i].getPara("line_id"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,1,item);
                item = new QTableWidgetItem(rowSet[i].getPara("lng"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,2,item);
                item = new QTableWidgetItem(rowSet[i].getPara("lat"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,3,item);
                item = new QTableWidgetItem(rowSet[i].getPara("sea_level"));
                item->setTextAlignment(Qt::AlignHCenter);
                tableWidget->setItem(i,4,item);

            }
            connect(tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(updateDatabase(QTableWidgetItem*)));
        }

    }

}

TrainLinePanel::~TrainLinePanel()
{
    delete ui;
}

void TrainLinePanel::on_listWidget_itemClicked(QListWidgetItem *)
{

    QTableWidget* tableWidget = list_table_map[ui->listWidget->currentItem()->text()];
    ui->stackedWidget->setCurrentWidget(tableWidget);
}

void TrainLinePanel::on_add_line_btn_clicked()
{
    ui->line_name_lineEdit->setText("");
    ui->train_id_lineEdit->setText("");
    ui->stackedWidget->setCurrentIndex(0);

}

void TrainLinePanel::on_add_line_ok_btn_clicked()
{
    if(ui->train_id_lineEdit->text().trimmed() != "" && ui->line_name_lineEdit->text() != "")
    {
        QString sql = QString("insert into tb_lines_info (train_id,line_name) values(%1,'%2')").arg(ui->train_id_lineEdit->text()).arg(ui->line_name_lineEdit->text());
        qDebug()<<"xxxx"<<sql;
        GlobalInfo_t::getInstance()->db->exec(sql);
    }
    init();
    QTableWidget* tableWidget = list_table_map[ui->listWidget->item(ui->listWidget->count()-1)->text()];
    ui->stackedWidget->setCurrentWidget(tableWidget);
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
//    if(ui->listWidget->count() == 0)
//        return;
//    ui->listWidget->setCurrentItem(ui->listWidget->item(ui->listWidget->count()-1));
//    ui->listWidget->item(ui->listWidget->count()-1)->setSelected(true);
//    on_listWidget_itemClicked(ui->listWidget->item(ui->listWidget->count()-1));
}

void TrainLinePanel::on_delete_line_btn_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if(item == NULL)
        return;
    //int index = ui->listWidget->currentIndex().row();
    QStringList strList = item->text().split(QChar(':'));
    QString sql = QString("delete from tb_station_info where line_id=(select line_id from tb_lines_info where train_id=%1 and line_name='%2')").arg(strList[0]).arg(strList[1]);
    GlobalInfo_t::getInstance()->db->exec(sql);
    sql = QString("delete from tb_lines_info where train_id=%1 and line_name='%2'").arg(strList[0]).arg(strList[1]);
    GlobalInfo_t::getInstance()->db->exec(sql);
//    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(index+1));
//    ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
    init();
    ui->stackedWidget->setCurrentIndex(1);
//    if(ui->listWidget->count() == 0)
//    {
//        return;
//    }
//    ui->listWidget->setCurrentItem(ui->listWidget->item(0));
//    ui->listWidget->item(0)->setSelected(true);
//    on_listWidget_itemClicked(ui->listWidget->item(0));

}

void TrainLinePanel::on_add_station_btn_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    int index = ui->listWidget->currentRow();
    if(item == NULL)
        return;
    QStringList strList = item->text().split(QChar(':'));
    QString sql = QString("insert into tb_station_info(line_id) select line_id from tb_lines_info where train_id=%1 and line_name='%2'").arg(strList[0]).arg(strList[1]);
    GlobalInfo_t::getInstance()->db->exec(sql);
    init();
    ui->listWidget->setCurrentRow(index);
    ui->listWidget->setCurrentItem(ui->listWidget->item(index));
    on_listWidget_itemClicked(ui->listWidget->currentItem());
}

//void TrainLinePanel::on_tableWidget_itemChanged(QTableWidgetItem *item)
//{
//    if(ui->tableWidget->currentRow() == -1)
//        return;
//    QString station_id = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
//    QString sql;
//    QString columnName;
//    QString value;
//    switch(ui->tableWidget->currentColumn())
//    {
//    case 1:
//        columnName = "station_name_en";
//        value = QString("'%1'").arg(item->text());
//        break;
//    case 2:
//        columnName = "station_name_th";
//        value = QString("'%1'").arg(item->text());
//        break;
//    case 3:
//        columnName = "start_time";
//        value = QString("'%1'").arg(item->text());
//        break;
//    case 4:
//        columnName = "arrive_time";
//        value = QString("'%1'").arg(item->text());
//        break;
//    case 5:
//        columnName = "lat";
//        value = QString("%1").arg(item->text());
//        break;
//    case 6:
//        columnName = "lng";
//        value = QString("%1").arg(item->text());
//        break;
//    }
//    sql = QString("update tb_station_info set %1=%2 where station_id=%3").arg(columnName).arg(value).arg(station_id);
//    GlobalInfo_t::getInstance()->db->exec(sql);
//}

void TrainLinePanel::show()
{
    init();
    GlobalInfo_t::getInstance()->gps_send_flag = false;
    QWidget::show();
}
void TrainLinePanel::hide()
{
    GlobalInfo_t::getInstance()->gps_send_flag = true;
    QWidget::hide();
}
void TrainLinePanel::on_ok_btn_clicked()
{
    saveStation();
    hide();
}
void TrainLinePanel::saveStation()
{
    for(int i = 2;i < ui->stackedWidget->count();i++)
    {
        QTableWidget* tableWidget = dynamic_cast<QTableWidget*>(ui->stackedWidget->widget(i));
        for(int i = 0;i < tableWidget->rowCount();i++)
        {
            QString sql = QString("update tb_station_info set station_name_en='%1',station_name_th='%2',start_time='%3',arrive_time='%4',lat=%5,lng=%6 where station_id=%7")
                    .arg(tableWidget->item(i,1)->text())
                    .arg(tableWidget->item(i,2)->text())
                    .arg(tableWidget->item(i,3)->text())
                    .arg(tableWidget->item(i,4)->text())
                    .arg(tableWidget->item(i,5)->text())
                    .arg(tableWidget->item(i,6)->text())
                    .arg(tableWidget->item(i,0)->text());
            GlobalInfo_t::getInstance()->db->exec(sql);
        }
    }

}

void TrainLinePanel::on_setCurLineBtn_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if(item == NULL)
        return;
    QStringList strList = item->text().split(QChar(':'));
    ui->currentLineLabel->setText(strList[1]);
    QString sql = QString("select line_id from tb_lines_info where train_id=%1 and line_name='%2'").arg(strList[0].toInt()).arg(strList[1]);
    ResultSet set = GlobalInfo_t::getInstance()->db->query(sql);
    int newLineId = set[0].getPara("line_id").toInt();
    GlobalInfo_t::saveCurrentLineIdToLocalFile(newLineId);
    ui->currentLineLabel->setText(strList[1]);
    emit changeCurrentLine(newLineId);
}




void TrainLinePanel::on_runStateBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void TrainLinePanel::on_railway_btn_clicked()
{
    QTableWidget* tableWidget = list_table_map[ui->listWidget->currentItem()->text()+"_railway"];
    ui->stackedWidget->setCurrentWidget(tableWidget);
}
void TrainLinePanel::updateDatabase(QTableWidgetItem* item)
{
    if(item->tableWidget()->horizontalHeaderItem(0)->text() == "station id")
    {
        QString station_id = item->tableWidget()->item(item->row(),0)->text();
        QString val = item->text();
        QString colName;
        switch (item->column())
        {
        case 0:colName="station_id";break;
        case 1:colName="station_name_en";val = "'"+val+"'";break;
        case 2:colName="station_name_th";val = "'"+val+"'";break;
        case 3:colName="start_time";val = "'"+val+"'";break;
        case 4:colName="arrive_time";val = "'"+val+"'";break;
        case 5:colName="lat";break;
        case 6:colName="lng";break;
        case 7:colName="sea_level";break;
        }
        QString sql = QString("update tb_station_info set %1=%2 where station_id=%3").arg(colName).arg(val).arg(station_id);
        GlobalInfo_t::getInstance()->db->exec(sql);
    }
    else if(item->tableWidget()->horizontalHeaderItem(0)->text() == "sample id")
    {
        QString sample_id = item->tableWidget()->item(item->row(),0)->text();
        QString val = item->text();
        QString colName;
        switch (item->column())
        {
        case 0:colName="sample_id";break;
        case 1:colName="line_id";break;
        case 2:colName="lng";break;
        case 3:colName="lat";break;
        case 4:colName="sea_level";break;
        }
        QString sql = QString("update tb_railway_info set %1=%2 where sample_id=%3").arg(colName).arg(val).arg(sample_id);
        GlobalInfo_t::getInstance()->db->exec(sql);
    }
}
void TrainLinePanel::on_delete_station_btn_clicked()
{
    QTableWidget* tableWidget =  dynamic_cast<QTableWidget*>(ui->stackedWidget->currentWidget());
    int index = ui->listWidget->currentRow();
    if(tableWidget != NULL)
    {
        if(tableWidget->horizontalHeaderItem(0)->text() == "station id")
        {
            QTableWidgetItem* currentItem = tableWidget->currentItem();
            QString sql = QString("delete from tb_station_info where station_id=%1").arg(tableWidget->item(currentItem->row(),0)->text());
            GlobalInfo_t::getInstance()->db->exec(sql);
        }
    }
    init();
    ui->listWidget->setCurrentRow(index);
    ui->listWidget->setCurrentItem(ui->listWidget->item(index));
    on_listWidget_itemClicked(ui->listWidget->currentItem());

}
