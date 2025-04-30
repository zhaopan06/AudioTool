#include "LivePage.h"
#include "ui_LivePage.h"

LivePage::LivePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LivePage)
{
    ui->setupUi(this);
}

LivePage::~LivePage()
{
    delete ui;
}
