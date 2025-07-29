#ifndef DRESSUPPAGE_H
#define DRESSUPPAGE_H

#include <QDialog>
#include <QPushButton>
#include "DressUpPageBKItem.h"

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

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_setDressUp();

private:
    Ui::DressUpPage *ui;
    QPushButton *m_accButton = nullptr;
    QString m_path;
    QVector<DressUpPageBKItem*> m_bk_list;
    QVariantMap m_clickMap;
};

#endif // DRESSUPPAGE_H
