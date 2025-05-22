#include "MicInfoItem.h"
#include "Global.h"
#include "MenuHomeownerRight.h"
#include "MenuLockRight.h"
#include "UserinfoPage.h"
#include "ui_MicInfoItem.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"
#include "MenuManagerRight.h"

MicInfoItem::MicInfoItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MicInfoItem)
{
    ui->setupUi(this);
}

MicInfoItem::~MicInfoItem()
{
    delete ui;
}

void MicInfoItem::setData(QVariantMap data, int num)
{
    m_data = data;
    if(3 == m_data["status"].toInt())//锁麦状态
    {
        ui->gift->setIcon(QIcon(""));
        ui->gift->setText("");
        //TODO 设置锁麦图标
        ui->image->setPixmap(QPixmap::fromImage(QImage(":/images/live_mic_path.png")));
        ui->name->setText(QString::number(num+1) +  tr("号麦"));
        return;
    }
    QVariantMap map = data["member"].toMap();
    if(data["status"].toInt() >= 0)
    {
        if(map.empty())
        {
            ui->name->setText(QString::number(num+1) +  tr("号麦"));
            return;
        }

        ui->gift->setIcon(QIcon(":/images/mic_gift.png"));
        ui->gift->setText(map["cardiac"].toString());
        ui->name->setText(map["name"].toString());

        QString photo = map["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
            this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
        });
    }
    else
    {
        ui->gift->setIcon(QIcon(""));
        ui->gift->setText("");
        ui->image->setPixmap(QPixmap::fromImage(QImage(":/images/live_mic_path.png")));
        ui->name->setText(QString::number(num+1) +  tr("号麦"));
    }

    if(map["userId"].toString() == HttpUserInfo::instance()->getUserID())
    {
        emit setMyselfMicInfo(data["status"].toInt());
    }

    m_multipleAuthoriation = m_data["member"].toMap()["multipleAuthoriation"].toString();
}

QString MicInfoItem::getUserId()
{
    return m_data["member"].toMap()["userId"].toString();
}

void MicInfoItem::updateData(QVariantMap data)
{
    ui->gift->setText(data["cardiac"].toString());
}

void MicInfoItem::updateMultipleAuthoriation(QString str)
{
    m_multipleAuthoriation = str;
}

void MicInfoItem::on_image_rightClicked()
{    
     QPoint point = QCursor::pos();
    if(-1 == m_data["status"].toInt())//空闲
    {
         MenuLockRight::getInstance()->setData(m_data);
         MenuLockRight::getInstance()->move(point);
         MenuLockRight::getInstance()->show();
    }
    else if(3 == m_data["status"].toInt())//锁麦状态
    {        
        MenuLockRight::getInstance()->setData(m_data);
        MenuLockRight::getInstance()->move(point);
        MenuLockRight::getInstance()->show();
    }
    else
    {        
        if(g_isHomeowner)
        {
            showMapTojson(m_data);
            MenuHomeownerRight::getInstance()->setData(m_data, m_multipleAuthoriation);
            MenuHomeownerRight::getInstance()->move(point);
            MenuHomeownerRight::getInstance()->show();
        }
        else if(g_isManager)
        {
            MenuManagerRight::getInstance()->setData(m_data);
            MenuManagerRight::getInstance()->move(point);
            MenuManagerRight::getInstance()->show();
        }
        else
        {
            QString type = g_multipleAuthoriation.at(0);
            if(type.toInt() == 1)
            {
                UserinfoPage *page = UserinfoPage::getInstance();
                QString uid = m_data["member"].toMap()["userId"].toString();
                page->init(uid);
                QPoint point1;
                QPoint labelGlobalPos = ui->image->mapToGlobal(QPoint(0, 0));
                point1.setX(labelGlobalPos.rx() - page->width());
                point1.setY(labelGlobalPos.ry());
                page->move(point1);
                page->show();
                return;
            }
        }
    }
}

