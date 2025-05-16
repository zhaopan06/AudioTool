#include "UserinfoPageGiftItem.h"
#include "ui_UserinfoPageGiftItem.h"
#include "HttpInterFace.h"

UserinfoPageGiftItem::UserinfoPageGiftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPageGiftItem)
{
    ui->setupUi(this);
}

UserinfoPageGiftItem::~UserinfoPageGiftItem()
{
    delete ui;
}

void UserinfoPageGiftItem::setData(QVariantMap data)
{
    ui->name->setText(data["giftName"].toString());
    ui->giftPrice->setText(data["giftPrice"].toString());
    ui->giftNum->setText(data["giftNum"].toString());

    QString photo = data["giftIcon"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap(path));
    });
}
