#ifndef CHATTEXTMYITEM_H
#define CHATTEXTMYITEM_H

#include <QDialog>

namespace Ui {
class ChatTextMyItem;
}

class ChatTextMyItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatTextMyItem(QWidget *parent = nullptr);
    ~ChatTextMyItem();

    void setData(QString path, QString msg);

private:
    Ui::ChatTextMyItem *ui;
};

#endif // CHATTEXTMYITEM_H
