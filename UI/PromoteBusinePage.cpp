#include "PromoteBusinePage.h"
#include "Global.h"
#include "PromoteBusinePageItem.h"
#include "PromoteBusinePageTopItem.h"
#include "ui_PromoteBusinePage.h"
#include "HttpInterFace.h"

PromoteBusinePage::PromoteBusinePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PromoteBusinePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->listWidget->setAlignment(Qt::AlignTop);
    ui->contList->setAlignment(Qt::AlignTop);
}

PromoteBusinePage::~PromoteBusinePage()
{
    delete ui;
}

void PromoteBusinePage::init(QString roomId)
{
    m_roomId = roomId;
    HttpInterFace::getInstance()->getRecommendRoom(roomId,[&](QVariant vart){

        QVariantList list = vart.toMap()["data"].toMap()["recommendRoom"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            PromoteBusinePageItem *item  =new PromoteBusinePageItem;
            connect(item, &PromoteBusinePageItem::showRoomId, this, [&](QString roomID){
                m_currRoomId = roomID;
                on_day_btn_clicked();
            });
            item->setData(data);
            ui->listWidget->addWidget(item);
        }
    });
}

void PromoteBusinePage::on_topBtn_clicked()
{

}

void PromoteBusinePage::on_minBtn_clicked()
{
    showMinimized();
}

void PromoteBusinePage::on_closeBtn_clicked()
{
    close();
}


void PromoteBusinePage::on_pushButton_clicked()
{
    cleanupLayout(ui->listWidget);
    init(m_roomId);
}


void PromoteBusinePage::on_pushButton_2_clicked()
{
    cleanupLayout(ui->listWidget);

    HttpInterFace::getInstance()->getRecommendRoom(m_roomId,[&](QVariant vart){

        QVariantList list = vart.toMap()["data"].toMap()["noticeRoom"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            PromoteBusinePageItem *item  =new PromoteBusinePageItem;
            connect(item, &PromoteBusinePageItem::showRoomId, this, [&](QString roomID){
                m_currRoomId = roomID;
                on_day_btn_clicked();
            });
            item->setData(data);
            ui->listWidget->addWidget(item);
        }
    });
}


void PromoteBusinePage::on_day_btn_clicked()
{
    cleanupLayout(ui->contList);

    HttpInterFace::getInstance()->getContributeList(1, 0, 20, m_roomId, [&](const QVariant &data) {        

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            PromoteBusinePageTopItem *item = new PromoteBusinePageTopItem();
            item->setFixedSize(398,71);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}


void PromoteBusinePage::on_week_btn_clicked()
{
    cleanupLayout(ui->contList);

    HttpInterFace::getInstance()->getContributeList(1, 1, 20, m_roomId, [&](const QVariant &data) {        

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            PromoteBusinePageTopItem *item = new PromoteBusinePageTopItem();
            item->setFixedSize(398,71);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}


void PromoteBusinePage::on_m_btn_clicked()
{
    cleanupLayout(ui->contList);

    HttpInterFace::getInstance()->getContributeList(1, 2, 20, m_roomId, [&](const QVariant &data) {        

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            PromoteBusinePageTopItem *item = new PromoteBusinePageTopItem();
            item->setFixedSize(398,71);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}

