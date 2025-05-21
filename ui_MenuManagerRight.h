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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuManagerRight
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *MenuManagerRight)
    {
        if (MenuManagerRight->objectName().isEmpty())
            MenuManagerRight->setObjectName(QString::fromUtf8("MenuManagerRight"));
        MenuManagerRight->resize(132, 140);
        MenuManagerRight->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(MenuManagerRight);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MenuManagerRight);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: #36383B;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"     border:none;\n"
"text-align: left;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 1);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
"QPushButton::hover{\n"
"border:none;\n"
" background-color: #5A5D61;\n"
"\n"
"     border:none;\n"
"text-align: left;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 1);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_4);


        verticalLayout->addWidget(widget);


        retranslateUi(MenuManagerRight);

        QMetaObject::connectSlotsByName(MenuManagerRight);
    } // setupUi

    void retranslateUi(QDialog *MenuManagerRight)
    {
        MenuManagerRight->setWindowTitle(QCoreApplication::translate("MenuManagerRight", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuManagerRight", "\346\212\261\344\270\213\351\272\246", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MenuManagerRight", "\351\227\255\351\272\246", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MenuManagerRight", "\347\234\213\350\265\204\346\226\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuManagerRight: public Ui_MenuManagerRight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUMANAGERRIGHT_H
