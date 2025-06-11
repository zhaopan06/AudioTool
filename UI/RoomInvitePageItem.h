#ifndef ROOMINVITEPAGEITEM_H
#define ROOMINVITEPAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class RoomInvitePageItem;
}

class RoomInvitePageItem : public QDialog
{
    Q_OBJECT

public:
    explicit RoomInvitePageItem(QWidget *parent = nullptr);
    ~RoomInvitePageItem();
    void setData(QVariantMap data);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::RoomInvitePageItem *ui;
    QVariantMap m_data;
};

#endif // ROOMINVITEPAGEITEM_H
