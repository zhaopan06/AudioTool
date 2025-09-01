#include "SetTingMenu.h"
#include "qtimer.h"
#include "ui_SetTingMenu.h"
#include <QMouseEvent>
#include <QDebug>

SetTingMenu::SetTingMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetTingMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Tool);
    qApp->installEventFilter(this);
}

SetTingMenu::~SetTingMenu()
{
    qApp->installEventFilter(this);
    delete ui;
}

bool SetTingMenu::eventFilter(QObject *obj, QEvent *event)
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

void SetTingMenu::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    close();
}

//刷新页面
void SetTingMenu::on_pushButton_clicked()
{
    emit updateRoomData();
    close();
}
//帮助中心
void SetTingMenu::on_pushButton_3_clicked()
{
    close();
}

void SetTingMenu::on_pushButton_4_clicked()
{
    close();
}

void SetTingMenu::on_pushButton_2_clicked()
{
    emit setTing();
    close();
}

void SetTingMenu::on_pushButton_5_clicked()
{
    emit aboutPage();
    close();
}

