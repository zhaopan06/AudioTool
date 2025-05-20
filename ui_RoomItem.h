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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_RoomItem
{
public:
    click_label *imageLab;
    QLabel *roomName;
    QLabel *userName;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *hotValue;

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
        imageLab->setScaledContents(true);
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
        widget_2 = new QWidget(RoomItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 156, 28));
        widget_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        hotValue = new QPushButton(widget_2);
        hotValue->setObjectName(QString::fromUtf8("hotValue"));
        hotValue->setMinimumSize(QSize(0, 28));
        hotValue->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;\n"
"\n"
"background: rgba(22, 22, 22, 0.5);\n"
"border-top-left-radius: 0;\n"
"border-top-right-radius: 16px;\n"
"border-bottom-right-radius: 0;\n"
"border-bottom-left-radius: 16px;\n"
"\n"
"padding-top: 4px;\n"
"padding-bottom: 4px; \n"
"padding-left: 8px; \n"
"padding-right: 8px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon_number.png"), QSize(), QIcon::Normal, QIcon::Off);
        hotValue->setIcon(icon);

        horizontalLayout_2->addWidget(hotValue);


        retranslateUi(RoomItem);

        QMetaObject::connectSlotsByName(RoomItem);
    } // setupUi

    void retranslateUi(QDialog *RoomItem)
    {
        RoomItem->setWindowTitle(QCoreApplication::translate("RoomItem", "Dialog", nullptr));
        imageLab->setText(QString());
        roomName->setText(QCoreApplication::translate("RoomItem", "\346\265\252\346\274\253\346\273\241\345\261\213-\344\273\231\345\245\263\351\201\277\351\243\216\346\270\257", nullptr));
        userName->setText(QCoreApplication::translate("RoomItem", "\346\210\277\344\270\273\357\274\232\342\226\201\345\200\224\345\274\272\343\201\223\347\224\267\345\255\251\343\201\206", nullptr));
        hotValue->setText(QCoreApplication::translate("RoomItem", "11111", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomItem: public Ui_RoomItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEM_H
