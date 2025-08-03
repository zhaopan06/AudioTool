#include "toastpage.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QGuiApplication>

ToastPage::ToastPage(const QString &message, QWidget *parent) : QWidget(parent), m_opacity(1.0)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(20, 20, 20, 20);

    m_label = new QLabel(message, this);
    QFont font("微软雅黑", 18);
    m_label->setFont(font);
    m_label->setStyleSheet("color: white; font-size: 20px;");
    m_label->setAlignment(Qt::AlignCenter);

    layout->addWidget(m_label);
    setLayout(layout);

    m_fadeAnimation = new QPropertyAnimation(this, "opacity", this);
    m_fadeAnimation->setDuration(500);
    m_fadeAnimation->setStartValue(1.0);
    m_fadeAnimation->setEndValue(0.0);
    connect(m_fadeAnimation, &QPropertyAnimation::finished, this, &ToastPage::close);

    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    m_timer->start(1500);
    connect(m_timer, &QTimer::timeout, this, [this]() {
        m_fadeAnimation->start();
    });

    adjustSize();

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QRect screenGeometry = screen->geometry();
        int x = (screenGeometry.width() - width()) / 2;
        int y = (screenGeometry.height() * 0.4) - height() / 2;
        move(x, y);
    }
}

ToastPage::~ToastPage()
{
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
    if (m_fadeAnimation) {
        delete m_fadeAnimation;
    }
}

void ToastPage::showToast(QWidget *parent, const QString &message)
{
    ToastPage *toast = new ToastPage(message, parent);
    toast->show();
}

double ToastPage::opacity() const
{
    return m_opacity;
}

void ToastPage::setOpacity(double opacity)
{
    m_opacity = opacity;
    setWindowOpacity(m_opacity);
}

void ToastPage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QBrush brush(QColor(0, 0, 0, 180));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 16, 16);
}
