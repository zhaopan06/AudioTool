#ifndef WEBPLAYERPAGE_H
#define WEBPLAYERPAGE_H

#include "qcoreevent.h"
#include <QDialog>
#include <QWebEngineView>

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

protected:
    // 拦截所有鼠标事件，不处理
    bool event(QEvent *ev) override {

        return false; // 让事件穿透
    }
private:
    Ui::WebPlayerPage *ui;
    QWebEngineView m_web;
};

#endif // WEBPLAYERPAGE_H
