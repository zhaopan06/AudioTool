#include "HotPushPageItem.h"
#include "ui_HotPushPageItem.h"
#include <QDebug>

HotPushPageItem::HotPushPageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotPushPageItem)
{
    ui->setupUi(this);
}

HotPushPageItem::~HotPushPageItem()
{
    delete ui;
}

void HotPushPageItem::setData(QVariantMap data,QButtonGroup *group)
{
    m_data = data;
    ui->name->setText(data["placeName"].toString());
    ui->activateNum->setText(data["activateNum"].toString());
    ui->consume->setText(data["consume"].toString());
    group->addButton(ui->pushButton);
}

void HotPushPageItem::mouseReleaseEvent(QMouseEvent *)
{
    ui->pushButton->setChecked(!ui->pushButton->isChecked());
    emit clickData(m_data);
}
