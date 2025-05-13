#include "MicInfoItem.h"
#include "ui_MicInfoItem.h"
#include "HttpInterFace.h"

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
    if(data["status"].toInt() >= 0)
    {
        QVariantMap map = data["member"].toMap();
        ui->gift->setIcon(QIcon(":/images/mic_gift.png"));
        ui->gift->setText(map["cardiac"].toString());

        ui->name->setText(map["name"].toString());

        QString photo = map["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
            this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
        });
    }
    else
        ui->name->setText(QString::number(num+1) +  tr("号麦"));
}
