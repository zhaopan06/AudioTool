#include "ChatImageMyItem.h"
#include "ui_ChatImageMyItem.h"
#include "HttpInterFace.h"

ChatImageMyItem::ChatImageMyItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatImageMyItem)
{
    ui->setupUi(this);
}

ChatImageMyItem::~ChatImageMyItem()
{
    delete ui;
}

void ChatImageMyItem::setData(QString image, QString photo)
{
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    QPixmap pix = QPixmap::fromImage(QImage(image));
    pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setFixedWidth(pix.width());
    ui->image->setFixedHeight(pix.height());
    ui->image->setPixmap(pix);
    ui->image->setRadius(16);
}
