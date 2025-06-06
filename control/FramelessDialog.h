#include <QDialog>
#include <QFlags>  // 添加这行

class FramelessDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FramelessDialog(QWidget *parent = nullptr);

    // 使用 Q_DECLARE_FLAGS 宏声明标志类型
    enum Edge { None = 0, Top = 1, Bottom = 2, Left = 4, Right = 8 };
    Q_DECLARE_FLAGS(Edges, Edge)  // 这行是关键

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Edges m_dragEdge = None;  // 使用 Edges 类型替代 Edge
    QPoint m_dragStartPos;
    QRect m_originalGeometry;

    Edges getEdgeAt(const QPoint &pos);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FramelessDialog::Edges)  // 在类声明后添加这行
