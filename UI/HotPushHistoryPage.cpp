#include "HotPushHistoryPage.h"
#include "ui_HotPushHistoryPage.h"
#include "HttpInterFace.h"
#include "Global.h"
#include "HotPushHistoryPageItem.h"

HotPushHistoryPage::HotPushHistoryPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotPushHistoryPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->scrollAreaWidgetContents->layout()->setAlignment(Qt::AlignTop);

}

HotPushHistoryPage::~HotPushHistoryPage()
{
    delete ui;
}

void HotPushHistoryPage::init(QString roomid)
{
    HttpInterFace::getInstance()->getHotDataHistory(roomid,1, [&](const QVariant vat){
        QVariantMap data = vat.toMap();
        QVariantList list = data["data"].toList();
        for(auto au: list)
        {
            HotPushHistoryPageItem *item = new HotPushHistoryPageItem;
            item->setData(au.toMap());
            ui->list->addWidget(item);
        }

    });
}



void HotPushHistoryPage::on_pushButton_3_clicked()
{
    accept();
}


void HotPushHistoryPage::on_Attention_clicked()
{
    close();
}


void HotPushHistoryPage::on_closeBtn_clicked()
{
    close();
}

