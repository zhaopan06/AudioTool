#include "ChatPage.h"
#include "ChatPageLeftItem.h"
#include "Global.h"
#include "qevent.h"
#include "qscrollbar.h"
#include "ui_ChatPage.h"
#include "HttpUserInfo.h"

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
    }

    if(m_chatPage == nullptr)
    {
        m_chatPage = new ChatPageC2C;
        ui->stackedWidget2->addWidget(m_chatPage);
        ui->stackedWidget2->setCurrentIndex(0);
        ui->stackedWidget1->setCurrentIndex(0);
    }
}

void ChatPage::on_communicationBtn_clicked()
{
    ui->stackedWidget1->setCurrentIndex(1);
}


void ChatPage::on_msgPageBtn_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);
}


void ChatPage::on_closeBtn_clicked()
{
    hide();
}

void ChatPage::initChatHisMsg(QString uid)
{
    TimInterface::getInstance()->initTIMMsgGetMsgList(uid);
    m_chatPage->setUid(uid);
}
void ChatPage::c2c_initTimMsgList(QVariantList list)
{
    m_chatPage->init(list);
}

void ChatPage::c2c_msg_image(QVariantMap data, QString path, QString bigPath)
{
    m_chatPage->addImageMsg(data, path, bigPath);
}

