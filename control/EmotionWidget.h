#pragma once

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include "ui_EmotionWidget.h"

#define CHAT_EMOTION_COUNT  36

class EmotionLabel : public QLabel
{
    Q_OBJECT

public:
    EmotionLabel(const QString &path, QWidget *parent = nullptr) : QLabel(parent) { m_path = path; }
    QString path() const { return m_path; }

Q_SIGNALS:
    void clicked(QString);

protected:
    void mouseReleaseEvent(QMouseEvent *ev)
    {
        if ((Qt::LeftButton == ev->button()) && (rect().contains(ev->pos())))
        {
            emit clicked(m_path);
        }
    }

private:
    QString m_path;
};
class EmotionWidget : public QWidget
{
	Q_OBJECT

public:
	EmotionWidget(QObject *parent = Q_NULLPTR);
	~EmotionWidget();

    void initChatEmotion();
    void setLiveStyle();
Q_SIGNALS:
	void emotionClicked(QString);

private:
//    void addEmotionItem(QString fileName);

private:
    Ui::EmotionWidget ui;
	QStringList m_emotionList;
};
