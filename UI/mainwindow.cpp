#include "mainwindow.h"
#include "ContributeItem.h"
#include "Global.h"
#include "MicseQuenceItem.h"
#include "NewUserPage.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include "agorartcengineinterface.h"
#include "Base/Http/HttpInterFace.h"
#include "Base/Http/HttpUserInfo.h"
#include "LoginPage.h"
#include <QRandomGenerator>
#include "RoomItem.h"
#include <QMenu>
#include <QClipboard>
#include "OnlineItem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->micList->setAlignment(Qt::AlignTop);
    ui->contList->setAlignment(Qt::AlignTop);

    LoginPage login;
    if(login.exec() == QDialog::Accepted)
    {

    }
    else
    {
        exit(0);
    }

    initUserUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUserUI()
{
    ui->mic_stackedWidget->setCurrentIndex(0);

    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    QString name = data["user"].toMap()["name"].toString();
    ui->userName->setText(name);
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        this->ui->userImage->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    QVariantMap familyData = HttpInterFace::getInstance()->getLiveRoomInfo();
    QVariantMap roomInfo = familyData["data"].toMap();

    //公会相关
    QVariantMap pcFamilyPo = roomInfo["pcFamilyPo"].toMap();
    QString fName = pcFamilyPo["name"].toString();
    ui->guildName->setText(fName);
    QString fID = pcFamilyPo["id"].toString();
    ui->IDLabel->setText(fID);
    QString intro = pcFamilyPo["intro"].toString();
    ui->intro->setText(intro);
    QString fPhotoUrl = pcFamilyPo["photo"].toString();
    HttpInterFace::getInstance()->downLoad(fPhotoUrl, [&](const QString &path) {
        this->ui->guildImage->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    if(pcFamilyPo["wallList"].toList().size() > 0)
    {
        QString title = pcFamilyPo["wallList"].toList().at(0).toMap()["title"].toString();
        ui->label_8->setText(title);
        QString wallPhotoUrl = pcFamilyPo["wallList"].toList().at(0).toMap()["medalUrl"].toString();
        HttpInterFace::getInstance()->downLoad(wallPhotoUrl, [&](const QString &path) {
            this->ui->label_9->setPixmap(QPixmap::fromImage(QImage(path)));
        });
    }

    //直播房间相关
    if(roomInfo["pcChatRoomPo"].toList().size() > 0)
    {
        QVariantMap pcChatRoomPo = roomInfo["pcChatRoomPo"].toList().at(0).toMap();
        RoomItem *roomItem = new RoomItem;
        roomItem->setData(pcChatRoomPo);
        connect(roomItem, SIGNAL(enterTheRoom(QVariantMap)),this,SLOT(enterTheToom(QVariantMap)));
        roomItem->setFixedSize(155,211);
        ui->gridLayout->addWidget(roomItem,0,0);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 66)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void MainWindow::joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed)
{
    qDebug()<<"join sueccess--------" <<channel;
}
//直播间的每个人麦克风音量回调
void MainWindow::audioVolumeIndication(int uid,int value)
{

}

//创建房间
void MainWindow::createRoom()
{
    QVariantMap data =  HttpInterFace::getInstance()->createRoom("","PCTest");
    qDebug()<<"data---"<<data;
    if(1 == data["code"].toInt())
    {
    }
}


void MainWindow::on_pushButton_clicked()
{
    QVariantMap data =  HttpInterFace::getInstance()->addMic(30000003,1);
    qDebug()<<"data---"<<data;
    if(1 == data["code"].toInt())
    {
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    if(m_timInterface == nullptr)
    {
        m_timInterface = new TimInterface;
        m_timInterface->initSDK();

        connect(m_timInterface, &TimInterface::loginStatus, this, &MainWindow::loginIm);
    }
}

void MainWindow::loginIm(int code, QString msg)
{
    if (code != ERR_SUCC)
    {
        qDebug()<<"login error-----------code-"<<code<<"---desc-"<<msg;

    }
    else
    {        
        QString chatRoomld = HttpUserInfo::instance()->getRoomID();
        m_timInterface->groupJoin(chatRoomld.toLatin1());
    }
}

//发送消息
void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();
    m_timInterface->setSendJson(IMType_Text, msg);
}


void MainWindow::on_emoBtn_clicked()
{
    if(nullptr == m_men)
    {
        m_men = new QMenu;        
        QHBoxLayout *hbox = new QHBoxLayout;
        m_emotionWidget = new EmotionWidget(this);
        m_emotionWidget->initChatEmotion();
        connect(m_emotionWidget, SIGNAL(emotionClicked(QString)), this, SLOT(emotionClicked(QString)));
        hbox->setMargin(0);
        hbox->addWidget(m_emotionWidget);
        m_men->setLayout(hbox);
    }
    QPoint point;
    point.setX(ui->emoBtn->mapToGlobal(QPoint(0, 0)).rx());
    point.setY(ui->emoBtn->mapToGlobal(QPoint(0, 0)).ry() - m_emotionWidget->height() - 10);
    m_men->move(point);
    m_men->exec();
}

void MainWindow::emotionClicked(QString path)
{
    ui->sendBtn->setFocus();
    QString text;
    if(path.contains("/"))
    {
        text = path.split("/").at(2);
        if(text.contains("."))
        {
            text = text.split(".").at(0);
            int number =  text.split("_").at(text.split("_").size()-1).toInt();
            if(number < 4)
            {
                switch (number)
                {
                case 0://发送骰子
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 7);
                    m_timInterface->setSendJson(IMType_dice, QString::number(diceRoll));
                    break;
                }
                case 1://发送猜拳
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 4);
                    qDebug()<<"diceRoll---"<<diceRoll;
                    m_timInterface->setSendJson(IMType_finger, QString::number(diceRoll));
                    break;
                }
                case 2://发送爆灯
                {
                    m_timInterface->setSendJson(IMType_light, "");
                    break;
                }
                case 3://美味基
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 9);
                    qDebug()<<"diceRoll---"<<diceRoll;
                    m_timInterface->setSendJson(IMType_machine, QString::number(diceRoll));

                    break;
                }
                default:
                    break;
                }
            }
            else
            {
                //表情
                if(number <= 21)
                    number --;
                else if(number >= 27 && number < 32)
                    number += 4;
                else if(number == 32)
                    number = 43;
                else if(number == 33)
                    number = 45;
                else if(number >= 34 && number < 36)
                    number += 4 ;

                QString str = QString("%1").arg(number, 3, 10, QChar('0'));
                text = text.left(8) + "_" + str;
                m_timInterface->setSendJson(IMType_emjio, text);
            }
        }
    }
}


