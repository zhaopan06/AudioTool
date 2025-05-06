#include "EmotionWidget.h"
#include <QTableWidgetItem>
#include <QMovie>


EmotionWidget::EmotionWidget(QObject *parent)
    : QWidget(qobject_cast<QWidget *>(parent))
{
    ui.setupUi(this);
    ui.gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

EmotionWidget::~EmotionWidget()
{
}

void EmotionWidget::setLiveStyle()
{
    //ui.scrollArea->setStyleSheet("background:rgba(33,49,87,1);"
    //                             "border:none;");
}

void EmotionWidget::initChatEmotion()
{    
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setFixedSize(456,511);

    for (int i = 0; i < CHAT_EMOTION_COUNT; i++)
    {
        QString path = QString("images/emotion/vc_emoji_%1.png").arg(i);
        int row = i / 6;
        int col = i % 6;

        EmotionLabel* emotionIcon = new EmotionLabel(path);
        connect(emotionIcon, SIGNAL(clicked(QString)), this, SIGNAL(emotionClicked(QString)));
        emotionIcon->setMargin(4);
        emotionIcon->setStyleSheet("border:none;");
        emotionIcon->setFixedSize(55,54);
        emotionIcon->setScaledContents(true);
        emotionIcon->setPixmap(QPixmap(path));
        ui.gridLayout->addWidget(emotionIcon,row, col);
    }
}
