#ifndef HOTPUSHHISTORYPAGEITEM_H
#define HOTPUSHHISTORYPAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class HotPushHistoryPageItem;
}

class HotPushHistoryPageItem : public QDialog
{
    Q_OBJECT

public:
    explicit HotPushHistoryPageItem(QWidget *parent = nullptr);
    ~HotPushHistoryPageItem();

    void setData(QVariantMap data);
private:
    Ui::HotPushHistoryPageItem *ui;
    QVariantMap m_data;
};

#endif // HOTPUSHHISTORYPAGEITEM_H
