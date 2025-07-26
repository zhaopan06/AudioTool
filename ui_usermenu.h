/********************************************************************************
** Form generated from reading UI file 'usermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMENU_H
#define UI_USERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMenu
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UserMenu)
    {
        if (UserMenu->objectName().isEmpty())
            UserMenu->setObjectName(QString::fromUtf8("UserMenu"));
        UserMenu->resize(132, 113);
        verticalLayout = new QVBoxLayout(UserMenu);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UserMenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-image: url(:/images/\345\275\242\347\212\266.png);\n"
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
"color: #ED525A;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"line-height: 25px;   \n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 17, 10, 10);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_2);


        verticalLayout->addWidget(widget);


        retranslateUi(UserMenu);

        QMetaObject::connectSlotsByName(UserMenu);
    } // setupUi

    void retranslateUi(QDialog *UserMenu)
    {
        UserMenu->setWindowTitle(QCoreApplication::translate("UserMenu", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("UserMenu", "\346\210\221\347\232\204\350\265\204\346\226\231", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserMenu", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMenu: public Ui_UserMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMENU_H
