#ifndef AUDIOVALUEPAGE_H
#define AUDIOVALUEPAGE_H

#include <QDialog>

namespace Ui {
class AudioValuePage;
}

class AudioValuePage : public QDialog
{
    Q_OBJECT

public:
    explicit AudioValuePage(QWidget *parent = nullptr);
    ~AudioValuePage();

    void setValue(int value);
private slots:
    void on_verticalSlider_valueChanged(int value);

protected:
    void leaveEvent(QEvent *event)override;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result)override;

signals:
    void valueChange(int);
private:
    Ui::AudioValuePage *ui;
};

#endif // AUDIOVALUEPAGE_H
