#ifndef NEWUSERITEM_H
#define NEWUSERITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class NewUserItem;
}

class NewUserItem : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserItem(QWidget *parent = nullptr);
    ~NewUserItem();

    void setData(QVariantMap data);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NewUserItem *ui;
    QVariantMap m_data;
    int m_isFollow = 0; //0没关注
};

#endif // NEWUSERITEM_H
