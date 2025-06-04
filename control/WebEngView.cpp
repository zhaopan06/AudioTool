#include "WebEngView.h"
#include "ui_WebEngView.h"

WebEngView::WebEngView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WebEngView)
{
    ui->setupUi(this);
    ui->verticalLayout_2->addWidget(&m_web);
    connect(m_web.page(),SIGNAL(loadFinished(bool)),this,SLOT(loadFinished(bool)));
}

WebEngView::~WebEngView()
{
    delete ui;
}

void WebEngView::init(QString str)
{
    m_web.load(str);
}
