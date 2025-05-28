#ifndef IMAGETEXTEDIT_H
#define IMAGETEXTEDIT_H

#include "qevent.h"
#include "qfileinfo.h"
#include "qimagereader.h"
#include "qmimedata.h"
#include "qtextedit.h"

class ImageTextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit ImageTextEdit(QWidget *parent = nullptr) : QTextEdit(parent)
    {
        setAcceptRichText(true);
        setAcceptDrops(true);
    }

protected:

    void dragEnterEvent(QDragEnterEvent *e) override
    {
        if (e->mimeData()->hasImage() || hasImageUrls(e->mimeData()))
        {
            e->acceptProposedAction();
        }
        else
        {
            QTextEdit::dragEnterEvent(e);
        }
    }


    void dragMoveEvent(QDragMoveEvent *e) override
    {
        if (e->mimeData()->hasImage() || hasImageUrls(e->mimeData()))
        {
            e->acceptProposedAction();
        }
        else
        {
            QTextEdit::dragMoveEvent(e);
        }
    }


    void dropEvent(QDropEvent *e) override
    {
        if (handleImageDrop(e->mimeData()))
        {
            e->acceptProposedAction();
        }
        else
        {
            QTextEdit::dropEvent(e);
        }
    }

private:
    bool hasImageUrls(const QMimeData *mimeData) const
    {
        if (!mimeData->hasUrls()) return false;
        for (const QUrl &url : mimeData->urls())
        {
            if (url.isLocalFile())
            {
                QString ext = QFileInfo(url.toLocalFile()).suffix().toLower();
                if (QImageReader::supportedImageFormats().contains(ext.toUtf8()))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // 处理图片插入
    bool handleImageDrop(const QMimeData *mimeData)
    {
        if (mimeData->hasImage())
        {
            insertImage(qvariant_cast<QImage>(mimeData->imageData()));
            return true;
        }
        else if (hasImageUrls(mimeData))
        {
            for (const QUrl &url : mimeData->urls())
            {
                if (url.isLocalFile())
                {
                    QString path = url.toLocalFile();
                    QImage image(path);
                    if (!image.isNull())
                    {
                        insertImage(image);
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    void insertImage(const QImage &image)
    {
        if(image.width() > 400 || image.height() > 300)
        {
            QImage newImage = image.scaled(400, 300, Qt::KeepAspectRatio);
            textCursor().insertImage(newImage);
        }
        else
          textCursor().insertImage(image);

        QTextCursor cursor = textCursor();
        cursor.movePosition(QTextCursor::End);
        setTextCursor(cursor);
    }
};

#endif // IMAGETEXTEDIT_H
