#include "ChatPageC2CTextItem.h"
#include "Global.h"
#include "ImageDialog.h"
#include "ui_ChatPageC2CTextItem.h"
#include "HttpInterFace.h"

ChatPageC2CTextItem::ChatPageC2CTextItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2CTextItem)
{
    ui->setupUi(this);
}

ChatPageC2CTextItem::~ChatPageC2CTextItem()
{
    delete ui;
}

void ChatPageC2CTextItem::setData(QVariantMap data, QString text, int width)
{
    QString user_profile_face_url = data["user_profile_face_url"].toString();
    HttpInterFace::getInstance()->downLoad(user_profile_face_url, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });
    QString nickname = data["user_profile_nick_name"].toString();
    ui->name->setText(nickname);

    //设置文字
    ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    QString labelText = text;
    labelText = replaceEmojiTagsSimple(labelText);
    labelText.replace("\n","<br />");
    QString textStyle = "<p style='line-height:22px'>" + labelText + "</p>";
    ui->label->setText(textStyle);
    QFont font("Microsoft YaHei");
    font.setPixelSize(16);
    QFontMetrics fontMetrics(font);
    int textWidth = fontMetrics.horizontalAdvance(text);
    if(textWidth > (width - 160))
    {
        ui->widget_2->setFixedWidth(width - 160);
        ui->label->setWordWrap(true);
        ui->label->adjustSize();
        this->adjustSize();
    }
    else
    {
        ui->label->adjustSize();
        ui->widget_2->adjustSize();
        this->adjustSize();
    }
}

void ChatPageC2CTextItem::setImage(QVariantMap data, QString path, QString largePath)
{
    QString faceUrl = data["user_profile_face_url"].toString();
    HttpInterFace::getInstance()->downLoad(faceUrl, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });
    QString nickname = data["user_profile_nick_name"].toString();
    ui->name->setText(nickname);

    ui->widget_2->setStyleSheet("");
    m_bigImageUrl = largePath;

    ui->label->setFixedSize(156,156);
    this->setFixedHeight(186);
    ui->widget_2->setFixedSize(156,156);
    ui->widget_2->layout()->setMargin(0);
    HttpInterFace::getInstance()->downLoad(path, [&](const QString &path) {

        QPixmap pix = QPixmap::fromImage(QImage(path));
        pix = pix.scaled(156,156,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->label->setFixedWidth(pix.width());
        ui->label->setFixedHeight(pix.height());
        ui->widget_2->setFixedSize(pix.width(),pix.height());
        ui->label->setPixmap(pix);
        ui->label->setRadius(16);
    });
}

void ChatPageC2CTextItem::on_label_clicked()
{
    if(!m_bigImageUrl.isEmpty())
    {
        ImageDialog page;
        page.setUrlPath(m_bigImageUrl);
        page.exec();
    }
}

