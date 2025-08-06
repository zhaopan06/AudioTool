#ifndef MENULOCKRIGHT_H
#define MENULOCKRIGHT_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class MenuLockRight;
}

class MenuLockRight : public QDialog
{
    Q_OBJECT

public:
    static MenuLockRight* getInstance();
    ~MenuLockRight();
    void setData(QVariantMap data);
private:
    explicit MenuLockRight(QWidget *parent = nullptr);
private:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MenuLockRight *ui;
    QVariantMap m_data;
};

#endif // MENULOCKRIGHT_H
