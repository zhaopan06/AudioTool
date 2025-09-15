#ifndef SHOWPLAYER_H
#define SHOWPLAYER_H

#include <QApplication>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>
#include <QMediaMetaData>

class VideoPlayerWindow : public QMainWindow {
    Q_OBJECT

public:
    VideoPlayerWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        player = new QMediaPlayer(this);
        videoWidget = new QVideoWidget(this);

        setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
        videoWidget->setAttribute(Qt::WA_TranslucentBackground);

        setCentralWidget(videoWidget);
        player->setVideoOutput(videoWidget);

        setWindowTitle("透明视频播放器");

        connect(player, &QMediaPlayer::mediaStatusChanged, this, &VideoPlayerWindow::handleMediaStatus);
        connect(player, &QMediaPlayer::stateChanged, this, &VideoPlayerWindow::handleStateChanged);

        resize(500,500);
        show();
    }

    void setUrl(const QString &url)
    {
        player->setMedia(QUrl(url));
        player->play();
    }

private slots:
    void handleMediaStatus(QMediaPlayer::MediaStatus status)
    {
        if (status == QMediaPlayer::LoadedMedia)
        {
            QSize videoSize = player->metaData(QMediaMetaData::Resolution).toSize();
            if (!videoSize.isEmpty())
            {
                resize(videoSize);
                show();
            }
        }
    }

    void handleStateChanged(QMediaPlayer::State state) {
        if (state == QMediaPlayer::StoppedState) {

            close();
            deleteLater();
        }
    }

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};
#endif // SHOWPLAYER_H
