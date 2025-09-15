#ifndef ROUNDLABEL_H
#define ROUNDLABEL_H
#include <QLabel>
class CRoundLabel:public QLabel
{
    Q_OBJECT
public:
    CRoundLabel(QWidget* parent=0);
signals:
    void clicked();
    void rightClicked();
protected:
    void paintEvent(QPaintEvent *e);    
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
private:
    bool m_bTransLayer;
};
#endif
