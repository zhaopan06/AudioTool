#include "MicseQuenceItem.h"
#include "ui_MicseQuenceItem.h"
#include "HttpInterFace.h"

MicseQuenceItem::MicseQuenceItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MicseQuenceItem)
{
    ui->setupUi(this);
}

MicseQuenceItem::~MicseQuenceItem()
{
    delete ui;
}

void MicseQuenceItem::setData(QVariantMap data, int num)
{
    m_data = data;

    ui->label->setText(QString::number(num));

    QString age = data["age"].toString();
    ui->pushButton->setText(age);

    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString vipLevelId = data["vipLevelId"].toString();
    ui->user_lab->setText(vipLevelId);

    int sex = data["vipLevelId"].toInt();
    if(1 == sex)
    {
        ui->pushButton->setIcon(QIcon(":/images/live_people_man.png"));
    }
    else if(0 == sex)
    {
        ui->pushButton->setIcon(QIcon(":/images/live_people_woman.png"));
    }

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });

}
//上麦
void MicseQuenceItem::on_micBtn_clicked()
{

}

