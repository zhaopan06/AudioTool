/********************************************************************************
** Form generated from reading UI file 'ChatImageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATIMAGEITEM_H
#define UI_CHATIMAGEITEM_H

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

class Ui_ChatImageItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    CRoundLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *user_lab;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    click_label *image;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ChatImageItem)
    {
        if (ChatImageItem->objectName().isEmpty())
            ChatImageItem->setObjectName(QString::fromUtf8("ChatImageItem"));
        ChatImageItem->resize(466, 218);
        verticalLayout = new QVBoxLayout(ChatImageItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ChatImageItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 66));
        widget->setMaximumSize(QSize(16777215, 66));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        label = new CRoundLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(52, 52));
        label->setMaximumSize(QSize(52, 52));

        horizontalLayout_2->addWidget(label);

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
        horizontalLayout_3->setContentsMargins(-1, -1, 20, -1);
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
        image = new click_label(ChatImageItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(150, 150));
        image->setMaximumSize(QSize(150, 150));
        image->setStyleSheet(QString::fromUtf8("border-radius: 16px;"));
        image->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(image);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatImageItem);

        QMetaObject::connectSlotsByName(ChatImageItem);
    } // setupUi

    void retranslateUi(QDialog *ChatImageItem)
    {
        ChatImageItem->setWindowTitle(QCoreApplication::translate("ChatImageItem", "Dialog", nullptr));
        label->setText(QString());
        nameLab->setText(QCoreApplication::translate("ChatImageItem", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("ChatImageItem", "\347\256\241\347\220\206", nullptr));
        user_lab->setText(QCoreApplication::translate("ChatImageItem", "8", nullptr));
        label_4->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatImageItem: public Ui_ChatImageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATIMAGEITEM_H
