#include "UserinfoPageSimple.h"
#include "Global.h"
#include "ui_UserinfoPageSimple.h"
#include "HttpInterFace.h"
#include <windows.h>
#include "UserinfoPage.h"

UserinfoPageSimple *UserinfoPageSimple::getInstance()
{
    static UserinfoPageSimple pUserinfoPageSimpleFace;
    return &pUserinfoPageSimpleFace;
}

UserinfoPageSimple::UserinfoPageSimple(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPageSimple)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);    
}

UserinfoPageSimple::~UserinfoPageSimple()
{
    delete ui;
}

void UserinfoPageSimple::init(QString userID)
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
            ui->big_image->setRadius(12);
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
        if(0 == isAttention)
        {
            m_isFollow = false;
            ui->Attention->show();
            ui->pushButton_3->show();
            ui->Attention->setText(tr("关注"));
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
            ui->pushButton_3->hide();
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

void UserinfoPageSimple::uninit()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->big_image->setPixmap(QPixmap());
    ui->big_image->setRadius(0);
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
    hide();
}

void UserinfoPageSimple::on_pushButton_5_clicked()
{
    UserinfoPage *page = UserinfoPage::getInstance();
    page->init(m_userId);
    page->show();
}


void UserinfoPageSimple::on_Attention_clicked()
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


void UserinfoPageSimple::on_pushButton_3_clicked()
{
    g_main->chatC2C(m_data);
    close();
}

void UserinfoPageSimple::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    hide();
}

bool UserinfoPageSimple::nativeEvent(const QByteArray &eventType, void *message, long *result)
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
    return QWidget::nativeEvent(eventType, message, result);
}

