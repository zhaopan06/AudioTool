#include "ChatPage.h"
#include "ChatPageCommunicationItem.h"
#include "ChatPageLeftItem.h"
#include "qevent.h"
#include "qmutex.h"
#include "qscrollbar.h"
#include "qtimer.h"
#include "ui_ChatPage.h"
#include "HttpInterFace.h"
#include "MsgBox.h"
#include "Base/IMSDK/TimInterface.h"

ChatPage* ChatPage::instance = nullptr;
ChatPage* ChatPage::getInstance()
{
    if (!instance)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!instance)
        {
            instance = new ChatPage();
        }
    }
    return instance;
}

void ChatPage::destroyInstance()
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

ChatPage::ChatPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    ui->listWidget->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->listWidget->verticalScrollBar()->setSingleStep(20);
    if(m_chatPage == nullptr)
    {
        m_chatPage = new ChatPageC2C;
        connect(m_chatPage, &ChatPageC2C::updateLeftText, this, &ChatPage::updateLeftText);
        ui->stackedWidget2->addWidget(m_chatPage);
        ui->stackedWidget2->setCurrentIndex(0);
        ui->stackedWidget1->setCurrentIndex(0);
    }
    installEventFilter(this);
}

ChatPage::~ChatPage()
{
    if(m_chatPage)
        m_chatPage->deleteLater();
    delete ui;
}

void ChatPage::init(QVariant data)
{

}

void ChatPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 66)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void ChatPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void ChatPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void ChatPage::showEvent(QShowEvent *event)
{
    static bool isF = false;
    if(false == isF)
    {
        if(m_chatList.size() > 0)
        {
            QTimer::singleShot(100, this, [this](){
                ui->listWidget->setCurrentRow(0);
                m_chatList.at(0)->setClick();
            });
        }
        isF = true;
    }
}

bool ChatPage::eventFilter(QObject *obj, QEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

    if (keyEvent->key() == Qt::Key_Escape)
    {
        return true;
    }

    return QDialog::eventFilter(obj, event);
}

void ChatPage::c2c_msg_text(QVariantMap data, QString msg)
{
    QString uid = data["user_profile_identifier"].toString();
    if(updateLeftText(msg, uid))
    {
        QVariantMap setData;
        setData["conv_unread_num"] = 1;
        setData["conv_id"] = data["user_profile_identifier"];
        setData["conv_show_name"] = data["user_profile_nick_name"];
        setData["conv_face_url"] = data["user_profile_face_url"];

        ChatPageLeftItem *item = new ChatPageLeftItem;
        connect(item, &ChatPageLeftItem::leftItemClicked, this, &ChatPage::initChatHisMsg);
        item->setData(setData, msg);
        QListWidgetItem *item1 = new QListWidgetItem();
        ui->listWidget->insertItem(0,item1);
        ui->listWidget->setItemWidget(item1,item);
        item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        m_chatList.append(item);
        return;
    }

    if(uid == m_chatPage->getUid())
        m_chatPage->addTextMsg(data, msg);
}

void ChatPage::c2c_initTimList(QVariantList list)
{
    foreach (auto var, list)
    {
        QString setText;
        QVariantMap data = var.toMap();
        if(!data["conv_id"].toString().contains("user"))
            continue;

        QVariantList elems = data["conv_last_msg"].toMap()["message_elem_array"].toList();
        foreach (auto var, elems)
        {
            QString text = var.toMap()["text_elem_content"].toString();
            uint32_t elem_type = var.toMap()["elem_type"].toInt();
            if(1 == elem_type)
            {
                setText = QStringLiteral("[图片]");
            }
            if(0 == elem_type)
            {
                setText = text;
            }
            if(3 == elem_type)
            {
                setText = QStringLiteral("[房间邀请]");
            }
        }

        QVariantMap setData;
        setData["conv_unread_num"] = data["conv_unread_num"];
        setData["conv_id"] = data["conv_id"];
        setData["conv_show_name"] = data["conv_show_name"];
        setData["conv_face_url"] = data["conv_face_url"];
        ChatPageLeftItem *item = new ChatPageLeftItem;
        connect(item, &ChatPageLeftItem::leftItemClicked, this, &ChatPage::initChatHisMsg);
        item->setData(setData, setText);
        QListWidgetItem *item1 = new QListWidgetItem();
        ui->listWidget->addItem(item1);
        ui->listWidget->setItemWidget(item1,item);
        item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        m_chatList.append(item);
    }
}

