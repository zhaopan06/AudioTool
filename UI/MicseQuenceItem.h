#ifndef MICSEQUENCEITEM_H
#define MICSEQUENCEITEM_H

#include <QDialog>
#include<QVariantMap>

namespace Ui {
class MicseQuenceItem;
}

class MicseQuenceItem : public QDialog
{
    Q_OBJECT

public:
    explicit MicseQuenceItem(QWidget *parent = nullptr);
    ~MicseQuenceItem();

    void setData(QVariantMap data);

private slots:
    void on_micBtn_clicked();

private:
    Ui::MicseQuenceItem *ui;
    QVariantMap m_data;
};

#endif // MICSEQUENCEITEM_H
