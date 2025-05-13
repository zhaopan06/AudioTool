#include "ChatTextItem.h"
#include "ui_ChatTextItem.h"
#include "HttpInterFace.h"


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

    //设置文字
    QLabel *label = new QLabel();
    if(1 == type)
    {
        label->setStyleSheet("font-family: \"微软雅黑\";"
                             "font-size: 16px;"
                             "color: #FFFFFF;"
                             "text-align: left;");
    }
    else if(12 == type)
    {
        label->setStyleSheet("font-family: \"微软雅黑\";"
                             "font-size: 16px;"
                             "color: rgba(237, 82, 90, 1);"
                             "text-align: left;");
    }

    ui->textLayout->addWidget(label);
    QString labelText = msg;
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
        label->setFixedHeight(label->height() - 24);
        this->setFixedHeight(label->height() + 64);
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