void ChatPage::on_communicationBtn_clicked()
{
    ui->stackedWidget1->setCurrentIndex(1);
    if(ui->listWidget_3->count() == 0)
    {
        auto var = ui->buttonGroup->checkedButton();
        var->click();
    }


    ui->label_3->setPixmap(QPixmap(QStringLiteral(":/images/icon_消息没未读未选.png")));
    ui->label_5->setStyleSheet("font-size:14px;"
                               "color:rgba(255,255,255,0.5);");

    ui->label_2->setPixmap(QPixmap(QStringLiteral(":/images/icon_通讯录.png")));
    ui->label_4->setStyleSheet("font-size:14px;"
                               "color:rgba(255,255,255,1);");
}


void ChatPage::on_msgPageBtn_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);

    ui->label_3->setPixmap(QPixmap(QStringLiteral(":/images/icon_消息没未读.png")));
    ui->label_5->setStyleSheet("font-size:14px;"
                               "color:rgba(255,255,255,1);");

    ui->label_2->setPixmap(QPixmap(QStringLiteral(":/images/icon_通讯录未选.png")));
    ui->label_4->setStyleSheet("font-size:14px;"
                               "color:rgba(255,255,255,0.5);");
}


void ChatPage::on_closeBtn_clicked()
{
    hide();
}

void ChatPage::initChatHisMsg(QString uid)
{
    if(m_curID == uid)
        return;
    TimInterface::getInstance()->initTIMMsgGetMsgList(uid);
    m_chatPage->setUid(uid);
    m_curID = uid;

    TimInterface::getInstance()->sendTIMMsgSendMessageReadReceipts(uid);
}

void ChatPage::c2c_initTimMsgList(QVariantList list)
{
    m_chatPage->init(list);
}

void ChatPage::c2c_msg_image(QVariantMap data, QString path, QString bigPath)
{
    QString uid = data["user_profile_identifier"].toString();
    if(updateLeftText(QStringLiteral("图片"), uid))
    {
        QVariantMap setData;
        setData["conv_unread_num"] = 1;
        setData["conv_id"] = data["user_profile_identifier"];
        setData["conv_show_name"] = data["user_profile_nick_name"];
        setData["conv_face_url"] = data["user_profile_face_url"];

        ChatPageLeftItem *item = new ChatPageLeftItem;
        connect(item, &ChatPageLeftItem::leftItemClicked, this, &ChatPage::initChatHisMsg);
        item->setData(setData, QStringLiteral("图片"));
        QListWidgetItem *item1 = new QListWidgetItem();
        ui->listWidget->insertItem(0,item1);
        ui->listWidget->setItemWidget(item1,item);
        item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        m_chatList.append(item);
        return;
    }

    if(uid == m_chatPage->getUid())
        m_chatPage->addImageMsg(data, path, bigPath);
}

void ChatPage::c2c_msgNumber(int numbers)
{
    if(numbers <= 0)
    {
        ui->number->hide();
        return;
    }
    if(numbers > 0 & numbers < 10)
    {
        ui->number->setFixedWidth(14);
    }
    if(numbers >= 10)
    {
        ui->number->setFixedWidth(28);
    }
    if(numbers > 99)
    {
        ui->number->show();
        ui->number->setFixedWidth(28);
        ui->number->setText("99+");
        return;
    }
    ui->number->setText(QString::number(numbers));
    ui->number->show();
}

void ChatPage::msg_uidNumbers(QString uid, int numbers)
{
    foreach (auto var, m_chatList)
    {
        if(var->getUid() == uid)
        {
            if(uid == m_curID)
            {
                var->updateNumbers(0);
                return;
            }
            else
            {
                var->updateNumbers(numbers);
            }
        }
    }
}

