#include "ChatImageItem.h"
#include "ui_ChatImageItem.h"

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

void ChatImageItem::setData(QVariantMap data)
{

}
