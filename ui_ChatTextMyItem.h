/********************************************************************************
** Form generated from reading UI file 'ChatTextMyItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTEXTMYITEM_H
#define UI_CHATTEXTMYITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatTextMyItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *textLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *horizontalWidget;
    CRoundLabel *image;
    CRoundLabel *image_2;

    void setupUi(QDialog *ChatTextMyItem)
    {
        if (ChatTextMyItem->objectName().isEmpty())
            ChatTextMyItem->setObjectName(QString::fromUtf8("ChatTextMyItem"));
        ChatTextMyItem->resize(466, 76);
        horizontalLayout_2 = new QHBoxLayout(ChatTextMyItem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 15, 0, 15);
        widget_2 = new QWidget(ChatTextMyItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setLayoutDirection(Qt::RightToLeft);
        widget_2->setStyleSheet(QString::fromUtf8("background: rgba(60, 60, 86, 1);\n"
"border-top-left-radius: 12px;   \n"
"border-top-right-radius: 12px;   \n"
"border-bottom-right-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"text-align: right;"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(12, 6, 12, 6);
        textLayout = new QHBoxLayout();
        textLayout->setSpacing(0);
        textLayout->setObjectName(QString::fromUtf8("textLayout"));
        textLayout->setContentsMargins(0, -1, 0, 0);

        horizontalLayout_4->addLayout(textLayout);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(ChatTextMyItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: rgba(60, 60, 86, 1);\n"
"border-top-left-radius: 12px;   \n"
"border-top-right-radius: 12px;   \n"
"border-bottom-right-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"text-align: right;"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(34, 34));
        label->setMaximumSize(QSize(34, 34));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalWidget = new QWidget(ChatTextMyItem);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(66, 0));
        horizontalWidget->setMaximumSize(QSize(66, 16777215));
        horizontalWidget->setLayoutDirection(Qt::RightToLeft);
        image = new CRoundLabel(horizontalWidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(10, 12, 46, 46));
        image->setMinimumSize(QSize(46, 46));
        image->setMaximumSize(QSize(46, 46));
        image_2 = new CRoundLabel(horizontalWidget);
        image_2->setObjectName(QString::fromUtf8("image_2"));
        image_2->setGeometry(QRect(0, 2, 66, 66));

        horizontalLayout_2->addWidget(horizontalWidget);


        retranslateUi(ChatTextMyItem);

        QMetaObject::connectSlotsByName(ChatTextMyItem);
    } // setupUi

    void retranslateUi(QDialog *ChatTextMyItem)
    {
        ChatTextMyItem->setWindowTitle(QCoreApplication::translate("ChatTextMyItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
        image_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatTextMyItem: public Ui_ChatTextMyItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTEXTMYITEM_H
