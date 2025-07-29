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

    void init();
private slots:
    void on_pushButton_clicked();

    void on_closeBtn_clicked();

private:
    Ui::DressUpPage *ui;
};

#endif // DRESSUPPAGE_H
