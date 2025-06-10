#include "MicInfoItem.h"
#include "Global.h"
#include "MenuHomeownerRight.h"
#include "MenuLockRight.h"
#include "UserinfoPageSimple.h"
#include "qmovie.h"
#include "qscreen.h"
#include "ui_MicInfoItem.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"
#include "MenuManagerRight.h"

MicInfoItem::MicInfoItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MicInfoItem)
{
    ui->setupUi(this);
    ui->image->installEventFilter(this);
    QMovie *movie = new QMovie(":/images/gifts/sound.gif");
    movie->setScaledSize(ui->label->size());
    ui->label->setMovie(movie);
    movie->start();
    ui->label->hide();
    ui->mic->hide();
}

MicInfoItem::~MicInfoItem()
{
    delete ui;
}

void MicInfoItem::setData(QVariantMap data, int num)
{
    if(0 == data["status"].toInt())
    {
        ui->mic->hide();
    }
    if(1 == data["status"].toInt())
    {
        ui->mic->show();
    }

    m_data = data;
    if(3 == data["status"].toInt())//锁麦状态
    {
        ui->gift->setIcon(QIcon(""));
        ui->gift->setText("");
        //TODO 设置锁麦图标
        ui->image->setPixmap(QPixmap::fromImage(QImage(":/images/live_mic_lock.png")));
        ui->name->setText(QString::number(num+1) +  tr("号麦"));
        return;
    }

    if(data["status"].toInt() == -1)
    {
        ui->gift->setIcon(QIcon(""));
        ui->gift->setText("");
        ui->image->setPixmap(QPixmap::fromImage(QImage(":/images/live_mic_path.png")));
        ui->name->setText(QString::number(num+1) +  tr("号麦"));
        m_multipleAuthoriation = "";
        return;
    }

    showMapTojson(data);
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

void MicInfoItem::setAudioValue(QString uid, int value)
{
    if(value < 30)
    {
        ui->label->hide();
        return;
    }

    if(uid == "0")
    {
        QString uid = m_data["member"].toMap()["userId"].toString();
        if(uid == HttpUserInfo::instance()->getUserID())
        {
            ui->label->show();
        }
    }
    else
    {       
        if(uid == m_data["member"].toMap()["userId"].toString())
        {          
            ui->label->show();
        }
    }
}

bool MicInfoItem::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->image)
    {
        if (event->type() == QEvent::Enter)
        {
            if(m_data["member"].toMap()["userId"].toString().isEmpty())
                return true;
            if(MenuManagerRight::getInstance()->isVisible())
                return true;
            QPoint labelGlobalPos = ui->image->mapToGlobal(QPoint(0, 0));
            UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
            page->init(m_data["member"].toMap()["userId"].toString());
            QPoint point1;
            point1.setX(labelGlobalPos.rx() - page->width());
            point1.setY(labelGlobalPos.ry());
            page->move(point1);
            page->show();
            return true;
        }
        else if (event->type() == QEvent::Leave)
        {
            QPoint mouseGlobalPos = QCursor::pos();
            QRect widgetAGeometry = UserinfoPageSimple::getInstance()->geometry();
            if (!widgetAGeometry.contains(mouseGlobalPos))
            {
                UserinfoPageSimple::getInstance()->uninit();
            }

            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
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
                UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
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

