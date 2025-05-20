/********************************************************************************
** Form generated from reading UI file 'MenuManagerRight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUMANAGERRIGHT_H
#define UI_MENUMANAGERRIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MenuManagerRight
{
public:

    void setupUi(QDialog *MenuManagerRight)
    {
        if (MenuManagerRight->objectName().isEmpty())
            MenuManagerRight->setObjectName(QString::fromUtf8("MenuManagerRight"));
        MenuManagerRight->resize(400, 300);

        retranslateUi(MenuManagerRight);

        QMetaObject::connectSlotsByName(MenuManagerRight);
    } // setupUi

    void retranslateUi(QDialog *MenuManagerRight)
    {
        MenuManagerRight->setWindowTitle(QCoreApplication::translate("MenuManagerRight", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuManagerRight: public Ui_MenuManagerRight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUMANAGERRIGHT_H
