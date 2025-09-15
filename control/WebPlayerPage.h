#ifndef WEBPLAYERPAGE_H
#define WEBPLAYERPAGE_H

#include "qcoreevent.h"
#include <QDialog>
#include <QWebEngineView>

class WebChannelInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebChannelInterface(QObject *parent = nullptr) : QObject(parent) {}
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

    bool event(QEvent *ev) override {

        return false;
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
