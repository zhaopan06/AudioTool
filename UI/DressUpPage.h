#ifndef DRESSUPPAGE_H
#define DRESSUPPAGE_H

#include <QDialog>

namespace Ui {
class DressUpPage;
}

class DressUpPage : public QDialog
{
    Q_OBJECT

public:
    explicit DressUpPage(QWidget *parent = nullptr);
    ~DressUpPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DressUpPage *ui;
};

#endif // DRESSUPPAGE_H
