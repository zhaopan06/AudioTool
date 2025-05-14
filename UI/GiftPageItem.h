#ifndef GIFTPAGEITEM_H
#define GIFTPAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class GiftPageItem;
}

class GiftPageItem : public QDialog
{
    Q_OBJECT

public:
    explicit GiftPageItem(QWidget *parent = nullptr);
    ~GiftPageItem();

    void setData(QVariantMap data);

private:
    Ui::GiftPageItem *ui;
    QVariantMap m_data;
};

#endif // GIFTPAGEITEM_H
