#include "PlayerPage.h"
#include "ui_PlayerPage.h"
#include <QVideoWidget>

PlayerPage::PlayerPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerPage)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer;

    QVideoWidget *videoWidget = new QVideoWidget;
    m_player->setVideoOutput(videoWidget);
    ui->verticalLayout->addWidget(videoWidget);
}

PlayerPage::~PlayerPage()
{
    delete ui;
}

void PlayerPage::play(QString path)
{
    QString testPath = "https://testfile.linkfunapp.com/image/ser/svga/1738834894779985.svga";
    //m_player->setMedia(QUrl::fromLocalFile(path));
    m_player->setMedia(QUrl(testPath));
    m_player->play();
}
