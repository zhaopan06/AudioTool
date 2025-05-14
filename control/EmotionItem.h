#ifndef EMOTIONITEM_H
#define EMOTIONITEM_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class EmotionItem;
}

class EmotionItem : public QDialog
{
    Q_OBJECT

public:
    explicit EmotionItem(QWidget *parent = nullptr);
    ~EmotionItem();
    void setData(QVariantMap data);
signals:
    void clicked(QVariantMap);

private slots:
    void on_addSourceBtn_2_clicked();

private:
    Ui::EmotionItem *ui;
    QVariantMap m_data;
};

#endif // EMOTIONITEM_H
