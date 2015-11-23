#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"soft_keyboard.h"
#include<QListWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   // setWindowFlags(Qt::FramelessWindowHint|(windowFlags() & (~Qt::WindowCloseButtonHint)));
    ui->setupUi(this);
    trainLinePanel = new TrainLinePanel(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


