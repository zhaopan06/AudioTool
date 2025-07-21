#ifndef HOTPUSHPAGE_H
#define HOTPUSHPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class HotPushPage;
}

class HotPushPage : public QDialog
{
    Q_OBJECT

public:
    explicit HotPushPage(QWidget *parent = nullptr);
    ~HotPushPage();

    void init(QString roomID);

private slots:
    void on_closeBtn_clicked();

    void on_pushButton_3_clicked();

    void on_Attention_clicked();

    void on_pushButton_clicked();

private:
    Ui::HotPushPage *ui;
    QVariantMap m_clickData;
};

#endif // HOTPUSHPAGE_H
