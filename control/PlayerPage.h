#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include "qmediaplayer.h"
#include <QDialog>

namespace Ui {
class PlayerPage;
}

class PlayerPage : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerPage(QWidget *parent = nullptr);
    ~PlayerPage();

    void play(QString path);

private:
    Ui::PlayerPage *ui;
    QMediaPlayer *m_player;
};

#endif // PLAYERPAGE_H
