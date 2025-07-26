#include "SetTingMenu.h"
#include "ui_SetTingMenu.h"
#include <QMouseEvent>

SetTingMenu::SetTingMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetTingMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    qApp->installEventFilter(this);
}

SetTingMenu::~SetTingMenu()
{
    delete ui;
}

bool SetTingMenu::eventFilter(QObject *obj, QEvent *event)
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
//刷新页面
void SetTingMenu::on_pushButton_clicked()
{

}
//帮助中心
void SetTingMenu::on_pushButton_3_clicked()
{

}

void SetTingMenu::on_pushButton_4_clicked()
{

}

void SetTingMenu::on_pushButton_2_clicked()
{

}

void SetTingMenu::on_pushButton_5_clicked()
{

}

