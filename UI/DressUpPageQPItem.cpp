#include "DressUpPageQPItem.h"
#include "ui_DressUpPageQPItem.h"
#include "HttpInterFace.h"
#include "Global.h"

DressUpPageQPItem::DressUpPageQPItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DressUpPageQPItem)
{
    ui->setupUi(this);
}

DressUpPageQPItem::~DressUpPageQPItem()
{
    delete ui;
}

void DressUpPageQPItem::setData(QVariantMap data)
{
    QString name = data["name"].toString();
    ui->name->setText(name);
    bool wear = data["wear"].toBool();
    ui->label->setVisible(wear);
    QString diffDate = data["diffDate"].toString();
    if(diffDate.isEmpty())
        ui->time->setText(QStringLiteral("通用"));
    else
        ui->time->setText(QStringLiteral("剩余") + diffDate + QStringLiteral("天"));

    QString photo = data["icon"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        QPixmap pix(path);
        pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->image->setPixmap(pix);
        ui->image->setRadius(16);
        ui->image->setMove();
        m_path = path;
    });
}

void DressUpPageQPItem::enterEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->width()*1.2,ui->image->height()*1.2,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}

void DressUpPageQPItem::leaveEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}

