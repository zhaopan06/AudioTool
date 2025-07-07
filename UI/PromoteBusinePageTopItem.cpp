#include "PromoteBusinePageTopItem.h"
#include "Global.h"
#include "ui_PromoteBusinePageTopItem.h"
#include "HttpInterFace.h"

PromoteBusinePageTopItem::PromoteBusinePageTopItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PromoteBusinePageTopItem)
{
    ui->setupUi(this);
}

PromoteBusinePageTopItem::~PromoteBusinePageTopItem()
{
    delete ui;
}

void PromoteBusinePageTopItem::setData(QVariantMap data)
{
    m_data = data;
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

        ui->widget_2->setStyleSheet("QWidget#widget_2 {"
                                    "background-image: url(:/images/bk_top1.png);"
                                    "background-position: center;"
                                    "background-repeat: no-repeat;"
                                    "}");
        ui->nameLab->setStyleSheet("font-size: 16px;"
                                   "color: #A96A00;"
                                   "line-height: 20px;"
                                   "font-style: normal;");

        break;
    }
    case 2:
    {
        QString path = ":/images/top2.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));

        ui->widget_2->setStyleSheet("QWidget#widget_2 {"
                                    "background-image: url(:/images/bk_top2.png);"
                                    "background-position: center;"
                                    "background-repeat: no-repeat;"
                                    "}");
        ui->nameLab->setStyleSheet("font-size: 16px;"
                                   "color: #4A515B;"
                                   "line-height: 20px;"
                                   "font-style: normal;");

        break;
    }
    case 3:
    {
        QString path = ":/images/top3.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));

        ui->widget_2->setStyleSheet("QWidget#widget_2 {"
                                    "background-image: url(:/images/bk_top3.png);"
                                    "background-position: center;"
                                    "background-repeat: no-repeat;"
                                    "}");
        ui->nameLab->setStyleSheet("font-size: 16px;"
                                   "color: #A8531C;"
                                   "line-height: 20px;"
                                   "font-style: normal;");

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

void PromoteBusinePageTopItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"double click";
    showMapTojson(m_data);
    emit ChatC2C(m_data["userId"].toString());
}
