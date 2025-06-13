#ifndef ROOMEIDTPAGE_H
#define ROOMEIDTPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class RoomEidtPage;
}

class RoomEidtPage : public QDialog
{
    Q_OBJECT

public:
    explicit RoomEidtPage(QWidget *parent = nullptr);
    ~RoomEidtPage();

    void setData(QVariantMap data);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_image_clicked();

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

    void on_closeBtn_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_textEdit_textChanged();
private:
    Ui::RoomEidtPage *ui;
    bool  m_bMoveing = false;
    QPoint m_pMovePosition = QPoint(0,0);
    QString m_path;
    QVariantMap m_data;
    QString m_imageUrl;
};

#endif // ROOMEIDTPAGE_H
