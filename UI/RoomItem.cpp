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
        QPixmap pix(path);
        pix = pix.scaled(ui->imageLab->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        ui->imageLab->setPixmap(pix);
        ui->imageLab->setRadius(16);
        ui->imageLab->setMove();
        m_path = path;
    });
}

void RoomItem::on_imageLab_clicked()
{
    emit enterTheRoom(m_data);
}

void RoomItem::enterEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->imageLab->size()*1.2, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->imageLab->setPixmap(pix);
}

void RoomItem::leaveEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->imageLab->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->imageLab->setPixmap(pix);
}
