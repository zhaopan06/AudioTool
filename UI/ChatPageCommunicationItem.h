#ifndef CHATPAGECOMMUNICATIONITEM_H
#define CHATPAGECOMMUNICATIONITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ChatPageCommunicationItem;
}

class ChatPageCommunicationItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageCommunicationItem(QWidget *parent = nullptr);
    ~ChatPageCommunicationItem();
    void setData(QVariantMap data);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

signals:
    void ChatC2C(QVariantMap data);
private:
    Ui::ChatPageCommunicationItem *ui;
    QVariantMap m_data;
};

#endif // CHATPAGECOMMUNICATIONITEM_H
