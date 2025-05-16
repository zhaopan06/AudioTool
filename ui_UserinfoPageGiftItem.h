/********************************************************************************
** Form generated from reading UI file 'UserinfoPageGiftItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGEGIFTITEM_H
#define UI_USERINFOPAGEGIFTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserinfoPageGiftItem
{
public:
    QWidget *widget;
    QLabel *image;
    QPushButton *giftPrice;
    QLabel *giftNum;
    QLabel *name;

    void setupUi(QDialog *UserinfoPageGiftItem)
    {
        if (UserinfoPageGiftItem->objectName().isEmpty())
            UserinfoPageGiftItem->setObjectName(QString::fromUtf8("UserinfoPageGiftItem"));
        UserinfoPageGiftItem->resize(100, 159);
        UserinfoPageGiftItem->setMinimumSize(QSize(100, 159));
        widget = new QWidget(UserinfoPageGiftItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 100, 116));
        widget->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        image = new QLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(12, 8, 76, 76));
        image->setScaledContents(true);
        giftPrice = new QPushButton(widget);
        giftPrice->setObjectName(QString::fromUtf8("giftPrice"));
        giftPrice->setGeometry(QRect(0, 90, 100, 17));
        giftPrice->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #FFFFFF;"));
        giftNum = new QLabel(UserinfoPageGiftItem);
        giftNum->setObjectName(QString::fromUtf8("giftNum"));
        giftNum->setGeometry(QRect(0, 142, 100, 17));
        giftNum->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"font-style: normal;"));
        giftNum->setAlignment(Qt::AlignCenter);
        name = new QLabel(UserinfoPageGiftItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(0, 122, 100, 17));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 12px;\n"
"color: #FFFFFF;\n"
"line-height: 17px;"));
        name->setAlignment(Qt::AlignCenter);

        retranslateUi(UserinfoPageGiftItem);

        QMetaObject::connectSlotsByName(UserinfoPageGiftItem);
    } // setupUi

    void retranslateUi(QDialog *UserinfoPageGiftItem)
    {
        UserinfoPageGiftItem->setWindowTitle(QCoreApplication::translate("UserinfoPageGiftItem", "Dialog", nullptr));
        image->setText(QString());
        giftPrice->setText(QCoreApplication::translate("UserinfoPageGiftItem", "PushButton", nullptr));
        giftNum->setText(QCoreApplication::translate("UserinfoPageGiftItem", "TextLabel", nullptr));
        name->setText(QCoreApplication::translate("UserinfoPageGiftItem", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserinfoPageGiftItem: public Ui_UserinfoPageGiftItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGEGIFTITEM_H
