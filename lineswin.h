#ifndef LINEWIN_H
#define LINEWIN_H
#include <QWidget>
#include"globalinfo.h"
#include "ui_lineswin.h"
#include<QHash>
#include<QDomDocument>
#include<QSqlTableModel>
namespace Ui {
class LineWin;
}

class LineWin : public QWidget
{
    Q_OBJECT
//    DomParser domParser;
public:
    QSqlTableModel* model;
    Ui::LineWin *ui;
    explicit LineWin(QWidget *parent = 0);
    ~LineWin();
    
private:
    bool isRepeat_listView(const QModelIndex& index);
//    void loadListWidget();
private slots:
    void on_create_btn_clicked();
    void onItemChanged(const QModelIndex& topLeft,const QModelIndex& bottomRight);
    void on_save_btn_clicked();
    void on_close_btn_clicked();

    void on_edit_btn_clicked();

    void on_delete_btn_clicked();

private:

};

#endif // LINEWIN_H

