/********************************************************************************
** Form generated from reading UI file 'RoomItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMITEM_H
#define UI_ROOMITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_RoomItem
{
public:
    click_label *imageLab;
    QLabel *roomName;
    QLabel *userName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *number;

    void setupUi(QDialog *RoomItem)
    {
        if (RoomItem->objectName().isEmpty())
            RoomItem->setObjectName(QString::fromUtf8("RoomItem"));
        RoomItem->resize(156, 211);
        RoomItem->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 16px;"));
        imageLab = new click_label(RoomItem);
        imageLab->setObjectName(QString::fromUtf8("imageLab"));
        imageLab->setGeometry(QRect(0, 0, 156, 156));
        imageLab->setStyleSheet(QString::fromUtf8("border-radius: 16px;"));
        roomName = new QLabel(RoomItem);
        roomName->setObjectName(QString::fromUtf8("roomName"));
        roomName->setGeometry(QRect(0, 166, 156, 22));
        roomName->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));
        userName = new QLabel(RoomItem);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(0, 194, 156, 17));
        userName->setStyleSheet(QString::fromUtf8("font-family: \342\200\234\345\276\256\350\275\257\351\233\205\351\273\221\342\200\235;\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"text-align: left;\n"
"font-style: normal;"));
        widget = new QWidget(RoomItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(101, 0, 55, 33));
        widget->setMinimumSize(QSize(55, 28));
        widget->setStyleSheet(QString::fromUtf8("background: #161616;\n"
"\n"
"\n"
"border-top-left-radius: 0;\n"
"    border-top-right-radius: 16px;\n"
"    border-bottom-right-radius: 0;\n"
"    border-bottom-left-radius: 16px;\n"
"\n"
"opacity: 0.5;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 6, 0, -1);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16, 16));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_number.png")));

        horizontalLayout->addWidget(label_4);

        number = new QLabel(widget);
        number->setObjectName(QString::fromUtf8("number"));
        number->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(number);


        retranslateUi(RoomItem);

        QMetaObject::connectSlotsByName(RoomItem);
    } // setupUi

    void retranslateUi(QDialog *RoomItem)
    {
        RoomItem->setWindowTitle(QCoreApplication::translate("RoomItem", "Dialog", nullptr));
        imageLab->setText(QString());
        roomName->setText(QCoreApplication::translate("RoomItem", "\346\265\252\346\274\253\346\273\241\345\261\213-\344\273\231\345\245\263\351\201\277\351\243\216\346\270\257", nullptr));
        userName->setText(QCoreApplication::translate("RoomItem", "\346\210\277\344\270\273\357\274\232\342\226\201\345\200\224\345\274\272\343\201\223\347\224\267\345\255\251\343\201\206", nullptr));
        label_4->setText(QString());
        number->setText(QCoreApplication::translate("RoomItem", "138", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomItem: public Ui_RoomItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEM_H
