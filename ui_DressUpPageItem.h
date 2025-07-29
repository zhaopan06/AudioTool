/********************************************************************************
** Form generated from reading UI file 'DressUpPageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRESSUPPAGEITEM_H
#define UI_DRESSUPPAGEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DressUpPageItem
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *DressUpPageItem)
    {
        if (DressUpPageItem->objectName().isEmpty())
            DressUpPageItem->setObjectName(QString::fromUtf8("DressUpPageItem"));
        DressUpPageItem->resize(100, 100);
        DressUpPageItem->setMinimumSize(QSize(100, 100));
        pushButton = new QPushButton(DressUpPageItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 140, 75, 23));
        pushButton_2 = new QPushButton(DressUpPageItem);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 180, 75, 23));
        pushButton_3 = new QPushButton(DressUpPageItem);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 100, 75, 23));
        pushButton_4 = new QPushButton(DressUpPageItem);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 80, 80));
        pushButton_4->setMinimumSize(QSize(80, 80));

        retranslateUi(DressUpPageItem);

        QMetaObject::connectSlotsByName(DressUpPageItem);
    } // setupUi

    void retranslateUi(QDialog *DressUpPageItem)
    {
        DressUpPageItem->setWindowTitle(QCoreApplication::translate("DressUpPageItem", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DressUpPageItem", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DressUpPageItem", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DressUpPageItem", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DressUpPageItem", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DressUpPageItem: public Ui_DressUpPageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRESSUPPAGEITEM_H
