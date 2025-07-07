#ifndef HOTPUSHPAGE_H
#define HOTPUSHPAGE_H

#include <QDialog>

namespace Ui {
class HotPushPage;
}

class HotPushPage : public QDialog
{
    Q_OBJECT

public:
    explicit HotPushPage(QWidget *parent = nullptr);
    ~HotPushPage();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::HotPushPage *ui;
};

#endif // HOTPUSHPAGE_H
