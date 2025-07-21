#ifndef TOASTPAGE_H
#define TOASTPAGE_H

#include <QDialog>
#include <QPropertyAnimation>

namespace Ui {
class ToastPage;
}


class ToastPage : public QDialog
{
    Q_OBJECT
public:
    explicit ToastPage(QWidget *parent = nullptr);
    static void showToast(QWidget *parent, const QString &message, int duration = 2000);

    void setText(QString text);
signals:

private:
    Ui::ToastPage *ui;
    QPropertyAnimation *animation;

};

#endif // TOASTPAGE_H
