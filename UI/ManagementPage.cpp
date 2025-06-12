#include "ManagementPage.h"
#include "Global.h"
#include "ManagementPageItem.h"
#include "qevent.h"
#include "ui_ManagementPage.h"
#include "HttpInterFace.h"

ManagementPage::ManagementPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagementPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

ManagementPage::~ManagementPage()
{
    delete ui;
}
//emceeUserList 主持人 roomAdminList 管理  muteUserList禁言  blackUserList 拉黑
void ManagementPage::init(QVariantMap data)
{
    m_roomInfo = data;
    on_button1_1_clicked();
}

void ManagementPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void ManagementPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void ManagementPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void ManagementPage::on_closeBtn_clicked()
{
    this->close();
}


void ManagementPage::on_button1_1_clicked()
{
    ui->listWidget->clear();
    QString roomID = m_roomInfo["roomId"].toString();
    HttpInterFace::getInstance()->getOwnerAuthList(roomID, [&](QVariant vart){

        QVariantList list  = vart.toMap()["data"].toMap()["emceeUserList"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ManagementPageItem *item  =new ManagementPageItem;
            connect(item, &ManagementPageItem::removeOne, this, [&](QVariantMap data){
                QString userId = data["userId"].toString();
                QVariantMap map = HttpInterFace::getInstance()->settingEmceeOrAdmin(2, userId);
                showMapTojson(map);
                on_button1_1_clicked();
            });
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        }


    });
}

void ManagementPage::on_button1_3_clicked()
{
    ui->listWidget->clear();
    QString roomID = m_roomInfo["roomId"].toString();
    HttpInterFace::getInstance()->getOwnerAuthList(roomID, [&](QVariant vart){

        QVariantList list  = vart.toMap()["data"].toMap()["roomAdminList"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ManagementPageItem *item  =new ManagementPageItem;
            connect(item, &ManagementPageItem::removeOne, this, [&](QVariantMap data){
                QString userId = data["userId"].toString();
                HttpInterFace::getInstance()->settingEmceeOrAdmin(3, userId);
                on_button1_3_clicked();
            });
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        }


    });
}

void ManagementPage::on_button1_2_clicked()
{
    ui->listWidget->clear();
    QString roomID = m_roomInfo["roomId"].toString();
    HttpInterFace::getInstance()->getOwnerAuthList(roomID, [&](QVariant vart){

        QVariantList list  = vart.toMap()["data"].toMap()["muteUserList"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ManagementPageItem *item  =new ManagementPageItem;
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        }


    });
}

void ManagementPage::on_button1_4_clicked()
{
    ui->listWidget->clear();
    QString roomID = m_roomInfo["roomId"].toString();
    HttpInterFace::getInstance()->getOwnerAuthList(roomID, [&](QVariant vart){

        QVariantList list  = vart.toMap()["data"].toMap()["blackUserList"].toList();
        foreach (auto var, list)
        {
            QVariantMap data = var.toMap();
            ManagementPageItem *item  =new ManagementPageItem;
            connect(item, &ManagementPageItem::removeOne, this, [&](QVariantMap data){

                QString userId = data["userId"].toString();
                QVariantMap map = HttpInterFace::getInstance()->settingEmceeOrAdmin(5, userId);
                on_button1_4_clicked();
            });
            item->setData(data);

            QListWidgetItem *item1 = new QListWidgetItem();
            ui->listWidget->addItem(item1);
            ui->listWidget->setItemWidget(item1,item);
            item1->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item->height()));
        }


    });
}

