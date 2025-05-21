/********************************************************************************
** Form generated from reading UI file 'MenuHomeownerRight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUHOMEOWNERRIGHT_H
#define UI_MENUHOMEOWNERRIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuHomeownerRight
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;

    void setupUi(QDialog *MenuHomeownerRight)
    {
        if (MenuHomeownerRight->objectName().isEmpty())
            MenuHomeownerRight->setObjectName(QString::fromUtf8("MenuHomeownerRight"));
        MenuHomeownerRight->resize(132, 300);
        verticalLayout = new QVBoxLayout(MenuHomeownerRight);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MenuHomeownerRight);
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
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_14);


        verticalLayout->addWidget(widget);


        retranslateUi(MenuHomeownerRight);

        QMetaObject::connectSlotsByName(MenuHomeownerRight);
    } // setupUi

    void retranslateUi(QDialog *MenuHomeownerRight)
    {
        MenuHomeownerRight->setWindowTitle(QCoreApplication::translate("MenuHomeownerRight", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("MenuHomeownerRight", "\351\227\255\351\272\246", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MenuHomeownerRight", "\346\212\261\344\270\213\351\272\246", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MenuHomeownerRight", "\350\201\212\345\244\251", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MenuHomeownerRight", "\347\234\213\350\265\204\346\226\231", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MenuHomeownerRight", "\350\256\276\344\270\272\347\256\241\347\220\206", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MenuHomeownerRight", "\350\256\276\344\270\272\344\270\273\346\214\201\344\272\272", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MenuHomeownerRight", "\347\246\201\350\250\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuHomeownerRight: public Ui_MenuHomeownerRight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUHOMEOWNERRIGHT_H
