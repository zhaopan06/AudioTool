#ifndef MICINFOITEM_H
#define MICINFOITEM_H

#include <QDialog>
#include <QVariantMap>
#include "qmovie.h"

namespace Ui {
class MicInfoItem;
}

class MicInfoItem : public QDialog
{
    Q_OBJECT

public:
    explicit MicInfoItem(QWidget *parent = nullptr);
    ~MicInfoItem();

    void setData(QVariantMap data, int num);
    QString getUserId();
    void updateData(QVariantMap data);
    void updateMultipleAuthoriation(QString str);
    void setAudioValue(QString uid, int value);

signals:
    void setMyselfMicInfo(int);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_image_rightClicked();

private:
    Ui::MicInfoItem *ui;
    QString m_multipleAuthoriation;
    QVariantMap m_data;
    QMovie movie;
};

#endif // MICINFOITEM_H
