#ifndef NEWUSERPAGE_H
#define NEWUSERPAGE_H

#include <QDialog>

namespace Ui {
class NewUserPage;
}

class NewUserPage : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserPage(QWidget *parent = nullptr);
    ~NewUserPage();

    void init();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_updateBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::NewUserPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
};

#endif // NEWUSERPAGE_H
