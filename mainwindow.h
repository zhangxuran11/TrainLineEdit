#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"detailinfowin.h"
#include "lineswin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    LineWin* line_w;
    DetailInfoWin* detail_w;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
