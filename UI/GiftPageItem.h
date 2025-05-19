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

protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *event);
private:
    Ui::GiftPageItem *ui;
    QVariantMap m_data;
    QString m_path;
};

#endif // GIFTPAGEITEM_H
