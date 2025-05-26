#include "ChatPageLeftItem.h"
#include "ui_ChatPageLeftItem.h"

ChatPageLeftItem::ChatPageLeftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageLeftItem)
{
    ui->setupUi(this);
}

ChatPageLeftItem::~ChatPageLeftItem()
{
    delete ui;
}
