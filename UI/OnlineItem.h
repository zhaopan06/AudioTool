#ifndef ONLINEITEM_H
#define ONLINEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class OnlineItem;
}

class OnlineItem : public QDialog
{
    Q_OBJECT

public:
    explicit OnlineItem(QWidget *parent = nullptr);
    ~OnlineItem();
    void  setData(QVariantMap data, QString id);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::OnlineItem *ui;
    QVariantMap m_data;    
};

#endif // ONLINEITEM_H
