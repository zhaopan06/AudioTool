#include "DressUpPage.h"
#include "ui_DressUpPage.h"
#include "HttpInterFace.h"
#include "DressUpPageBKItem.h"
#include "DressUpPageQPItem.h"
#include "Global.h"
#include "ImageDialog.h"

DressUpPage::DressUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DressUpPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_accButton = new QPushButton(QStringLiteral("确认使用"), this);
    int yPos = this->height() - 56 - 30;
    m_accButton->setGeometry(96, yPos, 360, 56);
    m_accButton->setStyleSheet(
        "QPushButton {"
        "   border-radius: 28px;"
        "   font-size: 16px;"
        "   color: #FFFFFF;"
        "   text-align: center;"
        "   font-family: \"微软雅黑\";"
        "   font-weight: 500;"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);"
        "}"
        "QPushButton:hover {"
        "   font-size: 18px;"  // 悬停时字体变大
        "}"
        );
    connect(m_accButton, &QPushButton::clicked, this, &DressUpPage::on_setDressUp);
}

DressUpPage::~DressUpPage()
{
    m_bk_list.clear();
    delete ui;
}

void DressUpPage::init()
{
    m_bk_list.clear();
    cleanupLayout(ui->gridLayout);
    HttpInterFace::getInstance()->getDressUp(3, [&](const QVariant &content){

        showMapTojson(content.toMap());
        QVariantList list =  content.toMap()["data"].toList();
        for (int var = 0; var < list.size(); ++var)
        {
            DressUpPageBKItem *item = new DressUpPageBKItem;
            m_bk_list.append(item);
            connect(item, &DressUpPageBKItem::item_click, this, [&](QVariantMap data){
                m_clickMap = data;
                DressUpPageBKItem *item = qobject_cast<DressUpPageBKItem*>(sender());
                for(auto au: m_bk_list)
                {
                    if(au != item)
                        au->setclick(false);
                }
            });
            item->setData(list.at(var).toMap());
            bool wear = list.at(var).toMap()["wear"].toBool();
            if(wear)
            {
                QString photo = list.at(var).toMap()["src"].toString();
                HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
                    QPixmap pix(path);
                    pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
                    ui->image->setPixmap(pix);
                    ui->image->setRadius(16);
                    ui->image->setMove();
                    m_path = path;
                });
            }

            int row = var / 3;
            int col = var % 3;
            ui->gridLayout->addWidget(item,row, col);
        }
    });
}

void DressUpPage::on_pushButton_clicked()
{
    ImageDialog page;
    page.setUrlPath(m_path);
    page.exec();
}


void DressUpPage::on_closeBtn_clicked()
{
    close();
}


void DressUpPage::on_pushButton_3_clicked()
{
    cleanupLayout(ui->gridLayout);
    HttpInterFace::getInstance()->getDressUp(2, [&](const QVariant &content){

        showMapTojson(content.toMap());
        QVariantList list =  content.toMap()["data"].toList();
        for (int var = 0; var < list.size(); ++var)
        {
            DressUpPageQPItem *item = new DressUpPageQPItem;
            item->setData(list.at(var).toMap());
            bool wear = list.at(var).toMap()["wear"].toBool();
            if(wear)
            {
                QString photo = list.at(var).toMap()["icon"].toString();
                HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
                    QPixmap pix(path);
                    pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
                    ui->image->setPixmap(pix);
                    ui->image->setRadius(16);
                    ui->image->setMove();
                    m_path = path;
                });
            }
            int row = var / 3;
            int col = var % 3;
            ui->gridLayout->addWidget(item,row, col);
        }
    });
}


void DressUpPage::on_pushButton_4_clicked()
{
    cleanupLayout(ui->gridLayout);
    HttpInterFace::getInstance()->getDressUp(0, [&](const QVariant &content){

        QVariantList list =  content.toMap()["data"].toList();
        for (int var = 0; var < list.size(); ++var)
        {
            DressUpPageQPItem *item = new DressUpPageQPItem;
            item->setData(list.at(var).toMap());
            bool wear = list.at(var).toMap()["wear"].toBool();
            if(wear)
            {
                QString photo = list.at(var).toMap()["icon"].toString();
                HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
                    QPixmap pix(path);
                    pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
                    ui->image->setPixmap(pix);
                    ui->image->setRadius(16);
                    ui->image->setMove();
                    m_path = path;
                });
            }
            int row = var / 3;
            int col = var % 3;
            ui->gridLayout->addWidget(item,row, col);
        }
    });
}


void DressUpPage::on_pushButton_5_clicked()
{
    cleanupLayout(ui->gridLayout);
    HttpInterFace::getInstance()->getDressUp(1, [&](const QVariant &content){

        QVariantList list =  content.toMap()["data"].toList();
        for (int var = 0; var < list.size(); ++var)
        {
            DressUpPageQPItem *item = new DressUpPageQPItem;
            item->setData(list.at(var).toMap());
            bool wear = list.at(var).toMap()["wear"].toBool();
            if(wear)
            {
                QString photo = list.at(var).toMap()["icon"].toString();
                HttpInterFace::getInstance()->downLoad(photo, [&](const QString &path) {
                    QPixmap pix(path);
                    pix = pix.scaled(ui->image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
                    ui->image->setPixmap(pix);
                    ui->image->setRadius(16);
                    ui->image->setMove();
                    m_path = path;
                });
            }
            int row = var / 3;
            int col = var % 3;
            ui->gridLayout->addWidget(item,row, col);
        }
    });
}


void DressUpPage::on_pushButton_2_clicked()
{
    init();
}

void DressUpPage::on_setDressUp()
{
    showMapTojson(m_clickMap);
    int id = m_clickMap["avatarFrameId"].toInt();
    int type = m_clickMap["type"].toInt();
    HttpInterFace::getInstance()->setDressUp(id, type, [&](const QVariant &content){
        showMapTojson(content.toMap());
        this->accept();
    });
}

