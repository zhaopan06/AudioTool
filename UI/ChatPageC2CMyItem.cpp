#include "ChatPageC2CMyItem.h"
#include "ImageDialog.h"
#include "ui_ChatPageC2CMyItem.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"
#include "Global.h"
#include "qmovie.h"
#include "qtimer.h"

ChatPageC2CMyItem::ChatPageC2CMyItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2CMyItem)
{
    ui->setupUi(this);
    ui->horizontalLayout->setAlignment(Qt::AlignRight);
    ui->horizontalWidget->layout()->setAlignment(Qt::AlignTop);
}

ChatPageC2CMyItem::~ChatPageC2CMyItem()
{
    delete ui;
}

void ChatPageC2CMyItem::setData(QString path, QString msg, int width)
{
    ui->widget->hide();
    HttpInterFace::getInstance()->downLoad(path, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    //设置文字
    QLabel *label = new QLabel();
    label->setStyleSheet("background:rgba(255,255,255,0);");
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
    if(textWidth > (width - 160))
    {
        ui->widget_2->setFixedWidth(width - 160);
        label->setWordWrap(true);
        label->adjustSize();
        this->adjustSize();
    }
    else
    {
        label->adjustSize();
        ui->widget_2->adjustSize();
        this->adjustSize();
    }
}

void ChatPageC2CMyItem::setImage(QString path, QString largePath)
{
    ui->widget_2->hide();
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });


    ui->widget->setStyleSheet("");
    m_bigImageUrl = largePath;

    ui->label->setFixedSize(156,156);
    this->setFixedHeight(186);
    ui->widget->setFixedHeight(156);
    ui->widget->layout()->setContentsMargins(0,0,0,0);
    HttpInterFace::getInstance()->downLoad(path, [&](const QString &path) {

        QPixmap pix = QPixmap::fromImage(QImage(path));
        if(pix.width() > pix.height())
        {
            pix = pix.scaledToHeight(156);
        }
        else
        {
            pix = pix.scaled(156,156,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        }
        ui->label->setFixedWidth(pix.width());
        ui->label->setFixedHeight(pix.height());
        ui->widget->setFixedSize(pix.width(),pix.height());
        ui->label->setPixmap(pix);
        ui->label->setRadius(16);
    });
}

void ChatPageC2CMyItem::setLocalImage(QString path)
{
    ui->widget_2->hide();
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });


    ui->widget->setStyleSheet("");
    m_bigImageUrl = path;

    ui->label->setFixedSize(156,156);
    this->setFixedHeight(186);
    ui->widget->setFixedSize(156,156);
    ui->widget->layout()->setMargin(0);

    QPixmap pix = QPixmap::fromImage(QImage(path));
    pix = pix.scaled(156,156,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label->setFixedWidth(pix.width());
    ui->label->setFixedHeight(pix.height());
    ui->widget->setFixedSize(pix.width(),pix.height());
    ui->label->setPixmap(pix);
    ui->label->setRadius(16);
}

void ChatPageC2CMyItem::setEmotion(QString path, int type)
{
    ui->widget_2->hide();
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photoUrl, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
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
        giftPath = ":/images/gifts/light.gif";
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

void ChatPageC2CMyItem::on_label_clicked()
{
    if(!m_bigImageUrl.isEmpty())
    {
        ImageDialog page;
        page.setUrlPath(m_bigImageUrl);
        page.exec();
    }
}

