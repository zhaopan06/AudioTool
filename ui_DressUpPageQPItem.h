/********************************************************************************
** Form generated from reading UI file 'DressUpPageQPItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRESSUPPAGEQPITEM_H
#define UI_DRESSUPPAGEQPITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_DressUpPageQPItem
{
public:
    click_label *image;
    QLabel *time;
    QLabel *name;
    QLabel *label;

    void setupUi(QDialog *DressUpPageQPItem)
    {
        if (DressUpPageQPItem->objectName().isEmpty())
            DressUpPageQPItem->setObjectName(QString::fromUtf8("DressUpPageQPItem"));
        DressUpPageQPItem->resize(142, 200);
        DressUpPageQPItem->setMinimumSize(QSize(142, 200));
        image = new click_label(DressUpPageQPItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 142, 142));
        time = new QLabel(DressUpPageQPItem);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(10, 179, 122, 20));
        time->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: rgba(34, 36, 41, 0.5); \n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        time->setAlignment(Qt::AlignCenter);
        name = new QLabel(DressUpPageQPItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 152, 122, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #222429;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        name->setAlignment(Qt::AlignCenter);
        label = new QLabel(DressUpPageQPItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(85, 8, 49, 16));
        label->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;\n"
"padding-top: -2px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
"line-height: 16px;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(DressUpPageQPItem);

        QMetaObject::connectSlotsByName(DressUpPageQPItem);
    } // setupUi

    void retranslateUi(QDialog *DressUpPageQPItem)
    {
        DressUpPageQPItem->setWindowTitle(QCoreApplication::translate("DressUpPageQPItem", "Dialog", nullptr));
        image->setText(QString());
        time->setText(QCoreApplication::translate("DressUpPageQPItem", "TextLabel", nullptr));
        name->setText(QCoreApplication::translate("DressUpPageQPItem", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("DressUpPageQPItem", "\344\275\277\347\224\250\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DressUpPageQPItem: public Ui_DressUpPageQPItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRESSUPPAGEQPITEM_H
