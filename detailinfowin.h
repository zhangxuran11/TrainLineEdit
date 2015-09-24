#ifndef DETAILINFO_H
#define DETAILINFO_H

#include <QWidget>
#include"QListWidget"
namespace Ui {
class DetailInfoWin;
}

class DetailInfoWin : public QWidget
{
    Q_OBJECT
    QListWidgetItem* listItem;
public:
    explicit DetailInfoWin(QWidget *parent = 0);
    ~DetailInfoWin();
    void showDetail(QListWidgetItem* item);
private slots:
    void on_add_btn_clicked();

    void on_ok_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::DetailInfoWin *ui;
};

#endif // DETAILINFO_H
