#ifndef WEBENGVIEW_H
#define WEBENGVIEW_H

#include <QDialog>
#include <QWebEngineView>

namespace Ui {
class WebEngView;
}

class WebEngView : public QDialog
{
    Q_OBJECT

public:
    explicit WebEngView(QWidget *parent = nullptr);
    ~WebEngView();

    void init(QString str);

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_lock_n_clicked();

    void on_closeBtn_clicked();

    void on_topBtn_clicked();

    void on_lock_c_clicked();

private:
    Ui::WebEngView *ui;
    QWebEngineView m_web;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
};

#endif // WEBENGVIEW_H
