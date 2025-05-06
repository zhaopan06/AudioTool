#include "OnlineItem.h"
#include "ui_OnlineItem.h"

OnlineItem::OnlineItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OnlineItem)
{
    ui->setupUi(this);
}

OnlineItem::~OnlineItem()
{
    delete ui;
}

void OnlineItem::setData(QVariantMap data, int type)
{
    if(type == 0)
    {
        ui->user_btn->hide();
        ui->user_lab->hide();
    }
    else if(type == 1)
    {
        ui->room_btn->hide();
        ui->room_lab->hide();
    }

    m_data = data;
}
