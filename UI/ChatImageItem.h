#ifndef CHATIMAGEITEM_H
#define CHATIMAGEITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ChatImageItem;
}

class ChatImageItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatImageItem(QWidget *parent = nullptr);
    ~ChatImageItem();

    void setData(QVariantMap data);
private:
    Ui::ChatImageItem *ui;
    QVariantMap m_data;
};

#endif // CHATIMAGEITEM_H
