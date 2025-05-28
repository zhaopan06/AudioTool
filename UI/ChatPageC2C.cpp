#include "ChatPageC2C.h"
#include "ChatPageC2CMyItem.h"
#include "ChatPageC2CTextItem.h"
#include "Global.h"
#include "HttpUserInfo.h"
#include "qclipboard.h"
#include "qevent.h"
#include "qfileinfo.h"
#include "qimagereader.h"
#include "qjsonobject.h"
#include "qmimedata.h"
#include "ui_ChatPageC2C.h"
#include "TimInterface.h"
#include "QFileDialog.h"

ChatPageC2C::ChatPageC2C(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2C)
{
    ui->setupUi(this);
    ui->textEdit->setAcceptRichText(true);
    ui->textEdit->installEventFilter(this);
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
        QVariantMap userData = data["message_sender_profile"].toMap();

        QVariantList elems = data["message_elem_array"].toList();
        foreach (auto var, elems)
        {
            uint32_t elem_type = var.toMap()["elem_type"].toInt();
            if(1 == elem_type)//图片
            {
                QString path = var.toMap()["image_elem_thumb_url"].toString();
                QString largePath = var.toMap()["image_elem_large_url"].toString();

                if(userData["user_profile_identifier"].toString() == "user" + HttpUserInfo::instance()->getUserID())
                {
                    ChatPageC2CMyItem *item1 = new ChatPageC2CMyItem;
                    QListWidgetItem *item = new QListWidgetItem();
                    ui->listWidget->insertItem(0, item);
                    ui->listWidget->setItemWidget(item,item1);
                    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                    item1->setImage(path, largePath);
                    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
                    ui->listWidget->scrollToBottom();
                }
                else
                {
                    ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
                    QListWidgetItem *item = new QListWidgetItem();
                    ui->listWidget->insertItem(0, item);
                    ui->listWidget->setItemWidget(item,item1);
                    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                    item1->setImage(userData, path, largePath);
                    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
                    ui->listWidget->scrollToBottom();
                }


            }
            if(0 == elem_type)
            {
                QString text = var.toMap()["text_elem_content"].toString();
                if(userData["user_profile_identifier"].toString() == "user" + HttpUserInfo::instance()->getUserID())
                {
                    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
                    QString photoUrl = data["user"].toMap()["photo"].toString();
                    ChatPageC2CMyItem *item1 = new ChatPageC2CMyItem;
                    item1->setData(photoUrl, text, ui->listWidget->width());

                    QListWidgetItem *item = new QListWidgetItem();
                    ui->listWidget->insertItem(0, item);
                    ui->listWidget->setItemWidget(item,item1);
                    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
                    ui->listWidget->scrollToBottom();
                }
                else
                {
                    ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
                    item1->setData(userData, text, ui->listWidget->width());

                    QListWidgetItem *item = new QListWidgetItem();
                    ui->listWidget->insertItem(0, item);
                    ui->listWidget->setItemWidget(item,item1);
                    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
                    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
                    ui->listWidget->scrollToBottom();
                }
            }
        }
    }
}

void ChatPageC2C::setUid(QString conv_id)
{
    m_message_conv_id = conv_id;
}

void ChatPageC2C::addTextMsg(QVariantMap data, QString text)
{
    ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
    item1->setData(data, text, ui->listWidget->width());

    QListWidgetItem *item = new QListWidgetItem();
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    ui->listWidget->scrollToBottom();
}

void ChatPageC2C::on_textEdit_textChanged()
{
    if(ui->textEdit->toPlainText().size() > 1)
    {
        ui->sendBtn->setDisabled(false);
    }
    else
    {
        ui->sendBtn->setDisabled(true);
    }
}

void ChatPageC2C::on_sendBtn_clicked()
{
    QString text = ui->textEdit->toPlainText();
    TimInterface::getInstance()->setC2CSendJson(IMType_Text, text, m_message_conv_id);
    ui->textEdit->clear();

    ChatPageC2CMyItem *item1 = new ChatPageC2CMyItem;
    QVariantMap data = HttpUserInfo::instance()->getLoginInfo();
    QString photoUrl = data["user"].toMap()["photo"].toString();
    item1->setData(photoUrl, text, ui->listWidget->width());

    QListWidgetItem *item = new QListWidgetItem();
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    ui->listWidget->scrollToBottom();
}

bool ChatPageC2C::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->matches(QKeySequence::Paste))
        {
            handleImagePaste();
            return true; // 拦截粘贴事件
        }
    }
    return QObject::eventFilter(obj, event);
}

void ChatPageC2C::handleImagePaste()
{
    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();

    if (mimeData->hasImage())
    {
        QImage image = qvariant_cast<QImage>(mimeData->imageData());
        ui->textEdit->textCursor().insertImage(image); // 插入图片
    }
    else if (mimeData->hasUrls())
    {
        QList<QUrl> urls = mimeData->urls();
        for (const QUrl &url : urls)
        {
            if (url.isLocalFile() && QImageReader::supportedImageFormats().contains(QFileInfo(url.toLocalFile()).suffix().toLower().toUtf8()))
            {
                QImage image(url.toLocalFile());
                if (!image.isNull())
                {
                    ui->textEdit->textCursor().insertImage(image);
                }
            }
        }
    }
    else
    {
        ui->textEdit->paste(); // 默认粘贴文本
    }
}

void ChatPageC2C::on_imageBtn_clicked()
{
    QString localPath = QFileDialog::getOpenFileName(0, QStringLiteral("选择图片"), "", QStringLiteral("jpg、png图片(*.jpg *.png)"));
    if (localPath.isEmpty())
    {
        return;
    }
    QImage pix(localPath);
    ui->textEdit->insertImage(pix);
}

