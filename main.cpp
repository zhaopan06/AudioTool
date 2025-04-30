#include "mainwindow.h"
#include "Global.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CreateDir();
    MainWindow w;
    w.show();
    return a.exec();
}
