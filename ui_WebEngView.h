/********************************************************************************
** Form generated from reading UI file 'WebEngView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBENGVIEW_H
#define UI_WEBENGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WebEngView
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QDialog *WebEngView)
    {
        if (WebEngView->objectName().isEmpty())
            WebEngView->setObjectName(QString::fromUtf8("WebEngView"));
        WebEngView->resize(1031, 637);
        verticalLayout = new QVBoxLayout(WebEngView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(WebEngView);

        QMetaObject::connectSlotsByName(WebEngView);
    } // setupUi

    void retranslateUi(QDialog *WebEngView)
    {
        WebEngView->setWindowTitle(QCoreApplication::translate("WebEngView", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WebEngView: public Ui_WebEngView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBENGVIEW_H
