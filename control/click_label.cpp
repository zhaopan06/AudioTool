
#include "click_label.h"
#include <QPainterPath>
#include <QPainter>
void click_label::mouseReleaseEvent(QMouseEvent *)
{
    emit clicked();
}
void click_label::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    // ¿¹¾â³Ý
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(m_isRound)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QPainterPath path;
        int round = qMin(width(), height());
        path.addEllipse(0, 0, round, round);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, width(), height(), *pixmap());
    }
    else if(m_radius > 0)
    {
        QPainterPath path;

        path.addRoundedRect(0, 0, width(), height(),m_radius,m_radius);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, width(), height(), *pixmap());
    }else
        QLabel::paintEvent(e);
}
void click_label::enterEvent(QEvent *event)
{

}

void click_label::leaveEvent(QEvent *event)
{

}
