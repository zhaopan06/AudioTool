#include "ChatPageCommunicationItem.h"
#include "ui_ChatPageCommunicationItem.h"
#include "HttpInterFace.h"

ChatPageCommunicationItem::ChatPageCommunicationItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageCommunicationItem)
{
    ui->setupUi(this);
}

ChatPageCommunicationItem::~ChatPageCommunicationItem()
{
    delete ui;
}

void ChatPageCommunicationItem::setData(QVariantMap data)
{
    m_data = data;
    QString name = data["name"].toString();
    ui->name->setText(name);

    QString userId = data["userId"].toString();
    ui->userId->setText(QStringLiteral("ID：") + userId);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });

    QString age = data["age"].toString();
    ui->ageBtn->setText(age);

    int sex = data["sex"].toInt();
    if(0 == sex)//女生
    {

    }
    else
    {

    }



    HttpInterFace::getInstance()->queryMessageListUserInfo(userId, [&](const QVariant &data) {

        if(data.toMap()["data"].toList().size() > 0)
        {
            QVariantMap dataMap = data.toMap()["data"].toList().at(0).toMap();
            int isLiving = dataMap["isLiving"].toInt();
            if(1 == isLiving || 2 == isLiving)
            {
                ui->label_4->show();
            }
            else
            {
                ui->label_4->hide();
            }

            int isAttention = dataMap["isAttention"].toInt();
            if(isAttention > 0)
            {
                ui->pushButton_3->show();
                ui->pushButton->hide();
            }
            else
            {
                ui->pushButton_3->hide();
                ui->pushButton->show();
            }
        }
    });
}
//关注
void ChatPageCommunicationItem::on_pushButton_clicked()
{
    QVariantMap data = HttpInterFace::getInstance()->followUser(m_data["userId"].toString(), 1);
    ui->pushButton_3->show();
    ui->pushButton->hide();
}

//取消关注
void ChatPageCommunicationItem::on_pushButton_3_clicked()
{    
    QVariantMap data = HttpInterFace::getInstance()->followUser(m_data["userId"].toString(), 0);
    ui->pushButton_3->hide();
    ui->pushButton->show();
}

//私聊
void ChatPageCommunicationItem::on_pushButton_2_clicked()
{
    emit ChatC2C(m_data);
}

