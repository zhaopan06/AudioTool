#include "mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

    LoginPage *login = new LoginPage;
    if(login->exec() == QDialog::Accepted)
    {

    }
    else
    {
        exit(0);
    }

    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    RoomItem *roomItem = new RoomItem;
    roomItem->setFixedSize(155,211);
    ui->gridLayout->addWidget(roomItem,0,0);

    initUserUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUserUI()
{
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    QString name = data["user"].toMap()["name"].toString();
    ui->userName->setText(name);
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        this->ui->userImage->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}

void MainWindow::joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed)
{
    qDebug()<<"join sueccess--------" <<channel;
}
//直播间的每个人麦克风音量回调
void MainWindow::audioVolumeIndication(int uid,int value)
{

}

void MainWindow::on_enterRoom_clicked()
{
    if(m_agoraFace == nullptr)
    {
        m_agoraFace = new AgoraRtcEngineInterface;
        m_agoraFace->vInitAgoraSdk();
        connect(m_agoraFace, &AgoraRtcEngineInterface::joinedChannelSuccess, this, &MainWindow::joinedChannelSuccess);
        connect(m_agoraFace, &AgoraRtcEngineInterface::audioVolumeIndication, this, &MainWindow::audioVolumeIndication);
    }

    int roomID = 30000003;
    QVariantMap data =  HttpInterFace::getInstance()->joinRoom(roomID,1,"");
    if(1 == data["code"].toInt())
    {
        QString rtcToken = data["data"].toMap()["rtcToken"].toString();
        QString chatRoomId = data["data"].toMap()["roomId"].toString();
        int userId = data["data"].toMap()["userInfoResponse"].toMap()["userId"].toInt();
        HttpUserInfo::instance()->setRoomInfo(data["data"].toMap());

        m_agoraFace->joinChannel(rtcToken, chatRoomId, userId);
        m_agoraFace->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
        m_agoraFace->enableLoopbackRecording(true);
    }
}

void MainWindow::on_createRoom_clicked()
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
        m_men->setFixedSize(226,226);
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
    point.setY(ui->emoBtn->mapToGlobal(QPoint(0, 0)).ry() - m_emotionWidget->height() - 26);
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
    QString text = ui->label_4->text();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);
}

