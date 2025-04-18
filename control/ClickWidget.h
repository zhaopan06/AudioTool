#ifndef CLICKWIDGET_H
#define CLICKWIDGET_H

#include <QWidget>

class ClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickWidget(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
public slots:
};

#endif // CLICKWIDGET_H
