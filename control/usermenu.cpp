#include "usermenu.h"
#include "ui_usermenu.h"
#include <windows.h>
#include <QDebug>
#include <QMouseEvent>

UserMenu::UserMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    qApp->installEventFilter(this);
}

UserMenu::~UserMenu()
{
    delete ui;
}

bool UserMenu::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!this->geometry().contains(mouseEvent->globalPos()))
        {
            if(this->isVisible())
            {
                this->hide();
                this->deleteLater();
            }
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void UserMenu::on_pushButton_clicked()
{
    emit showMyselfData();
    this->deleteLater();
}

void UserMenu::on_pushButton_2_clicked()
{
    qApp->quit();
}

