#include "MenuHomeownerRight.h"
#include "ui_MenuHomeownerRight.h"

MenuHomeownerRight::MenuHomeownerRight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuHomeownerRight)
{
    ui->setupUi(this);
}

MenuHomeownerRight::~MenuHomeownerRight()
{
    delete ui;
}
