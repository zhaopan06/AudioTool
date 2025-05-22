#include "GiftPage.h"
#include "GiftPageItem.h"
#include "Global.h"
#include "qscrollbar.h"
#include "ui_GiftPage.h"
#include "HttpInterFace.h"
#include <windows.h>
#include "HttpUserInfo.h"

GiftPage::GiftPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GiftPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->gridLayout_2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

GiftPage::~GiftPage()
{
    delete ui;
}

bool GiftPage::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG")
    {
        MSG* msg = (MSG*)message;
        switch(msg->message)
        {
        case WM_NCACTIVATE:
            bool active = (bool)(msg->wParam);
            if(!active)
            {
                this->hide();
            }
        }
    }
    return QWidget::nativeEvent(eventType, message, result);//交给Qt处理
}

void GiftPage::init()
{
    QString roomID = HttpUserInfo::instance()->getClassRoomID();
    QVariantMap data = HttpInterFace::getInstance()->getGiftList();
    QVariantList list = data["data"].toMap()["giftResponseVos"].toList();
    m_list = list;
    m_number = 20;
    foreach (QVariant var, list)
    {
        if(QStringLiteral("礼物") ==  var.toMap()["name"].toString())
        {
            QVariantList list = var.toMap()["giftResponseList"].toList();
            m_giftList = list;
            m_number = list.size() > 20? 20 : list.size();
            for (int var = 0; var < m_number; ++var)
            {
                GiftPageItem *item = new GiftPageItem;
                item->setData(list.at(var).toMap());

                int row = var / 4;
                int col = var % 4;
                ui->gridLayout->addWidget(item,row, col);
            }
        }
    }

    connect(ui->scrollArea->verticalScrollBar(), &QScrollBar::valueChanged,
            [=](int value){
                int max = ui->scrollArea->verticalScrollBar()->maximum();
                if(value >= max-20)
                {
                    if(m_number == m_giftList.size())
                        return;
                    for (int var = m_number; var < m_giftList.size(); ++var)
                    {
                        GiftPageItem *item = new GiftPageItem;
                        item->setData(m_giftList.at(var).toMap());

                        int row = var / 4;
                        int col = var % 4;
                        ui->gridLayout->addWidget(item,row, col);
                    }
                    m_number = m_giftList.size();
                }
            });

    ui->label_2->setText(data["data"].toMap()["balance"].toString());
}


void GiftPage::on_pushButton_clicked()
{

}


void GiftPage::on_giftBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void GiftPage::on_gift1Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    cleanupLayout(ui->gridLayout_2);
    foreach (QVariant var, m_list)
    {
        if(QStringLiteral("礼盒") ==  var.toMap()["name"].toString())
        {
            QVariantList list = var.toMap()["giftResponseList"].toList();
            for (int var = 0; var < list.size(); ++var)
            {
                GiftPageItem *item = new GiftPageItem;
                item->setData(list.at(var).toMap());

                int row = var / 4;
                int col = var % 4;
                ui->gridLayout_2->addWidget(item,row, col);
            }
        }
    }
}

void GiftPage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    cleanupLayout(ui->gridLayout_2);
    foreach (QVariant var, m_list)
    {
        if(QStringLiteral("VIP") ==  var.toMap()["name"].toString())
        {
            QVariantList list = var.toMap()["giftResponseList"].toList();
            for (int var = 0; var < list.size(); ++var)
            {
                GiftPageItem *item = new GiftPageItem;
                item->setData(list.at(var).toMap());

                int row = var / 4;
                int col = var % 4;
                ui->gridLayout_2->addWidget(item,row, col);
            }
        }
    }
}


void GiftPage::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    cleanupLayout(ui->gridLayout_2);
    foreach (QVariant var, m_list)
    {
        if(QStringLiteral("背包") ==  var.toMap()["name"].toString())
        {
            QVariantList list = var.toMap()["giftResponseList"].toList();
            for (int var = 0; var < list.size(); ++var)
            {
                GiftPageItem *item = new GiftPageItem;
                item->setData(list.at(var).toMap());

                int row = var / 4;
                int col = var % 4;
                ui->gridLayout_2->addWidget(item,row, col);
            }
        }
    }
}

