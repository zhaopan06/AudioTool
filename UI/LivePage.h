#ifndef LIVEPAGE_H
#define LIVEPAGE_H

#include <QDialog>

namespace Ui {
class LivePage;
}

class LivePage : public QDialog
{
    Q_OBJECT

public:
    explicit LivePage(QWidget *parent = nullptr);
    ~LivePage();

private:
    Ui::LivePage *ui;
};

#endif // LIVEPAGE_H
