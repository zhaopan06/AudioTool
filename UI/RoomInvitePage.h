#ifndef ROOMINVITEPAGE_H
#define ROOMINVITEPAGE_H

#include <QDialog>

namespace Ui {
class RoomInvitePage;
}

class RoomInvitePage : public QDialog
{
    Q_OBJECT

public:
    explicit RoomInvitePage(QWidget *parent = nullptr);
    ~RoomInvitePage();

    void setData(QVariantMap data);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_textEdit_textChanged();

    void on_image_clicked();

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::RoomInvitePage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
};

#endif // ROOMINVITEPAGE_H
