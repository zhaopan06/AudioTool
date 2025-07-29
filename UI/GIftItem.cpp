#include "GIftItem.h"
#include "qdatetime.h"
#include "ui_GIftItem.h"

GIftItem::GIftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GIftItem)
{
    ui->setupUi(this);
}

GIftItem::~GIftItem()
{
    delete ui;
}

void GIftItem::setData(QVariantMap fromUser, QVariantMap gift, QVariantMap toUser)
{
    QString fromName = fromUser["name"].toString();
    QString giftNum = gift["giftNum"].toString();
    QString giftName = gift["name"].toString();
    QString toName = toUser["name"].toString();

    ui->timeLab->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

    QString label = QString("<span style='color: rgba(245, 151, 255, 1);'>%1</span>"
        "<span style='color: white;'> 对 </span>"
        "<span style='color: rgba(140, 231, 254, 1);'>%2</span>"
        "<span style='color: white;'> 送出 </span>"
        "<span style='color: white;'>%3 x%4</span>").arg(fromName, toName, giftName, giftNum);

    ui->label->setText(label);

}
