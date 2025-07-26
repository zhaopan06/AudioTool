/********************************************************************************
** Form generated from reading UI file 'SetTingMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMENU_H
#define UI_SETTINGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetTingMenu
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *SetTingMenu)
    {
        if (SetTingMenu->objectName().isEmpty())
            SetTingMenu->setObjectName(QString::fromUtf8("SetTingMenu"));
        SetTingMenu->resize(132, 236);
        verticalLayout = new QVBoxLayout(SetTingMenu);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetTingMenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-image: url(:/images/\345\275\242\347\212\266_big.png);\n"
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
"text-align: left;\n"
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
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 27, 20, 20);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 25));
        pushButton_4->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 25));
        pushButton_5->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(pushButton_5);


        verticalLayout->addWidget(widget);


        retranslateUi(SetTingMenu);

        QMetaObject::connectSlotsByName(SetTingMenu);
    } // setupUi

    void retranslateUi(QDialog *SetTingMenu)
    {
        SetTingMenu->setWindowTitle(QCoreApplication::translate("SetTingMenu", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SetTingMenu", "\345\210\267\346\226\260\351\241\265\351\235\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SetTingMenu", "\345\270\256\345\212\251\344\270\255\345\277\203", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SetTingMenu", "\350\201\224\347\263\273\345\256\242\346\234\215", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SetTingMenu", "\350\256\276\347\275\256", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SetTingMenu", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetTingMenu: public Ui_SetTingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMENU_H
