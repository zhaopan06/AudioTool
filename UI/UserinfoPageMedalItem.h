#ifndef USERINFOPAGEMEDALITEM_H
#define USERINFOPAGEMEDALITEM_H

#include <QDialog>

namespace Ui {
class UserinfoPageMedalItem;
}

class UserinfoPageMedalItem : public QDialog
{
    Q_OBJECT

public:
    explicit UserinfoPageMedalItem(QWidget *parent = nullptr);
    ~UserinfoPageMedalItem();

    void setData(QVariantMap data);
private:
    Ui::UserinfoPageMedalItem *ui;
};

#endif // USERINFOPAGEMEDALITEM_H
