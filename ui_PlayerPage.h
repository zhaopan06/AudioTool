/********************************************************************************
** Form generated from reading UI file 'PlayerPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERPAGE_H
#define UI_PLAYERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlayerPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *PlayerPage)
    {
        if (PlayerPage->objectName().isEmpty())
            PlayerPage->setObjectName(QString::fromUtf8("PlayerPage"));
        PlayerPage->resize(600, 449);
        verticalLayout_2 = new QVBoxLayout(PlayerPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PlayerPage);

        QMetaObject::connectSlotsByName(PlayerPage);
    } // setupUi

    void retranslateUi(QDialog *PlayerPage)
    {
        PlayerPage->setWindowTitle(QCoreApplication::translate("PlayerPage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerPage: public Ui_PlayerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERPAGE_H
