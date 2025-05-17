#ifndef CONTRIBUTEITEM_H
#define CONTRIBUTEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ContributeItem;
}

class ContributeItem : public QDialog
{
    Q_OBJECT

public:
    explicit ContributeItem(QWidget *parent = nullptr);
    ~ContributeItem();

    void setData(QVariantMap data);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::ContributeItem *ui;
    QVariantMap m_data;
};

#endif // CONTRIBUTEITEM_H
