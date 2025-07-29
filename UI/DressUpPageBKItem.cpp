#include "DressUpPageBKItem.h"
#include "ui_DressUpPageBKItem.h"
#include "HttpInterFace.h"
#include "Global.h"
DressUpPageBKItem::DressUpPageBKItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DressUpPageBKItem)
{
    ui->setupUi(this);
}

DressUpPageBKItem::~DressUpPageBKItem()
{
    delete ui;
}

void DressUpPageBKItem::setData(QVariantMap data)
{
    m_data = data;
    QString photo = data["src"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        QPixmap pix(path);
        pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        ui->image->setPixmap(pix);
        ui->image->setRadius(12);
        ui->image->setMove();
        m_path = path;
    });
    QString name = data["name"].toString();
    ui->name->setText(name);
    bool wear = data["wear"].toBool();
    ui->label->setVisible(wear);
    QString diffDate = data["diffDate"].toString();
    if(diffDate.isEmpty())
        ui->time->setText(QStringLiteral("通用"));
    else
        ui->time->setText(QStringLiteral("剩余") + diffDate + QStringLiteral("天"));
}

void DressUpPageBKItem::setclick(bool click)
{
    if(!click)
    {
        ui->image_2->setStyleSheet("background: transparent;");
    }
}

void DressUpPageBKItem::enterEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->size()*1.2, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}

void DressUpPageBKItem::leaveEvent(QEvent *event)
{
    QPixmap pix(m_path);
    pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
}

void DressUpPageBKItem::on_image_2_clicked()
{
    ui->image_2->setStyleSheet("border-radius: 12px;"
                             "background: transparent;"
                             "border: 3px solid rgba(240, 150, 242, 1);");
    emit item_click(m_data);
}

