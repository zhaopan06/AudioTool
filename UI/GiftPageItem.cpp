#include "GiftPageItem.h"
#include "Global.h"
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
        QPixmap pix(path);
        pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->image->setPixmap(pix);
        m_path = path;
    });

    QString cornerMarkIcon = data["cornerMarkIcon"].toString();
    if(!cornerMarkIcon.isEmpty())
    {
        HttpInterFace::getInstance()->downLoad(cornerMarkIcon, [&](const QString &path) {
            QPixmap pix(path);
            pix = pix.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->label->setPixmap(pix);
        });
    }

    if(data["lockFlag"].toInt() == 0)
    {
        ui->lockImage->hide();
    }

    QString giftTag = data["giftTag"].toString();
    if(!giftTag.isEmpty())
    {
        ui->giftTag->setText(giftTag);
    }
    else
        ui->widget->hide();

}

void GiftPageItem::enterEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->width()*1.2, ui->image->height()*1.2,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}

void GiftPageItem::leaveEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}
