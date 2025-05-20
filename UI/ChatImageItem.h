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

    void setData(QVariantMap data, QString imageUrl, QString bigImageUrl);
    void setGiftPath(QVariantMap data, QString imageUrl);
private slots:
    void on_image_clicked();

private:
    Ui::ChatImageItem *ui;
    QVariantMap m_data;
    QString m_path;
    QString m_bigImageUrl;
    bool m_isGift;
};

#endif // CHATIMAGEITEM_H
