#ifndef CHATTEXTITEM_H
#define CHATTEXTITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ChatTextItem;
}

class ChatTextItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatTextItem(QWidget *parent = nullptr);
    ~ChatTextItem();

    void setData(QVariantMap data, QString msg, int type);

    void setImage(QVariantMap data, QString msg);

private:
    Ui::ChatTextItem *ui;
    QVariantMap m_data;
};

#endif // CHATTEXTITEM_H
