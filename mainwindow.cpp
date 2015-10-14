#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"soft_keyboard.h"
#include<QListWidget>
#include"ui_lineswin.h"
#include"ui_detailinfowin.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setWindowFlags(Qt::FramelessWindowHint|(windowFlags() & (~Qt::WindowCloseButtonHint)));
    ui->setupUi(this);
    Soft_Keyboard *keyboard = new Soft_Keyboard;

    line_w = new LineWin(this);
    detail_w = new DetailInfoWin(this);
    connect(line_w->ui->listView,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    connect(detail_w->ui->tableView,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    line_w->show();
    detail_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


