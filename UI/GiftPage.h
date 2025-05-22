#ifndef GIFTPAGE_H
#define GIFTPAGE_H

#include <QDialog>

namespace Ui {
class GiftPage;
}

class GiftPage : public QDialog
{
    Q_OBJECT

public:
    explicit GiftPage(QWidget *parent = nullptr);
    ~GiftPage();
    void init();
private slots:
    void on_pushButton_clicked();

    void on_giftBtn_clicked();

    void on_gift1Btn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    Ui::GiftPage *ui;
    QVariantList m_list;
    int m_number;
    QVariantList m_giftList;
};

#endif // GIFTPAGE_H
