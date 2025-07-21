#ifndef HOTPUSHPAGEITEM_H
#define HOTPUSHPAGEITEM_H

#include <QDialog>
#include <QButtonGroup>
#include <QVariantMap>

namespace Ui {
class HotPushPageItem;
}

class HotPushPageItem : public QDialog
{
    Q_OBJECT

public:
    explicit HotPushPageItem(QWidget *parent = nullptr);
    ~HotPushPageItem();
    void setData(QVariantMap data, QButtonGroup *group);

signals:
    void clickData(QVariantMap);
protected:
    void mouseReleaseEvent(QMouseEvent*);
private:
    Ui::HotPushPageItem *ui;
    QVariantMap m_data;
};

#endif // HOTPUSHPAGEITEM_H
