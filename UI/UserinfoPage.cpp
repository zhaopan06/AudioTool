#include "UserinfoPage.h"
#include "ui_UserinfoPage.h"

UserinfoPage::UserinfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPage)
{
    ui->setupUi(this);
}

UserinfoPage::~UserinfoPage()
{
    delete ui;
}
