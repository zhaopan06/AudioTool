#ifndef MANAGEMENTPAGEITEM_H
#define MANAGEMENTPAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ManagementPageItem;
}

class ManagementPageItem : public QDialog
{
    Q_OBJECT

public:
    explicit ManagementPageItem(QWidget *parent = nullptr);
    ~ManagementPageItem();

    void setData(QVariantMap data);
private slots:
    void on_pushButton_clicked();

signals:
    void removeOne(QVariantMap);
private:
    Ui::ManagementPageItem *ui;
    QVariantMap m_data;
};

#endif // MANAGEMENTPAGEITEM_H
