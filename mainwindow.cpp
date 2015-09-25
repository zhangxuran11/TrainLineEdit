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

    ui->setupUi(this);
    Soft_Keyboard *keyboard = new Soft_Keyboard;

    line_w = new LineWin(this);
    detail_w = new DetailInfoWin(this);
    connect(line_w->ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    connect(detail_w->ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),keyboard,SLOT(show(QModelIndex)));
    line_w->show();
    detail_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
