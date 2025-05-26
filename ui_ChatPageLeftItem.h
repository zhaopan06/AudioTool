/********************************************************************************
** Form generated from reading UI file 'ChatPageLeftItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGELEFTITEM_H
#define UI_CHATPAGELEFTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "CRoundLabel.h"

QT_BEGIN_NAMESPACE

class Ui_ChatPageLeftItem
{
public:
    QHBoxLayout *horizontalLayout;
    CRoundLabel *image;
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
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 11, 16, 11);
        image = new CRoundLabel(ChatPageLeftItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);

        horizontalLayout->addWidget(image);

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
        text->setMinimumSize(QSize(0, 20));
        text->setMaximumSize(QSize(16777215, 20));
        text->setStyleSheet(QString::fromUtf8("font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout->addWidget(text);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ChatPageLeftItem);

        QMetaObject::connectSlotsByName(ChatPageLeftItem);
    } // setupUi

    void retranslateUi(QDialog *ChatPageLeftItem)
    {
        ChatPageLeftItem->setWindowTitle(QCoreApplication::translate("ChatPageLeftItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QString());
        text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatPageLeftItem: public Ui_ChatPageLeftItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGELEFTITEM_H
