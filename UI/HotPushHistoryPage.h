#ifndef HOTPUSHHISTORYPAGE_H
#define HOTPUSHHISTORYPAGE_H

#include <QDialog>

namespace Ui {
class HotPushHistoryPage;
}

class HotPushHistoryPage : public QDialog
{
    Q_OBJECT

public:
    explicit HotPushHistoryPage(QWidget *parent = nullptr);
    ~HotPushHistoryPage();

    void init(QString roomid);
private slots:
    void on_pushButton_3_clicked();

    void on_Attention_clicked();

    void on_closeBtn_clicked();

private:
    Ui::HotPushHistoryPage *ui;
};

#endif // HOTPUSHHISTORYPAGE_H
