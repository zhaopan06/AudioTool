#include "ManagementPage.h"
#include "qevent.h"
#include "ui_ManagementPage.h"

ManagementPage::ManagementPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagementPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

ManagementPage::~ManagementPage()
{
    delete ui;
}

void ManagementPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void ManagementPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void ManagementPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void ManagementPage::on_closeBtn_clicked()
{
    this->close();
}


void ManagementPage::on_button1_1_clicked()
{

}

void ManagementPage::on_button1_3_clicked()
{

}

void ManagementPage::on_button1_2_clicked()
{

}

void ManagementPage::on_button1_4_clicked()
{

}

