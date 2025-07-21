#include "HotPushPage.h"
#include "ui_HotPushPage.h"
#include "HttpInterFace.h"
#include "Global.h"
#include "HotPushPageItem.h"
#include "HttpUserInfo.h"
#include "HotPushHistoryPage.h"
#include "ToastPage.h"

HotPushPage::HotPushPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HotPushPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->pushButton->setLayoutDirection(Qt::RightToLeft);
}

HotPushPage::~HotPushPage()
{
    delete ui;
}

void HotPushPage::init(QString roomID)
{
    HttpInterFace::getInstance()->getHouPushData(roomID, [&](const QVariant &data){

        QVariantMap mapData = data.toMap()["data"].toMap();
        QVariantList referralPlaceConfigList = mapData["referralPlaceConfigList"].toList();

        QButtonGroup *checkGroup = new QButtonGroup();
        for (int var = 0; var < referralPlaceConfigList.size(); ++var)
        {
            HotPushPageItem *item = new HotPushPageItem;
            item->setData(referralPlaceConfigList.at(var).toMap(), checkGroup);
            connect(item, &HotPushPageItem::clickData, this, [&](QVariantMap data){
                m_clickData = data;
            });

            int row = var / 3;
            int col = var % 3;
            ui->gridLayout->addWidget(item,row, col);
        }

        QString date = mapData["recommTime"].toString();
        ui->dateBtn->setText(date);
        ui->myCardNum->setText(mapData["myCardNum"].toString());

    });
}

void HotPushPage::on_closeBtn_clicked()
{
    close();
}

void HotPushPage::on_pushButton_3_clicked()
{
    QString placeId = m_clickData["id"].toString();
    QString roomId = HttpUserInfo::instance()->getClassRoomID();

    if(ui->myCardNum->text().toInt() <= 0 )
    {
        ToastPage::showToast(this, QStringLiteral("热推卡数量不足"));
        return;
    }
    HttpInterFace::getInstance()->useReferralCard(placeId, roomId, [&](const QVariant &data){

    });
}


void HotPushPage::on_Attention_clicked()
{
    close();
}


void HotPushPage::on_pushButton_clicked()
{
    HotPushHistoryPage page;
    page.init(g_roomID);
    page.exec();
}