void ChatPage::on_pushButton_3_clicked()
{
    ui->listWidget_3->clear();
    HttpInterFace::getInstance()->getMyFollow(1,0,[&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ChatPageCommunicationItem *item  =new ChatPageCommunicationItem;
            connect(item, &ChatPageCommunicationItem::ChatC2C, this, &ChatPage::ChatC2C);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget_3->addItem(item1);
            ui->listWidget_3->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget_3->contentsRect().width(), item->height()));
            ui->listWidget_3->setCurrentRow(ui->listWidget_3->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

void ChatPage::on_pushButton_4_clicked()
{
    ui->listWidget_3->clear();
    HttpInterFace::getInstance()->getMyFollow(1,1,[&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ChatPageCommunicationItem *item  =new ChatPageCommunicationItem;
            connect(item, &ChatPageCommunicationItem::ChatC2C, this, &ChatPage::ChatC2C);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget_3->addItem(item1);
            ui->listWidget_3->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget_3->contentsRect().width(), item->height()));
            ui->listWidget_3->setCurrentRow(ui->listWidget_3->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

void ChatPage::on_pushButton_clicked()
{
    ui->listWidget_3->clear();
    HttpInterFace::getInstance()->getMyFollow(1,2,[&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ChatPageCommunicationItem *item  =new ChatPageCommunicationItem;
            connect(item, &ChatPageCommunicationItem::ChatC2C, this, &ChatPage::ChatC2C);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget_3->addItem(item1);
            ui->listWidget_3->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget_3->contentsRect().width(), item->height()));
            ui->listWidget_3->setCurrentRow(ui->listWidget_3->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

void ChatPage::on_pushButton_2_clicked()
{
    ui->listWidget_3->clear();
    HttpInterFace::getInstance()->getMyFollow(1,4,[&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ChatPageCommunicationItem *item  =new ChatPageCommunicationItem;
            connect(item, &ChatPageCommunicationItem::ChatC2C, this, &ChatPage::ChatC2C);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget_3->addItem(item1);
            ui->listWidget_3->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget_3->contentsRect().width(), item->height()));
            ui->listWidget_3->setCurrentRow(ui->listWidget_3->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

void ChatPage::ChatC2C(QVariantMap data)
{
    on_msgPageBtn_clicked();

    QString uid = "user" + data["userId"].toString();
    for(int i=0; i<m_chatList.size(); i++)
    {
        auto var = m_chatList.at(i);
        if(var->getUid() == uid)
        {
            var->setClick();
            ui->listWidget->setCurrentRow(i);
            return;
        }
    }

    QVariantMap setData;
    setData["conv_id"] = uid;
    setData["conv_show_name"] = data["name"];
    setData["conv_face_url"] = data["photo"];
    ChatPageLeftItem *item = new ChatPageLeftItem;
    connect(item, &ChatPageLeftItem::leftItemClicked, this, &ChatPage::initChatHisMsg);
    item->setData(setData, "");
    QListWidgetItem *item1 = new QListWidgetItem();
    ui->listWidget->insertItem(0, item1);
    ui->listWidget->setItemWidget(item1,item);
    item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
    ui->listWidget->setCurrentRow(0);
    m_chatList.insert(0,item);

    item->setClick();
}

void ChatPage::c2c_msg_inviteFriends(QVariantMap data)
{
    QString uid = data["user_profile_identifier"].toString();
    if(updateLeftText(QStringLiteral("房间邀请"), uid))
    {
        QVariantMap setData;
        setData["conv_unread_num"] = 1;
        setData["conv_id"] = data["user_profile_identifier"];
        setData["conv_show_name"] = data["user_profile_nick_name"];
        setData["conv_face_url"] = data["user_profile_face_url"];

        ChatPageLeftItem *item = new ChatPageLeftItem;
        connect(item, &ChatPageLeftItem::leftItemClicked, this, &ChatPage::initChatHisMsg);
        item->setData(setData, QStringLiteral("房间邀请"));
        QListWidgetItem *item1 = new QListWidgetItem();
        ui->listWidget->insertItem(0,item1);
        ui->listWidget->setItemWidget(item1,item);
        item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        m_chatList.append(item);
        return;
    }

    if(uid == m_chatPage->getUid())
        m_chatPage->addInviteFriends(data);
}

bool ChatPage::updateLeftText(QString text, QString uid)
{
    bool isNewUser = true;
    foreach (auto var, m_chatList)
    {
        if(var->getUid() == uid)
        {
            isNewUser = false;
            var->updateText(text);
            return isNewUser;
        }
    }

    return isNewUser;
}


void ChatPage::on_searchBtn_clicked()
{
    QString searchText = ui->lineEdit->text();
    if(searchText.isEmpty())
        return;

    HttpInterFace::getInstance()->getMyFollow(1,2,[&](const QVariant &data) {

        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ChatPageCommunicationItem *item  =new ChatPageCommunicationItem;
            connect(item, &ChatPageCommunicationItem::ChatC2C, this, &ChatPage::ChatC2C);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget_2->addItem(item1);
            ui->listWidget_2->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget_2->contentsRect().width(), item->height()));
            ui->listWidget_2->setCurrentRow(ui->listWidget_2->count()-1);
            ui->listWidget_2->scrollToBottom();            
        }

        if(list.size() > 0)
        {
            ui->stackedWidget_3->setCurrentIndex(1);
        }
        else
        {
            ui->stackedWidget_3->setCurrentIndex(0);
            MsgBox::showMsg(this,tr("提示"), data.toMap()["message"].toString());
        }
    }, searchText);
}

void ChatPage::on_minBtn_clicked()
{
    showMinimized();
}

void ChatPage::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->stackedWidget_3->setCurrentIndex(0);
    }
}

