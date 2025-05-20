#include "mainwindow.h"
#include "ChatImageItem.h"
#include "ChatImageMyItem.h"
#include "ChatTextItem.h"
#include "ChatTextMyItem.h"
#include "ContributeItem.h"
#include "GIftItem.h"
#include "GiftPage.h"
#include "Global.h"
#include "MicInfoItem.h"
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
#include <QScrollBar>
#include <QFileDialog>
#include "MsgBox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->micList->setAlignment(Qt::AlignTop);
    ui->contList->setAlignment(Qt::AlignTop);
    ui->micLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //设置listWidget无虚框
    ui->msgList->setFocusPolicy(Qt::NoFocus);
    ui->msgList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->msgList->verticalScrollBar()->setSingleStep(20);
    ui->enterRoomList->setFocusPolicy(Qt::NoFocus);
    ui->enterRoomList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->enterRoomList->verticalScrollBar()->setSingleStep(20);
    ui->chatList->setFocusPolicy(Qt::NoFocus);
    ui->chatList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->chatList->verticalScrollBar()->setSingleStep(20);
    ui->osList->setFocusPolicy(Qt::NoFocus);
    ui->osList->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->osList->verticalScrollBar()->setSingleStep(20);

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
    initAgora();
    ui->mic_stackedWidget->setCurrentIndex(0);
    ui->autioMicBtn->show();
    ui->downMicBtn->hide();

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

void MainWindow::reconnect()
{
    if(0 == m_agoraFace->leaveChannel())
    {        
        QVariantMap roomdata =  HttpInterFace::getInstance()->joinRoom(g_roomID.toInt(), 1 , "");
        if(1 == roomdata["code"].toInt())
        {
            roomdata = roomdata["data"].toMap();
            QString rtcToken = roomdata["rtcToken"].toString();
            QString chatRoomId = roomdata["roomId"].toString();
            int userId = roomdata["userInfoResponse"].toMap()["userId"].toInt();

            m_agoraFace->joinChannel(rtcToken, chatRoomId, userId);
            m_agoraFace->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
            m_agoraFace->enableLoopbackRecording(true);
        }
        else
            MsgBox::showMsg(NULL,tr("提示"), roomdata["message"].toString());
    }
    else
    {
        MsgBox::showMsg(NULL,tr("提示"), tr("声网内部错误，请重启程序"));
    }
}

void MainWindow::initTim()
{
    if(m_timInterface == nullptr)
    {
        m_timInterface = new TimInterface;
        m_timInterface->initSDK();

        connect(m_timInterface, &TimInterface::msg_liveClose, this, &MainWindow::msg_liveClose);
        connect(m_timInterface, &TimInterface::loginStatus, this, &MainWindow::loginIm);
        connect(m_timInterface, &TimInterface::msg_notice, this, &MainWindow::msg_notice);
        connect(m_timInterface, &TimInterface::msg_txt, this, &MainWindow::msg_txt);
        connect(m_timInterface, &TimInterface::msg_image, this, &MainWindow::msg_image);
        connect(m_timInterface, &TimInterface::msg_gift, this, &MainWindow::msg_gift);
        connect(m_timInterface, &TimInterface::msg_micInfo, this, &MainWindow::msg_micInfo);
        connect(m_timInterface, &TimInterface::msg_updateMicList, this, &MainWindow::updateMicList);
        connect(m_timInterface, &TimInterface::msg_uninit, this, &MainWindow::msg_uninit);
        connect(m_timInterface, &TimInterface::msg_emotion, this, &MainWindow::msg_emotion);
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
        QString chatRoomld = HttpUserInfo::instance()->getIMRoomID();
        m_timInterface->groupJoin(chatRoomld.toLatin1());
    }
}

