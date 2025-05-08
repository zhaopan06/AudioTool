#include "mainwindow.h"
#include "Global.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile fStyle("app.qss");
    if (!fStyle.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0,"open error","error",QMessageBox::Yes);
    }
    a.setStyleSheet(fStyle.readAll());

    CreateDir();
    MainWindow w;
    w.show();
    return a.exec();
}
