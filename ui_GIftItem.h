/********************************************************************************
** Form generated from reading UI file 'GIftItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFTITEM_H
#define UI_GIFTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GIftItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *timeLab;

    void setupUi(QDialog *GIftItem)
    {
        if (GIftItem->objectName().isEmpty())
            GIftItem->setObjectName(QString::fromUtf8("GIftItem"));
        GIftItem->resize(390, 45);
        verticalLayout = new QVBoxLayout(GIftItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(GIftItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-size: 16px;"));

        verticalLayout->addWidget(label);

        timeLab = new QLabel(GIftItem);
        timeLab->setObjectName(QString::fromUtf8("timeLab"));
        timeLab->setMinimumSize(QSize(0, 22));
        timeLab->setMaximumSize(QSize(16777215, 22));
        timeLab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout->addWidget(timeLab);


        retranslateUi(GIftItem);

        QMetaObject::connectSlotsByName(GIftItem);
    } // setupUi

    void retranslateUi(QDialog *GIftItem)
    {
        GIftItem->setWindowTitle(QCoreApplication::translate("GIftItem", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GIftItem", "TextLabel", nullptr));
        timeLab->setText(QCoreApplication::translate("GIftItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GIftItem: public Ui_GIftItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIFTITEM_H
