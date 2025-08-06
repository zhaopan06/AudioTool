#ifndef USERINFOPAGESIMPLE_H
#define USERINFOPAGESIMPLE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class UserinfoPageSimple;
}

class UserinfoPageSimple : public QDialog
{
    Q_OBJECT

public:
    static UserinfoPageSimple* getInstance();
    ~UserinfoPageSimple();
    void init(QString userID);
    void uninit();
private:
    explicit UserinfoPageSimple(QWidget *parent = nullptr);
private slots:
    void on_pushButton_5_clicked();

    void on_Attention_clicked();

    void on_pushButton_3_clicked();

protected:
    void leaveEvent(QEvent *event)override;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result)override;
private:
    Ui::UserinfoPageSimple *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    QString m_userId;
    int m_type;
    bool m_isFollow;
    QVariantMap m_data;
};

#endif // USERINFOPAGESIMPLE_H
