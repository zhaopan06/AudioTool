/********************************************************************************
** Form generated from reading UI file 'ToastPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOASTPAGE_H
#define UI_TOASTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToastPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;

    void setupUi(QDialog *ToastPage)
    {
        if (ToastPage->objectName().isEmpty())
            ToastPage->setObjectName(QString::fromUtf8("ToastPage"));
        ToastPage->resize(259, 77);
        verticalLayout = new QVBoxLayout(ToastPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ToastPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(80, 24, 80, 24);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 22px;\n"
"color: #FFFFFF;\n"
"line-height: 30px;\n"
"text-align: center;\n"
"font-style: normal;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(widget);


        retranslateUi(ToastPage);

        QMetaObject::connectSlotsByName(ToastPage);
    } // setupUi

    void retranslateUi(QDialog *ToastPage)
    {
        ToastPage->setWindowTitle(QCoreApplication::translate("ToastPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ToastPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToastPage: public Ui_ToastPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOASTPAGE_H
