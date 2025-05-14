#include "GiftPageItem.h"
#include "ui_GiftPageItem.h"
#include "HttpInterFace.h"

GiftPageItem::GiftPageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GiftPageItem)
{
    ui->setupUi(this);
}

GiftPageItem::~GiftPageItem()
{
    delete ui;
}

void GiftPageItem::setData(QVariantMap data)
{
    ui->name->setText(data["name"].toString());
    ui->price->setText(data["price"].toString());
    HttpInterFace::getInstance()->downLoad(data["icon"].toString(), [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}
