/********************************************************************************
** Form generated from reading UI file 'RoomInvitePageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMINVITEPAGEITEM_H
#define UI_ROOMINVITEPAGEITEM_H

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

QT_BEGIN_NAMESPACE

class Ui_RoomInvitePageItem
{
public:
    QHBoxLayout *horizontalLayout;
    CRoundLabel *image;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ageBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *RoomInvitePageItem)
    {
        if (RoomInvitePageItem->objectName().isEmpty())
            RoomInvitePageItem->setObjectName(QString::fromUtf8("RoomInvitePageItem"));
        RoomInvitePageItem->resize(580, 89);
        RoomInvitePageItem->setMinimumSize(QSize(0, 70));
        RoomInvitePageItem->setMaximumSize(QSize(16777215, 89));
        RoomInvitePageItem->setStyleSheet(QString::fromUtf8("border-radius: 0px;"));
        horizontalLayout = new QHBoxLayout(RoomInvitePageItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 13, 16, 17);
        image = new CRoundLabel(RoomInvitePageItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);

        horizontalLayout->addWidget(image);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        name = new QLabel(RoomInvitePageItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setMaximumSize(QSize(16777215, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        horizontalLayout_3->addWidget(name);

        label = new QLabel(RoomInvitePageItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(40, 16));
        label->setMaximumSize(QSize(40, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(137, 244, 147, 0.2);\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 11px;\n"
"color: #89F493;\n"
"line-height: 16px;\n"
"font-style: normal;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ageBtn = new QPushButton(RoomInvitePageItem);
        ageBtn->setObjectName(QString::fromUtf8("ageBtn"));
        ageBtn->setMinimumSize(QSize(38, 16));
        ageBtn->setMaximumSize(QSize(16777215, 16));
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

        horizontalLayout_2->addWidget(ageBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(RoomInvitePageItem);
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

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(RoomInvitePageItem);

        QMetaObject::connectSlotsByName(RoomInvitePageItem);
    } // setupUi

    void retranslateUi(QDialog *RoomInvitePageItem)
    {
        RoomInvitePageItem->setWindowTitle(QCoreApplication::translate("RoomInvitePageItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("RoomInvitePageItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        label->setText(QCoreApplication::translate("RoomInvitePageItem", "\345\234\250\347\272\277", nullptr));
        ageBtn->setText(QCoreApplication::translate("RoomInvitePageItem", "24", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RoomInvitePageItem", "\351\202\200\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomInvitePageItem: public Ui_RoomInvitePageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMINVITEPAGEITEM_H
