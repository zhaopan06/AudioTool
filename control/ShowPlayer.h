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
        // 创建媒体播放器和视频窗口
        player = new QMediaPlayer(this);
        videoWidget = new QVideoWidget(this);

        // 设置视频窗口为无边框、透明且不在任务栏显示
        setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
        videoWidget->setAttribute(Qt::WA_TranslucentBackground);

        // 设置为中央部件
        setCentralWidget(videoWidget);
        player->setVideoOutput(videoWidget);

        // 设置窗口属性
        setWindowTitle("透明视频播放器");

        // 连接信号和槽
        connect(player, &QMediaPlayer::mediaStatusChanged, this, &VideoPlayerWindow::handleMediaStatus);
        connect(player, &QMediaPlayer::stateChanged, this, &VideoPlayerWindow::handleStateChanged);

        resize(500,500);
        show();
    }

    // 设置视频URL并开始播放
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
                show(); // 加载完成后显示窗口
            }
        }
    }

    void handleStateChanged(QMediaPlayer::State state) {
        if (state == QMediaPlayer::StoppedState) {
            // 视频播放结束后关闭窗口并释放资源
            close();
            deleteLater();
        }
    }

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};
#endif // SHOWPLAYER_H
