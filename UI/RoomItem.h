#ifndef ROOMITEM_H
#define ROOMITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class RoomItem;
}

class RoomItem : public QDialog
{
    Q_OBJECT

public:
    explicit RoomItem(QWidget *parent = nullptr);
    ~RoomItem();

    void setData(QVariantMap roomInfo);
signals:
    void enterTheRoom(QVariantMap);

private slots:
    void on_imageLab_clicked();

private:
    Ui::RoomItem *ui;
    QVariantMap m_data;
};

#endif // ROOMITEM_H
