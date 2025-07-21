#include "ToastPage.h"
#include "ui_ToastPage.h"
#include <QHBoxLayout>
#include <QTimer>

ToastPage::ToastPage(QWidget *parent)
    : QDialog{parent},
    ui(new Ui::ToastPage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);


    animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
}

void ToastPage::showToast(QWidget *parent, const QString &message, int duration)
{
    ToastPage *toast = new ToastPage(parent);
    toast->setText(message);
    toast->adjustSize();

    // 居中显示
    QPoint center = parent->geometry().center() - toast->rect().center();
    toast->move(center);

    toast->show();
    toast->animation->start();

    QTimer::singleShot(duration, [toast]() {
        QPropertyAnimation *fadeOut = new QPropertyAnimation(toast, "windowOpacity");
        fadeOut->setDuration(300);
        fadeOut->setStartValue(1);
        fadeOut->setEndValue(0);
        fadeOut->start();
        connect(fadeOut, &QPropertyAnimation::finished, toast, &ToastPage::deleteLater);
    });
}

void ToastPage::setText(QString text)
{
    ui->label->setText(text);
}
