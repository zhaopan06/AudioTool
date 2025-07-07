/********************************************************************************
** Form generated from reading UI file 'PromoteBusinePageTopItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTEBUSINEPAGETOPITEM_H
#define UI_PROMOTEBUSINEPAGETOPITEM_H

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

class Ui_PromoteBusinePageTopItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *widget;
    CRoundLabel *image;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *PromoteBusinePageTopItem)
    {
        if (PromoteBusinePageTopItem->objectName().isEmpty())
            PromoteBusinePageTopItem->setObjectName(QString::fromUtf8("PromoteBusinePageTopItem"));
        PromoteBusinePageTopItem->resize(397, 71);
        horizontalLayout = new QHBoxLayout(PromoteBusinePageTopItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(PromoteBusinePageTopItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(12, 0, 12, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(24, 24));
        label->setMaximumSize(QSize(24, 24));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/top1.png")));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(40, 50));
        widget->setMaximumSize(QSize(40, 50));
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 5, 40, 40));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 34, 40, 16));
        label_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        nameLab = new QLabel(widget_2);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setMinimumSize(QSize(0, 22));
        nameLab->setStyleSheet(QString::fromUtf8("font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        verticalLayout->addWidget(nameLab);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #ffffff;"));

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #ffffff;\n"
"line-height: 20px;\n"
"font-style: normal;"));

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout->addWidget(widget_2);


        retranslateUi(PromoteBusinePageTopItem);

        QMetaObject::connectSlotsByName(PromoteBusinePageTopItem);
    } // setupUi

    void retranslateUi(QDialog *PromoteBusinePageTopItem)
    {
        PromoteBusinePageTopItem->setWindowTitle(QCoreApplication::translate("PromoteBusinePageTopItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
        label_2->setText(QCoreApplication::translate("PromoteBusinePageTopItem", "\345\234\250\346\210\277\351\227\264", nullptr));
        nameLab->setText(QCoreApplication::translate("PromoteBusinePageTopItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PromoteBusinePageTopItem: public Ui_PromoteBusinePageTopItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTEBUSINEPAGETOPITEM_H
