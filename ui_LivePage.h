/********************************************************************************
** Form generated from reading UI file 'LivePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVEPAGE_H
#define UI_LIVEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_LivePage
{
public:

    void setupUi(QDialog *LivePage)
    {
        if (LivePage->objectName().isEmpty())
            LivePage->setObjectName(QString::fromUtf8("LivePage"));
        LivePage->resize(400, 300);

        retranslateUi(LivePage);

        QMetaObject::connectSlotsByName(LivePage);
    } // setupUi

    void retranslateUi(QDialog *LivePage)
    {
        LivePage->setWindowTitle(QCoreApplication::translate("LivePage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LivePage: public Ui_LivePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVEPAGE_H
