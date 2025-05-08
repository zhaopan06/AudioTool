/********************************************************************************
** Form generated from reading UI file 'ContributeItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRIBUTEITEM_H
#define UI_CONTRIBUTEITEM_H

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

class Ui_ContributeItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget;
    CRoundLabel *image;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ContributeItem)
    {
        if (ContributeItem->objectName().isEmpty())
            ContributeItem->setObjectName(QString::fromUtf8("ContributeItem"));
        ContributeItem->resize(400, 70);
        horizontalLayout = new QHBoxLayout(ContributeItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ContributeItem);
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

        horizontalLayout->addWidget(label);

        widget = new QWidget(ContributeItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(40, 48));
        widget->setMaximumSize(QSize(40, 48));
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 40, 40));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 32, 40, 16));
        label_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 12, -1, 0);
        nameLab = new QLabel(ContributeItem);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setMinimumSize(QSize(0, 22));
        nameLab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        verticalLayout->addWidget(nameLab);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        label_3 = new QLabel(ContributeItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(ContributeItem);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #ffffff;\n"
"line-height: 20px;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(label_4);


        retranslateUi(ContributeItem);

        QMetaObject::connectSlotsByName(ContributeItem);
    } // setupUi

    void retranslateUi(QDialog *ContributeItem)
    {
        ContributeItem->setWindowTitle(QCoreApplication::translate("ContributeItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
        label_2->setText(QCoreApplication::translate("ContributeItem", "\345\234\250\346\210\277\351\227\264", nullptr));
        nameLab->setText(QCoreApplication::translate("ContributeItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContributeItem: public Ui_ContributeItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRIBUTEITEM_H
