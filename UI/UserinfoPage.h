#ifndef USERINFOPAGE_H
#define USERINFOPAGE_H

#include <QDialog>

namespace Ui {
class UserinfoPage;
}

class UserinfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit UserinfoPage(QWidget *parent = nullptr);
    ~UserinfoPage();

    void init(QString userID);

private slots:
    void on_closeBtn_clicked();

private:
    Ui::UserinfoPage *ui;
};

#endif // USERINFOPAGE_H
