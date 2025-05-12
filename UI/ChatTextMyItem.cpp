#include "ChatTextMyItem.h"
#include "ui_ChatTextMyItem.h"
#include "HttpInterFace.h"

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
    HttpInterFace::getInstance()->downLoad(path, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });

    //设置文字
    QLabel *label = new QLabel();
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
        this->setFixedHeight(label->height() + 30);
    }
    else
    {
        label->adjustSize();
        ui->widget_2->setFixedWidth(label->width() + 30);
    }
}
