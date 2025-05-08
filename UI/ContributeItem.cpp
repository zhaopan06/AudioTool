#include "ContributeItem.h"
#include "ui_ContributeItem.h"
#include "HttpInterFace.h"

ContributeItem::ContributeItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ContributeItem)
{
    ui->setupUi(this);
}

ContributeItem::~ContributeItem()
{
    delete ui;
}

void ContributeItem::setData(QVariantMap data)
{
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    bool userInRoom = data["userInRoom"].toBool();
    ui->label_2->setVisible(userInRoom);

    int ranking = data["ranking"].toInt();
    switch (ranking) {
    case 1:
    {
        QString path = ":/images/top1.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        ui->label_3->setText(tr("当前"));
        ui->label_4->setText(tr("第一名"));
        break;
    }
    case 2:
    {
        QString path = ":/images/top2.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        break;
    }
    case 3:
    {
        QString path = ":/images/top3.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        break;
    }
    default:
        break;
    }

    if(ranking > 3)
    {
        ui->label->setText(QString::number(ranking));
        ui->label->setPixmap(QPixmap());
    }

    if(ranking > 1)
    {
        ui->label_3->setText(tr("距离前一名"));
        ui->label_4->setText(data["difference"].toString());
    }

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}
