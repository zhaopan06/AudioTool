#ifndef EMOTIONPAGE_H
#define EMOTIONPAGE_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class EmotionPage;
}

class EmotionPage : public QDialog
{
    Q_OBJECT

public:
    explicit EmotionPage(QWidget *parent = nullptr);
    ~EmotionPage();

    void initChatEmotion();

signals:
    void emotionClicked(QVariantMap);


private:
    QStringList m_emotionList;
    Ui::EmotionPage *ui;
};

#endif // EMOTIONPAGE_H
