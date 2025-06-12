/********************************************************************************
** Form generated from reading UI file 'ChatInviteItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATINVITEITEM_H
#define UI_CHATINVITEITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_ChatInviteItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    CRoundLabel *image;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *name;
    QWidget *widget_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *roomId;
    QSpacerItem *horizontalSpacer;
    click_label *roomPhoto;
    QLabel *roomName;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    CRoundLabel *mySelfImage;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ChatInviteItem)
    {
        if (ChatInviteItem->objectName().isEmpty())
            ChatInviteItem->setObjectName(QString::fromUtf8("ChatInviteItem"));
        ChatInviteItem->resize(458, 218);
        ChatInviteItem->setMinimumSize(QSize(214, 218));
        ChatInviteItem->setMaximumSize(QSize(16777215, 218));
        horizontalLayout = new QHBoxLayout(ChatInviteItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 0, 16, 0);
        widget_4 = new QWidget(ChatInviteItem);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(46, 0));
        widget_4->setMaximumSize(QSize(46, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        image = new CRoundLabel(widget_4);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(46, 46));
        image->setMaximumSize(QSize(46, 46));

        verticalLayout_3->addWidget(image);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_4);

        widget = new QWidget(ChatInviteItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(156, 0));
        widget->setMaximumSize(QSize(156, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setMaximumSize(QSize(16777215, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_2->addWidget(name);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(156, 156));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 138, 28));
        widget_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        roomId = new QPushButton(widget_2);
        roomId->setObjectName(QString::fromUtf8("roomId"));
        roomId->setMinimumSize(QSize(0, 28));
        roomId->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;\n"
"\n"
"background: rgba(22, 22, 22, 0.5);\n"
"border-top-left-radius: 16;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 16;\n"
"border-bottom-left-radius: 0px;\n"
"\n"
"padding-top: 4px;\n"
"padding-bottom: 4px; \n"
"padding-left: 8px; \n"
"padding-right: 8px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon_number.png"), QSize(), QIcon::Normal, QIcon::Off);
        roomId->setIcon(icon);

        horizontalLayout_2->addWidget(roomId);

        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        roomPhoto = new click_label(widget_3);
        roomPhoto->setObjectName(QString::fromUtf8("roomPhoto"));
        roomPhoto->setGeometry(QRect(0, 0, 156, 156));
        roomPhoto->setStyleSheet(QString::fromUtf8("border-radius: 16px;"));
        roomPhoto->setScaledContents(true);

        verticalLayout_2->addWidget(widget_3);

        roomName = new QLabel(widget);
        roomName->setObjectName(QString::fromUtf8("roomName"));
        roomName->setMinimumSize(QSize(0, 22));
        roomName->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_2->addWidget(roomName);


        horizontalLayout->addWidget(widget);

        widget_5 = new QWidget(ChatInviteItem);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(46, 0));
        widget_5->setMaximumSize(QSize(46, 16777215));
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mySelfImage = new CRoundLabel(widget_5);
        mySelfImage->setObjectName(QString::fromUtf8("mySelfImage"));
        mySelfImage->setMinimumSize(QSize(46, 46));
        mySelfImage->setMaximumSize(QSize(46, 46));

        verticalLayout->addWidget(mySelfImage);

        verticalSpacer_2 = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_5);


        retranslateUi(ChatInviteItem);

        QMetaObject::connectSlotsByName(ChatInviteItem);
    } // setupUi

    void retranslateUi(QDialog *ChatInviteItem)
    {
        ChatInviteItem->setWindowTitle(QCoreApplication::translate("ChatInviteItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("ChatInviteItem", "TextLabel", nullptr));
        roomId->setText(QCoreApplication::translate("ChatInviteItem", "11111", nullptr));
        roomPhoto->setText(QString());
        roomName->setText(QCoreApplication::translate("ChatInviteItem", "\346\265\252\346\274\253\346\273\241\345\261\213-\344\273\231\345\245\263\351\201\277\351\243\216\346\270\257", nullptr));
        mySelfImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatInviteItem: public Ui_ChatInviteItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATINVITEITEM_H
