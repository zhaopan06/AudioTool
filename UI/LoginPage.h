#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_login_status_clicked(bool checked);

    void on_back_btn_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_back_label_clicked();

    void on_login_btn_clicked();

    void on_next_page_btn_clicked();

    void on_help_btn_clicked();

    void on_closeBtn_clicked();

    void on_minBtn_clicked();

    void on_help_Btn_1_clicked();

private:
    void updateBtnStyle();
private:
    Ui::LoginPage *ui;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;
    int m_count = 0;

};

#endif // LOGINPAGE_H
