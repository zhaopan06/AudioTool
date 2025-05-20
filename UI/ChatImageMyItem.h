#ifndef CHATIMAGEMYITEM_H
#define CHATIMAGEMYITEM_H

#include <QDialog>

namespace Ui {
class ChatImageMyItem;
}

class ChatImageMyItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatImageMyItem(QWidget *parent = nullptr);
    ~ChatImageMyItem();

    void setData(QString image, QString photo);
private slots:
    void on_image_clicked();

private:
    Ui::ChatImageMyItem *ui;
    QString m_path;
};

#endif // CHATIMAGEMYITEM_H
