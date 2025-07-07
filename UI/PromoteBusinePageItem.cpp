#include "PromoteBusinePageItem.h"
#include "ui_PromoteBusinePageItem.h"
#include "HttpInterFace.h"

PromoteBusinePageItem::PromoteBusinePageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PromoteBusinePageItem)
{
    ui->setupUi(this);
}

PromoteBusinePageItem::~PromoteBusinePageItem()
{
    delete ui;
}

void PromoteBusinePageItem::setData(QVariantMap data)
{
    m_data = data;

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        ui->photo->setPixmap(QPixmap(path));
        ui->photo->setRadius(6);
    });
    ui->hotValue->setText(data["hotValue"].toString());
    ui->name->setText(data["name"].toString());
    ui->roomId->setText(QStringLiteral("ID：") + data["roomId"].toString());
}

void PromoteBusinePageItem::on_photo_clicked()
{
    emit showRoomId(m_data["roomId"].toString());
}

