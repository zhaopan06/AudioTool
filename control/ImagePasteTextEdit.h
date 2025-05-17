#ifndef IMAGEPASTETEXTEDIT_H
#define IMAGEPASTETEXTEDIT_H

#include <QTextEdit>
#include <QMimeData>
#include <QFileDialog>
#include <QDebug>

class ImagePasteTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    ImagePasteTextEdit(QWidget *parent = nullptr) : QTextEdit(parent) {}

protected:
    void insertFromMimeData(const QMimeData *source) override
    {
        // 检查粘贴内容是否包含图片
        if (source->hasImage())
        {
            QImage image = qvariant_cast<QImage>(source->imageData());
            QString savePath = QFileDialog::getSaveFileName(this, "保存图片", QDir::homePath(), "PNG Image (*.png)");
            if (!savePath.isEmpty())
            {
                image.save(savePath); // 保存图片到本地
                this->insertPlainText(savePath); // 插入图片路径到编辑框
                emit imagePasted(savePath); // 发送信号
                qDebug()<<"path---"<<savePath;
            }
        }
        // 其他类型（如文本）正常处理
        else
        {
            QTextEdit::insertFromMimeData(source);
        }
    }

signals:
    void imagePasted(const QString &imagePath); // 图片粘贴完成信号
};

#endif // IMAGEPASTETEXTEDIT_H
