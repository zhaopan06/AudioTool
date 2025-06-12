#include "ManagementPageItem.h"
#include "ui_ManagementPageItem.h"
#include <QPointer>
#include "HttpInterFace.h"

ManagementPageItem::ManagementPageItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManagementPageItem)
{
    ui->setupUi(this);
}

ManagementPageItem::~ManagementPageItem()
{
    delete ui;
}

void ManagementPageItem::setData(QVariantMap data)
{
    m_data = data;
    QString name = data["name"].toString();
    ui->name->setText(name);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });

    QString age = data["age"].toString();
    ui->ageBtn->setText(age);

    int sex = data["sex"].toInt();
    if(1 == sex)
    {
        ui->ageBtn->setIcon(QIcon(":/images/live_people_man.png"));
    }
    else if(0 == sex)
    {
        ui->ageBtn->setIcon(QIcon(":/images/live_people_woman.png"));
    }

    QString userId = data["userId"].toString();
    auto weakThis = QPointer<ManagementPageItem>(this);
    HttpInterFace::getInstance()->queryMessageListUserInfo(userId, [weakThis](const QVariant &data) {

        if (weakThis.isNull()) return;
        if(data.toMap()["data"].toList().size() > 0)
        {
            QVariantMap dataMap = data.toMap()["data"].toList().at(0).toMap();
            int isLiving = dataMap["isLiving"].toInt();
            if(1 == isLiving || 2 == isLiving)
            {
                weakThis->ui->label->show();
            }
            else
            {
                weakThis->ui->label->hide();
            }
        }
    });
}

void ManagementPageItem::on_pushButton_clicked()
{
    emit removeOne(m_data);
}

