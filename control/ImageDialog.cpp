#include "ImageDialog.h"
#include "ui_ImageDialog.h"
#include <QPainter>
#include <QDebug>
#include <QImageIOHandler>
#include <QImageReader>

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->left->hide();
    ui->right->hide();
}

ImageDialog::~ImageDialog()
{
    delete ui;
}
void ImageDialog::paintEvent(QPaintEvent *event)
{

}

void ImageDialog::setImageList(QStringList list)
{
    ui->left->show();
    ui->right->show();    
}

void ImageDialog::fileDownloaded(bool success, QString path)
{
    // 如果下载不成功则不显示
    if (!success)
    {
        return;
    }
    m_pathList.append(path);
    for(int i=0;i<m_pathList.size();i++)
    {
        if(m_path == m_pathList.at(i))
            m_currentIndex = i;
    }
}

void ImageDialog::setPath(QString path)
{
    m_path = path;
    QPixmap pix(path);

    QImageReader reader(path);
    QImageIOHandler::Transformations transformation = reader.transformation();
    if(transformation == QImageIOHandler::TransformationRotate90)
    {
        QMatrix matrix;
        matrix.rotate(90);
        pix = pix.transformed(matrix,Qt::SmoothTransformation);
    }
    if(transformation == QImageIOHandler::TransformationRotate180)
    {
        QMatrix matrix;
        matrix.rotate(180);
        pix = pix.transformed(matrix,Qt::SmoothTransformation);
    }
    if(transformation == QImageIOHandler::TransformationRotate270)
    {
        QMatrix matrix;
        matrix.rotate(270);
        pix = pix.transformed(matrix,Qt::SmoothTransformation);
    }

    pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap( pix );

//    QPixmap pix(path);
//    pix = pix.scaled(818,552,Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->image->setPixmap( pix );
    show();
    activateWindow();

}
void ImageDialog::setPix(QPixmap pix)
{
    pix = pix.scaled(ui->image->width(),ui->image->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap( pix );
    show();
    activateWindow();
}

void ImageDialog::on_close_clicked()
{
    this->hide();
}

void ImageDialog::on_left_clicked()
{
    m_currentIndex--;
    if(m_currentIndex < 0)
    {
        m_currentIndex = 0;
        return;
    }
    setPath(m_pathList.at(m_currentIndex));
}

void ImageDialog::on_right_clicked()
{
    m_currentIndex++;
    if(m_currentIndex >= m_pathList.size())
    {
        m_currentIndex = m_pathList.size() - 1;
        return;
    }
    setPath(m_pathList.at(m_currentIndex));
}
