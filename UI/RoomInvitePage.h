#ifndef ROOMINVITEPAGE_H
#define ROOMINVITEPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class RoomInvitePage;
}

class RoomInvitePage : public QDialog
{
    Q_OBJECT

public:
    explicit RoomInvitePage(QWidget *parent = nullptr);
    ~RoomInvitePage();

    void init();
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_copyBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_closeBtn_clicked();

signals:
    void roomInvite(QVariantMap);

private:
    Ui::RoomInvitePage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
};

#endif // ROOMINVITEPAGE_H
