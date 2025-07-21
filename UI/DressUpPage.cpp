#include "DressUpPage.h"
#include "ui_DressUpPage.h"

DressUpPage::DressUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DressUpPage)
{
    ui->setupUi(this);
}

DressUpPage::~DressUpPage()
{
    delete ui;
}

void DressUpPage::on_pushButton_clicked()
{

}

