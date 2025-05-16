#ifndef USERINFOPAGEGIFTITEM_H
#define USERINFOPAGEGIFTITEM_H

#include <QDialog>

namespace Ui {
class UserinfoPageGiftItem;
}

class UserinfoPageGiftItem : public QDialog
{
    Q_OBJECT

public:
    explicit UserinfoPageGiftItem(QWidget *parent = nullptr);
    ~UserinfoPageGiftItem();

    void setData(QVariantMap data);
private:
    Ui::UserinfoPageGiftItem *ui;
};

#endif // USERINFOPAGEGIFTITEM_H
