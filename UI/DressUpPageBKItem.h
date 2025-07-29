#ifndef DRESSUPPAGEBKITEM_H
#define DRESSUPPAGEBKITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class DressUpPageBKItem;
}

class DressUpPageBKItem : public QDialog
{
    Q_OBJECT

public:
    explicit DressUpPageBKItem(QWidget *parent = nullptr);
    ~DressUpPageBKItem();
    void setData(QVariantMap data);
    void setclick(bool click);

protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *event);
private slots:
    void on_image_2_clicked();

signals:
    void item_click(QVariantMap);
private:
    Ui::DressUpPageBKItem *ui;
    QVariantMap m_data;
    QString m_path;
};

#endif // DRESSUPPAGEBKITEM_H
