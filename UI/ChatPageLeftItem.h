#ifndef CHATPAGELEFTITEM_H
#define CHATPAGELEFTITEM_H

#include <QDialog>

namespace Ui {
class ChatPageLeftItem;
}

class ChatPageLeftItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageLeftItem(QWidget *parent = nullptr);
    ~ChatPageLeftItem();

private:
    Ui::ChatPageLeftItem *ui;
};

#endif // CHATPAGELEFTITEM_H
