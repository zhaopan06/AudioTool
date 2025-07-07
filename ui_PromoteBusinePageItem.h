/********************************************************************************
** Form generated from reading UI file 'PromoteBusinePageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTEBUSINEPAGEITEM_H
#define UI_PROMOTEBUSINEPAGEITEM_H

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

class Ui_PromoteBusinePageItem
{
public:
    QHBoxLayout *horizontalLayout;
    click_label *photo;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *roomId;
    QSpacerItem *horizontalSpacer;
    QPushButton *hotValue;

    void setupUi(QDialog *PromoteBusinePageItem)
    {
        if (PromoteBusinePageItem->objectName().isEmpty())
            PromoteBusinePageItem->setObjectName(QString::fromUtf8("PromoteBusinePageItem"));
        PromoteBusinePageItem->resize(503, 63);
        PromoteBusinePageItem->setMaximumSize(QSize(16777215, 63));
        PromoteBusinePageItem->setStyleSheet(QString::fromUtf8("background: #624676;\n"
"border-radius: 6px;"));
        horizontalLayout = new QHBoxLayout(PromoteBusinePageItem);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(7, 7, 8, 8);
        photo = new click_label(PromoteBusinePageItem);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(48, 48));
        photo->setMaximumSize(QSize(48, 48));
        photo->setScaledContents(true);

        horizontalLayout->addWidget(photo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLabel(PromoteBusinePageItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 20));
        name->setMaximumSize(QSize(16777215, 20));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout->addWidget(name);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(PromoteBusinePageItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 16));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        roomId = new QLabel(widget);
        roomId->setObjectName(QString::fromUtf8("roomId"));
        roomId->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"text-align: center;\n"
"font-style: normal;"));

        horizontalLayout_2->addWidget(roomId);

        horizontalSpacer = new QSpacerItem(343, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        hotValue = new QPushButton(widget);
        hotValue->setObjectName(QString::fromUtf8("hotValue"));
        hotValue->setMinimumSize(QSize(31, 17));
        hotValue->setMaximumSize(QSize(31, 17));
        hotValue->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"font-style: normal;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon_\347\201\253 .png"), QSize(), QIcon::Normal, QIcon::Off);
        hotValue->setIcon(icon);

        horizontalLayout_2->addWidget(hotValue);


        verticalLayout->addWidget(widget);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PromoteBusinePageItem);

        QMetaObject::connectSlotsByName(PromoteBusinePageItem);
    } // setupUi

    void retranslateUi(QDialog *PromoteBusinePageItem)
    {
        PromoteBusinePageItem->setWindowTitle(QCoreApplication::translate("PromoteBusinePageItem", "Dialog", nullptr));
        photo->setText(QString());
        name->setText(QCoreApplication::translate("PromoteBusinePageItem", "\347\225\231\345\243\260-\345\206\262\345\210\272\346\234\210\346\246\234", nullptr));
        roomId->setText(QCoreApplication::translate("PromoteBusinePageItem", "TextLabel", nullptr));
        hotValue->setText(QCoreApplication::translate("PromoteBusinePageItem", "29", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromoteBusinePageItem: public Ui_PromoteBusinePageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTEBUSINEPAGEITEM_H
