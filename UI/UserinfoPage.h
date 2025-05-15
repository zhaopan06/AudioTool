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

private:
    Ui::UserinfoPage *ui;
};

#endif // USERINFOPAGE_H
