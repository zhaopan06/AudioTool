#include "UserinfoPageMedalItem.h"
#include "ui_UserinfoPageMedalItem.h"
#include "HttpInterFace.h"

UserinfoPageMedalItem::UserinfoPageMedalItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPageMedalItem)
{
    ui->setupUi(this);
}

UserinfoPageMedalItem::~UserinfoPageMedalItem()
{
    delete ui;
}

void UserinfoPageMedalItem::setData(QVariantMap data)
{
     ui->name->setText(data["title"].toString());

    QString photo = data["medalUrl"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap(path));
    });
}
