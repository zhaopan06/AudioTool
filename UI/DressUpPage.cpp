#include "DressUpPage.h"
#include "ui_DressUpPage.h"

DressUpPage::DressUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DressUpPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

DressUpPage::~DressUpPage()
{
    delete ui;
}

void DressUpPage::init()
{

}

void DressUpPage::on_pushButton_clicked()
{

}


void DressUpPage::on_closeBtn_clicked()
{
    close();
}

