#include "HotPushHistoryPageItem.h"
#include "ui_HotPushHistoryPageItem.h"

HotPushHistoryPageItem::HotPushHistoryPageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotPushHistoryPageItem)
{
    ui->setupUi(this);
}

HotPushHistoryPageItem::~HotPushHistoryPageItem()
{
    delete ui;
}

void HotPushHistoryPageItem::setData(QVariantMap data)
{
    m_data = data;
    ui->count->setText(data["count"].toString());
    ui->useTime->setText(data["useTime"].toString());
    ui->placeName->setText(data["placeName"].toString());
    ui->time->setText(data["time"].toString());
}
