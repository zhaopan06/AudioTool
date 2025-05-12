#ifndef GIFTITEM_H
#define GIFTITEM_H

#include <QDialog>

namespace Ui {
class GIftItem;
}

class GIftItem : public QDialog
{
    Q_OBJECT

public:
    explicit GIftItem(QWidget *parent = nullptr);
    ~GIftItem();

    void setData(QVariantMap fromUser, QVariantMap gift, QVariantMap toUser);
private:
    Ui::GIftItem *ui;
};

#endif // GIFTITEM_H
