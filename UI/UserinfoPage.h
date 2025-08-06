#ifndef USERINFOPAGE_H
#define USERINFOPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class UserinfoPage;
}

class UserinfoPage : public QDialog
{
    Q_OBJECT

public:
    static UserinfoPage* getInstance();
    ~UserinfoPage();
    void init(QString userID);
    void uninit();

private:
    explicit UserinfoPage(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);   

private slots:
    void on_closeBtn_clicked();

    void on_onlineBtn_clicked();

    void on_squareBtn_clicked();

    void on_contributeBtn_clicked();

    void on_sendBtn_clicked();

    void on_receiveBtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_Attention_clicked();

    void on_pushButton_3_clicked();

private:
    void updateGift(int type, int type1);

signals:
    void chatC2C(QVariantMap);
private:
    Ui::UserinfoPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    QString m_userId;
    int m_type;
    bool m_isFollow;
    QVariantMap m_data;
};

#endif // USERINFOPAGE_H
