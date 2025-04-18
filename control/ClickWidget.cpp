#include "ClickWidget.h"
#include <QMouseEvent>
ClickWidget::ClickWidget(QWidget *parent) : QWidget(parent)
{
}


void ClickWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if ((Qt::LeftButton == ev->button()) && (rect().contains(ev->pos())))
    {
        emit clicked();
    }
}