void MainWindow::on_closeBtn_clicked()
{
    exit(0);
}


void MainWindow::on_minBtn_clicked()
{
    showMinimized();
}

//复制工会ID
void MainWindow::on_copyBtn_clicked()
{
    QString text = ui->IDLabel->text();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);
}

//刷新
void MainWindow::on_updateBtn_clicked()
{

}
//进入房间
void MainWindow::enterTheToom(QVariantMap data)
{
    QString id = data["id"].toString();
    int currentPage = 1;

    HttpInterFace::getInstance()->getOnlineInfo(id,currentPage, [&](const QVariant &data) {

        QVariantMap onlineInfo =  data.toMap();
        QVariantList list = onlineInfo["data"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            OnlineItem *item = new OnlineItem();
            item->setFixedSize(390,70);
            item->setData(map,id);
            ui->onlineList->addWidget(item);
        }

    });
    HttpInterFace::getInstance()->getMicApplyList(id, [&](const QVariant &data) {

        QVariantMap info =  data.toMap();
        QVariantList list = info["data"].toList();
        if(list.size() > 0)
            ui->mic_stackedWidget->setCurrentIndex(1);
        else
            ui->mic_stackedWidget->setCurrentIndex(0);

        for(int i=0; i<list.size(); i++)
        {
            QVariantMap map = list.at(i).toMap();
            MicseQuenceItem *item = new MicseQuenceItem();
            item->setFixedSize(390,70);
            item->setData(map, i+1);
            ui->micList->addWidget(item);
        }

    });

    if(m_agoraFace == nullptr)
    {
        m_agoraFace = new AgoraRtcEngineInterface;
        m_agoraFace->vInitAgoraSdk();
        connect(m_agoraFace, &AgoraRtcEngineInterface::joinedChannelSuccess, this, &MainWindow::joinedChannelSuccess);
        connect(m_agoraFace, &AgoraRtcEngineInterface::audioVolumeIndication, this, &MainWindow::audioVolumeIndication);
    }

    QVariantMap roomdata =  HttpInterFace::getInstance()->joinRoom(id.toInt(), 1 , "");
    if(1 == roomdata["code"].toInt())
    {
        roomdata = roomdata["data"].toMap();
        QString rtcToken = roomdata["rtcToken"].toString();
        QString chatRoomId = roomdata["roomId"].toString();
        int userId = roomdata["userInfoResponse"].toMap()["userId"].toInt();
        HttpUserInfo::instance()->setRoomInfo(roomdata);

        m_agoraFace->joinChannel(rtcToken, chatRoomId, userId);
        m_agoraFace->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
        m_agoraFace->enableLoopbackRecording(true);

        QString roomName = roomdata["roomName"].toString();
        ui->roomName->setText(roomName);
        QString roomId = roomdata["roomId"].toString();
        ui->roomID->setText(QStringLiteral("ID：") + roomId);

        //TODO 设置麦序
        QVariantList micInfoList = roomdata["micInfoList"].toList();
        for(int i = 0; i < micInfoList.size(); i++)
        {
            qDebug()<<"micinfo---"<<micInfoList.at(i);
        }


        ui->stackedWidget->setCurrentIndex(1);
    }
}

//线上
void MainWindow::on_onlineBtn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//萌新
void MainWindow::on_squareBtn_clicked()
{
    NewUserPage page;
    page.init();
    page.exec();
}

//贡献
void MainWindow::on_contributeBtn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

//日榜
void MainWindow::on_day_btn_clicked()
{
    QVariantMap data = HttpUserInfo::instance()->getRoomInfo();
    QString roomid = data["roomId"].toString();
    HttpInterFace::getInstance()->getContributeList(1, 0, 20, roomid, [&](const QVariant &data) {

        cleanupLayout(ui->contList);

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            ContributeItem *item = new ContributeItem();
            item->setFixedSize(390,70);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}


void MainWindow::on_week_btn_clicked()
{
    QVariantMap data = HttpUserInfo::instance()->getRoomInfo();
    QString roomid = data["roomId"].toString();
    HttpInterFace::getInstance()->getContributeList(1, 1, 20, roomid, [&](const QVariant &data) {

        cleanupLayout(ui->contList);

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            ContributeItem *item = new ContributeItem();
            item->setFixedSize(390,70);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}


void MainWindow::on_m_btn_clicked()
{
    QVariantMap data = HttpUserInfo::instance()->getRoomInfo();
    QString roomid = data["roomId"].toString();
    HttpInterFace::getInstance()->getContributeList(1, 2, 20, roomid, [&](const QVariant &data) {

        cleanupLayout(ui->contList);

        QVariantMap reData = data.toMap()["data"].toMap();

        QVariantList list = reData["rankingDtos"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            ContributeItem *item = new ContributeItem();
            item->setFixedSize(390,70);
            item->setData(map);
            ui->contList->addWidget(item);
        }
    });
}

