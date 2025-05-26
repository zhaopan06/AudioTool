#ifndef CHATPAGEC2C_H
#define CHATPAGEC2C_H

#include <QDialog>

namespace Ui {
class ChatPageC2C;
}

class ChatPageC2C : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageC2C(QWidget *parent = nullptr);
    ~ChatPageC2C();

private:
    Ui::ChatPageC2C *ui;
};

#endif // CHATPAGEC2C_H
