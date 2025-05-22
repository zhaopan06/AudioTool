/********************************************************************************
** Form generated from reading UI file 'MenuLockRight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENULOCKRIGHT_H
#define UI_MENULOCKRIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuLockRight
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *MenuLockRight)
    {
        if (MenuLockRight->objectName().isEmpty())
            MenuLockRight->setObjectName(QString::fromUtf8("MenuLockRight"));
        MenuLockRight->resize(132, 68);
        horizontalLayout = new QHBoxLayout(MenuLockRight);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MenuLockRight);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: #36383B;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"     border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 1);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
"QPushButton::hover{\n"
"border:none;\n"
"background-color: #5A5D61;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 1);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addWidget(widget);


        retranslateUi(MenuLockRight);

        QMetaObject::connectSlotsByName(MenuLockRight);
    } // setupUi

    void retranslateUi(QDialog *MenuLockRight)
    {
        MenuLockRight->setWindowTitle(QCoreApplication::translate("MenuLockRight", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("MenuLockRight", "\351\224\201\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuLockRight: public Ui_MenuLockRight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENULOCKRIGHT_H
