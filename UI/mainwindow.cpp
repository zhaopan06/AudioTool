#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include "agorartcengineinterface.h"
#include "Base/Http/HttpInterFace.h"
#include "Base/Http/HttpUserInfo.h"
#include "LoginPage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

#ifndef NO
    LoginPage *login = new LoginPage;
    if(login->exec() == QDialog::Accepted)
    {

    }
    else
    {
        exit(0);
    }
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed)
{
    qDebug()<<"join sueccess--------" <<channel;
}

void MainWindow::audioVolumeIndication(int uid,int value)
{
    qDebug()<<"audioVolumeIndication uid---"<<uid<<"  value---"<<value;
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

