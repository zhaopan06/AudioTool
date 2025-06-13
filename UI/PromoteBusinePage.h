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

private slots:
    void on_topBtn_clicked();

    void on_minBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::PromoteBusinePage *ui;
};

#endif // PROMOTEBUSINEPAGE_H
