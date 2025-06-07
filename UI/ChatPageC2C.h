#ifndef CHATPAGEC2C_H
#define CHATPAGEC2C_H

#include "EmotionPage.h"
#include <QDialog>

namespace Ui {
class ChatPageC2C;
}

class ChatPageC2C : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageC2C(QWidget *parent = nullptr);
    ~ChatPageC2C();

    void init(QVariantList list);
    void setUid(QString conv_id);

    void addTextMsg(QVariantMap data, QString text);
    void addImageMsg(QVariantMap data, QString path, QString largePath);
    void addInviteFriends(QVariantMap data);
    QString getUid();
signals:
    void updateLeftText(QString,QString);
private:
    bool eventFilter(QObject *obj, QEvent *event);
    void handleImagePaste();
private slots:
    void on_textEdit_textChanged();

    void on_sendBtn_clicked();

    void on_imageBtn_clicked();

    void on_emoBtn_clicked();

    void emotionClicked(QVariantMap data);
    void on_Attention_clicked();

private:
    Ui::ChatPageC2C *ui;
    QString m_message_conv_id;
    EmotionPage *m_emotionPage= nullptr;
    bool m_isFollow = false;
};

#endif // CHATPAGEC2C_H
