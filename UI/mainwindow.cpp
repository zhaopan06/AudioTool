#include "mainwindow.h"
#include "AudioValuePage.h"
#include "ChatImageItem.h"
#include "ChatImageMyItem.h"
#include "ChatTextItem.h"
#include "ChatTextMyItem.h"
#include "CommonTool.h"
#include "ContributeItem.h"
#include "GIftItem.h"
#include "GiftPage.h"
#include "Global.h"
#include "ManagementPage.h"
#include "MicInfoItem.h"
#include "MicseQuenceItem.h"
#include "NewUserPage.h"
#include "PromoteBusinePage.h"
#include "RoomEidtPage.h"
#include "RoomInvitePage.h"
#include "UserinfoPage.h"
#include "WebPlayerPage.h"
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
#include <QProcess>
#include "HotPushPage.h"
#include "clientconfig.h"
#include "SetTingPage.h"
#include <QtConcurrent/QtConcurrent>

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
    ui->msgList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->msgList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_isDragging = false;
    m_dragEdge = None;
    installEventFilter(this);
    setMouseTracking(true);
    g_main = this;

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

    QVariantMap data =  ClientConfig::getInstance()->getLoginData();
    if(!data.isEmpty())
    {
        HttpUserInfo::instance()->setLoginInfo(data);
    }
    else
    {
        LoginPage login;
        if(login.exec() == QDialog::Rejected)
        {
            exit(0);
        }
    }

    ui->pushButton_8->hide();
    ui->pushButton_10->hide();

    connect(HttpInterFace::getInstance(), &HttpInterFace::error_msg_box_text, this,[&](QString msg, int code){

        if(0 == code)
        {
            ClientConfig::getInstance()->setLoginData(QVariantMap());
            rebootExe();
        }
        else if(356 == code)
        {
            MsgBox::showMsg(this,tr("提示"), msg + " code=" + QString::number(code) );
            ClientConfig::getInstance()->setLoginData(QVariantMap());
            rebootExe();
        }
        else
        {
            MsgBox::showMsg(this,tr("提示"), msg + " code=" + QString::number(code) );
        }
    });

    initUserUI();
}

MainWindow::~MainWindow()
{
    if(m_agoraFace)
        m_agoraFace->deleteLater();
    if(m_timInterface)
    {
        m_timInterface->logout();
        m_timInterface->deleteLater();
        m_timInterface = nullptr;
    }
    if(m_emotionPage)
        m_emotionPage->deleteLater();
    if(m_giftPage)
        m_giftPage->deleteLater();
    m_micList.clear();

    if(m_valuePage)
        m_valuePage->deleteLater();
    if(m_soundValuePage)
        m_soundValuePage->deleteLater();
    if(m_player)
        m_player->deleteLater();

    if(m_chatPage)
        ChatPage::destroyInstance();

    delete ui;
}

void MainWindow::initUserUI()
{
    ui->number->hide();
    ui->mic_stackedWidget->setCurrentIndex(0);
    ui->autioMicBtn->show();
    ui->downMicBtn->hide();

    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    QString name = data["user"].toMap()["name"].toString();
    ui->userName->setText(name);
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        ui->userImage->setPixmap(QPixmap::fromImage(QImage(path)));
    });


    QtConcurrent::run([this]() {
        initAgora();
        initTim();
        m_timInterface->login();
    });

    initRoomInfoUI();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        Edge edge = getEdgeAt(mouseEvent->pos());
        updateCursor(edge);
    }
    return QWidget::eventFilter(watched, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_dragEdge = getEdgeAt(event->pos());

        if(event->pos().ry() < 66)
        {
            m_dragStartPos = event->globalPos();
            m_isDragging = true;
            m_dragEdge = getEdgeAt(event->pos());
        }
        else if (m_dragEdge != None)
        {
            m_dragStartPos = event->globalPos();
            m_isDragging = true;
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging)
    {
        QPoint diff = event->globalPos() - m_dragStartPos;
        if (m_dragEdge == None)
        {
            move(this->pos() + diff);
        }
        else
        {
            QRect newRect = geometry();
            if (m_dragEdge & Top) {
                newRect.setTop(event->globalPos().y());
            }
            if (m_dragEdge & Bottom) {
                newRect.setBottom(event->globalPos().y());
            }
            if (m_dragEdge & Left) {
                newRect.setLeft(event->globalPos().x());
            }
            if (m_dragEdge & Right) {
                newRect.setRight(event->globalPos().x());
            }
            setGeometry(newRect);
        }
        m_dragStartPos = event->globalPos();
    }
}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isDragging = false;
    QRect erct =  this->geometry();
    ClientConfig::getInstance()->writeIniFile("CLIENT", "x", QString::number(erct.x()) );
    ClientConfig::getInstance()->writeIniFile("CLIENT", "y", QString::number(erct.y()) );
    ClientConfig::getInstance()->writeIniFile("CLIENT", "width", QString::number(erct.width()) );
    ClientConfig::getInstance()->writeIniFile("CLIENT", "height", QString::number(erct.height()) );
}

