#include "UserinfoPage.h"
#include "ui_UserinfoPage.h"
#include "HttpInterFace.h"

UserinfoPage::UserinfoPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserinfoPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

UserinfoPage::~UserinfoPage()
{
    delete ui;
}

void UserinfoPage::init(QString userID)
{
    HttpInterFace::getInstance()->getUserInfo(userID, [&](const QVariant &map) {

        QVariantMap data = map.toMap()["data"].toMap();
        QString photo = data["photo"].toString();
        HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
            this->ui->big_image->setPixmap(QPixmap(path));
            this->ui->image->setPixmap(QPixmap(path));
        });

        QString name = data["name"].toString();
        ui->name->setText(name);

        ui->constellation->setText(data["constellation"].toString());

        ui->age->setText(data["age"].toString());
        int sex = data["age"].toInt();
        if(0 == sex)//性别：0是女生，1是男生
        {

        }
        else
        {

        }

        ui->userLevel->setText(data["userLevel"].toString());
        ui->userId->setText(tr("ID：") + data["userId"].toString());
        ui->location->setText(data["location"].toString());
        ui->fansNum->setText(data["fansNum"].toString());
        ui->playDayNum->setText(data["playDayNum"].toString());

        int isAttention = data["isAttention"].toInt();
        if(0 == isAttention)//是否已关注该用户，1是，0否,-1=查看自己资料，无需展示关注按钮
        {
            ui->Attention->setText(tr("关注"));
        }
        else if(1 == isAttention)
        {
            ui->Attention->setText(tr("取消关注"));
        }
        else
        {
            ui->Attention->hide();
        }

        ui->intro->setText(data["intro"].toString());

    });
}

void UserinfoPage::on_closeBtn_clicked()
{
    close();
}

