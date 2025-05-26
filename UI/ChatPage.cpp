#include "ChatPage.h"
#include "ChatPageLeftItem.h"
#include "Global.h"
#include "qevent.h"
#include "qscrollbar.h"
#include "ui_ChatPage.h"

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
    showMapTojson(data.toMap());
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
    showMapTojson(data);
}

void ChatPage::c2c_initTimList(QVariantList list)
{
    foreach (auto var, list)
    {
        QString setText;
        QVariantMap data = var.toMap();
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

        QVariantMap setData = data["conv_last_msg"].toMap()["message_sender_profile"].toMap();
        ChatPageLeftItem *item = new ChatPageLeftItem;
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

