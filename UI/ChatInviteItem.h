#ifndef CHATINVITEITEM_H
#define CHATINVITEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ChatInviteItem;
}

class ChatInviteItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatInviteItem(QWidget *parent = nullptr);
    ~ChatInviteItem();

    void setData(QVariantMap data);
private slots:
    void on_roomPhoto_clicked();

private:
    Ui::ChatInviteItem *ui;

    QVariantMap m_data;
};

#endif // CHATINVITEITEM_H
