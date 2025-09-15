#include "WebEngView.h"
#include "ui_WebEngView.h"
#include <QMouseEvent>

WebEngView::WebEngView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WebEngView)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->verticalLayout_2->addWidget(&m_web);    
    ui->lock_c->hide();
    ui->lock_n->show();
}

WebEngView::~WebEngView()
{
    delete ui;
}


void WebEngView::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 48)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void WebEngView::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void WebEngView::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void WebEngView::init(QString str)
{
    m_web.load(str);
}

void WebEngView::on_closeBtn_clicked()
{
    close();
}


void WebEngView::on_topBtn_clicked()
{
    bool isOnTop = windowFlags() & Qt::WindowStaysOnTopHint;
    setWindowFlag(Qt::WindowStaysOnTopHint, !isOnTop);
    show();

    if (!isOnTop)
    {
        setWindowTitle("窗口状态: 置顶");
    }
    else
    {
        setWindowTitle("窗口状态: 普通");
    }
}


void WebEngView::on_lock_n_clicked()
{
    ui->lock_n->hide();
    ui->lock_c->show();
}


void WebEngView::on_lock_c_clicked()
{
    ui->lock_c->hide();
    ui->lock_n->show();
}

