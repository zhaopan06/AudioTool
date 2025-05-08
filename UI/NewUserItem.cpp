#include "NewUserItem.h"
#include "ui_NewUserItem.h"
#include "HttpInterFace.h"

NewUserItem::NewUserItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewUserItem)
{
    ui->setupUi(this);
}

NewUserItem::~NewUserItem()
{
    delete ui;
}

void NewUserItem::setData(QVariantMap data)
{
    m_data = data;
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    bool userInRoom = data["userInRoom"].toBool();
    ui->label_2->setVisible(userInRoom);

    qint64 timestamp = data["registerTime"].toInt();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
    QString formattedDate = dateTime.toString("yyyy-MM-dd");
    if(dateTime.date() == QDateTime::currentDateTime().date())
    {
        ui->label->setText(QStringLiteral("今天注册"));
    }
    else
    {
        ui->label->setText(formattedDate + QStringLiteral("注册"));
    }


    int attentionType =  data["attentionType"].toInt();
    m_isFollow = attentionType;
    if(0 == attentionType)
        ui->pushButton->setChecked(false);
    if(1 == attentionType)
    {
        ui->pushButton->setText(QStringLiteral("取消关注"));
        ui->pushButton->setChecked(true);
    }


    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}

//关注
void NewUserItem::on_pushButton_clicked()
{
    QString id = m_data["id"].toString();
    int isFollow = 0;
    int attentionType =  m_isFollow;
    if(0 == attentionType)
    {
        isFollow = 1;
    }
    else
    {
        isFollow = 0;
    }
    QVariantMap data = HttpInterFace::getInstance()->followUser(id, isFollow);

    if(0 == isFollow)
    {
        ui->pushButton->setText(QStringLiteral("关注"));
        ui->pushButton->setChecked(false);
    }
    if(1 == isFollow)
    {
        ui->pushButton->setText(QStringLiteral("取消关注"));
        ui->pushButton->setChecked(true);
    }

    m_isFollow = isFollow;

}

//邀请
void NewUserItem::on_pushButton_3_clicked()
{

}

//打招呼
void NewUserItem::on_pushButton_2_clicked()
{

}

