#include "WebPlayerPage.h"
#include "ui_WebPlayerPage.h"
#include <QWebEngineSettings>

WebPlayerPage::WebPlayerPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WebPlayerPage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->verticalLayout_2->addWidget(&m_web);
    connect(m_web.page(),SIGNAL(loadFinished(bool)),this,SLOT(loadFinished(bool)));

    m_web.setAttribute(Qt::WA_TranslucentBackground);
    m_web.page()->setBackgroundColor(Qt::transparent);
    m_web.settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    m_web.settings()->setAttribute(QWebEngineSettings::AllowRunningInsecureContent, true);
    m_web.load(QString("https://testm.linkfunapp.com/app.html#/h5/player"));
}

WebPlayerPage::~WebPlayerPage()
{
    delete ui;
}

void WebPlayerPage::init(QString str)
{
    qDebug()<<"str-----------"<<str;
    m_str = str;
    if(isload)
    {
        QString jsCode = QString("jsbridge.StartPlayGift(function(res) { "
                                 "   console.log('收到数据', res); "
                                 "}, %1)"
                                 ).arg(m_str);
        m_web.page()->runJavaScript(jsCode, [](const QVariant &result){
            qDebug() << "init from JavaScript:" << result;
        });
    }
}

void WebPlayerPage::loadFinished(bool b)
{
    if(!m_str.isEmpty())
    {
        QString jsCode = QString("jsbridge.StartPlayGift(function(res) { "
                                 "console.log('收到数据', res); "
                                 "}, %1)"
                                 ).arg(m_str);

        m_web.page()->runJavaScript(jsCode, [](const QVariant &result){
            qDebug() << "loadFinished Data from JavaScript:" << result;
        });
    }
    isload = b;
}
