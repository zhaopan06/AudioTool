#ifndef CHATPAGEC2CTEXTITEM_H
#define CHATPAGEC2CTEXTITEM_H

#include <QDialog>

namespace Ui {
class ChatPageC2CTextItem;
}

class ChatPageC2CTextItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageC2CTextItem(QWidget *parent = nullptr);
    ~ChatPageC2CTextItem();
    void setData(QVariantMap data, QString text);
    void setImage(QVariantMap data, QString path, QString largePath);
private slots:
    void on_label_clicked();

private:
    Ui::ChatPageC2CTextItem *ui;
    QString m_bigImageUrl;
};

#endif // CHATPAGEC2CTEXTITEM_H
