#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "agorartcengineinterface.h"
#include <QMainWindow>

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

private slots:
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void audioVolumeIndication(int uid,int value);

    void on_enterRoom_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AgoraRtcEngineInterface *m_agoraFace = nullptr;
};
#endif // MAINWINDOW_H
