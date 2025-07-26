#include "FramelessDialog.h"
#include "qdebug.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>

FramelessDialog::FramelessDialog(QWidget *parent)
    : QWidget(parent), m_isDragging(false), m_dragEdge(None)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    installEventFilter(this);
    setMouseTracking(true);
}

bool FramelessDialog::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        Edge edge = getEdgeAt(mouseEvent->pos());
        updateCursor(edge);
    }
    return QWidget::eventFilter(watched, event);
}

void FramelessDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->globalPos();
        m_isDragging = true;
        m_dragEdge = getEdgeAt(event->pos());
    }
}

void FramelessDialog::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"1----------";
    if (m_isDragging)
    {
        QPoint diff = event->globalPos() - m_dragStartPos;
        if (m_dragEdge == None)
        {
            // Move the window
            move(this->pos() + diff);
        }
        else
        {
            // Resize window logic
            QRect newRect = geometry();
            if (m_dragEdge & Top) {
                newRect.setTop(event->globalPos().y());
            }
            if (m_dragEdge & Bottom) {
                newRect.setBottom(event->globalPos().y());
            }
            if (m_dragEdge & Left) {
                newRect.setLeft(event->globalPos().x());
            }
            if (m_dragEdge & Right) {
                newRect.setRight(event->globalPos().x());
            }
            setGeometry(newRect);
        }
        m_dragStartPos = event->globalPos();  // Update the start position for the next move
    }
}


void FramelessDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isDragging = false;
}

FramelessDialog::Edge FramelessDialog::getEdgeAt(const QPoint &pos)
{
    const int margin = 10;  // Edge area width in pixels

    if (pos.y() < margin) {
        return (pos.x() < margin) ? TopLeft : (pos.x() > width() - margin ? TopRight : Top);
    } else if (pos.y() > height() - margin) {
        return (pos.x() < margin) ? BottomLeft : (pos.x() > width() - margin ? BottomRight : Bottom);
    } else if (pos.x() < margin) {
        return Left;
    } else if (pos.x() > width() - margin) {
        return Right;
    }
    return None;
}

void FramelessDialog::updateCursor(Edge edge)
{
    if (edge == None) {
        setCursor(Qt::ArrowCursor);
    } else if (edge == TopLeft || edge == BottomRight) {
        setCursor(Qt::SizeFDiagCursor);
    } else if (edge == TopRight || edge == BottomLeft) {
        setCursor(Qt::SizeBDiagCursor);
    } else if (edge == Left || edge == Right) {
        setCursor(Qt::SizeHorCursor);
    } else if (edge == Top || edge == Bottom) {
        setCursor(Qt::SizeVerCursor);
    }
}
