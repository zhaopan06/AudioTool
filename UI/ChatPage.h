#ifndef CHATPAGE_H
#define CHATPAGE_H

#include "ChatPageC2C.h"
#include <QDialog>
#include <QVariantMap>
#include "ChatPageLeftItem.h"

namespace Ui {
class ChatPage;
}

class ChatPage : public QDialog
{
    Q_OBJECT
public:
    static ChatPage* getInstance();
    static void destroyInstance();
private:
    explicit ChatPage(QWidget *parent = nullptr);
public:
    ~ChatPage();
    void init(QVariant data);
protected:
    void mouseMoveEvent(QMouseEvent* event)override;
    void mousePressEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void showEvent(QShowEvent *event)override;
    bool eventFilter(QObject *obj, QEvent *event)override;
public slots:
    void c2c_msg_text(QVariantMap data, QString msg);
    void c2c_initTimList(QVariantList list);
    void c2c_initTimMsgList(QVariantList list);
    void c2c_msg_image(QVariantMap data, QString path, QString bigPath);
    void c2c_msgNumber(int numbers);
    void msg_uidNumbers(QString uid, int numbers);
    void ChatC2C(QVariantMap data);
    void c2c_msg_inviteFriends(QVariantMap data);

private slots:
    void on_communicationBtn_clicked();

    void on_msgPageBtn_clicked();

    void on_closeBtn_clicked();

    void initChatHisMsg(QString uid);
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    bool updateLeftText(QString text, QString uid);
    void on_searchBtn_clicked();

    void on_minBtn_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::ChatPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    ChatPageC2C *m_chatPage = nullptr;
    QVector<ChatPageLeftItem*> m_chatList;
    QString m_curID;

    static ChatPage* instance; // 静态实例指针
};

#endif // CHATPAGE_H
