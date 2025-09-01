#include "ChatTextMyItem.h"
#include "qmovie.h"
#include "qtimer.h"
#include "ui_ChatTextMyItem.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"
#include "Global.h"

ChatTextMyItem::ChatTextMyItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatTextMyItem)
{
    ui->setupUi(this);
    ui->horizontalLayout->setAlignment(Qt::AlignRight);
}

ChatTextMyItem::~ChatTextMyItem()
{
    delete ui;
}

void ChatTextMyItem::setData(QString path, QString msg)
{
    ui->widget->hide();
    HttpInterFace::getInstance()->downLoad(path, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoBorder = data["user"].toMap()["photoBorder"].toString();
    showMapTojson(data["user"].toMap());
    qDebug()<<"photoBorder==="<<photoBorder;
    HttpInterFace::getInstance()->downLoad(photoBorder, [&](const QString &path) {
        ui->image_2->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    //设置文字
    QLabel *label = new QLabel();
    label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    ui->textLayout->addWidget(label);
    QString labelText = msg;
    labelText = replaceEmojiTagsSimple(labelText);
    labelText.replace("\n","<br />");
    QString textStyle = "<p style='line-height:22px'>" + labelText + "</p>";
    label->setText(textStyle);
    QFont font("Microsoft YaHei");
    font.setPixelSize(16);
    QFontMetrics fontMetrics(font);
    int textWidth = fontMetrics.horizontalAdvance(msg);
    if(textWidth > 378)
    {
        ui->widget_2->setFixedWidth(395);
        label->setWordWrap(true);
        label->adjustSize();
        this->adjustSize();
    }
    else
    {
        label->adjustSize();
        ui->widget_2->setFixedWidth(label->width() + 24);
    }
}

void ChatTextMyItem::setEmotion(QString path, int type)
{
    ui->widget_2->hide();
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
    QString photoBorder = data["user"].toMap()["photoBorder"].toString();
    HttpInterFace::getInstance()->downLoad(photoBorder, [&](const QString &path) {
        this->ui->image_2->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    if(type > 4)
    {
        this->ui->label->setPixmap(QPixmap(path));
        return;
    }

    QString giftPath;
    switch (type) {
    case 1://骰子
    {
        giftPath = ":/images/gifts/dice.gif";
        break;
    }
    case 2:
    {
        giftPath = ":/images/gifts/finger.gif";
        break;
    }
    case 3:
    {
        giftPath = ":/images/gifts/light.webp";
        break;
    }
    case 4:
    {
        giftPath = ":/images/gifts/mic.gif";
        break;
    }

    default:
        break;
    }

    QMovie *movie = new QMovie(giftPath);
    movie->setScaledSize(QSize(34,34));
    ui->label->setMovie(movie);
    movie->start();

    QTimer::singleShot(3000, [movie, path, this]() {
        movie->stop();
        this->ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}