MainWindow::Edge MainWindow::getEdgeAt(const QPoint &pos)
{
    const int margin = 10;

    if (pos.y() < margin) {
        return (pos.x() < margin) ? TopLeft : (pos.x() > width() - margin ? TopRight : Top);
    } else if (pos.y() > height() - margin) {
        return (pos.x() < margin) ? BottomLeft : (pos.x() > width() - margin ? BottomRight : Bottom);
    } else if (pos.x() < margin) {
        return Left;
    } else if (pos.x() > width() - margin) {
        return Right;
    }
    return None;
}

void MainWindow::updateCursor(Edge edge)
{
    if (edge == None) {
        setCursor(Qt::ArrowCursor);
    } else if (edge == TopLeft || edge == BottomRight) {
        setCursor(Qt::SizeFDiagCursor);
    } else if (edge == TopRight || edge == BottomLeft) {
        setCursor(Qt::SizeBDiagCursor);
    } else if (edge == Left || edge == Right) {
        setCursor(Qt::SizeHorCursor);
    } else if (edge == Top || edge == Bottom) {
        setCursor(Qt::SizeVerCursor);
    }
}

#include <QTextCodec>
bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG") //windows平台
    {
        MSG* msg = reinterpret_cast<MSG*>(message);

        if(msg->message == WM_COPYDATA)
        {
            COPYDATASTRUCT *data = reinterpret_cast<COPYDATASTRUCT*>(msg->lParam);
            QTextCodec *gbk = QTextCodec::codecForName("GB18030");
            QString recevice = gbk->toUnicode((char *)(data->lpData));
            if(recevice.contains("showAudioTool"))
            {
                this->show();
                this->activateWindow();
                return true;
            }
        }
    }
    return QWidget::nativeEvent(eventType, message, result);//交给Qt处理
}

void MainWindow::joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed)
{
    qDebug()<<"join sueccess--------" <<channel;
}
//直播间的每个人麦克风音量回调
void MainWindow::audioVolumeIndication(int uid,int value)
{
    foreach (auto var, m_micList)
    {        
        if(var->getUserId() == QString::number(uid))        {

            var->setAudioValue(QString::number(uid), value);
            return;
        }
        if(0 == uid)
        {
            var->setAudioValue(QString::number(uid), value);
            return;
        }
    }
}

void MainWindow::reconnect()
{
    if(0 == m_agoraFace->leaveChannel())
    {
        HttpInterFace::getInstance()->joinRoom(g_roomID.toInt(), 1 , "", [&](const QVariant vart){
            QVariantMap roomdata = vart.toMap();
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
                MsgBox::showMsg(this,tr("提示"), roomdata["message"].toString());
        }, [&](int code, const QString& str){
            ui->stackedWidget->setCurrentIndex(0);
        });
    }
    else
    {
        MsgBox::showMsg(this,tr("提示"), tr("声网内部错误，请重启程序"));
    }
}

