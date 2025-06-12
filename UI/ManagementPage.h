#ifndef MANAGEMENTPAGE_H
#define MANAGEMENTPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ManagementPage;
}

class ManagementPage : public QDialog
{
    Q_OBJECT

public:
    explicit ManagementPage(QWidget *parent = nullptr);
    ~ManagementPage();

    void init(QVariantMap data);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_closeBtn_clicked();

    void on_button1_1_clicked();

    void on_button1_3_clicked();

    void on_button1_2_clicked();

    void on_button1_4_clicked();

private:
    Ui::ManagementPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    QVariantMap m_roomInfo;
};

#endif // MANAGEMENTPAGE_H
