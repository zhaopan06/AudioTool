#include "MenuManagerRight.h"
#include "Global.h"
#include "UserinfoPageSimple.h"
#include "ui_MenuManagerRight.h"
#include <windows.h>
#include "HttpInterFace.h"

MenuManagerRight* MenuManagerRight::pMenuManagerRightFace = NULL;
MenuManagerRight *MenuManagerRight::getInstance()
{
    if(pMenuManagerRightFace == NULL)
    {
        pMenuManagerRightFace = new MenuManagerRight();
    }
    return pMenuManagerRightFace;
}

MenuManagerRight::MenuManagerRight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuManagerRight)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

MenuManagerRight::~MenuManagerRight()
{
    delete ui;
}

bool MenuManagerRight::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG")
    {
        MSG* msg = (MSG*)message;
        switch(msg->message)
        {
        case WM_NCACTIVATE:
            bool active = (bool)(msg->wParam);
            if(!active)
            {
                this->hide();
            }
        }
    }
    return QWidget::nativeEvent(eventType, message, result);
}

void MenuManagerRight::setData(QVariantMap data)
{
    m_data = data;
    if(0 == m_data["status"].toInt())//闭麦
    {
        ui->pushButton_3->setText(tr("闭麦"));
    }
    if(1 == m_data["status"].toInt())//开麦
    {
        ui->pushButton_3->setText(tr("开麦"));
    }
}

void MenuManagerRight::on_pushButton_3_clicked()
{
    this->hide();

    QString uid = m_data["member"].toMap()["userId"].toString();
    if(0 == m_data["status"].toInt())//开麦状态
    {
        HttpInterFace::getInstance()->micOpenOrClose(g_roomID, uid, 1);
    }
    if(1 == m_data["status"].toInt())//闭麦状态
    {
        HttpInterFace::getInstance()->micOpenOrClose(g_roomID, uid, 0);
    }
}


void MenuManagerRight::on_pushButton_4_clicked()
{
    this->hide();
    UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
    QString uid = m_data["member"].toMap()["userId"].toString();
    page->init(uid);
    QPoint point1;
    QPoint labelGlobalPos = mapToGlobal(QPoint(0, 0));
    point1.setX(labelGlobalPos.rx() - page->width());
    point1.setY(labelGlobalPos.ry());
    page->move(point1);
    page->show();
}

//抱下麦
void MenuManagerRight::on_pushButton_2_clicked()
{
    this->hide();
    QString uid = m_data["member"].toMap()["userId"].toString();
    HttpInterFace::getInstance()->b_downMic(g_roomID, uid);
}