void MainWindow::initTim()
{
    if(m_timInterface == nullptr)
    {
        m_timInterface = TimInterface::getInstance();
        m_timInterface->initSDK();

        connect(m_timInterface, &TimInterface::msg_liveClose, this, &MainWindow::msg_liveClose);
        connect(m_timInterface, &TimInterface::loginStatus, this, &MainWindow::loginIm);
        connect(m_timInterface, &TimInterface::msg_notice, this, &MainWindow::msg_notice);
        connect(m_timInterface, &TimInterface::msg_playerUrl, this, &MainWindow::msg_playerUrl);
        connect(m_timInterface, &TimInterface::msg_txt, this, &MainWindow::msg_txt);
        connect(m_timInterface, &TimInterface::msg_image, this, &MainWindow::msg_image);
        connect(m_timInterface, &TimInterface::msg_gift, this, &MainWindow::msg_gift);
        connect(m_timInterface, &TimInterface::msg_gift_mp4, this, &MainWindow::msg_gift_mp4);
        connect(m_timInterface, &TimInterface::msg_micInfo, this, &MainWindow::msg_micInfo);
        connect(m_timInterface, &TimInterface::msg_updateMicList, this, &MainWindow::updateMicList);
        connect(m_timInterface, &TimInterface::msg_uninit, this, &MainWindow::msg_uninit);
        connect(m_timInterface, &TimInterface::msg_emotion, this, &MainWindow::msg_emotion);
        connect(m_timInterface, &TimInterface::msg_vip, this, &MainWindow::msg_vip);
        connect(m_timInterface, &TimInterface::msg_multipleAuthoriation, this, &MainWindow::msg_multipleAuthoriation);
        connect(m_timInterface, &TimInterface::msg_numbers, this, &MainWindow::msg_numbers);
    }
}

void MainWindow::loginIm(int code, QString msg)
{
    if (code != ERR_SUCC)
    {
        MsgBox::showMsg(this,tr("提示"), tr("私聊登录失败：") + msg);
    }
    else
    {
        if(nullptr == m_chatPage)
        {
            m_chatPage = ChatPage::getInstance();
            connect(m_timInterface, &TimInterface::c2c_msg_text, m_chatPage, &ChatPage::c2c_msg_text);
            connect(m_timInterface, &TimInterface::c2c_initTimList, m_chatPage, &ChatPage::c2c_initTimList);
            connect(m_timInterface, &TimInterface::c2c_initTimMsgList, m_chatPage, &ChatPage::c2c_initTimMsgList);
            connect(m_timInterface, &TimInterface::c2c_msg_image, m_chatPage, &ChatPage::c2c_msg_image);
            connect(m_timInterface, &TimInterface::msg_numbers, m_chatPage, &ChatPage::c2c_msgNumber);
            connect(m_timInterface, &TimInterface::msg_uidNumbers, m_chatPage, &ChatPage::msg_uidNumbers);
            connect(m_timInterface, &TimInterface::c2c_msg_inviteFriends, m_chatPage, &ChatPage::c2c_msg_inviteFriends);
            connect(UserinfoPage::getInstance(), &UserinfoPage::chatC2C, this,[&](QVariantMap data){
                m_chatPage->show();
                m_chatPage->ChatC2C(data);
            });            

            QtConcurrent::run([this]() {
                m_timInterface->initTIMConvGetConvList();
                m_timInterface->getTIMConvGetTotalUnreadMessageCount();
            });
        }
    }
}

