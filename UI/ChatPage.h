#ifndef CHATPAGE_H
#define CHATPAGE_H

#include "ChatPageC2C.h"
#include <QDialog>
#include <QVariantMap>
#include "Base/IMSDK/TimInterface.h"

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
private slots:
    void on_communicationBtn_clicked();

    void on_msgPageBtn_clicked();

    void on_closeBtn_clicked();

    void initChatHisMsg(QString uid);
private:
    Ui::ChatPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    ChatPageC2C *m_chatPage = nullptr;
};

#endif // CHATPAGE_H
