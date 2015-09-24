#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    line_w = new LineWin(this);
    detail_w = new DetailInfoWin(this);
    line_w->show();
    detail_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