void MainWindow::msg_liveClose()
{
    g_multipleAuthoriation = "";
    g_isManager = false;
    g_isHomeowner = false;
    cleanupLayout(ui->micLayout);
    cleanupLayout(ui->onlineList);
    cleanupLayout(ui->contList);
    cleanupLayout(ui->micList);

    m_micList.clear();
    ui->msgList->clear();
    ui->osList->clear();
    ui->chatList->clear();
    ui->enterRoomList->clear();
    ui->giftList->clear();

    QString chatRoomld = HttpUserInfo::instance()->getIMRoomID();
    m_timInterface->groupOut(chatRoomld.toLatin1());

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

void MainWindow::msg_image(QVariantMap user, QString path, QString largePath)
{
    ChatImageItem *item1 = new ChatImageItem;
    item1->setData(user, path, largePath);

    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatImageItem *item3 = new ChatImageItem;
    item3->setData(user, path, largePath);
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

void MainWindow::msg_multipleAuthoriation(QVariantMap data)
{
    foreach (auto var, m_micList)
    {
        if(var->getUserId() == data["data"].toMap()["pushData"].toMap()["targetUserId"].toString())
        {
            var->updateMultipleAuthoriation(data["data"].toMap()["pushData"].toMap()["multipleAuthoriation"].toString());
        }
        if(data["data"].toMap()["pushData"].toMap()["targetUserId"].toString() == HttpUserInfo::instance()->getUserID())
        {
            QString multipleAuthoriation = data["data"].toMap()["pushData"].toMap()["multipleAuthoriation"].toString();
            g_multipleAuthoriation = multipleAuthoriation;
            QString type = multipleAuthoriation.at(1);
            g_isManager = type.toInt();
            if(!g_isManager)
            {
                //ui->imageBtn->hide();
            }
            type = multipleAuthoriation.at(0);
            if(type.toInt() == 2)
                g_isHomeowner = true;
            else
                g_isHomeowner = false;
            if(!g_isHomeowner)
            {
                ui->closeLiveBtn->hide();
            }
        }
    }
}

void MainWindow::msg_playerUrl(QString url)
{
    //m_player->show();
    //m_player->starPlay(url);
}

void MainWindow::msg_vip(QVariantMap user, QString url)
{
    ChatImageItem *item1 = new ChatImageItem;
    item1->setGiftPath(user, url);

    QListWidgetItem *item = new QListWidgetItem();
    ui->msgList->addItem(item);
    ui->msgList->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->msgList->contentsRect().width(), item1->height()));
    ui->msgList->setCurrentRow(ui->msgList->count()-1);
    ui->msgList->scrollToBottom();

    ChatImageItem *item3 = new ChatImageItem;
    item3->setGiftPath(user, url);
    QListWidgetItem *item2 = new QListWidgetItem();
    ui->chatList->addItem(item2);
    ui->chatList->setItemWidget(item2,item3);
    item2->setSizeHint(QSize(ui->chatList->contentsRect().width(), item3->height()));
    ui->chatList->setCurrentRow(ui->chatList->count()-1);
    ui->chatList->scrollToBottom();

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

void MainWindow::msg_numbers(int numbers)
{
    if(numbers <= 0)
    {
        ui->number->hide();
    }
    if(numbers > 0 & numbers < 10)
    {
        ui->number->show();
        ui->number->setFixedWidth(14);
        ui->number->setText(QString::number(numbers));
    }
    if(numbers >= 10)
    {
        ui->number->show();
        ui->number->setFixedWidth(28);
        ui->number->setText(QString::number(numbers));
    }
    if(numbers > 99)
    {
        ui->number->show();
        ui->number->setFixedWidth(28);
        ui->number->setText("99+");
        return;
    }
}


//发送文字消息
void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();
    if(msg == (" "))
        return;
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
        m_emotionPage = new EmotionPage(this);
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
    qApp->quit();
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
    initRoomInfoUI();
}
//进入房间
void MainWindow::enterTheToom(QVariantMap data)
{
    ui->stackedWidget->setCurrentIndex(1);
    QString id = data["id"].toString();
    g_roomID = id;    

    QTimer::singleShot(10, this, [this](){

        int currentPage = 1;
        HttpInterFace::getInstance()->getOnlineInfo(g_roomID,currentPage, [&](const QVariant &data) {

            QVariantMap onlineInfo =  data.toMap();
            QVariantList list = onlineInfo["data"].toList();
            for(QVariant var : list)
            {
                QVariantMap map = var.toMap();
                OnlineItem *item = new OnlineItem();
                item->setFixedSize(390,70);
                item->setData(map,g_roomID);
                this->ui->onlineList->addWidget(item);
            }
        });
    });

    HttpInterFace::getInstance()->joinRoom(id.toInt(), 1 , "", [&](const QVariant vart){

        QVariantMap roomdata = vart.toMap();
        roomdata = roomdata["data"].toMap();
        m_roomInfo = roomdata;
        HttpUserInfo::instance()->setRoomInfo(roomdata);

        QString rtcToken = roomdata["rtcToken"].toString();
        QString chatRoomId = roomdata["roomId"].toString();

        int userId = roomdata["userInfoResponse"].toMap()["userId"].toInt();
        QtConcurrent::run([this,rtcToken, chatRoomId,userId]() {
            m_agoraFace->joinChannel(rtcToken, chatRoomId, userId);
            m_agoraFace->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
            m_agoraFace->enableLoopbackRecording(true);
        });

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

        QString chatRoomld = HttpUserInfo::instance()->getIMRoomID();
        m_timInterface->groupJoin(chatRoomld.toLatin1());
        QString multipleAuthoriation = roomdata["multipleAuthoriation"].toString();
        g_multipleAuthoriation = multipleAuthoriation;
        QString type = multipleAuthoriation.at(1);
        QString type1 = multipleAuthoriation.at(2);
        if(type.toInt() == 1 || type1.toInt() == 1)
        {
            g_isManager = true;
        }
        else
        {
            g_isManager = false;
        }

        type = multipleAuthoriation.at(0);
        if(type.toInt() == 2)
            g_isHomeowner = true;
        else
            g_isHomeowner = false;
        if(!g_isHomeowner)
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

            label->setFixedWidth(ui->msgList->width());
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
    }, [&](int code, const QString& str){
             ui->stackedWidget->setCurrentIndex(0);
    });

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

void MainWindow::initRoomInfoUI()
{
    cleanupLayout(ui->gridLayout);
    HttpInterFace::getInstance()->getLiveRoomInfo_asy([&](QVariant vart){

        QVariantMap roomInfo = vart.toMap()["data"].toMap();
        QVariantMap pcFamilyPo = roomInfo["pcFamilyPo"].toMap();
        QString fName = pcFamilyPo["name"].toString();
        ui->guildName->setText(fName);
        QString fID = pcFamilyPo["id"].toString();
        ui->IDLabel->setText(fID);
        QString intro = pcFamilyPo["intro"].toString();
        ui->intro->setText(intro);
        QString fPhotoUrl = pcFamilyPo["photo"].toString();
        HttpInterFace::getInstance()->downLoad(fPhotoUrl, [&](const QString &path) {
            ui->guildImage->setPixmap(QPixmap::fromImage(QImage(path)));
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
    }, this);
}

void MainWindow::setMyselfMicInfo(int status)
{
    if(status >= 0)
    {
        ui->downMicBtn->show();
        ui->autioMicBtn->hide();
        if(status == 0)
            m_agoraFace->setClientRole(CLIENT_ROLE_BROADCASTER);
        if(status == 1)
            m_agoraFace->setClientRole(CLIENT_ROLE_AUDIENCE);
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
    NewUserPage::getInstance()->init();
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
            item->setData(map, i+1, g_isManager);
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
    HttpInterFace::getInstance()->b_upMic(roomID, userID,nullptr,this);
}

void MainWindow::on_autioMicBtn_clicked()
{
    if(ui->autioMicBtn->isChecked())
    {
        HttpInterFace::getInstance()->addMic(HttpUserInfo::instance()->getClassRoomID(),1, [=](const QVariant &content){
            ui->autioMicBtn->setText(QStringLiteral("取消上麦"));
        },this);

    }
    else
    {
        HttpInterFace::getInstance()->addMic(HttpUserInfo::instance()->getClassRoomID(),0, [=](const QVariant &content){
            ui->autioMicBtn->setText(QStringLiteral("上麦"));
        },this);
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
    if(!g_isManager)
    {
        MsgBox::showMsg(this,tr("提示"), tr("只有房主+主持身份用户可以使用该功能"));
    }
    else
    {
        if(QDialog::Accepted == MsgBox::showMsg(this,tr("提示"), tr("是否清空全麦魅力值"),MsgBox::QUERYDIALOG))
        {
            HttpInterFace::getInstance()->clearCardiacValue(g_roomID, [&](const QVariant &map) {

            });
        }
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    if(QDialog::Accepted == MsgBox::showMsg(this,tr("提示"), tr("是否确认通知我的全部粉丝"),MsgBox::QUERYDIALOG))
    {
        HttpInterFace::getInstance()->noticeFans(g_roomID, [&](const QVariant &map) {
            QVariantMap data = map.toMap();
            if(data["code"].toInt() != 1)
            {
                MsgBox::showMsg(this,tr("提示"), data["message"].toString());
            }
        });
    }
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
        return;
    }
    if(arg1.isEmpty())
    {
        ui->sendBtn->setDisabled(true);
    }
    else
    {
        ui->sendBtn->setDisabled(false);
    }
}

void MainWindow::on_closeLiveBtn_clicked()
{
    if(QDialog::Accepted == MsgBox::showMsg(this,tr("提示"), tr("所有用户将强制退出房间，确定结束直播吗？"),MsgBox::QUERYDIALOG))
    {
        HttpInterFace::getInstance()->closeRoom(g_roomID,[=](const QVariant &content){
            QVariantMap data = content.toMap();
            if(data["code"].toInt() == 1)
            {
                msg_liveClose();
            }
        });
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(nullptr == m_valuePage)
    {
        m_valuePage = new AudioValuePage(this);
        connect(m_valuePage, &AudioValuePage::valueChange, this, [this](int value) {

            m_agoraFace->setRecordingDeviceVolume(value);
        });
    }
    if(m_agoraFace->getRecordingDeviceList().size() <= 0)
    {
        MsgBox::showMsg(this,tr("提示"), tr("没有麦克风设备"));
        return;
    }
    m_valuePage->setValue(m_agoraFace->getRecordingDeviceVolume());
    QPoint point;
    point.setX(ui->pushButton_4->mapToGlobal(QPoint(0, 0)).rx());
    point.setY(ui->pushButton_4->mapToGlobal(QPoint(0, 0)).ry() - m_valuePage->height());
    m_valuePage->move(point);
    m_valuePage->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    if(nullptr == m_soundValuePage)
    {
        m_soundValuePage = new AudioValuePage(this);
        connect(m_soundValuePage, &AudioValuePage::valueChange, this, [this](int value) {
            if(value >0)
                m_agoraFace->setPlaybackDeviceMute(false);
            m_agoraFace->setPalyoutDeviceVolume(value);
        });
    }
    m_soundValuePage->setValue(m_agoraFace->getPalyoutDeviceVolume());
    QPoint point;
    point.setX(ui->pushButton_6->mapToGlobal(QPoint(0, 0)).rx());
    point.setY(ui->pushButton_6->mapToGlobal(QPoint(0, 0)).ry() - m_soundValuePage->height());
    m_soundValuePage->move(point);
    m_soundValuePage->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    ChatPage::getInstance()->show();
    ChatPage::getInstance()->activateWindow();
}

void MainWindow::chatC2C(QVariantMap data)
{
    on_pushButton_7_clicked();
    m_chatPage->show();
    m_chatPage->ChatC2C(data);
}

void MainWindow::initMax(bool isMax)
{
    if(isMax)
        ui->maxBtn->hide();
    else
        ui->max_c_btn->hide();
}

void MainWindow::on_pushButton_19_clicked()
{
    if(false == g_isHomeowner)
    {
        MsgBox::showMsg(this,tr("提示"), tr("只有房主才能使用该功能"));
        return;
    }
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    ManagementPage page;
    page.init(m_roomInfo);
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}


void MainWindow::on_pushButton_26_clicked()
{
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    RoomEidtPage page;
    page.setData(m_roomInfo);
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}


void MainWindow::on_pushButton_25_clicked()
{
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    RoomInvitePage page;
    connect(&page, &RoomInvitePage::roomInvite, this, [&](QVariantMap data){

        data["user_profile_identifier"] = "user" + data["userId"].toString();
        data["user_profile_nick_name"] = data["name"].toString();
        data["user_profile_face_url"] = data["photo"].toString();

        data["roomPhoto"] = m_roomInfo["roomPhoto"];
        data["roomId"] = m_roomInfo["roomId"];
        data["roomName"] = m_roomInfo["roomName"];

        TimInterface::getInstance()->sendInvMsg("user" + data["userId"].toString());
        m_chatPage->c2c_msg_inviteFriends(data);
    });
    page.init(m_roomInfo);
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}


void MainWindow::on_pushButton_22_clicked()
{
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    PromoteBusinePage page;
    page.init(m_roomInfo["roomId"].toString());
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}


void MainWindow::on_pushButton_20_clicked()
{
    if(false == g_isHomeowner)
    {
        MsgBox::showMsg(this,tr("提示"), tr("只有房主才能使用该功能"));
        return;
    }
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    HotPushPage page;
    page.init(m_roomInfo["roomId"].toString());
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}

void MainWindow::on_maxBtn_clicked()
{
    ui->maxBtn->hide();
    ui->max_c_btn->show();
    showMaximized();
    ClientConfig::getInstance()->writeIniFile("CLIENT", "isMax", "1");
}

void MainWindow::on_max_c_btn_clicked()
{
    ui->maxBtn->show();
    ui->max_c_btn->hide();
    showNormal();
    ClientConfig::getInstance()->writeIniFile("CLIENT", "isMax", "0");
}

#include "usermenu.h"
#include "UserinfoPageSimple.h"
#include <QScreen>
#include "SetTingMenu.h"
void MainWindow::on_pushButton_9_clicked()
{
    SetTingMenu *menu = new SetTingMenu;
    connect(menu, &SetTingMenu::updateRoomData, this, &MainWindow::updateOnlineInfo);
    connect(menu, &SetTingMenu::setTing, this, &MainWindow::setTing);
    connect(menu, &SetTingMenu::aboutPage, this, &MainWindow::aboutPage);

    QPoint point;
    point.setX(ui->pushButton_9->mapToGlobal(QPoint(0, 0)).rx() + ui->pushButton_9->width()/2 - menu->width()/2);
    point.setY(ui->pushButton_9->mapToGlobal(QPoint(0, 0)).ry() + ui->pushButton_9->height());

    menu->move(point);
    menu->show();
    m_isDragging = false;
}


void MainWindow::on_userName_clicked()
{
    UserMenu *meun = new UserMenu;
    connect(meun, &UserMenu::showMyselfData, [&](){
        UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
        page->init(HttpUserInfo::instance()->getUserID());

        QScreen *targetScreen = QGuiApplication::screenAt(QCursor::pos());
        if (!targetScreen) targetScreen = QGuiApplication::primaryScreen();
        QRect screenRect = targetScreen->geometry();
        page->move(screenRect.center() - page->rect().center());

        page->show();
    });
    connect(meun, &UserMenu::reLogin, this, [](){
        ClientConfig::getInstance()->writeIniFile("CLIENT", "isrememberpasswd", "0" );
        ClientConfig::getInstance()->setLoginData(QVariantMap());
        rebootExe();
    });

    QPoint point;
    point.setX(ui->userName->mapToGlobal(QPoint(0, 0)).rx() + ui->userName->width()/2 - meun->width()/2);
    point.setY(ui->userName->mapToGlobal(QPoint(0, 0)).ry() + ui->userName->height());

    meun->move(point);
    meun->show();
    m_isDragging = false;
}

#include "DressUpPage.h"
void MainWindow::on_pushButton_21_clicked()
{
    QWidget *mask = new QWidget(this);
    mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    mask->setGeometry(rect());
    mask->show();

    DressUpPage page;
    page.init();
    connect(&page, &QDialog::finished, [=](){
        mask->deleteLater();
    });
    page.exec();
}

void MainWindow::updateOnlineInfo()
{
    cleanupLayout(ui->onlineList);
    int currentPage = 1;
    HttpInterFace::getInstance()->getOnlineInfo(g_roomID,currentPage, [&](const QVariant &data) {

        QVariantMap onlineInfo =  data.toMap();
        QVariantList list = onlineInfo["data"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            OnlineItem *item = new OnlineItem();
            item->setFixedSize(390,70);
            item->setData(map,g_roomID);
            ui->onlineList->addWidget(item);
        }
    });
}

void MainWindow::setTing()
{
    QTimer::singleShot(30, this, [this](){
        QWidget *mask = new QWidget(this);
        mask->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
        mask->setGeometry(rect());
        mask->show();

        SetTingPage page;
        page.init();
        connect(&page, &QDialog::finished, [=](){
            mask->deleteLater();
        });
        page.exec();
    });
}

void MainWindow::aboutPage()
{

}

void MainWindow::on_pushButton_11_clicked()
{

}

void MainWindow::msg_gift_mp4(QString str)
{
    if(nullptr == m_player)
    {
        m_player = new WebPlayerPage(ui->widget_26);
        m_player->setGeometry(ui->widget_26->geometry());
    }

    m_player->init(str);
    m_player->show();
}

