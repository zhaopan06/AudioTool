#include "RoomInvitePage.h"
#include "HttpUserInfo.h"
#include "RoomInvitePageItem.h"
#include "qclipboard.h"
#include "qevent.h"
#include "ui_RoomInvitePage.h"
#include "HttpInterFace.h"

RoomInvitePage::RoomInvitePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomInvitePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
}

RoomInvitePage::~RoomInvitePage()
{
    delete ui;
}

void RoomInvitePage::init(QVariantMap data)
{
    QString url = data["shareUrl"].toString();
    QString roomId = data["roomId"].toString();
    QVariantMap loginInfo = HttpUserInfo::instance()->getLoginInfo();
    QString userName = loginInfo["user"].toMap()["name"].toString();
    url =  url + QString("?type=room&roomId=%1&userName=%2").arg(roomId, userName);
    ui->label->setText(url);
    on_pushButton_clicked();
}

void RoomInvitePage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void RoomInvitePage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void RoomInvitePage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void RoomInvitePage::on_copyBtn_clicked()
{
    QString text = ui->label->text();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(text);
    ui->copyBtn->setText(QStringLiteral("已复制"));
}

void RoomInvitePage::on_pushButton_clicked()
{
    ui->listWidget->clear();
    HttpInterFace::getInstance()->getMessageList([&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            RoomInvitePageItem *item  =new RoomInvitePageItem;
            connect(item, &RoomInvitePageItem::roomInvite, this, &RoomInvitePage::roomInvite);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        }
    });
}

void RoomInvitePage::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    HttpInterFace::getInstance()->getMyFollow(1,1,[&](const QVariant &data) {
        QVariantList list = data.toMap()["data"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            RoomInvitePageItem *item  =new RoomInvitePageItem;
            connect(item, &RoomInvitePageItem::roomInvite, this, &RoomInvitePage::roomInvite);
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));         
        }
    });
}


void RoomInvitePage::on_closeBtn_clicked()
{
    close();
}

