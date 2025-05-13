/********************************************************************************
** Form generated from reading UI file 'ChatTextItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTEXTITEM_H
#define UI_CHATTEXTITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatTextItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    CRoundLabel *image;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *user_lab;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *laout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *textLayout;

    void setupUi(QDialog *ChatTextItem)
    {
        if (ChatTextItem->objectName().isEmpty())
            ChatTextItem->setObjectName(QString::fromUtf8("ChatTextItem"));
        ChatTextItem->resize(466, 98);
        ChatTextItem->setMinimumSize(QSize(466, 98));
        ChatTextItem->setMaximumSize(QSize(466, 16777215));
        verticalLayout = new QVBoxLayout(ChatTextItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ChatTextItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(52, 52));
        image->setMaximumSize(QSize(52, 52));

        horizontalLayout_2->addWidget(image);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 10, -1, 8);
        nameLab = new QLabel(widget);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        verticalLayout_2->addWidget(nameLab);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(40, 18));
        label_3->setMaximumSize(QSize(40, 18));
        label_3->setStyleSheet(QString::fromUtf8("background: #ED525A;\n"
"border-radius: 9px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
"line-height: 16px;\n"
"font-style: normal;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        user_lab = new QLabel(widget);
        user_lab->setObjectName(QString::fromUtf8("user_lab"));
        user_lab->setMinimumSize(QSize(37, 16));
        user_lab->setMaximumSize(QSize(37, 16));
        user_lab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 10px;\n"
"color: #FFFFFF;\n"
"text-align: right;\n"
"font-style: normal;\n"
"\n"
"background-image: url(:/images/live_lev.png);\n"
"background-position: center;\n"
"padding-right: 6px; \n"
" text-align: right;"));
        user_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(user_lab);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(74, 18));
        label_4->setMaximumSize(QSize(74, 18));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(68, -1, -1, -1);
        laout = new QHBoxLayout();
        laout->setObjectName(QString::fromUtf8("laout"));
        widget_2 = new QWidget(ChatTextItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgba(60, 60, 86, 1);\n"
"border-top-left-radius: 0px;   \n"
"border-top-right-radius: 12px;   \n"
"border-bottom-right-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"\n"
""));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(12, 0, 12, 6);
        textLayout = new QHBoxLayout();
        textLayout->setObjectName(QString::fromUtf8("textLayout"));

        horizontalLayout_4->addLayout(textLayout);


        laout->addWidget(widget_2);


        horizontalLayout->addLayout(laout);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatTextItem);

        QMetaObject::connectSlotsByName(ChatTextItem);
    } // setupUi

    void retranslateUi(QDialog *ChatTextItem)
    {
        ChatTextItem->setWindowTitle(QCoreApplication::translate("ChatTextItem", "Dialog", nullptr));
        image->setText(QString());
        nameLab->setText(QCoreApplication::translate("ChatTextItem", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("ChatTextItem", "\347\256\241\347\220\206", nullptr));
        user_lab->setText(QCoreApplication::translate("ChatTextItem", "8", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatTextItem: public Ui_ChatTextItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTEXTITEM_H
