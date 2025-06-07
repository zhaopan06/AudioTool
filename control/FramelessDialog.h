#ifndef FRAMELESSDIALOG_H
#define FRAMELESSDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsBlurEffect>
#include <QCursor>

class FramelessDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FramelessDialog(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    enum Edge {
        None = 0,
        Top = 1, Bottom = 2, Left = 4, Right = 8,
        TopLeft = Top | Left, TopRight = Top | Right,
        BottomLeft = Bottom | Left, BottomRight = Bottom | Right
    };

    Edge getEdgeAt(const QPoint &pos);
    void updateCursor(Edge edge);
    void setWindowEffects();

    bool m_isDragging;
    QPoint m_dragStartPos;
    Edge m_dragEdge;
    QGraphicsBlurEffect *m_blurEffect;
};

#endif // FRAMELESSDIALOG_H
