#ifndef CHATEMOTIONITEM_H
#define CHATEMOTIONITEM_H

#include <QDialog>

namespace Ui {
class ChatEmoTionItem;
}

class ChatEmoTionItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatEmoTionItem(QWidget *parent = nullptr);
    ~ChatEmoTionItem();

private:
    Ui::ChatEmoTionItem *ui;
};

#endif // CHATEMOTIONITEM_H
