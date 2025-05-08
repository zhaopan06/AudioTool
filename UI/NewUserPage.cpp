#include "NewUserPage.h"
#include "Global.h"
#include "NewUserItem.h"
#include "qevent.h"
#include "ui_NewUserPage.h"
#include "HttpInterFace.h"

NewUserPage::NewUserPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewUserPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

NewUserPage::~NewUserPage()
{
    delete ui;
}

void NewUserPage::init()
{
    HttpInterFace::getInstance()->getPcNewUserSquareList(1, 20, [&](const QVariant &data) {

        cleanupLayout(ui->listLayout);
        QVariantMap reData = data.toMap()["data"].toMap();
        QVariantList list = reData["list"].toList();
        for(QVariant var : list)
        {
            QVariantMap map = var.toMap();
            NewUserItem *item = new NewUserItem();
            item->setData(map);
            ui->listLayout->addWidget(item);
        }
    });
}

void NewUserPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void NewUserPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void NewUserPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}

void NewUserPage::on_updateBtn_clicked()
{

}


void NewUserPage::on_closeBtn_clicked()
{
    this->close();
}

