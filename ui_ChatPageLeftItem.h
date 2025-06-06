/********************************************************************************
** Form generated from reading UI file 'ChatPageLeftItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGELEFTITEM_H
#define UI_CHATPAGELEFTITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPageLeftItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    CRoundLabel *image;
    QLabel *number;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *text;

    void setupUi(QDialog *ChatPageLeftItem)
    {
        if (ChatPageLeftItem->objectName().isEmpty())
            ChatPageLeftItem->setObjectName(QString::fromUtf8("ChatPageLeftItem"));
        ChatPageLeftItem->resize(300, 70);
        ChatPageLeftItem->setMinimumSize(QSize(300, 70));
        ChatPageLeftItem->setMaximumSize(QSize(300, 70));
        ChatPageLeftItem->setStyleSheet(QString::fromUtf8(" background-color: transparent; "));
        horizontalLayout = new QHBoxLayout(ChatPageLeftItem);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 11, 16, 11);
        widget = new QWidget(ChatPageLeftItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(66, 16777215));
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(16, 4, 40, 40));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);
        number = new QLabel(widget);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(38, 2, 28, 14));
        number->setStyleSheet(QString::fromUtf8("background: #ED525A;\n"
"border-radius: 7px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 10px;\n"
"color: #FFFFFF;\n"
"line-height: 14px;\n"
"font-style: normal;"));
        number->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLabel(ChatPageLeftItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setMaximumSize(QSize(16777215, 22));
        name->setStyleSheet(QString::fromUtf8("font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout->addWidget(name);

        text = new QLabel(ChatPageLeftItem);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMinimumSize(QSize(214, 20));
        text->setMaximumSize(QSize(214, 20));
        text->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;"));

        verticalLayout->addWidget(text);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ChatPageLeftItem);

        QMetaObject::connectSlotsByName(ChatPageLeftItem);
    } // setupUi

    void retranslateUi(QDialog *ChatPageLeftItem)
    {
        ChatPageLeftItem->setWindowTitle(QCoreApplication::translate("ChatPageLeftItem", "Dialog", nullptr));
        image->setText(QString());
        number->setText(QCoreApplication::translate("ChatPageLeftItem", "99+", nullptr));
        name->setText(QString());
        text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatPageLeftItem: public Ui_ChatPageLeftItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGELEFTITEM_H
