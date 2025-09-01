#include "usermenu.h"
#include "qtimer.h"
#include "ui_usermenu.h"
#include <windows.h>
#include <QDebug>
#include <QMouseEvent>

UserMenu::UserMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Tool);
    qApp->installEventFilter(this);
}

UserMenu::~UserMenu()
{
    qApp->removeEventFilter(this);
    delete ui;
}

bool UserMenu::eventFilter(QObject *obj, QEvent *event)
{
    QWidget *widget = qobject_cast<QWidget*>(obj);
    if (widget && (widget == this || this->isAncestorOf(widget)))
    {
        return QObject::eventFilter(obj, event); // 是自己的事件，不处理
    }

    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!this->geometry().contains(mouseEvent->globalPos()))
        {
            close();
            return true;
        }
    }

    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!this->geometry().contains(mouseEvent->globalPos()))
        {
            if(this->isVisible())
            {
                close();
            }
            return true;
        }
    }
    if (event->type() == QEvent::FocusOut)
    {
        QTimer::singleShot(100, this, [this]() {

            if (this->isVisible() && !this->hasFocus())
            {
                QWidget *activeWindow = QApplication::activeWindow();
                if (activeWindow && activeWindow != this)
                {
                    close();
                }
            }
        });
    }
    return QObject::eventFilter(obj, event);
}

void UserMenu::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    close();
}

void UserMenu::on_pushButton_clicked()
{
    emit showMyselfData();
    close();
}

void UserMenu::on_pushButton_2_clicked()
{
    emit reLogin();
}

