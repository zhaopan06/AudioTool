#ifndef MENUMANAGERRIGHT_H
#define MENUMANAGERRIGHT_H

#include <QDialog>

namespace Ui {
class MenuManagerRight;
}

class MenuManagerRight : public QDialog
{
    Q_OBJECT

public:
    explicit MenuManagerRight(QWidget *parent = nullptr);
    ~MenuManagerRight();

private:
    Ui::MenuManagerRight *ui;
};

#endif // MENUMANAGERRIGHT_H
