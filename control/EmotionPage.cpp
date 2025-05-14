#include "EmotionPage.h"
#include "EmotionItem.h"
#include "qevent.h"
#include "ui_EmotionPage.h"
#include "qjsondocument.h"
#include <QTableWidgetItem>
#include <QMovie>

QVariant readJsonFile(const QString &filePath)
{

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开文件:" << filePath;
        return false;
    }

    // 2. 读取全部内容
    QByteArray jsonData = file.readAll();
    file.close();

    // 3. 解析JSON
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "JSON解析错误:" << parseError.errorString()
            << "at offset:" << parseError.offset;
        return false;
    }

    return  doc.toVariant();
}

EmotionPage::EmotionPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmotionPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

EmotionPage::~EmotionPage()
{
    delete ui;
}

void EmotionPage::initChatEmotion()
{
    QVariant data = readJsonFile("images/emotion/emotionJson.json");
    QVariantList list =  data.toList();
    for (int i = 0; i < list.size(); i++)
    {
        int row = i / 5;
        int col = i % 5;

        EmotionItem *item = new EmotionItem;
        item->setFixedSize(91,83);
        connect(item, SIGNAL(clicked(QVariantMap)), this, SIGNAL(emotionClicked(QVariantMap)));
        item->setData(list.at(i).toMap());
        ui->gridLayout->addWidget(item,row, col);
    }
}
