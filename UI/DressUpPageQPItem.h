#ifndef DRESSUPPAGEQPITEM_H
#define DRESSUPPAGEQPITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class DressUpPageQPItem;
}

class DressUpPageQPItem : public QDialog
{
    Q_OBJECT

public:
    explicit DressUpPageQPItem(QWidget *parent = nullptr);
    ~DressUpPageQPItem();
    void setData(QVariantMap data);

protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *event);
private:
    Ui::DressUpPageQPItem *ui;
    QVariantMap m_data;
    QString m_path;
};

#endif // DRESSUPPAGEQPITEM_H
