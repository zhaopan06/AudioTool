#include "MenuManagerRight.h"
#include "ui_MenuManagerRight.h"

MenuManagerRight::MenuManagerRight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuManagerRight)
{
    ui->setupUi(this);
}

MenuManagerRight::~MenuManagerRight()
{
    delete ui;
}
