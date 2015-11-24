#ifndef TRAINLINEPANEL_H
#define TRAINLINEPANEL_H

#include <QWidget>
#include<QMap>
#include"soft_keyboard.h"
namespace Ui {
class TrainLinePanel;
}

class TrainLinePanel : public QWidget
{
    Q_OBJECT
    QMap<QString,QTableWidget*> list_table_map;
    Soft_Keyboard *keyboard;
public:
    explicit TrainLinePanel(QWidget *parent = 0);
    ~TrainLinePanel();
    void show();
    void hide();
    void insertRailwayTestData(const QPointF& p_start,const QPointF& p_end,int count);//just for test
signals:
    void changeCurrentLine(int line_id);
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_add_line_btn_clicked();
    void on_add_line_ok_btn_clicked();
    void on_delete_line_btn_clicked();
    void on_add_station_btn_clicked();
    void on_ok_btn_clicked();
    void on_setCurLineBtn_clicked();
    void on_runStateBtn_clicked();
    void on_railway_btn_clicked();
    void updateDatabase(QTableWidgetItem*);
    void on_delete_station_btn_clicked();
    void on_add_sample_btn_clicked();

    void on_delete_sample_btn_clicked();

private:

    void saveStation();
    void init();
    Ui::TrainLinePanel *ui;
};

#endif // TRAINLINEPANEL_H
