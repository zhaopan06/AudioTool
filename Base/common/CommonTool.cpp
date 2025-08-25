#include "CommonTool.h"
#include <QCoreApplication>
#include <QProcess>
#include <QMediaPlayer>
#include <QDebug>

void rebootExe()
{
    QString program = QCoreApplication::applicationFilePath();
    QStringList arguments = QCoreApplication::arguments();
    QProcess::startDetached(program, arguments);
    QCoreApplication::exit(0);
}

void playMp3Async()
{
    static int number = 0;
    if(number > 5)
    {
        return;
    }
    number ++;
    QMediaPlayer *player = new QMediaPlayer;
    QString exeDir = QCoreApplication::applicationDirPath();
    player->setMedia(QUrl::fromLocalFile(exeDir + "/images/audio/NewMessage.mp3"));
    player->setVolume(80);
    QObject::connect(player, &QMediaPlayer::stateChanged, [player](QMediaPlayer::State state) {
        if (state == QMediaPlayer::StoppedState)
        {
            number--;
            player->deleteLater();
        }
    });

    QObject::connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
                     [&](QMediaPlayer::Error error)
                     {
                         number--;
                         player->deleteLater();
                     });

    player->play();
}
