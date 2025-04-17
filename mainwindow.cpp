#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include "agorartcengineinterface.h"
#include "Base/Http/HttpInterFace.h"
#include "Base/Http/HttpUserInfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_agoraFace = new AgoraRtcEngineInterface;
    m_agoraFace->vInitAgoraSdk();
    connect(m_agoraFace, &AgoraRtcEngineInterface::joinedChannelSuccess, this, &MainWindow::joinedChannelSuccess);
    connect(m_agoraFace, &AgoraRtcEngineInterface::audioVolumeIndication, this, &MainWindow::audioVolumeIndication);
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
    qDebug()<<"uid---"<<uid<<"  value---"<<value;
}

void MainWindow::on_enterRoom_clicked()
{
    int roomID = 30000003;
    QVariantMap data =  HttpInterFace::getInstance()->joinRoom(roomID,1,"");
    if(data["code"].toInt() == 1)//成功
    {
        QString rtcToken = data["data"].toMap()["rtcToken"].toString();
        qDebug()<<"rtcToken---"<<data;
        m_agoraFace->joinChannel(rtcToken, "30000003", "", 123456789);
    }


//    m_agoraFace->joinChannel("", "111", "", 30000003);
}


void MainWindow::on_pushButton_clicked()
{
    QVariantMap Captchadata =  HttpInterFace::getInstance()->getCaptcha("13333333333","+86");
    if(Captchadata["code"].toInt() == 1)
    {
        QVariantMap data = HttpInterFace::getInstance()->loginToServer("13333333333", "654321");       
        if(data["code"].toInt() == 1)
        {
            qDebug()<<"success ---"<<data["message"].toString();
            HttpUserInfo::instance()->setLoginInfo(data["data"].toMap());
        }
        else
        {
            qDebug()<<"message ---"<<data["message"].toInt();
        }
    }
    else
    {
        qDebug()<<"message ---"<<Captchadata["message"].toInt();
    }

}

