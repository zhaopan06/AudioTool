#ifndef PROMOTEBUSINEPAGE_H
#define PROMOTEBUSINEPAGE_H

#include <QDialog>

namespace Ui {
class PromoteBusinePage;
}

class PromoteBusinePage : public QDialog
{
    Q_OBJECT

public:
    explicit PromoteBusinePage(QWidget *parent = nullptr);
    ~PromoteBusinePage();

    void init(QString roomId);
private slots:
    void on_topBtn_clicked();

    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_day_btn_clicked();

    void on_week_btn_clicked();

    void on_m_btn_clicked();

private:
    Ui::PromoteBusinePage *ui;
    QString m_roomId;
    QString m_currRoomId;
};

#endif // PROMOTEBUSINEPAGE_H
