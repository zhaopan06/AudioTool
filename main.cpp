#include "mainwindow.h"
#include "Global.h"
#include "qevent.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
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
