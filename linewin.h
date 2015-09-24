#ifndef LINEWIN_H
#define LINEWIN_H
#include"domparser.h"
#include <QWidget>
#include"globalinfo.h"
#include "ui_lineswin.h"
#include<QHash>
#include<QDomDocument>
namespace Ui {
class LineWin;
}

class LineWin : public QWidget
{
    Q_OBJECT
    DomParser domParser;
public:
    explicit LineWin(QWidget *parent = 0);
    ~LineWin();
    
private:
    bool isRepeat_listWidget(QListWidgetItem* item);
private slots:
    void on_create_btn_clicked();
    void on_listWidget_itemChanged(QListWidgetItem *item);
    void on_save_btn_clicked();
    void on_close_btn_clicked();

    void on_edit_btn_clicked();

    void on_delete_btn_clicked();

private:
    Ui::LineWin *ui;
};

#endif // LINEWIN_H
