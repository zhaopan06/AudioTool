#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ImageDialog;
}

class ImageDialog : public QDialog
{
    Q_OBJECT
public:   
    void setPath(QString path);
    void setPix(QPixmap pix);

    explicit ImageDialog(QWidget *parent = 0);
    ~ImageDialog();
    void setImageList(QStringList list);
private slots:
    void on_close_clicked();

    void fileDownloaded(bool success, QString path);


    void on_left_clicked();

    void on_right_clicked();

private:
    void paintEvent(QPaintEvent *event);
    Ui::ImageDialog *ui;
    QStringList m_pathList;
    int m_currentIndex = 0;
    QString m_path;
};

#endif // IMAGEDIALOG_H
