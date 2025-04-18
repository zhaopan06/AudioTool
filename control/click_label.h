// clicklabel.h

#ifndef CLICKED_LABEL_H
#define CLICKED_LABEL_H

#include <QWidget>
#include <QLabel>


class click_label : public QLabel
{
    Q_OBJECT
public:
    click_label(QWidget *parent=0): QLabel(parent) {
        setScaledContents(true);
//        setStyleSheet(" background: solid lightGray; ");
    }
    virtual ~click_label() {}
    void setRadius(int radius){m_radius = radius;}//…Ë÷√‘≤Ω«
    void setRound(){m_isRound = true;}
    void setColor(){m_isShowColor = true;}
signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *e);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);

protected:
    void mouseReleaseEvent(QMouseEvent*);

private:
    int m_radius = 0;
    bool m_isShowColor = false;
    bool m_isRound = false;
};


#endif // CLICKEDLABEL_H
