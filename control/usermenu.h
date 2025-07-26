#ifndef USERMENU_H
#define USERMENU_H

#include <QDialog>

namespace Ui {
class UserMenu;
}

class UserMenu : public QDialog
{
    Q_OBJECT

public:
    explicit UserMenu(QWidget *parent = nullptr);
    ~UserMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void showMyselfData();

private:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::UserMenu *ui;
};

#endif // USERMENU_H
