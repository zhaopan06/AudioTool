#include "ChatTextItem.h"
#include "qmovie.h"
#include "qtimer.h"
#include "ui_ChatTextItem.h"
#include "HttpInterFace.h"
#include <QRegularExpression>
#include "Global.h"
#include <QLabel>
#include <QApplication>
#include <QVBoxLayout>
#include <QFontMetrics>
#include <QFontDatabase>

ChatTextItem::ChatTextItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatTextItem)
{
    ui->setupUi(this);
    ui->laout->setAlignment(Qt::AlignLeft);
}

ChatTextItem::~ChatTextItem()
{
    delete ui;
}

void ChatTextItem::setData(QVariantMap data,QString msg, int type)
{
    showMapTojson(data);
    QVariantMap userLevelCompare = data["userLevelCompare"].toMap();
    QString level = userLevelCompare["level"].toString();
    ui->user_lab->setText(level);

    QString multipleAuthoriation = data["multipleAuthoriation"].toString();
    if(multipleAuthoriation.size() > 6)
    {
        int num = QString(multipleAuthoriation.at(0)).toInt();
        if(2 == num)
        {
            ui->label_3->setText(tr("房主"));
        }
        else
        {
            num = QString(multipleAuthoriation.at(2)).toInt();
            if(1 == num)
            {
                ui->label_3->setText(tr("管理"));
            }
            else
            {
                ui->label_3->hide();
            }
        }
    }

    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
    QString photoBorder = data["photoBorder"].toString();
    HttpInterFace::getInstance()->downLoad(photoBorder, [&](const QString &path) {
        this->ui->image_2->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    QLabel *label = new QLabel();
    label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    if(12 == type)
    {
        label->setStyleSheet("font-family: \"微软雅黑\";"
                             "font-size: 16px;"
                             "color: rgba(237, 82, 90, 1);"
                             "text-align: left;");
    }

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

void ChatTextItem::setImage(QVariantMap data, QString msg)
{

}

void ChatTextItem::setEmotion(QVariantMap data, QString path, int type)
{
    QVariantMap userLevelCompare = data["userLevelCompare"].toMap();
    QString level = userLevelCompare["level"].toString();
    ui->user_lab->setText(level);

    QString multipleAuthoriation = data["multipleAuthoriation"].toString();
    if(multipleAuthoriation.size() > 6)
    {
        int num = QString(multipleAuthoriation.at(0)).toInt();
        if(2 == num)
        {
            ui->label_3->setText(tr("房主"));
        }
        else
        {
            num = QString(multipleAuthoriation.at(2)).toInt();
            if(1 == num)
            {
                ui->label_3->setText(tr("管理"));
            }
            else
            {
                ui->label_3->hide();
            }
        }
    }

    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
    QString photoBorder = data["photoBorder"].toString();
    HttpInterFace::getInstance()->downLoad(photoBorder, [&](const QString &path) {
        this->ui->image_2->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    QLabel *label = new QLabel();
    label->setFixedSize(34,34);
    label->setScaledContents(true);
    ui->textLayout->addWidget(label);
    this->adjustSize();
    if(type > 4)
    {
        label->setPixmap(QPixmap(path));
        return;
    }

    QString giftPath;
    switch (type) {
    case 1:
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
    label->setMovie(movie);
    movie->start();

    QTimer::singleShot(3000, [label, movie, path]() {
        movie->stop();
        label->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}
