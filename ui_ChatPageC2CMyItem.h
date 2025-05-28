/********************************************************************************
** Form generated from reading UI file 'ChatPageC2CMyItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGEC2CMYITEM_H
#define UI_CHATPAGEC2CMYITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_ChatPageC2CMyItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *textLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    click_label *label;
    QWidget *horizontalWidget;
    QVBoxLayout *verticalLayout;
    CRoundLabel *image;

    void setupUi(QDialog *ChatPageC2CMyItem)
    {
        if (ChatPageC2CMyItem->objectName().isEmpty())
            ChatPageC2CMyItem->setObjectName(QString::fromUtf8("ChatPageC2CMyItem"));
        ChatPageC2CMyItem->resize(555, 64);
        horizontalLayout_2 = new QHBoxLayout(ChatPageC2CMyItem);
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(16, 0, 16, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 12, 0, 12);
        widget_2 = new QWidget(ChatPageC2CMyItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setLayoutDirection(Qt::RightToLeft);
        widget_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
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

        widget = new QWidget(ChatPageC2CMyItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(" background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
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
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new click_label(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(34, 34));
        label->setMaximumSize(QSize(34, 34));
        label->setStyleSheet(QString::fromUtf8("background:rgba(255,255,255,0);"));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalWidget = new QWidget(ChatPageC2CMyItem);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(46, 16777215));
        horizontalWidget->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(horizontalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 12, 0, 0);
        image = new CRoundLabel(horizontalWidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(46, 46));
        image->setMaximumSize(QSize(46, 46));

        verticalLayout->addWidget(image);


        horizontalLayout_2->addWidget(horizontalWidget);


        retranslateUi(ChatPageC2CMyItem);

        QMetaObject::connectSlotsByName(ChatPageC2CMyItem);
    } // setupUi

    void retranslateUi(QDialog *ChatPageC2CMyItem)
    {
        ChatPageC2CMyItem->setWindowTitle(QCoreApplication::translate("ChatPageC2CMyItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatPageC2CMyItem: public Ui_ChatPageC2CMyItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGEC2CMYITEM_H
