#include "ChatPageC2C.h"
#include "ChatPageC2CTextItem.h"
#include "Global.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "ui_ChatPageC2C.h"

ChatPageC2C::ChatPageC2C(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2C)
{
    ui->setupUi(this);
}

ChatPageC2C::~ChatPageC2C()
{
    delete ui;
}

void ChatPageC2C::init(QVariantList list)
{
    ui->listWidget->clear();

    foreach (auto var, list)
    {
        QVariantMap data = var.toMap();
        QVariantList elems = data["message_elem_array"].toList();
        foreach (auto var, elems)
        {
            QString text = var.toMap()["text_elem_content"].toString();
            uint32_t elem_type = var.toMap()["elem_type"].toInt();
            if(1 == elem_type)//图片
            {
                showMapTojson(data);


                QString path = var.toMap()["image_elem_thumb_url"].toString();
                QString largePath = var.toMap()["image_elem_large_url"].toString();
                qDebug()<<"path---"<<path;
                qDebug()<<"largePath---"<<largePath;

                QVariantMap message_offline_push_config = data["message_offline_push_config"].toMap();
                QString userstr = message_offline_push_config["offline_push_config_ext"].toString();
                QJsonObject userData = QJsonDocument::fromJson(userstr.toUtf8()).object();

                ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
                QListWidgetItem *item = new QListWidgetItem();
                ui->listWidget->insertItem(0, item);
                ui->listWidget->setItemWidget(item,item1);
                item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                item1->setImage(userData.toVariantMap(), path, largePath);
            }
            if(0 == elem_type)
            {

                QVariantMap message_offline_push_config = data["message_offline_push_config"].toMap();
                QString userstr = message_offline_push_config["offline_push_config_ext"].toString();
                QJsonObject userData = QJsonDocument::fromJson(userstr.toUtf8()).object();

                ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
                QListWidgetItem *item = new QListWidgetItem();
                ui->listWidget->insertItem(0, item);
                ui->listWidget->setItemWidget(item,item1);
                item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                item1->setData(userData.toVariantMap(), text);
            }
        }
    }
}
