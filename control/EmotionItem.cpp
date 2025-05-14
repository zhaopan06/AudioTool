#include "EmotionItem.h"
#include "ui_EmotionItem.h"

EmotionItem::EmotionItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmotionItem)
{
    ui->setupUi(this);
}

EmotionItem::~EmotionItem()
{
    delete ui;
}

void EmotionItem::setData(QVariantMap data)
{
    m_data = data;
    QString path = data["path"].toString();
    ui->image->setPixmap(QPixmap(path));
    ui->name->setText(data["name"].toString());
}

void EmotionItem::on_addSourceBtn_2_clicked()
{
    emit clicked(m_data);
}

