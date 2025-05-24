#include "AudioValuePage.h"
#include "qdebug.h"
#include "ui_AudioValuePage.h"
#include <windows.h>

AudioValuePage::AudioValuePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AudioValuePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

AudioValuePage::~AudioValuePage()
{
    delete ui;
}

void AudioValuePage::setValue(int value)
{
    ui->verticalSlider->setValue(value);
}

void AudioValuePage::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    hide();
}

bool AudioValuePage::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG")
    {
        MSG* msg = (MSG*)message;
        switch(msg->message)
        {
        case WM_NCACTIVATE:
            bool active = (bool)(msg->wParam);
            if(!active)
            {
                this->hide();
            }
        }
    }
    return QWidget::nativeEvent(eventType, message, result);
}

void AudioValuePage::on_verticalSlider_valueChanged(int value)
{
    emit valueChange(value);
}


