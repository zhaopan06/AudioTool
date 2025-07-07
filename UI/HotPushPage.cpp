#include "HotPushPage.h"
#include "ui_HotPushPage.h"

HotPushPage::HotPushPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotPushPage)
{
    ui->setupUi(this);
}

HotPushPage::~HotPushPage()
{
    delete ui;
}

void HotPushPage::on_closeBtn_clicked()
{
    close();
}

