#include "RoomItem.h"
#include "ui_RoomItem.h"

RoomItem::RoomItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomItem)
{
    ui->setupUi(this);
}

RoomItem::~RoomItem()
{
    delete ui;
}

void RoomItem::setData(QVariantMap data)
{
    m_data = data;
}

void RoomItem::on_imageLab_clicked()
{
    emit enterTheRoom(m_data);
}

