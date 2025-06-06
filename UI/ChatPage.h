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
    enum Edge { None = 0, Top = 1, Bottom = 2, Left = 4, Right = 8 };
    Q_DECLARE_FLAGS(Edges, Edge)  // 这行是关键
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
    void c2c_msgNumber(int numbers);
    void msg_uidNumbers(QString uid, int numbers);
    void ChatC2C(QVariantMap data);

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

private:
    Edges m_dragEdge = None;  // 使用 Edges 类型替代 Edge
    QPoint m_dragStartPos;
    QRect m_originalGeometry;

    Edges getEdgeAt(const QPoint &pos);

private:
    Ui::ChatPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    ChatPageC2C *m_chatPage = nullptr;
    QVector<ChatPageLeftItem*> m_chatList;
    QString m_curID;
};

#endif // CHATPAGE_H
