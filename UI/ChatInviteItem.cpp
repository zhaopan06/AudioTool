#include "ChatInviteItem.h"
#include "ui_ChatInviteItem.h"
#include "HttpUserInfo.h"
#include "HttpInterFace.h"

ChatInviteItem::ChatInviteItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatInviteItem)
{
    ui->setupUi(this);
}

ChatInviteItem::~ChatInviteItem()
{
    delete ui;
}

void ChatInviteItem::setData(QVariantMap data)
{
    m_data = data;
    if(data["userId"].toString() != HttpUserInfo::instance()->getUserID())
    {
        ui->widget_4->hide();
        layout()->setAlignment(Qt::AlignRight);
        QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
        QString photoUrl = data["user"].toMap()["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
            ui->mySelfImage->setPixmap(QPixmap(path));
        });
    }
    else
    {
        ui->widget_5->hide();
        layout()->setAlignment(Qt::AlignLeft);
        QString photo = data["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
            ui->image->setPixmap(QPixmap(path));
        });
    }

    ui->roomId->setText(data["roomId"].toString());
    ui->roomName->setText(data["roomName"].toString());
    ui->name->setText(data["user_profile_nick_name"].toString());
    QString roomPhoto = data["roomPhoto"].toString();
    HttpInterFace::getInstance()->downLoad(roomPhoto, [&](const QString &path) {
        ui->roomPhoto->setPixmap(QPixmap(path));
        ui->roomPhoto->setRadius(16);
    });
}

void ChatInviteItem::on_roomPhoto_clicked()
{

}

