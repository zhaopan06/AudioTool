#ifndef WEBPLAYERPAGE_H
#define WEBPLAYERPAGE_H

#include "qcoreevent.h"
#include <QDialog>
#include <QWebEngineView>

// 交互类增加调试输出
class WebChannelInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebChannelInterface(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    QString receiveMessageFromJS(const QString &message) {
        qDebug() << "[Qt] JS to qt msg:" << message;
        return "Qt已收到: " + message;
    }

    QString getVersion() {
        qDebug() << "[Qt] JS vension";
        return "1.0.0";
    }

    void doSomething(const QString &param) {
        qDebug() << "[Qt] param:" << param;
    }
};

class WebChannelInterface;

namespace Ui {
class WebPlayerPage;
}

class WebPlayerPage : public QDialog
{
    Q_OBJECT

public:
    explicit WebPlayerPage(QWidget *parent = nullptr);
    ~WebPlayerPage();
    void init(QString str);

    private slots:
    void loadFinished(bool b);

protected:
    // 拦截所有鼠标事件，不处理
    bool event(QEvent *ev) override {

        return false; // 让事件穿透
    }
private:
    Ui::WebPlayerPage *ui;
    QWebEngineView m_web;
    QString m_str = "";
    bool isload = false;
    QWebChannel *webChannel;
    WebChannelInterface *webInterface;
};

#endif // WEBPLAYERPAGE_H
