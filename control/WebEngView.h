#ifndef WEBENGVIEW_H
#define WEBENGVIEW_H

#include <QDialog>
#include <QWebEngineView>

namespace Ui {
class WebEngView;
}

class WebEngView : public QDialog
{
    Q_OBJECT

public:
    explicit WebEngView(QWidget *parent = nullptr);
    ~WebEngView();

    void init(QString str);
private:
    Ui::WebEngView *ui;
    QWebEngineView m_web;
};

#endif // WEBENGVIEW_H
