#include "RoomEidtPage.h"
#include "Global.h"
#include "qevent.h"
#include "ui_RoomEidtPage.h"
#include "HttpInterFace.h"
#include <QFileDialog>
#include "MsgBox.h"

RoomEidtPage::RoomEidtPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomEidtPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RoomEidtPage::~RoomEidtPage()
{
    delete ui;
}

void RoomEidtPage::setData(QVariantMap data)
{
    m_data = data;
    QString announcement = data["announcement"].toString();
    ui->textEdit->setText(announcement);

    QString roomName = data["roomName"].toString();
    ui->lineEdit->setText(roomName);

    QString fPhotoUrl = data["roomPhoto"].toString();
    HttpInterFace::getInstance()->downLoad(fPhotoUrl, [&](const QString &path) {
        ui->image->setPixmap(QPixmap(path));
        ui->image->setRadius(16);
    });
}

void RoomEidtPage::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().ry() < 56)
    {
        m_bMoveing = true;
        m_pMovePosition = event->globalPos() - this->pos();
    }
}

void RoomEidtPage::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bMoveing&&
        (event->buttons() & Qt::LeftButton)&&
        (event->globalPos() - m_pMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - m_pMovePosition);
        m_pMovePosition = event->globalPos() - pos();
    }
}

void RoomEidtPage::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMoveing = false;
}
//更换封面
void RoomEidtPage::on_image_clicked()
{
    QString localPath = QFileDialog::getOpenFileName(0, QStringLiteral("选择图片"), "", QStringLiteral("jpg、png图片(*.jpg *.png)"));
    if (localPath.isEmpty())
    {
        return;
    }

    HttpInterFace::getInstance()->uploadFile(localPath, 0, [&](QVariant vart){
        showMapTojson(vart.toMap());
        m_imageUrl = vart.toMap()["data"].toMap()["url"].toString();
    });
    ui->image->setPixmap(localPath);
    m_path = localPath;
}

void RoomEidtPage::on_lineEdit_textChanged(const QString &arg1)
{
    int number = arg1.size();
    ui->label_4->setText(QString::number(number));
}

void RoomEidtPage::on_textEdit_textChanged()
{
    const int maxLength = 100;
    QString text = ui->textEdit->toPlainText();
    if (text.length() > maxLength)
    {

        QTextCursor cursor = ui->textEdit->textCursor();
        text = text.left(maxLength);
        ui->textEdit->setPlainText(text);
        cursor.setPosition(maxLength);
        ui->textEdit->setTextCursor(cursor);
    }

    QString arg1 = ui->textEdit->toPlainText();
    int number = arg1.size();
    ui->label_6->setText(QString::number(number));
}

void RoomEidtPage::on_okBtn_clicked()
{
    if(m_imageUrl.isEmpty())
    {
        MsgBox::showMsg(this,tr("提示"), tr("请上传文件"));
        return;
    }
    QString text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        MsgBox::showMsg(this,tr("提示"), tr("请输出房间名称"));
        return;
    }
    QString text1 = ui->textEdit->toPlainText();
    if(text1.isEmpty())
    {
        MsgBox::showMsg(this,tr("提示"), tr("请输出房间公告"));
        return;
    }
    QString roomID =  m_data["roomId"].toString();
    HttpInterFace::getInstance()->uploadLiveInfo(m_imageUrl,text,text1,roomID,[&](QVariant vart){
        MsgBox::showMsg(this,tr("提示"), tr("房间信息更新成功"));
        accept();
    });
}


void RoomEidtPage::on_cancelBtn_clicked()
{
    close();
}


void RoomEidtPage::on_closeBtn_clicked()
{
    close();
}
