#include "ChatEmoTionItem.h"
#include "ui_ChatEmoTionItem.h"

ChatEmoTionItem::ChatEmoTionItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatEmoTionItem)
{
    ui->setupUi(this);
}

ChatEmoTionItem::~ChatEmoTionItem()
{
    delete ui;
}
