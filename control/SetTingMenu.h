#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QDialog>

namespace Ui {
class SetTingMenu;
}

class SetTingMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SetTingMenu(QWidget *parent = nullptr);
    ~SetTingMenu();

signals:
    void updateRoomData();
    void setTing();
    void aboutPage();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    bool eventFilter(QObject *obj, QEvent *event);
    void leaveEvent(QEvent *event);
private:
    Ui::SetTingMenu *ui;
};

#endif // SETTINGMENU_H
