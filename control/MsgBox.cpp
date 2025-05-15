#include "MsgBox.h"
#include "ui_MsgBox.h"
#include <QDebug>

MsgBox::MsgBox(const QString &title, const QString msg, BTN_MODE mode, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::MsgBox)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setTitle(title);
    setMessage(msg);

    // 根据不同的样式显示不同的按钮
    switch (mode)
    {
    case MsgBox::TIPDIALOG:
        ui->okBtn->show();
        ui->cancelBtn->hide();
        break;

    case MsgBox::QUERYDIALOG:
        ui->okBtn->show();
        ui->cancelBtn->show();
        break;

    default:
        break;
    }
}
MsgBox::~MsgBox()
{
    delete ui;
}

void MsgBox::on_okBtn_clicked()
{
    accept();
}

void MsgBox::on_cancelBtn_clicked()
{
    reject();
}

int MsgBox::showMsg(QWidget *parent, const QString &title, const QString &msg, BTN_MODE mode)
{
    MsgBox msgBox(title, msg, mode, parent);

 //   QPoint point;
 //   point.setX(minWindow->x() + (minWindow->width() - msgBox.width())/2);
 //   point.setY(minWindow->y() + (minWindow->height() - msgBox.height())/2);
 //   msgBox.move(point);

    return msgBox.exec();
}

int MsgBox::showMsgTop(QWidget *parent, const QString &title, const QString &msg, BTN_MODE mode)
{
    MsgBox msgBox(title, msg, mode, parent);
    msgBox.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    return msgBox.exec();
}

void MsgBox::setTitle(const QString &title)
{
    setWindowTitle(title);
    ui->titleLabel->setText(title);
}

void MsgBox::setMessage(const QString &msg)
{
    ui->msg->setText(msg);
}

void MsgBox::on_closeBtn_clicked()
{
    reject();
}
