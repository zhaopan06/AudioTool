#include "OnlineItem.h"
#include "UserinfoPageSimple.h"
#include "ui_OnlineItem.h"
#include "HttpInterFace.h"
#include <QScreen>

OnlineItem::OnlineItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OnlineItem)
{
    ui->setupUi(this);
    ui->image->installEventFilter(this);
}

OnlineItem::~OnlineItem()
{
    delete ui;
}

bool OnlineItem::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->image)
    {
        if (event->type() == QEvent::Enter)
        {
            QPoint mouseGlobalPos = QCursor::pos();
            int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
            bool isMouseInLowerHalf = (mouseGlobalPos.y() > screenHeight / 2 - 80);
            QPoint labelGlobalPos = ui->image->mapToGlobal(QPoint(0, 0));
            UserinfoPageSimple *page = UserinfoPageSimple::getInstance();
            page->init(m_data["userId"].toString());
            QPoint point1;
            if(isMouseInLowerHalf)
            {
                point1.setX(labelGlobalPos.rx() - page->width());
                point1.setY(labelGlobalPos.ry() - page->height()/2);
            }
            else
            {
                point1.setX(labelGlobalPos.rx() - page->width());
                point1.setY(labelGlobalPos.ry());
            }
            page->move(point1);
            page->show();
            return true;
        }
        else if (event->type() == QEvent::Leave)
        {
            QPoint mouseGlobalPos = QCursor::pos();
            QRect widgetAGeometry = UserinfoPageSimple::getInstance()->geometry();
            if (!widgetAGeometry.contains(mouseGlobalPos))
            {
                UserinfoPageSimple::getInstance()->uninit();
            }

            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}
/*
status;//1-8代表1-8号麦，-1=在房间，-2=在线并且最近来过，-3=离线并最近来过  这是在线列表中status
-1 在房间  -2 在线 -3 离线
 */
void OnlineItem::setData(QVariantMap data, QString id)
{
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    QString vipLevelId = data["vipLevelId"].toString();
    ui->user_lab->setText(vipLevelId);

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap(path));
    });

    int status = data["status"].toInt();
    QString userId = data["userId"].toString();
    if(status == -1)
    {
        ui->user_btn->hide();

        if(userId == id) //房主
        {
            ui->user_lab->hide();

        }
        else
        {
            ui->room_lab->hide();
        }
    }
    else
    {
        ui->room_btn->hide();
        ui->room_lab->hide();
    }

    if(status > 0 && status < 9)
    {

        QString str =  QString::number(status) + QStringLiteral("号麦");
        ui->user_btn->setText(str);
    }

    if(status == -2)
    {
        ui->user_btn->setIcon(QIcon());
        ui->user_btn->setText(QStringLiteral("在线"));
    }
    if(status == -3)
    {
        ui->user_btn->setText(QStringLiteral("已离线"));
        ui->user_btn->setIcon(QIcon(":/images/icon16／已离线.png"));
        ui->user_btn->setStyleSheet("border-radius: 16px;"
                                    "background: rgba(67,69,73,1);"
                                    "font-size: 14px;"
                                    "color: #C7C6C6;");
    }
    m_data = data;
}
