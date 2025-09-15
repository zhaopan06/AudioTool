#include "ChatPageLeftItem.h"
#include "Global.h"
#include "ui_ChatPageLeftItem.h"
#include "HttpInterFace.h"

ChatPageLeftItem::ChatPageLeftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageLeftItem)
{
    ui->setupUi(this);
}

ChatPageLeftItem::~ChatPageLeftItem()
{
    delete ui;
}

void ChatPageLeftItem::setData(QVariantMap data, QString text)
{
    m_data = data;
    QString conv_face_url = data["conv_face_url"].toString();
    QString name = data["conv_show_name"].toString();
    ui->name->setText(name);

    QString str = text;
    str.replace("\r","");
    str.replace("\t","");
    str.replace("\n", "");
    QFont font("Microsoft YaHei");
    font.setPixelSize(16);
    QFontMetrics fontMetrics(font);
    int textWidth = fontMetrics.horizontalAdvance(str);
    if(textWidth > 250)
    {
        str = fontMetrics.elidedText(str,Qt::ElideRight,250);
        str = str.left(str.size()-1)+ QString("...");
    }
    ui->text->setText(str);

    int numbers = data["conv_unread_num"].toInt();
    updateNumbers(numbers);

    HttpInterFace::getInstance()->downLoad(conv_face_url, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
    });
}

void ChatPageLeftItem::setClick()
{
    emit leftItemClicked(m_data["conv_id"].toString());
}

QString ChatPageLeftItem::getUid()
{
    return m_data["conv_id"].toString();
}

void ChatPageLeftItem::updateText(QString text)
{
    QString str = text;
    str.replace("\r","");
    str.replace("\t","");
    str.replace("\n", "");
    QFont font("Microsoft YaHei");
    font.setPixelSize(16);
    QFontMetrics fontMetrics(font);
    int textWidth = fontMetrics.horizontalAdvance(str);
    if(textWidth > 250)
    {
        str = fontMetrics.elidedText(str,Qt::ElideRight,250);
        str = str.left(str.size()-1)+ QString("...");
    }
    ui->text->setText(str);
}

void ChatPageLeftItem::updateNumbers(int numbers)
{
    if(numbers <= 0)
    {
        ui->number->hide();
    }
    if(numbers > 0 & numbers < 10)
    {
        ui->number->show();
        ui->number->setFixedWidth(14);
         ui->number->setText(QString::number(numbers));
    }
    if(numbers >= 10)
    {
        ui->number->show();
        ui->number->setFixedWidth(28);
        ui->number->setText(QString::number(numbers));
    }
    if(numbers > 99)
    {
        ui->number->show();
        ui->number->setFixedWidth(28);
        ui->number->setText("99+");
        return;
    }
}

void ChatPageLeftItem::mouseReleaseEvent(QMouseEvent *ev)
{
    emit leftItemClicked(m_data["conv_id"].toString());
}
