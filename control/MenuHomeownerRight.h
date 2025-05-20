#ifndef MENUHOMEOWNERRIGHT_H
#define MENUHOMEOWNERRIGHT_H

#include <QDialog>

namespace Ui {
class MenuHomeownerRight;
}

class MenuHomeownerRight : public QDialog
{
    Q_OBJECT

public:
    explicit MenuHomeownerRight(QWidget *parent = nullptr);
    ~MenuHomeownerRight();

private:
    Ui::MenuHomeownerRight *ui;
};

#endif // MENUHOMEOWNERRIGHT_H
