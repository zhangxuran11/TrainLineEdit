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
    //trainLinePanel->insertRailwayTestData(QPointF(98.116252,-9.873845 ),QPointF(104.615845,-10.163175),10000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


