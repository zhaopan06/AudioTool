/********************************************************************************
** Form generated from reading UI file 'DressUpPageBKItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRESSUPPAGEBKITEM_H
#define UI_DRESSUPPAGEBKITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_DressUpPageBKItem
{
public:
    click_label *image;
    QLabel *label;
    QLabel *name;
    QLabel *time;
    click_label *image_2;

    void setupUi(QDialog *DressUpPageBKItem)
    {
        if (DressUpPageBKItem->objectName().isEmpty())
            DressUpPageBKItem->setObjectName(QString::fromUtf8("DressUpPageBKItem"));
        DressUpPageBKItem->resize(142, 265);
        DressUpPageBKItem->setMinimumSize(QSize(142, 265));
        DressUpPageBKItem->setMaximumSize(QSize(142, 265));
        image = new click_label(DressUpPageBKItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 142, 208));
        label = new QLabel(DressUpPageBKItem);
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
        name = new QLabel(DressUpPageBKItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 218, 122, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #222429;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        name->setAlignment(Qt::AlignCenter);
        time = new QLabel(DressUpPageBKItem);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(10, 245, 122, 20));
        time->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: rgba(34, 36, 41, 0.5); \n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        time->setAlignment(Qt::AlignCenter);
        image_2 = new click_label(DressUpPageBKItem);
        image_2->setObjectName(QString::fromUtf8("image_2"));
        image_2->setGeometry(QRect(0, 0, 142, 208));
        image_2->setStyleSheet(QString::fromUtf8("background: transparent;"));

        retranslateUi(DressUpPageBKItem);

        QMetaObject::connectSlotsByName(DressUpPageBKItem);
    } // setupUi

    void retranslateUi(QDialog *DressUpPageBKItem)
    {
        DressUpPageBKItem->setWindowTitle(QCoreApplication::translate("DressUpPageBKItem", "Dialog", nullptr));
        image->setText(QString());
        label->setText(QCoreApplication::translate("DressUpPageBKItem", "\344\275\277\347\224\250\344\270\255", nullptr));
        name->setText(QCoreApplication::translate("DressUpPageBKItem", "TextLabel", nullptr));
        time->setText(QCoreApplication::translate("DressUpPageBKItem", "TextLabel", nullptr));
        image_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DressUpPageBKItem: public Ui_DressUpPageBKItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRESSUPPAGEBKITEM_H
