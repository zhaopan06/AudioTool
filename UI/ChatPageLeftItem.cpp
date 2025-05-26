#include "ChatPageLeftItem.h"
#include "ui_ChatPageLeftItem.h"
#include "HttpInterFace.h"

ChatPageLeftItem::ChatPageLeftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageLeftItem)
{
    ui->setupUi(this);
    //TODO获取历史数据
    //TIMMsgGetMessageReactions
}

ChatPageLeftItem::~ChatPageLeftItem()
{
    delete ui;
}

void ChatPageLeftItem::setData(QVariantMap data, QString text)
{
    QString user_profile_face_url = data["user_profile_face_url"].toString();
    QString name = data["user_profile_nick_name"].toString();
    ui->name->setText(name);
    ui->text->setText(text);

    HttpInterFace::getInstance()->downLoad(user_profile_face_url, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });
}
