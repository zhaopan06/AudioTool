#include "MenuLockRight.h"
#include "HttpInterFace.h"
#include "ui_MenuLockRight.h"
#include <windows.h>

MenuLockRight* MenuLockRight::pMenuLockRightFace = NULL;
MenuLockRight *MenuLockRight::getInstance()
{
    if(pMenuLockRightFace == NULL)
    {
        pMenuLockRightFace = new MenuLockRight();
    }
    return pMenuLockRightFace;
}

MenuLockRight::MenuLockRight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuLockRight)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

bool MenuLockRight::nativeEvent(const QByteArray &eventType, void *message, long *result)
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

MenuLockRight::~MenuLockRight()
{
    delete ui;
}

void MenuLockRight::setData(QVariantMap data)
{
    m_data = data;
    //1=闭麦，3=锁麦
    if(3 == m_data["status"].toInt())
    {
        ui->pushButton->setText(tr("取消锁麦"));
    }
    else
    {
        ui->pushButton->setText(tr("锁麦"));
    }
}

void MenuLockRight::on_pushButton_clicked()
{
    this->hide();
    int mic_index = m_data["mic_index"].toInt();
    if(3 == m_data["status"].toInt())
    {
        HttpInterFace::getInstance()->lockMic(0,mic_index);
    }
    else
    {
        HttpInterFace::getInstance()->lockMic(1,mic_index);
    }
}

