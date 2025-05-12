#include "ChatImageItem.h"
#include "ui_ChatImageItem.h"
#include "HttpInterFace.h"

ChatImageItem::ChatImageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatImageItem)
{
    ui->setupUi(this);    
}

ChatImageItem::~ChatImageItem()
{
    delete ui;
}

void ChatImageItem::setData(QVariantMap data, QString imageUrl)
{
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    HttpInterFace::getInstance()->downLoad(imageUrl, [&](const QString &path) {

        QPixmap pix = QPixmap::fromImage(QImage(path));
        pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->image->setFixedWidth(pix.width());
        ui->image->setFixedHeight(pix.height());
        ui->image->setPixmap(pix);
        ui->image->setRadius(16);
    });

    QVariantMap userLevelCompare = data["userLevelCompare"].toMap();
    QString level = userLevelCompare["level"].toString();
    ui->user_lab->setText(level);

    QString multipleAuthoriation = data["multipleAuthoriation"].toString();
    if(multipleAuthoriation.size() > 6)
    {
        int num = QString(multipleAuthoriation.at(0)).toInt();
        if(2 == num)
        {
            ui->label_3->setText(tr("房主"));
        }
        else
        {
            num = QString(multipleAuthoriation.at(2)).toInt();
            if(1 == num)
            {
                ui->label_3->setText(tr("管理"));
            }
            else
            {
                ui->label_3->hide();
            }
        }
    }

}