void MainWindow::msg_liveClose()
{
    cleanupLayout(ui->micLayout);
    cleanupLayout(ui->onlineList);
    cleanupLayout(ui->contList);
    cleanupLayout(ui->micList);

    ui->msgList->clear();
    ui->osList->clear();
    ui->chatList->clear();
    ui->enterRoomList->clear();
    ui->giftList->clear();

    m_timInterface->logout();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::msg_notice(QVariantMap user, QString msg)
{
    QLabel* label = new QLabel;
    label->setStyleSheet("font-family: \"微软雅黑\";"
                         "font-weight: 400;"
                         "font-size: 16px;"
                         "color: #A8A8A7;"
                         "line-height: 22px;"
                         "text-align: left;"
                         "font-style: normal;");
    label->setFixedHeight(34);
    label->setText(user["name"].toString() + " " + msg);


    QListWidgetItem *item1 = new QListWidgetItem();
    ui->msgList->addItem(item1);
    ui->msgList->setItemWidget(item1,label);
    item1->setSizeHint(QSize(ui->msgList->contentsRect().width(), label->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    QLabel *label1 = new QLabel();
    label1->setFixedHeight(34);
    label1->setText(label->text());
    label1->setStyleSheet(label->styleSheet());
    QListWidgetItem *item = new QListWidgetItem();
    ui->enterRoomList->addItem(item);
    ui->enterRoomList->setItemWidget(item,label1);
    item->setSizeHint(QSize(ui->enterRoomList->contentsRect().width(), label1->height()));
    ui->enterRoomList->setCurrentRow(ui->enterRoomList->count()-1);
    ui->enterRoomList->scrollToBottom();

}

void MainWindow::msg_txt(QVariantMap user, QString msg, int type)
{
    ChatTextItem *item1 = new ChatTextItem;
    item1->setData(user, msg, type);
    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();


    ChatTextItem *item3 = new ChatTextItem;
    item3->setData(user, msg, type);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}

void MainWindow::msg_image(QVariantMap user, QString path)
{
    ChatImageItem *item1 = new ChatImageItem;
    item1->setData(user, path);

    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatImageItem *item3 = new ChatImageItem;
    item3->setData(user, path);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}

void MainWindow::msg_gift(QVariantMap form, QVariantMap gift, QVariantMap to)
{
    GIftItem *item = new GIftItem;
    item->setData(form, gift, to);
    QListWidgetItem *item1 = new QListWidgetItem();
    ui->giftList->addItem(item1);
    ui->giftList->setItemWidget(item1,item);
    item1->setSizeHint(QSize(ui->msgList->contentsRect().width(), item->height()));
    ui->giftList->setCurrentRow(ui->msgList->count()-1);
    ui->giftList->scrollToBottom();

    foreach (auto var, m_micList)
    {
        if(to["userId"].toString() == var->getUserId())
        {
            var->updateData(to);
        }
    }
}
//麦位发生变化
void MainWindow::msg_micInfo(QVariantList list)
{  
    foreach (auto var, list)
    {
        QVariantMap data = var.toMap();
        int mic_index = data["mic_index"].toString().toInt();
        MicInfoItem *item = m_micList.at(mic_index-1);
        item->setData(data, mic_index-1);        
    }  
}

void MainWindow::msg_emotion(QVariantMap user, QString path, int type)
{
    ChatTextItem *item1 = new ChatTextItem;
    item1->setEmotion(user, path, type);
    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();


    ChatTextItem *item3 = new ChatTextItem;
    item3->setEmotion(user, path, type);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}

//发送文字消息
void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();
    m_timInterface->setSendJson(IMType_Text, msg);

    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();

    ChatTextMyItem *item1 = new ChatTextMyItem;
    item1->setData(photoUrl, msg);
    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatTextMyItem *item3 = new ChatTextMyItem;
    item3->setData(photoUrl, msg);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();

    ui->msgEdit->clear();
}
//发送图片
void MainWindow::on_imageBtn_clicked()
{
    QString localPath = QFileDialog::getOpenFileName(0, QStringLiteral("选择图片"), "", QStringLiteral("jpg、png图片(*.jpg *.png)"));
    if (localPath.isEmpty())
    {
        return;
    }
    //    QFile file(localPath);
    //    if (!file.open(QIODevice::ReadOnly)) return;
    //    if(file.size() > 1024*1024*10)
    //    {
    //        file.close();
    //        return;
    //    }
    //    file.close();

    m_timInterface->sendImage(localPath);

    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    ChatImageMyItem *item1 = new ChatImageMyItem;
    item1->setData(localPath,photoUrl);

    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatImageMyItem *item3 = new ChatImageMyItem;
    item3->setData(localPath, photoUrl);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}


void MainWindow::on_emoBtn_clicked()
{
    if(nullptr == m_emotionPage)
    {
        m_emotionPage = new EmotionPage;
        m_emotionPage->initChatEmotion();
        connect(m_emotionPage, SIGNAL(emotionClicked(QVariantMap)), this, SLOT(emotionClicked(QVariantMap)));
    }

    QPoint point;
    point.setX(ui->giftBtn->mapToGlobal(QPoint(0, 0)).rx() - 16);
    point.setY(ui->giftBtn->mapToGlobal(QPoint(0, 0)).ry() - m_emotionPage->height() - 10);
    m_emotionPage->move(point);
    m_emotionPage->show();
}

void MainWindow::emotionClicked(QVariantMap data)
{
    m_emotionPage->hide();
    QString path = data["path"].toString();
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
                case 0:
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 7);
                    m_timInterface->setSendJson(IMType_dice, QString::number(diceRoll));
                    QString imagePath = "images/emotion/icon_dice_" + QString::number(diceRoll) + ".png";
                    setEmoTionItem(imagePath, 1);
                    break;
                }
                case 1:
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 4);
                    QString imagePath = "images/emotion/icon_finger_" + QString::number(diceRoll) + ".png";
                    m_timInterface->setSendJson(IMType_finger, QString::number(diceRoll));
                    setEmoTionItem(imagePath, 2);
                    break;
                }
                case 2:
                {
                    setEmoTionItem(path, 3);
                    m_timInterface->setSendJson(IMType_light, "");
                    break;
                }
                case 3:
                {
                    int diceRoll = QRandomGenerator::global()->bounded(1, 9);
                    QString imagePath = "images/emotion/icon_mic_" + QString::number(diceRoll) + ".png";
                    setEmoTionItem(imagePath, 4);
                    m_timInterface->setSendJson(IMType_machine, QString::number(diceRoll));
                    break;
                }
                }
            }
            else
            {
                setEmoTionItem(path, 5);
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
    g_roomID = id;

    int currentPage = 1;
    HttpInterFace::getInstance()->getOnlineInfo(g_roomID,currentPage, [&](const QVariant &data) {

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

    QVariantMap roomdata =  HttpInterFace::getInstance()->joinRoom(id.toInt(), 1 , "");
    if(1 == roomdata["code"].toInt())
    {
        roomdata = roomdata["data"].toMap();
        HttpUserInfo::instance()->setRoomInfo(roomdata);

        QString rtcToken = roomdata["rtcToken"].toString();
        QString chatRoomId = roomdata["roomId"].toString();
        int userId = roomdata["userInfoResponse"].toMap()["userId"].toInt();
        m_agoraFace->joinChannel(rtcToken, chatRoomId, userId);
        m_agoraFace->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
        m_agoraFace->enableLoopbackRecording(true);

        QString roomName = roomdata["roomName"].toString();
        ui->roomName->setText(roomName);
        QString roomId = roomdata["roomId"].toString();
        ui->roomID->setText(QStringLiteral("ID：") + roomId);

        //设置麦序
        QVariantList micInfoList = roomdata["micInfoList"].toList();
        cleanupLayout(ui->micLayout);
        m_micList.clear();
        for(int i = 0; i < micInfoList.size(); i++)
        {
            QVariantMap micData = micInfoList.at(i).toMap();
            MicInfoItem *item = new MicInfoItem;
            connect(item, &MicInfoItem::setMyselfMicInfo, this, &MainWindow::setMyselfMicInfo);
            item->setData(micData, i);
            int row = i / 4;
            int col = i % 4;
            ui->micLayout->addWidget(item,row, col);
            m_micList.append(item);

            if(HttpUserInfo::instance()->getUserID() == micData["member"].toMap()["userId"].toString())
            {
                ui->downMicBtn->show();
                ui->autioMicBtn->hide();
            }
        }

        initTim();
        m_timInterface->login();
        ui->stackedWidget->setCurrentIndex(1);

        QString multipleAuthoriation = roomdata["multipleAuthoriation"].toString();
        QString type = multipleAuthoriation.at(1);
        m_isManager = type.toInt();
        if(!m_isManager)
        {
            ui->imageBtn->hide();
        }
        type = multipleAuthoriation.at(0);
        if(type.toInt() == 2)
            m_isHomeowner = true;
        else
            m_isHomeowner = false;
        if(!m_isHomeowner)
        {
            ui->closeLiveBtn->hide();
        }

        updateMicList();

        HttpInterFace::getInstance()->getCommonConfig([&](const QVariant &data) {
            QVariantMap roomWelcomeInfo = data.toMap()["data"].toMap();
            QString msg = roomWelcomeInfo["roomWelcomeInfo"].toString();
            QLabel *label = new QLabel;
            label->setStyleSheet("font-family: \"微软雅黑\";"
                                 "font-size: 16px;"
                                 "color: #ED525A;");

            label->setFixedWidth(476);
            QString labelText = msg;
            labelText.replace("\n","<br />");
            QString textStyle = "<p style='line-height:22px'>" + labelText + "</p>";
            label->setText(textStyle);
            label->setWordWrap(true);
            label->adjustSize();           

            QListWidgetItem *item = new QListWidgetItem();
            ui->msgList->addItem(item);
            ui->msgList->setItemWidget(item,label);
            item->setSizeHint(QSize(ui->msgList->contentsRect().width(), label->height()));
            ui->msgList->setCurrentRow(ui->msgList->count()-1);
            ui->msgList->scrollToBottom();

            QLabel *label1 = new QLabel();
            label1->setFixedWidth(476);
            label1->setText(label->text());
            label1->setStyleSheet(label->styleSheet());
            label1->setWordWrap(true);
            QListWidgetItem *item1 = new QListWidgetItem();
            ui->osList->addItem(item1);
            ui->osList->setItemWidget(item1,label1);
            item1->setSizeHint(QSize(ui->osList->contentsRect().width(), label1->height()));
            ui->osList->setCurrentRow(ui->osList->count()-1);
            ui->osList->scrollToBottom();
        });
    }
}

void MainWindow::initAgora()
{
    if(m_agoraFace == nullptr)
    {
        m_agoraFace = new AgoraRtcEngineInterface;
        m_agoraFace->vInitAgoraSdk();
        connect(m_agoraFace, &AgoraRtcEngineInterface::joinedChannelSuccess, this, &MainWindow::joinedChannelSuccess);
        connect(m_agoraFace, &AgoraRtcEngineInterface::audioVolumeIndication, this, &MainWindow::audioVolumeIndication);
        connect(m_agoraFace, &AgoraRtcEngineInterface::reconnect, this, &MainWindow::reconnect);
    }
}

void MainWindow::setMyselfMicInfo(int status)
{
    if(status >= 0)
    {
        ui->downMicBtn->show();
        ui->autioMicBtn->hide();
        m_agoraFace->setClientRole(CLIENT_ROLE_BROADCASTER);
    }
    else
    {
        ui->downMicBtn->hide();
        ui->autioMicBtn->show();
        ui->autioMicBtn->setText(QStringLiteral("上麦"));
        m_agoraFace->setClientRole(CLIENT_ROLE_AUDIENCE);
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
    NewUserPage::getInstance()->show();
}

//贡献
void MainWindow::on_contributeBtn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    on_day_btn_clicked();
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


void MainWindow::on_allChatBtn_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_roomChatBtn_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_chatListBtn_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_osBtn_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::setEmoTionItem(QString path, int type)
{
    ChatTextMyItem *item1 = new ChatTextMyItem;
    item1->setEmotion(path, type);
    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();


    ChatTextMyItem *item3 = new ChatTextMyItem;
    item3->setEmotion(path, type);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}


void MainWindow::on_giftBtn_clicked()
{
    if(nullptr == m_giftPage)
    {
        m_giftPage = new GiftPage(this);
        m_giftPage->init();
    }
    QPoint point1;
    point1.setX(ui->giftBtn->mapToGlobal(QPoint(0, 0)).rx() - 16);
    point1.setY(ui->giftBtn->mapToGlobal(QPoint(0, 0)).ry() - m_giftPage->height() - 10);
    m_giftPage->move(point1);
    m_giftPage->show();
}

void MainWindow::updateMicList()
{
    HttpInterFace::getInstance()->getMicApplyList(g_roomID, [&](const QVariant &data) {

        cleanupLayout(ui->micList);
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
            connect(item, &MicseQuenceItem::upMicToUserID, this, &MainWindow::upMicToUserID);
            item->setFixedSize(390,70);
            item->setData(map, i+1, m_isManager);
            ui->micList->addWidget(item);

            if(map["userId"].toString() == HttpUserInfo::instance()->getUserID())
            {
                ui->autioMicBtn->setChecked(true);
                ui->autioMicBtn->setText(QStringLiteral("取消上麦"));
            }
        }

    });
}

void MainWindow::msg_uninit()
{
    QLabel* label = new QLabel;
    label->setStyleSheet("font-family: \"微软雅黑\";"
                         "font-weight: 400;"
                         "font-size: 16px;"
                         "color: #A8A8A7;"
                         "line-height: 22px;"
                         "text-align: left;"
                         "font-style: normal;");
    label->setFixedHeight(34);
    label->setText(tr("暂不支持该消息，请升级最新版本以获得完整功能体验"));


    QListWidgetItem *item1 = new QListWidgetItem();
    ui->msgList->addItem(item1);
    ui->msgList->setItemWidget(item1,label);
    item1->setSizeHint(QSize(ui->msgList->contentsRect().width(), label->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    QLabel *label1 = new QLabel();
    label1->setFixedHeight(34);
    label1->setText(label->text());
    label1->setStyleSheet(label->styleSheet());
    QListWidgetItem *item = new QListWidgetItem();
    ui->enterRoomList->addItem(item);
    ui->enterRoomList->setItemWidget(item,label1);
    item->setSizeHint(QSize(ui->enterRoomList->contentsRect().width(), label1->height()));
    ui->enterRoomList->setCurrentRow(ui->enterRoomList->count()-1);
    ui->enterRoomList->scrollToBottom();
}

void MainWindow::upMicToUserID(QString roomID, QString userID)
{
    QVariantMap data =  HttpInterFace::getInstance()->b_upMic(roomID, userID);
    if(data["code"].toInt() != 1)
    {
        MsgBox::showMsg(NULL,tr("提示"), data["message"].toString());
    }
}

void MainWindow::on_autioMicBtn_clicked()
{
    if(ui->autioMicBtn->isChecked())
    {
        HttpInterFace::getInstance()->addMic(HttpUserInfo::instance()->getClassRoomID(),1);
        ui->autioMicBtn->setText(QStringLiteral("取消上麦"));
    }
    else
    {
        HttpInterFace::getInstance()->addMic(HttpUserInfo::instance()->getClassRoomID(),0);
        ui->autioMicBtn->setText(QStringLiteral("上麦"));
    }
}

void MainWindow::on_downMicBtn_clicked()
{
    HttpInterFace::getInstance()->m_downMic();
    ui->downMicBtn->hide();
    ui->autioMicBtn->show();
    ui->autioMicBtn->setChecked(false);
    ui->autioMicBtn->setText(QStringLiteral("上麦"));
}


void MainWindow::on_pushButton_18_clicked()
{
    if(!m_isManager)
    {
        MsgBox::showMsg(NULL,tr("提示"), tr("只有房主+主持身份用户可以使用该功能"));
    }
    else
    {
        if(QDialog::Accepted == MsgBox::showMsg(NULL,tr("提示"), tr("是否清空全麦魅力值"),MsgBox::QUERYDIALOG))
        {
            HttpInterFace::getInstance()->clearCardiacValue(g_roomID, [&](const QVariant &map) {
                QVariantMap data = map.toMap();
                if(data["code"].toInt() != 1)
                {
                    MsgBox::showMsg(NULL,tr("提示"), data["message"].toString());
                }
            });
        }
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    HttpInterFace::getInstance()->noticeFans(g_roomID, [&](const QVariant &map) {
        QVariantMap data = map.toMap();
        if(data["code"].toInt() != 1)
        {
            MsgBox::showMsg(NULL,tr("提示"), data["message"].toString());
        }
    });
}

void MainWindow::on_msgEdit_sendImage(const QString &localPath)
{
    m_timInterface->sendImage(localPath);

    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    ChatImageMyItem *item1 = new ChatImageMyItem;
    item1->setData(localPath,photoUrl);

    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatImageMyItem *item3 = new ChatImageMyItem;
    item3->setData(localPath, photoUrl);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();
}


void MainWindow::on_msgEdit_textChanged(const QString &arg1)
{
    if(ui->msgEdit->isImageFile(arg1))
    {
        ui->msgEdit->clear();
    }
}


void MainWindow::on_closeLiveBtn_clicked()
{
    QVariantMap data = HttpInterFace::getInstance()->closeRoom(g_roomID);
    if(data["code"].toInt() == 1)
    {
        msg_liveClose();
    }
}

