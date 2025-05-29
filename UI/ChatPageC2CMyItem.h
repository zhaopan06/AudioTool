#ifndef CHATPAGEC2CMYITEM_H
#define CHATPAGEC2CMYITEM_H

#include <QDialog>

namespace Ui {
class ChatPageC2CMyItem;
}

class ChatPageC2CMyItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageC2CMyItem(QWidget *parent = nullptr);
    ~ChatPageC2CMyItem();

    void setData(QString path, QString msg, int width);
    void setEmotion(QString path, int type);
    void setImage(QString path, QString largePath);
    void setLocalImage(QString path);
private slots:
    void on_label_clicked();

private:
    Ui::ChatPageC2CMyItem *ui;
    QString m_bigImageUrl = "";
};

#endif // CHATPAGEC2CMYITEM_H
