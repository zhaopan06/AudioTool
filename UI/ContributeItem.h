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

private:
    Ui::ContributeItem *ui;
};

#endif // CONTRIBUTEITEM_H
