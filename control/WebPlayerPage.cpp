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
    m_web.page()->runJavaScript(QString("receiveJsonData(%1)").arg(str));
//   m_web.page()->runJavaScript("getDataFromPage();", [](const QVariant &result){
//       qDebug() << "Data from JavaScript:" << result;
//   });
}
