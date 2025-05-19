#ifndef IMAGEDROPLINEEDIT_H
#define IMAGEDROPLINEEDIT_H

#include "qapplication.h"
#include "qclipboard.h"
#include "qdatetime.h"
#include "qdir.h"
#include "qevent.h"
#include <QLineEdit>
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>

class ImageDropLineEdit : public QLineEdit {
    Q_OBJECT
public:
    ImageDropLineEdit(QWidget *parent = nullptr) : QLineEdit(parent)
    {
        setAcceptDrops(true);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->matches(QKeySequence::Paste))
        {
            const QClipboard *clipboard = QApplication::clipboard();
            const QMimeData *mimeData = clipboard->mimeData();

            if (mimeData->hasText())
            {
                QString pastedText = mimeData->text();
                if(isImageFile(pastedText))
                {
                    pastedText = QUrl(pastedText).toLocalFile();
                    emit sendImage(pastedText);
                }
            }
            else if (mimeData->hasImage())
            {
                QString tempPath = saveImageToTemp(mimeData->imageData());
                if (!tempPath.isEmpty())
                {
                    emit sendImage(tempPath);
                }
                return;
            }

            QLineEdit::keyPressEvent(event);
        }
        else
        {
            QLineEdit::keyPressEvent(event);
        }
    }

    void dragEnterEvent(QDragEnterEvent *event) override
    {
        if (event->mimeData()->hasUrls() || event->mimeData()->hasImage())
        {
            event->acceptProposedAction();
        }
        else
        {
            event->ignore();
        }
    }

    void dropEvent(QDropEvent *event) override
    {
        const QMimeData *mimeData = event->mimeData();
        if (mimeData->hasUrls())
        {
            QList<QUrl> urls = mimeData->urls();
            for (const QUrl &url : urls)
            {
                if (url.isLocalFile())
                {
                    QString filePath = url.toLocalFile();
                    if (isImageFile(filePath))
                    {
                        emit sendImage(filePath);
                        return;
                    }
                }
            }
        }

        if (mimeData->hasImage())
        {
            QString tempPath = saveImageToTemp(mimeData->imageData());
            if (!tempPath.isEmpty())
            {
                emit sendImage(tempPath);
            }
        }
    }

public:
    bool isImageFile(const QString &path)
    {
        QStringList imageExtensions = {"png", "jpg", "jpeg", "bmp"};
        return imageExtensions.contains(QFileInfo(path).suffix().toLower());
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

signals:
    void sendImage(const QString &imagePath);
};

#endif // IMAGEDROPLINEEDIT_H
