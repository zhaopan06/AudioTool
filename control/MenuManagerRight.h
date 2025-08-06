#ifndef MENUMANAGERRIGHT_H
#define MENUMANAGERRIGHT_H

#include <QDialog>
#include <QVariantMap>
namespace Ui {
class MenuManagerRight;
}

class MenuManagerRight : public QDialog
{
    Q_OBJECT

public:
    static MenuManagerRight* getInstance();
    ~MenuManagerRight();
    void setData(QVariantMap data);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    explicit MenuManagerRight(QWidget *parent = nullptr);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    Ui::MenuManagerRight *ui;
    QVariantMap m_data;
};

#endif // MENUMANAGERRIGHT_H
