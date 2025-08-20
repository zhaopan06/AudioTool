#include "UserinfoPage.h"
#include "Global.h"
#include "UserinfoPageGiftItem.h"
#include "UserinfoPageMedalItem.h"
#include "ui_UserinfoPage.h"
#include "HttpInterFace.h"
#include "qevent.h"
#include <windows.h>

UserinfoPage *UserinfoPage::getInstance()
{
    static UserinfoPage pUserinfoPageFace;
    return &pUserinfoPageFace;
}

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
        m_data = data;
        QString photo = data["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {

            QPixmap pix(path);
            pix = pix.scaled(ui->big_image->width()*1.2, ui->big_image->height()*1.2,Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->big_image->setPixmap(pix);
            ui->image->setPixmap(QPixmap(path));
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
            m_isFollow = false;
            ui->Attention->show();
            ui->Attention->setText(tr("关注"));
            ui->pushButton_3->show();
        }
        else if(1 == isAttention)
        {
            m_isFollow = true;
            ui->Attention->show();
            ui->Attention->setText(tr("取消关注"));
            ui->pushButton_3->show();
        }
        else
        {
            ui->Attention->hide();
            ui->pushButton_3->hide();
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

                QPixmap pixmap = QPixmap(path);
                QPixmap scaledPixmap = pixmap.scaled(
                    this->ui->label_14->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    );

                this->ui->label_14->setPixmap(scaledPixmap);
            });
        }
    });
}

void UserinfoPage::uninit()
{
    on_closeBtn_clicked();
}

void UserinfoPage::on_closeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->big_image->setPixmap(QPixmap());
    ui->image->setPixmap(QPixmap());
    ui->label_14->setPixmap(QPixmap());
    ui->name->setText("");
    ui->constellation->setText("");
    ui->age->setText("");
    ui->label_9->setText("");
    ui->isOnline->setText(tr("离线"));
    ui->userLevel->setText("");
    ui->userId->setText("");
    ui->location->setText("");
    ui->fansNum->setText("");
    ui->playDayNum->setText("");
    ui->intro->setText(tr("请填写个性签名"));
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

//关注
void UserinfoPage::on_Attention_clicked()
{
    int isFollow = 0;
    if(!m_isFollow)
    {
        isFollow = 1;
    }

    HttpInterFace::getInstance()->followUser(m_userId, isFollow, [=](const QVariant &content){
        QVariantMap data = content.toMap();
        if(0 == isFollow)
        {
            ui->Attention->setText(QStringLiteral("关注"));
        }
        if(1 == isFollow)
        {
            ui->Attention->setText(QStringLiteral("取消关注"));
        }
        m_isFollow = !m_isFollow;
    },this);
}

void UserinfoPage::on_pushButton_3_clicked()
{
    this->hide();
    emit chatC2C(m_data);
}

