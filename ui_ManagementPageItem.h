/********************************************************************************
** Form generated from reading UI file 'ManagementPageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTPAGEITEM_H
#define UI_MANAGEMENTPAGEITEM_H

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

class Ui_ManagementPageItem
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
    QPushButton *pushButton;

    void setupUi(QDialog *ManagementPageItem)
    {
        if (ManagementPageItem->objectName().isEmpty())
            ManagementPageItem->setObjectName(QString::fromUtf8("ManagementPageItem"));
        ManagementPageItem->resize(600, 70);
        ManagementPageItem->setStyleSheet(QString::fromUtf8("border-radius: 0px;"));
        horizontalLayout = new QHBoxLayout(ManagementPageItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 16, 10);
        image = new CRoundLabel(ManagementPageItem);
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
        name = new QLabel(ManagementPageItem);
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

        label = new QLabel(ManagementPageItem);
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
        ageBtn = new QPushButton(ManagementPageItem);
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

        pushButton = new QPushButton(ManagementPageItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(88, 32));
        pushButton->setMaximumSize(QSize(88, 32));
        pushButton->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(ManagementPageItem);

        QMetaObject::connectSlotsByName(ManagementPageItem);
    } // setupUi

    void retranslateUi(QDialog *ManagementPageItem)
    {
        ManagementPageItem->setWindowTitle(QCoreApplication::translate("ManagementPageItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("ManagementPageItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        label->setText(QCoreApplication::translate("ManagementPageItem", "\345\234\250\347\272\277", nullptr));
        ageBtn->setText(QCoreApplication::translate("ManagementPageItem", "24", nullptr));
        pushButton->setText(QCoreApplication::translate("ManagementPageItem", "\350\247\243\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagementPageItem: public Ui_ManagementPageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTPAGEITEM_H
