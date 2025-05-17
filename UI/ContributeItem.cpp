#include "ContributeItem.h"
#include "UserinfoPage.h"
#include "ui_ContributeItem.h"
#include "HttpInterFace.h"
#include <QScreen>

ContributeItem::ContributeItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ContributeItem)
{
    ui->setupUi(this);
    ui->image->installEventFilter(this);
}

ContributeItem::~ContributeItem()
{
    delete ui;
}

bool ContributeItem::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->image)
    {
        if (event->type() == QEvent::Enter)
        {
            QPoint mouseGlobalPos = QCursor::pos();
            int screenHeight = QGuiApplication::primaryScreen()->geometry().height();
            bool isMouseInLowerHalf = (mouseGlobalPos.y() > screenHeight / 2 - 80);
            QPoint labelGlobalPos = ui->image->mapToGlobal(QPoint(0, 0));
            UserinfoPage *page = UserinfoPage::getInstance();
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
            QRect widgetAGeometry = UserinfoPage::getInstance()->geometry();
            if (!widgetAGeometry.contains(mouseGlobalPos))
            {
                UserinfoPage::getInstance()->uninit();
            }

            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void ContributeItem::setData(QVariantMap data)
{
    m_data = data;
    QString name = data["name"].toString();
    ui->nameLab->setText(name);

    bool userInRoom = data["userInRoom"].toBool();
    ui->label_2->setVisible(userInRoom);

    int ranking = data["ranking"].toInt();
    switch (ranking) {
    case 1:
    {
        QString path = ":/images/top1.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        ui->label_3->setText(tr("当前"));
        ui->label_4->setText(tr("第一名"));
        break;
    }
    case 2:
    {
        QString path = ":/images/top2.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        break;
    }
    case 3:
    {
        QString path = ":/images/top3.png";
        ui->label->setPixmap(QPixmap::fromImage(QImage(path)));
        break;
    }
    default:
        break;
    }

    if(ranking > 3)
    {
        ui->label->setText(QString::number(ranking));
        ui->label->setPixmap(QPixmap());
    }

    if(ranking > 1)
    {
        ui->label_3->setText(tr("距离前一名"));
        ui->label_4->setText(data["difference"].toString());
    }

    QString photo = data["photo"].toString();
    HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
        this->ui->image->setPixmap(QPixmap::fromImage(QImage(path)));
    });
}
