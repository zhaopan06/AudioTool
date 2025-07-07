#ifndef PROMOTEBUSINEPAGEITEM_H
#define PROMOTEBUSINEPAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class PromoteBusinePageItem;
}

class PromoteBusinePageItem : public QDialog
{
    Q_OBJECT

public:
    explicit PromoteBusinePageItem(QWidget *parent = nullptr);
    ~PromoteBusinePageItem();

    void setData(QVariantMap data);

signals:
    void showRoomId(QString);
private slots:
    void on_photo_clicked();

private:
    Ui::PromoteBusinePageItem *ui;
    QVariantMap m_data;
};

#endif // PROMOTEBUSINEPAGEITEM_H
