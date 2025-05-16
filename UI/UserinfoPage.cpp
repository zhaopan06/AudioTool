#include "UserinfoPage.h"
#include "Global.h"
#include "UserinfoPageGiftItem.h"
#include "UserinfoPageMedalItem.h"
#include "ui_UserinfoPage.h"
#include "HttpInterFace.h"
#include "MsgBox.h"
#include "qevent.h"

UserinfoPage::UserinfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->gridLayout_3->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->stackedWidget->setCurrentIndex(0);
}

UserinfoPage::~UserinfoPage()
{
    delete ui;
}

void UserinfoPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void UserinfoPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void UserinfoPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void UserinfoPage::init(QString userID)
{
    m_userId = userID;

    HttpInterFace::getInstance()->getUserInfo(userID, [&](const QVariant &map) {

        QVariantMap data = map.toMap()["data"].toMap();
        QString photo = data["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
            this->ui->big_image->setPixmap(QPixmap(path));
            this->ui->image->setPixmap(QPixmap(path));
        });

        QString name = data["name"].toString();
        ui->name->setText(name);

        ui->constellation->setText(data["constellation"].toString());

        ui->age->setText(data["age"].toString());
        int sex = data["age"].toInt();
        if(1 == sex)
        {
            ui->age->setIcon(QIcon(":/images/live_people_man.png"));
        }
        else if(0 == sex)
        {
            ui->age->setIcon(QIcon(":/images/live_people_woman.png"));
        }

        ui->userLevel->setText(data["userLevel"].toString());
        ui->userId->setText(tr("ID：") + data["userId"].toString());
        ui->location->setText(data["location"].toString());
        ui->fansNum->setText(data["fansNum"].toString());
        ui->playDayNum->setText(data["playDayNum"].toString());

        int isAttention = data["isAttention"].toInt();
        if(0 == isAttention)//是否已关注该用户，1是，0否,-1=查看自己资料，无需展示关注按钮
        {
            ui->Attention->setText(tr("关注"));
        }
        else if(1 == isAttention)
        {
            ui->Attention->setText(tr("取消关注"));
        }
        else
        {
            ui->Attention->hide();
        }

        QString intre = data["intro"].toString();
        if(!intre.isEmpty())
            ui->intro->setText(intre);

        if(data["isOnline"].toInt() == 1)
            ui->isOnline->setText(tr("在线"));

        QVariantMap familySignRoomResponses = data["familySignRoomResponses"].toMap();
        QString familyName = familySignRoomResponses["familyName"].toString() + tr(" · 成员");
        ui->label_9->setText(familyName);

        if(data["imgTag"].toList().size() > 0)
        {
            QString src = data["imgTag"].toList().at(0).toMap()["src"].toString();
            HttpInterFace::getInstance()->downLoad(src, [&](const QString &path) {
                this->ui->label_14->setPixmap(QPixmap(path));
            });
        }
    });
}

void UserinfoPage::on_closeBtn_clicked()
{
    close();
}


void UserinfoPage::on_onlineBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void UserinfoPage::on_squareBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    on_sendBtn_clicked();
}


void UserinfoPage::on_contributeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    HttpInterFace::getInstance()->getUserMedals(m_userId, [&](const QVariant &map) {

        if(map.toMap()["code"].toInt() != 1)
        {
            MsgBox::showMsg(NULL, tr("提示"), map.toMap()["message"].toString());
            return;
        }

        QVariantList list = map.toMap()["data"].toList();
        for(int i=0; i<list.size(); ++i)
        {
            UserinfoPageMedalItem *item = new UserinfoPageMedalItem;
            item->setData(list.at(i).toMap());

            int row = i / 4;
            int col = i % 4;
            ui->gridLayout_3->addWidget(item,row, col);
        }

        ui->label_13->setText(QString::number(list.size()));
    });
}

void UserinfoPage::updateGift(int type, int type1)
{
    m_type = type1;
    cleanupLayout(ui->gridLayout);

    HttpInterFace::getInstance()->getGiftWall(m_userId, type, type1, [&](const QVariant &map) {

        QVariantMap data = map.toMap()["data"].toMap();
        QVariantList list = data["giftWallList"].toList();
        for(int i=0; i<list.size(); ++i)
        {
            UserinfoPageGiftItem *item = new UserinfoPageGiftItem;
            item->setData(list.at(i).toMap());

            int row = i / 4;
            int col = i % 4;
            ui->gridLayout->addWidget(item,row, col);
        }

        if(1 == m_type)
        {
            ui->label_2->setText(QString::number(list.size()));
        }
    });
}

void UserinfoPage::on_sendBtn_clicked()
{
    int type = 0;
    ui->pushButton_2->isChecked()? type = 1: type=0;
    updateGift(1, type);
}


void UserinfoPage::on_receiveBtn_clicked()
{
    int type = 0;
    ui->pushButton_2->isChecked()? type = 1: type=0;
    updateGift(0, type);
}


void UserinfoPage::on_pushButton_2_clicked()
{
    int type = 0;
    ui->sendBtn->isChecked()? type = 1: type=0;
    updateGift(type, 1);
}


void UserinfoPage::on_pushButton_4_clicked()
{
    int type = 0;
    ui->sendBtn->isChecked()? type = 1: type=0;
    updateGift(type, 0);
}

