#include "ChatPageC2C.h"
#include "ui_ChatPageC2C.h"

ChatPageC2C::ChatPageC2C(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2C)
{
    ui->setupUi(this);
}

ChatPageC2C::~ChatPageC2C()
{
    delete ui;
}
