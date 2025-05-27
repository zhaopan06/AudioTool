/********************************************************************************
** Form generated from reading UI file 'ChatPageC2CTextItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGEC2CTEXTITEM_H
#define UI_CHATPAGEC2CTEXTITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_ChatPageC2CTextItem
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    CRoundLabel *image;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *name;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *textLayout;
    click_label *label;

    void setupUi(QDialog *ChatPageC2CTextItem)
    {
        if (ChatPageC2CTextItem->objectName().isEmpty())
            ChatPageC2CTextItem->setObjectName(QString::fromUtf8("ChatPageC2CTextItem"));
        ChatPageC2CTextItem->resize(490, 64);
        horizontalLayout = new QHBoxLayout(ChatPageC2CTextItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        image = new CRoundLabel(ChatPageC2CTextItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(46, 46));
        image->setMaximumSize(QSize(46, 46));
        image->setScaledContents(true);

        verticalLayout->addWidget(image);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        widget = new QWidget(ChatPageC2CTextItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 12, 0);
        name = new QLabel(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_3->addWidget(name);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 34));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgba(60, 60, 86, 1);\n"
"border-top-left-radius: 0px;   \n"
"border-top-right-radius: 12px;   \n"
"border-bottom-right-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"text-align: right;"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(12, 6, 12, 6);
        textLayout = new QHBoxLayout();
        textLayout->setObjectName(QString::fromUtf8("textLayout"));
        label = new click_label(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(false);

        textLayout->addWidget(label);


        verticalLayout_2->addLayout(textLayout);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout->addWidget(widget);


        retranslateUi(ChatPageC2CTextItem);

        QMetaObject::connectSlotsByName(ChatPageC2CTextItem);
    } // setupUi

    void retranslateUi(QDialog *ChatPageC2CTextItem)
    {
        ChatPageC2CTextItem->setWindowTitle(QCoreApplication::translate("ChatPageC2CTextItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("ChatPageC2CTextItem", "TextLabel", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatPageC2CTextItem: public Ui_ChatPageC2CTextItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGEC2CTEXTITEM_H
