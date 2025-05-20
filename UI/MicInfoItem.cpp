#include "MicInfoItem.h"
#include "ui_MicInfoItem.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"

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

    m_data = map;
}

QString MicInfoItem::getUserId()
{
    return m_data["userId"].toString();
}

void MicInfoItem::updateData(QVariantMap data)
{
    ui->gift->setText(data["cardiac"].toString());
}

void MicInfoItem::on_image_rightClicked()
{

}

