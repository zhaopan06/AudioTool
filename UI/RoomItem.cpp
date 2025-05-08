#include "RoomItem.h"
#include "ui_RoomItem.h"
#include "HttpInterFace.h"

RoomItem::RoomItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomItem)
{
    ui->setupUi(this);
}

RoomItem::~RoomItem()
{
    delete ui;
}

void RoomItem::setData(QVariantMap roomInfo)
{
    m_data = roomInfo;
    QString fName = roomInfo["name"].toString();
    ui->roomName->setText(fName);

    QString userName = QStringLiteral("房主：") + roomInfo["roomOwnerName"].toString();
    ui->userName->setText(userName);


    QString hotValue = roomInfo["hotValue"].toString();
    ui->hotValue->setText(hotValue);

    QString fPhotoUrl = roomInfo["photo"].toString();
    HttpInterFace::getInstance()->downLoad(fPhotoUrl, [&](const QString &path) {
        this->ui->imageLab->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}

void RoomItem::on_imageLab_clicked()
{
    emit enterTheRoom(m_data);
}

