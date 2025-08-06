#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QDialog>

namespace Ui {
class SetTingPage;
}

class SetTingPage : public QDialog
{
    Q_OBJECT

public:
    explicit SetTingPage(QWidget *parent = nullptr);
    ~SetTingPage();
    void init();
private slots:
    void on_pushButton_2_clicked();

    void on_closeBtn_clicked();

    void on_pushButton_clicked();

    void on_audioMsg_clicked();

private:
    Ui::SetTingPage *ui;
};

#endif // SETTINGPAGE_H
