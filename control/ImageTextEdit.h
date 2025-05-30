#ifndef IMAGETEXTEDIT_H
#define IMAGETEXTEDIT_H

#include "qapplication.h"
#include "qclipboard.h"
#include "qdir.h"
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

    QVector<QString> getImageList()
    {
        return m_imageList;
    }

    void clearImageList()
    {
        m_imageList.clear();
    }

    QString saveImageToTemp(const QVariant &imageData)
    {
        QImage image = qvariant_cast<QImage>(imageData);
        if (image.isNull()) return "";

        QString tempDir = QDir::tempPath();
        QString tempPath = tempDir + "/dropped_image_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".png";
        if (image.save(tempPath, "PNG"))
        {
            return tempPath;
        }
        return "";
    }

protected:

    bool eventFilter(QObject *obj, QEvent *event)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->matches(QKeySequence::Paste))
        {
            handleImagePaste();
            return true; // 拦截粘贴事件
        }
        return QObject::eventFilter(obj, event);
    }

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
            QString tempPath = saveImageToTemp(mimeData->imageData());
            insertImage(tempPath);
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
                        insertImage(path);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void handleImagePaste()
    {
        const QClipboard *clipboard = QApplication::clipboard();
        const QMimeData *mimeData = clipboard->mimeData();

        if (mimeData->hasImage())
        {
            QString tempPath = saveImageToTemp(mimeData->imageData());
            insertImage(tempPath);
        }
        else if (mimeData->hasUrls())
        {
            QList<QUrl> urls = mimeData->urls();
            for (const QUrl &url : urls)
            {
                if (url.isLocalFile() && QImageReader::supportedImageFormats().contains(QFileInfo(url.toLocalFile()).suffix().toLower().toUtf8()))
                {
                    QImage image(url.toLocalFile());
                    if (!image.isNull())
                    {
                        insertImage(url.toLocalFile());
                    }
                }
            }
        }
        else
        {
            paste(); // 默认粘贴文本
        }
    }

public:
    void insertImage(const QString path)
    {
        QImage image(path);
        if(image.width() > 400 || image.height() > 300)
        {
            image = image.scaled(400, 300, Qt::KeepAspectRatio);
            textCursor().insertImage(image);
        }
        else
          textCursor().insertImage(image);

        QTextCursor cursor = textCursor();
        cursor.insertText("\n");
        cursor.movePosition(QTextCursor::End);
        setTextCursor(cursor);
        m_imageList.append(path);
    }

private:
    QVector<QString> m_imageList;
};

#endif // IMAGETEXTEDIT_H
