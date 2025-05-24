#include "MenuHomeownerRight.h"
#include "Global.h"
#include "UserinfoPageSimple.h"
#include "ui_MenuHomeownerRight.h"
#include <windows.h>
#include "HttpInterFace.h"

MenuHomeownerRight* MenuHomeownerRight::pMenuHomeownerRightFace = NULL;
MenuHomeownerRight *MenuHomeownerRight::getInstance()
{
    if(pMenuHomeownerRightFace == NULL)
    {
        pMenuHomeownerRightFace = new MenuHomeownerRight();
    }
    return pMenuHomeownerRightFace;
}

MenuHomeownerRight::MenuHomeownerRight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuHomeownerRight)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

MenuHomeownerRight::~MenuHomeownerRight()
{
    delete ui;
}

void MenuHomeownerRight::setData(QVariantMap data, QString multipleAuthoriation)
{
    m_data = data;
    if(0 == m_data["status"].toInt())//闭麦
    {
        ui->pushButton->setText(tr("闭麦"));
    }
    if(1 == m_data["status"].toInt())//开麦
    {
        ui->pushButton->setText(tr("开麦"));
    }

    m_multipleAuthoriation = multipleAuthoriation;
    QString type = multipleAuthoriation.at(2);
    if(type.toInt() == 1)
    {
        ui->pushButton_12->setText(tr("取消管理"));
    }
    else
    {
        ui->pushButton_12->setText(tr("设为管理"));
    }
    type = multipleAuthoriation.at(1);
    if(type.toInt() == 1)
    {
        ui->pushButton_13->setText(tr("取消主持"));
    }
    else
    {
        ui->pushButton_13->setText(tr("设为主持"));
    }
}

bool MenuHomeownerRight::nativeEvent(const QByteArray &eventType, void *message, long *result)
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

void MenuHomeownerRight::on_pushButton_clicked()
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

//下麦
void MenuHomeownerRight::on_pushButton_2_clicked()
{
    QString uid = m_data["member"].toMap()["userId"].toString();
    HttpInterFace::getInstance()->b_upMic(g_roomID, uid);
}

//聊天
void MenuHomeownerRight::on_pushButton_10_clicked()
{

}

//看资料
void MenuHomeownerRight::on_pushButton_9_clicked()
{
    this->hide();

    UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
    QString uid = m_data["member"].toMap()["userId"].toString();
    page->init(uid);
    QPoint point1;
    QPoint labelGlobalPos = mapToGlobal(QPoint(0, 0));
    point1.setX(labelGlobalPos.rx() - page->width());
    point1.setY(labelGlobalPos.ry() - page->height()/2);
    page->move(point1);
    page->show();
}

//设为管理
void MenuHomeownerRight::on_pushButton_12_clicked()
{
    QVariantMap data;
    this->hide();
    QString multipleAuthoriation = m_multipleAuthoriation;
    QString type = multipleAuthoriation.at(2);
    if(type.toInt() == 1)
    {
        QString uid = m_data["member"].toMap()["userId"].toString();
        data = HttpInterFace::getInstance()->settingEmceeOrAdmin(3, uid);
    }
    else
    {
        QString uid = m_data["member"].toMap()["userId"].toString();
        data = HttpInterFace::getInstance()->settingEmceeOrAdmin(1, uid);
    }
    showMapTojson(data);
}

//设为主持人
void MenuHomeownerRight::on_pushButton_13_clicked()
{
    QVariantMap data;
    this->hide();
    QString multipleAuthoriation = m_multipleAuthoriation;
    QString type = multipleAuthoriation.at(1);
    if(type.toInt() == 1)
    {
        QString uid = m_data["member"].toMap()["userId"].toString();
        data = HttpInterFace::getInstance()->settingEmceeOrAdmin(2, uid);
    }
    else
    {
        QString uid = m_data["member"].toMap()["userId"].toString();
        data = HttpInterFace::getInstance()->settingEmceeOrAdmin(0, uid);
    }
    showMapTojson(data);
}


void MenuHomeownerRight::on_pushButton_14_clicked()
{
    //禁言
}

