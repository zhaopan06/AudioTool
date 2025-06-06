#include "FramelessDialog.h"
#include "qevent.h"
#include <QPainter>

FramelessDialog::FramelessDialog(QWidget *parent)
    : QDialog(parent)
{
    // 关键设置
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // 可选：设置最小尺寸
    setMinimumSize(200, 150);
}

FramelessDialog::Edges FramelessDialog::getEdgeAt(const QPoint &pos)
{
    const int margin = 8;
    Edges edge = None;

    if (pos.x() < margin) edge |= Left;
    if (pos.x() > width() - margin) edge |= Right;
    if (pos.y() < margin) edge |= Top;
    if (pos.y() > height() - margin) edge |= Bottom;

    return edge;
}

void FramelessDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragEdge = getEdgeAt(event->pos());
        m_dragStartPos = event->globalPos();
        m_originalGeometry = geometry();
    }
    QDialog::mousePressEvent(event);
}

void FramelessDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        if (m_dragEdge != None) {
            // 计算鼠标移动距离
            QPoint delta = event->globalPos() - m_dragStartPos;
            QRect newGeo = m_originalGeometry;

            // 根据拖拽的边缘调整对应方向的尺寸
            if (m_dragEdge & Left) {
                newGeo.setLeft(newGeo.left() + delta.x());
                if (newGeo.width() < minimumWidth())
                    newGeo.setLeft(newGeo.right() - minimumWidth());
            }
            if (m_dragEdge & Right) {
                newGeo.setRight(newGeo.right() + delta.x());
            }
            if (m_dragEdge & Top) {
                newGeo.setTop(newGeo.top() + delta.y());
                if (newGeo.height() < minimumHeight())
                    newGeo.setTop(newGeo.bottom() - minimumHeight());
            }
            if (m_dragEdge & Bottom) {
                newGeo.setBottom(newGeo.bottom() + delta.y());
            }

            setGeometry(newGeo);
        }
    }
    QDialog::mouseMoveEvent(event);
}

void FramelessDialog::mouseReleaseEvent(QMouseEvent *event)
{
    m_dragEdge = None;
    QDialog::mouseReleaseEvent(event);
}

void FramelessDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 绘制半透明背景（可选）
    QPainter painter(this);
    painter.fillRect(rect(), QColor(50, 50, 50, 200));

    // 绘制边缘提示线（可选）
    painter.setPen(QColor(100, 100, 100, 150));
    const int margin = 5;
    painter.drawLine(0, margin, width(), margin); // 上边缘
    painter.drawLine(0, height()-margin, width(), height()-margin); // 下边缘
    painter.drawLine(margin, 0, margin, height()); // 左边缘
    painter.drawLine(width()-margin, 0, width()-margin, height()); // 右边缘
}
