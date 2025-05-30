#include "ChatPage.h"
#include "ChatPageCommunicationItem.h"
#include "ChatPageLeftItem.h"
#include "Global.h"
#include "qevent.h"
#include "qscrollbar.h"
#include "ui_ChatPage.h"
#include "HttpUserInfo.h"
#include "HttpInterFace.h"

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
}

ChatPage::~ChatPage()
{
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

void ChatPage::c2c_msg_text(QVariantMap data, QString msg)
{
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
        }

        QVariantMap setData;
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

    if(m_chatPage == nullptr)
    {
        m_chatPage = new ChatPageC2C;        
        if(m_chatList.size() > 0)
        {
            ui->listWidget->setCurrentRow(0);
            m_chatList.at(0)->setClick();
        }
        ui->stackedWidget2->addWidget(m_chatPage);
        ui->stackedWidget2->setCurrentIndex(0);
        ui->stackedWidget1->setCurrentIndex(0);
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
}
void ChatPage::c2c_initTimMsgList(QVariantList list)
{
    m_chatPage->init(list);
}

void ChatPage::c2c_msg_image(QVariantMap data, QString path, QString bigPath)
{
    m_chatPage->addImageMsg(data, path, bigPath);
}

//我的关注
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
            ui->listWidget_3->setCurrentRow(ui->listWidget->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

//我的粉丝
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
            ui->listWidget_3->setCurrentRow(ui->listWidget->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

//我的好友
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
            ui->listWidget_3->setCurrentRow(ui->listWidget->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

//我的访客
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
            ui->listWidget_3->setCurrentRow(ui->listWidget->count()-1);
            ui->listWidget_3->scrollToBottom();
        }
    });
}

void ChatPage::ChatC2C(QVariantMap data)
{
    //创建左边的Item
    ui->stackedWidget1->setCurrentIndex(0);
    QString uid = "user" + data["userId"].toString();

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
    m_chatList.append(item);

    item->setClick();
}

