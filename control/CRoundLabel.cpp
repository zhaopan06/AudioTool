#include "CRoundLabel.h"
#include "qdebug.h"
#include "qevent.h"
#include <QPainter>
#include <QPainterPath>
CRoundLabel::CRoundLabel(QWidget *parent):QLabel(parent)
{
    m_bTransLayer = false;
}
void CRoundLabel::paintEvent(QPaintEvent *e)
{
    if(NULL != pixmap())
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QPainterPath path;
        int round = qMin(width(), height());
        path.addEllipse(0, 0, round, round);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, width(), height(), *pixmap());
    }
    else
    {
       QLabel::paintEvent(e);
    }
}
void CRoundLabel::enterEvent(QEvent *event)
{
    m_bTransLayer = true;
    update();
}
void CRoundLabel::leaveEvent(QEvent *event)
{
    m_bTransLayer = false;
    update();
}
void CRoundLabel::mousePressEvent(QMouseEvent *ev)
{    
    if(ev->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    else if(ev->button() == Qt::RightButton)
    {
        qDebug() << "右键按下";
        emit rightClicked();
    }
}
