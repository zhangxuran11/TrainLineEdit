#include <QtGui/QApplication>
#include"mainwindow.h"
#include<QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("qss/mainframe.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    file.close();

    MainWindow main_w;
    main_w.show();

    return a.exec();
}
