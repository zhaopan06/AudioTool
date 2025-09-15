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
    QString newMsg = msg;
    if(newMsg.isEmpty())
        newMsg =  tr("网络错误");

    QWidget *mask = new QWidget(parent);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    if(parent)
    {
        mask->setGeometry(parent->rect());
        mask->show();
    }

    MsgBox msgBox(title, newMsg, mode, parent);

    connect(&msgBox, &QDialog::finished, [=](){
        mask->deleteLater();
    });

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
