#ifndef DETAILINFO_H
#define DETAILINFO_H

#include <QWidget>
#include<QTableWidget>
#include<QListWidget>
namespace Ui {
class DetailInfoWin;
}

class DetailInfoWin : public QWidget
{
    Q_OBJECT
  //  QListWidgetItem* listItem;
public:
    Ui::DetailInfoWin *ui;
    explicit DetailInfoWin(QWidget *parent = 0);
    ~DetailInfoWin();
    void showDetail(QListWidgetItem* item);
    void loadTable(QListWidgetItem* listItem);
private slots:
    void on_add_btn_clicked();

    void on_ok_btn_clicked();

    void on_cancel_btn_clicked();

private:

};

#endif // DETAILINFO_H
