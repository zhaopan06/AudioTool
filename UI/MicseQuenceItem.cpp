#include "MicseQuenceItem.h"
#include "ui_MicseQuenceItem.h"

MicseQuenceItem::MicseQuenceItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MicseQuenceItem)
{
    ui->setupUi(this);
}

MicseQuenceItem::~MicseQuenceItem()
{
    delete ui;
}

void MicseQuenceItem::setData(QVariantMap data)
{
    m_data = data;
}

void MicseQuenceItem::on_micBtn_clicked()
{

}

