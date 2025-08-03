#ifndef TOASTPAGE_H
#define TOASTPAGE_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>

class ToastPage : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double opacity READ opacity WRITE setOpacity)

public:
    explicit ToastPage(const QString &message, QWidget *parent = nullptr);
    ~ToastPage() override;

    static void showToast(QWidget *parent = nullptr, const QString &message = "");

    double opacity() const;
    void setOpacity(double opacity);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *m_label;
    QTimer *m_timer;
    double m_opacity;
    QPropertyAnimation *m_fadeAnimation;
};

#endif // TOASTPAGE_H
