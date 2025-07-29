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
    else if(m_radius > 0 && false == m_isMove)
    {
        QPainterPath path;
        path.addRoundedRect(0, 0, width(), height(),m_radius,m_radius);
        painter.setClipPath(path);

        QSize widgetSize = size();
        QSize pixmapSize = pixmap()->size();
        QSize scaledSize = pixmapSize.scaled(widgetSize, Qt::KeepAspectRatioByExpanding);
        int x = (widgetSize.width() - scaledSize.width()) / 2;
        int y = (widgetSize.height() - scaledSize.height()) / 2;

        painter.drawPixmap(QRect(x, y, scaledSize.width(), scaledSize.height()),
                           *pixmap(),
                           QRect(0, 0, pixmapSize.width(), pixmapSize.height()));
    }
    else if(m_radius > 0 &&  m_isMove)
    {
        QPainterPath path;
        path.addRoundedRect(0, 0, width(), height(),m_radius,m_radius);
        painter.setClipPath(path);
        int x = (width() - pixmap()->width()) / 2;
        int y = (height() - pixmap()->height()) / 2;
        painter.drawPixmap(x, y, pixmap()->width(), pixmap()->height(), *pixmap());
    }
    else
        QLabel::paintEvent(e);
}
void click_label::enterEvent(QEvent *event)
{

}

void click_label::leaveEvent(QEvent *event)
{

}
