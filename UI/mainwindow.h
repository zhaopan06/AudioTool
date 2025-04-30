#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "agorartcengineinterface.h"
#include <QMainWindow>
#include "TimInterface.h"
#include "EmotionWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUserUI();

private slots:
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void audioVolumeIndication(int uid,int value);

    void on_enterRoom_clicked();

    void on_createRoom_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void loginIm(int code, QString msg);

    void on_sendBtn_clicked();

    void on_emoBtn_clicked();

    void emotionClicked(QString path);
    void on_closeBtn_clicked();

    void on_minBtn_clicked();

    void on_copyBtn_clicked();

private:
    Ui::MainWindow *ui;
    AgoraRtcEngineInterface *m_agoraFace = nullptr;
    TimInterface *m_timInterface = nullptr;

    QMenu *m_men = nullptr;
    EmotionWidget *m_emotionWidget = nullptr;
};
#endif // MAINWINDOW_H
