#include "RoomInvitePage.h"
#include "qevent.h"
#include "ui_RoomInvitePage.h"

RoomInvitePage::RoomInvitePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomInvitePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RoomInvitePage::~RoomInvitePage()
{
    delete ui;
}

void RoomInvitePage::setData(QVariantMap data)
{

}

void RoomInvitePage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void RoomInvitePage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void RoomInvitePage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void RoomInvitePage::on_lineEdit_textChanged(const QString &arg1)
{
    int number = arg1.size();
    ui->label_4->setText(QString::number(number));
}


void RoomInvitePage::on_textEdit_textChanged()
{
    QString arg1 = ui->textEdit->toPlainText();
    int number = arg1.size();
    ui->label_6->setText(QString::number(number));
}

//更换封面
void RoomInvitePage::on_image_clicked()
{

}


void RoomInvitePage::on_okBtn_clicked()
{

}


void RoomInvitePage::on_cancelBtn_clicked()
{
    close();
}


void RoomInvitePage::on_closeBtn_clicked()
{
    close();
}

