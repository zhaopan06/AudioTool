#ifndef CHATPAGELEFTITEM_H
#define CHATPAGELEFTITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ChatPageLeftItem;
}

class ChatPageLeftItem : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPageLeftItem(QWidget *parent = nullptr);
    ~ChatPageLeftItem();
    void setData(QVariantMap data, QString text);
protected:
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void leftItemClicked(QString);
private:
    Ui::ChatPageLeftItem *ui;
    QVariantMap m_data;
};

#endif // CHATPAGELEFTITEM_H
