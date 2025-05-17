#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Base/IMSDK/TimInterface.h"
#include "GiftPage.h"
#include "MicInfoItem.h"
#include "agorartcengineinterface.h"
#include <QMainWindow>
#include "EmotionPage.h"

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

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void audioVolumeIndication(int uid,int value);

    void on_pushButton_2_clicked();

    void loginIm(int code, QString msg);

    void msg_notice(QVariantMap user, QString msg);
    void msg_txt(QVariantMap user, QString msg, int type);
    void msg_image(QVariantMap user, QString path);
    void msg_gift(QVariantMap form, QVariantMap gift, QVariantMap to);
    void msg_micInfo(QVariantList list);

    void on_sendBtn_clicked();

    void on_emoBtn_clicked();

    void emotionClicked(QVariantMap data);
    void on_closeBtn_clicked();

    void on_minBtn_clicked();

    void on_copyBtn_clicked();

    void on_updateBtn_clicked();

    void enterTheToom(QVariantMap data);

    void on_onlineBtn_clicked();

    void on_squareBtn_clicked();

    void on_contributeBtn_clicked();

    void on_day_btn_clicked();

    void on_week_btn_clicked();

    void on_m_btn_clicked();

    void on_allChatBtn_clicked();

    void on_roomChatBtn_clicked();

    void on_chatListBtn_clicked();

    void on_osBtn_clicked();

    void on_imageBtn_clicked();

    void on_autioMicBtn_clicked();

    void setEmoTionItem(QString path, int type);

    void setMyselfMicInfo(int status);
    void on_giftBtn_clicked();

    void updateMicList();

    void on_downMicBtn_clicked();

    void upMicToUserID(QString roomID, QString userID);
    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::MainWindow *ui;
    AgoraRtcEngineInterface *m_agoraFace = nullptr;
    TimInterface *m_timInterface = nullptr;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);

    EmotionPage *m_emotionPage= nullptr;

    GiftPage *m_giftPage = nullptr;
    bool m_isManager;//是否管理
    bool m_isHomeowner;//是否房主
    QVector<MicInfoItem*> m_micList;
};
#endif // MAINWINDOW_H
