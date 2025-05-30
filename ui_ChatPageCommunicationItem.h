/********************************************************************************
** Form generated from reading UI file 'ChatPageCommunicationItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGECOMMUNICATIONITEM_H
#define UI_CHATPAGECOMMUNICATIONITEM_H

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

QT_BEGIN_NAMESPACE

class Ui_ChatPageCommunicationItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    CRoundLabel *image;
    QLabel *label_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name;
    QPushButton *ageBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *userId;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *ChatPageCommunicationItem)
    {
        if (ChatPageCommunicationItem->objectName().isEmpty())
            ChatPageCommunicationItem->setObjectName(QString::fromUtf8("ChatPageCommunicationItem"));
        ChatPageCommunicationItem->resize(957, 70);
        ChatPageCommunicationItem->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_2 = new QHBoxLayout(ChatPageCommunicationItem);
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 1, 16, 1);
        widget = new QWidget(ChatPageCommunicationItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(68, 68));
        widget->setMaximumSize(QSize(68, 68));
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(16, 15, 40, 40));
        image->setScaledContents(true);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(16, 47, 40, 16));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
"text-align: center;\n"
"font-style: normal;\n"
"padding-bottom: 1px;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(ChatPageCommunicationItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 50, -1);
        name = new QLabel(widget_2);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setMaximumSize(QSize(16777215, 22));
        name->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_3->addWidget(name);

        ageBtn = new QPushButton(widget_2);
        ageBtn->setObjectName(QString::fromUtf8("ageBtn"));
        ageBtn->setMinimumSize(QSize(38, 0));
        ageBtn->setStyleSheet(QString::fromUtf8("background: rgba(128, 220, 255, 0.2);\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 11px;\n"
"color: #80DCFF;\n"
"line-height: 16px;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/live_people_man.png"), QSize(), QIcon::Normal, QIcon::Off);
        ageBtn->setIcon(icon);
        ageBtn->setIconSize(QSize(12, 12));

        horizontalLayout_3->addWidget(ageBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        userId = new QLabel(widget_2);
        userId->setObjectName(QString::fromUtf8("userId"));
        userId->setStyleSheet(QString::fromUtf8("font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_3->addWidget(userId);


        horizontalLayout_2->addWidget(widget_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(24);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(ChatPageCommunicationItem);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(88, 32));
        pushButton_2->setMaximumSize(QSize(88, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgba(245,151,255,0.2);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #F597FF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/live_inRoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(16, 17));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ChatPageCommunicationItem);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(88, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(ChatPageCommunicationItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(88, 32));
        pushButton->setMaximumSize(QSize(88, 32));
        pushButton->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;\n"
"\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 16px;"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ChatPageCommunicationItem);

        QMetaObject::connectSlotsByName(ChatPageCommunicationItem);
    } // setupUi

    void retranslateUi(QDialog *ChatPageCommunicationItem)
    {
        ChatPageCommunicationItem->setWindowTitle(QCoreApplication::translate("ChatPageCommunicationItem", "Dialog", nullptr));
        image->setText(QString());
        label_4->setText(QCoreApplication::translate("ChatPageCommunicationItem", "\347\233\264\346\222\255\344\270\255", nullptr));
        name->setText(QCoreApplication::translate("ChatPageCommunicationItem", "TextLabel", nullptr));
        ageBtn->setText(QCoreApplication::translate("ChatPageCommunicationItem", "24", nullptr));
        userId->setText(QCoreApplication::translate("ChatPageCommunicationItem", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatPageCommunicationItem", "\347\247\201\350\201\212", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChatPageCommunicationItem", "\345\217\226\346\266\210\345\205\263\346\263\250", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatPageCommunicationItem", "\345\205\263\346\263\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPageCommunicationItem: public Ui_ChatPageCommunicationItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGECOMMUNICATIONITEM_H
