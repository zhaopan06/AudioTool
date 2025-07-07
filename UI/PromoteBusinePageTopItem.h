#ifndef PROMOTEBUSINEPAGETOPITEM_H
#define PROMOTEBUSINEPAGETOPITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class PromoteBusinePageTopItem;
}

class PromoteBusinePageTopItem : public QDialog
{
    Q_OBJECT

public:
    explicit PromoteBusinePageTopItem(QWidget *parent = nullptr);
    ~PromoteBusinePageTopItem();

    void setData(QVariantMap data);
 protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
 signals:
    void ChatC2C(QString);
private:
    Ui::PromoteBusinePageTopItem *ui;
    QVariantMap m_data;
};

#endif // PROMOTEBUSINEPAGETOPITEM_H
