#ifndef MSGBOX_H
#define MSGBOX_H

#include <QDialog>

namespace Ui {
class MsgBox;
}

class MsgBox : public QDialog
{
    Q_OBJECT

public:
    enum BTN_MODE {TIPDIALOG = 0, QUERYDIALOG = 1};    
    MsgBox(const QString &title, const QString msg, BTN_MODE mode, QWidget *parent = 0);
    ~MsgBox();
    static int showMsg(QWidget *parent, const QString &title, const QString &msg, BTN_MODE mode = TIPDIALOG);

    static int showMsgTop(QWidget *parent, const QString &title, const QString &msg, BTN_MODE mode = TIPDIALOG);

    void setTitle(const QString &title);
    void setMessage(const QString &msg);
private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();    

    void on_closeBtn_clicked();

private:
    Ui::MsgBox *ui;
};

#endif // MSGBOX_H
