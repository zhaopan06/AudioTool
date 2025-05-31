#ifndef CHATPAGE_H
#define CHATPAGE_H

#include "ChatPageC2C.h"
#include <QDialog>
#include <QVariantMap>
#include "Base/IMSDK/TimInterface.h"
#include "ChatPageLeftItem.h"

namespace Ui {
class ChatPage;
}

class ChatPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget *parent = nullptr);
    ~ChatPage();
    void init(QVariant data);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
public slots:
    void c2c_msg_text(QVariantMap data, QString msg);
    void c2c_initTimList(QVariantList list);
    void c2c_initTimMsgList(QVariantList list);
    void c2c_msg_image(QVariantMap data, QString path, QString bigPath);
private slots:
    void on_communicationBtn_clicked();

    void on_msgPageBtn_clicked();

    void on_closeBtn_clicked();

    void initChatHisMsg(QString uid);
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void ChatC2C(QVariantMap data);

    void updateLeftText(QString text, QString uid);
private:
    Ui::ChatPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    ChatPageC2C *m_chatPage = nullptr;
    QVector<ChatPageLeftItem*> m_chatList;
    QString m_curID;
};

#endif // CHATPAGE_H
