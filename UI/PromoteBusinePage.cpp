#include "PromoteBusinePage.h"
#include "ui_PromoteBusinePage.h"

PromoteBusinePage::PromoteBusinePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PromoteBusinePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

PromoteBusinePage::~PromoteBusinePage()
{
    delete ui;
}

void PromoteBusinePage::on_topBtn_clicked()
{

}

void PromoteBusinePage::on_minBtn_clicked()
{

}

void PromoteBusinePage::on_closeBtn_clicked()
{

}

