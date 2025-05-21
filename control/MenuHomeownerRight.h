#ifndef MENUHOMEOWNERRIGHT_H
#define MENUHOMEOWNERRIGHT_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class MenuHomeownerRight;
}

class MenuHomeownerRight : public QDialog
{
    Q_OBJECT

public:
    static MenuHomeownerRight* getInstance();
    ~MenuHomeownerRight();
    void setData(QVariantMap data, QString multipleAuthoriation);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    explicit MenuHomeownerRight(QWidget *parent = nullptr);    

private:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    Ui::MenuHomeownerRight *ui;
    static MenuHomeownerRight *pMenuHomeownerRightFace;
    QVariantMap m_data;
    QString m_multipleAuthoriation;
};

#endif // MENUHOMEOWNERRIGHT_H
