#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Base/IMSDK/TimInterface.h"
#include "GiftPage.h"
#include "MicInfoItem.h"
#include "agorartcengineinterface.h"
#include <QMainWindow>
#include "EmotionPage.h"
#include "AudioValuePage.h"
#include "ChatPage.h"
#include <QMouseEvent>
#include <QGraphicsBlurEffect>
#include <QCursor>
//#include "VideoPlayer.h"

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

    void chatC2C(QVariantMap data);
    void initMax(bool isMax);
private:
    void initUserUI();
    void initTim();
    void initAgora();

    void initRoomInfoUI();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    enum Edge {
        None = 0,
        Top = 1, Bottom = 2, Left = 4, Right = 8,
        TopLeft = Top | Left, TopRight = Top | Right,
        BottomLeft = Bottom | Left, BottomRight = Bottom | Right
    };

    Edge getEdgeAt(const QPoint &pos);
    void updateCursor(Edge edge);

    bool m_isDragging = false;
    QPoint m_dragStartPos;
    Edge m_dragEdge;
    QGraphicsBlurEffect *m_blurEffect;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void audioVolumeIndication(int uid,int value);
    void reconnect();    

    void loginIm(int code, QString msg);

    void msg_numbers(int numbers);
    void msg_liveClose();
    void msg_notice(QVariantMap user, QString msg);
    void msg_txt(QVariantMap user, QString msg, int type);
    void msg_image(QVariantMap user, QString path, QString largePath);
    void msg_gift(QVariantMap form, QVariantMap gift, QVariantMap to);
    void msg_micInfo(QVariantList list);
    void msg_emotion(QVariantMap user, QString path, int type);
    void msg_vip(QVariantMap user, QString url);
    void msg_multipleAuthoriation(QVariantMap data);

    void msg_playerUrl(QString url);
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
    void msg_uninit();

    void on_downMicBtn_clicked();

    void upMicToUserID(QString roomID, QString userID);
    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_msgEdit_sendImage(const QString &localPath);

    void on_msgEdit_textChanged(const QString &arg1);

    void on_closeLiveBtn_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_20_clicked();

    void on_maxBtn_clicked();

    void on_max_c_btn_clicked();

    void on_pushButton_9_clicked();

    void on_userName_clicked();

private:
    Ui::MainWindow *ui;
    AgoraRtcEngineInterface *m_agoraFace = nullptr;
    TimInterface *m_timInterface = nullptr;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);

    EmotionPage *m_emotionPage= nullptr;

    GiftPage *m_giftPage = nullptr;    
    QVector<MicInfoItem*> m_micList;
    AudioValuePage *m_valuePage = nullptr;
    AudioValuePage *m_soundValuePage = nullptr;
    ChatPage *m_chatPage = nullptr;
    QVariantMap m_roomInfo;
    //VideoPlayer *m_player;
};
#endif // MAINWINDOW_H
