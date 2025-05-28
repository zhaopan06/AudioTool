#ifndef CHATPAGEC2C_H
#define CHATPAGEC2C_H

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

private:
    bool eventFilter(QObject *obj, QEvent *event);
    void handleImagePaste();
private slots:
    void on_textEdit_textChanged();

    void on_sendBtn_clicked();

    void on_imageBtn_clicked();

private:
    Ui::ChatPageC2C *ui;
    QString m_message_conv_id;
};

#endif // CHATPAGEC2C_H
