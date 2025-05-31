#include "ChatPageLeftItem.h"
#include "Global.h"
#include "ui_ChatPageLeftItem.h"
#include "HttpInterFace.h"

ChatPageLeftItem::ChatPageLeftItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageLeftItem)
{
    ui->setupUi(this);
    //TODO获取历史数据
    //TIMMsgGetMessageReactions
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
    ui->text->setText(text);

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
    ui->text->setText(text);
}

void ChatPageLeftItem::mouseReleaseEvent(QMouseEvent *ev)
{
    emit leftItemClicked(m_data["conv_id"].toString());
}
