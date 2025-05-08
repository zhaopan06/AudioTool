#include "OnlineItem.h"
#include "qdebug.h"
#include "ui_OnlineItem.h"
#include "HttpInterFace.h"

OnlineItem::OnlineItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OnlineItem)
{
    ui->setupUi(this);
}

OnlineItem::~OnlineItem()
{
    delete ui;
}
/*
 *
status;//1-8代表1-8号麦，-1=在房间，-2=在线并且最近来过，-3=离线并最近来过  这是在线列表中status


-1 在房间  -2 在线 -3 离线

 */
void OnlineItem::setData(QVariantMap data, QString id)
{
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString vipLevelId = data["vipLevelId"].toString();
    ui->user_lab->setText(vipLevelId);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    int status = data["status"].toInt();
    QString userId = data["userId"].toString();
    qDebug()<<"status---"<<status;
    if(status == -1)
    {
        ui->user_btn->hide();

        if(userId == id) //房主
        {
            ui->user_lab->hide();

        }
        else
        {
            ui->room_lab->hide();
        }
    }
    else
    {
        ui->room_btn->hide();
        ui->room_lab->hide();
    }

    if(status > 0 && status < 9)
    {

        QString str =  QString::number(status) + QStringLiteral("号麦");
        ui->user_btn->setText(str);
    }
    if(status == -2)
    {
    }
    if(status == -2)
    {

    }

    m_data = data;
}
