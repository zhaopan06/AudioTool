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
#include "qscrollbar.h"
#include "qtimer.h"
#include "ui_ChatPageC2C.h"
#include "TimInterface.h"
#include "QFileDialog.h"
#include "HttpInterFace.h"

ChatPageC2C::ChatPageC2C(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatPageC2C)
{
    ui->setupUi(this);
    ui->textEdit->setAcceptRichText(true);
    ui->textEdit->installEventFilter(this);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    ui->listWidget->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    ui->listWidget->verticalScrollBar()->setSingleStep(20);
    ui->textEdit->verticalScrollBar()->setSingleStep(10);
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
                    item1->setImage(path, largePath);

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
                    item1->setImage(userData, path, largePath);

                    QListWidgetItem *item = new QListWidgetItem();
                    ui->listWidget->insertItem(0, item);
                    ui->listWidget->setItemWidget(item,item1);
                    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));                    
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

    HttpInterFace::getInstance()->queryMessageListUserInfo(conv_id.remove("user"), [&](const QVariant &data) {

        if(data.toMap()["data"].toList().size() > 0)
        {
            QVariantMap dataMap = data.toMap()["data"].toList().at(0).toMap();
            ui->name->setText(dataMap["userName"].toString());
            int isOnline = dataMap["isOnline"].toInt();
            int isLiving = dataMap["isLiving"].toInt();
            if(0 == isOnline)
            {
                ui->pushButton_2->setText(QStringLiteral("离线"));
            }
            else
            {
                if(1 == isLiving || 2 == isLiving)
                {
                    QString roomName = dataMap["roomName"].toString();
                    ui->pushButton_2->setText(QStringLiteral("在房间：") + roomName);
                }
                else
                {
                    ui->pushButton_2->setText(QStringLiteral("在线"));
                }
            }


            int isAttention = dataMap["isAttention"].toInt();
            if(isAttention > 0)
            {
                m_isFollow = true;
                ui->Attention->setText(QStringLiteral("取消关注"));
            }
            else
            {
                m_isFollow = false;
                ui->Attention->setText(QStringLiteral("关注"));
            }

        }
    });
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

void ChatPageC2C::addImageMsg(QVariantMap data, QString path, QString largePath)
{
    ChatPageC2CTextItem *item1 = new ChatPageC2CTextItem;
    item1->setImage(data, path, largePath);

    QListWidgetItem *item = new QListWidgetItem();
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,item1);
    item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    ui->listWidget->scrollToBottom();
}

void ChatPageC2C::on_textEdit_textChanged()
{
    if(ui->textEdit->toPlainText().size() > 0)
    {
        ui->sendBtn->setDisabled(false);
    }
    else
    {
        ui->sendBtn->setDisabled(true);
    }

    QTimer::singleShot(10, [&]() {
        ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum()
                                                    );
    });
}

void ChatPageC2C::on_sendBtn_clicked()
{
    if(ui->textEdit->getImageList().size() > 0)
    {
        foreach (QString var, ui->textEdit->getImageList())
        {
            TimInterface::getInstance()->SendC2CImage(var, m_message_conv_id);

            ChatPageC2CMyItem *item1 = new ChatPageC2CMyItem;
            item1->setImage(var, var);
            QListWidgetItem *item = new QListWidgetItem();
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,item1);
            item->setSizeHint(QSize(ui->listWidget->contentsRect().width(), item1->height()));
            ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
            ui->listWidget->scrollToBottom();
        }
        ui->textEdit->clearImageList();
    }

    QString text1 = ui->textEdit->toHtml();  
    QString html1 =  restoreEmojiTags(text1);
    ui->textEdit->setHtml(html1);

    text1 = ui->textEdit->toHtml();  
    QRegularExpression imgTagReg(R"(<img\b[^>]*/?>)");
    QString cleanedText = text1.remove(imgTagReg);
    ui->textEdit->setHtml(cleanedText);   
    QString text = ui->textEdit->toPlainText();
    if(text.isEmpty())
        return;
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
            return true;
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
        QString tempPath = ui->textEdit->saveImageToTemp(mimeData->imageData());
        ui->textEdit->insertImage(tempPath);
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
                    ui->textEdit->insertImage(url.toLocalFile());
                }
            }
        }
    }
    else
    {
        ui->textEdit->paste();
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
    ui->textEdit->insertImage(localPath);
    ui->textEdit->setFocus();
}


void ChatPageC2C::on_emoBtn_clicked()
{
    if(nullptr == m_emotionPage)
    {
        m_emotionPage = new EmotionPage(this);
        m_emotionPage->initChatEmotion();
        connect(m_emotionPage, SIGNAL(emotionClicked(QVariantMap)), this, SLOT(emotionClicked(QVariantMap)));
    }

    QPoint point;
    point.setX(ui->emoBtn->mapToGlobal(QPoint(0, 0)).rx() - 16);
    point.setY(ui->emoBtn->mapToGlobal(QPoint(0, 0)).ry() - m_emotionPage->height() - 10);
    m_emotionPage->move(point);
    m_emotionPage->show();
}

void ChatPageC2C::emotionClicked(QVariantMap data)
{
    m_emotionPage->hide();
    QString path = data["path"].toString();
    QTextCursor insertcursor = ui->textEdit->textCursor();
    if(!insertcursor.isNull())
    {
        QString html = QString("<img src=\"%1\" width=16 height=16 style='width:16; height:16; vertical-align:middle; display:inline-block;'/>").arg(path);

        insertcursor.insertHtml(html);
    }
    ui->textEdit->setFocus();
}


void ChatPageC2C::on_Attention_clicked()
{
    int isFollow = 0;
    if(!m_isFollow)
    {
        isFollow = 1;
    }
    QVariantMap data = HttpInterFace::getInstance()->followUser(m_message_conv_id.remove("user"), isFollow);

    if(0 == isFollow)
    {
        ui->Attention->setText(QStringLiteral("关注"));
    }
    if(1 == isFollow)
    {
        ui->Attention->setText(QStringLiteral("取消关注"));
    }
    m_isFollow = !m_isFollow;
}

