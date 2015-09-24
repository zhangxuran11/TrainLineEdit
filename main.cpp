#include <QtGui/QApplication>
#include"mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_w;
    main_w.show();

    return a.exec();
}
