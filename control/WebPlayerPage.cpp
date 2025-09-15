#include "WebPlayerPage.h"
#include "ui_WebPlayerPage.h"
#include <QWebEngineSettings>
#include <QWebChannel>

WebPlayerPage::WebPlayerPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WebPlayerPage)
    , webChannel(new QWebChannel(this))
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


    webInterface = new WebChannelInterface(&m_web);
    const QString objectName = "webInterface";
    webChannel->registerObject(objectName, webInterface);
    m_web.page()->setWebChannel(webChannel);

    m_web.load(QString("https://testm.linkfunapp.com/app.html#/h5/player"));
}

WebPlayerPage::~WebPlayerPage()
{
    delete ui;
}

void WebPlayerPage::init(QString str)
{    
    m_str = str;
    if(isload)
    {
        QString jsCode = QString("window.StartPlayGift(%1)").arg(m_str);       
        m_web.page()->runJavaScript(jsCode, [](const QVariant &result){

        });
    }
}

void WebPlayerPage::loadFinished(bool b)
{
    if(!m_str.isEmpty())
    {
        QString jsCode = QString("window.StartPlayGift(%1)").arg(m_str);     
        m_web.page()->runJavaScript(jsCode, [](const QVariant &result){

        });
    }
    isload = b;
}
