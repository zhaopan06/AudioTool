/********************************************************************************
** Form generated from reading UI file 'UserinfoPageMedalItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGEMEDALITEM_H
#define UI_USERINFOPAGEMEDALITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserinfoPageMedalItem
{
public:
    QWidget *widget;
    QLabel *image;
    QLabel *name;

    void setupUi(QDialog *UserinfoPageMedalItem)
    {
        if (UserinfoPageMedalItem->objectName().isEmpty())
            UserinfoPageMedalItem->setObjectName(QString::fromUtf8("UserinfoPageMedalItem"));
        UserinfoPageMedalItem->resize(100, 116);
        UserinfoPageMedalItem->setMinimumSize(QSize(100, 116));
        widget = new QWidget(UserinfoPageMedalItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 100, 116));
        widget->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        image = new QLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(12, 8, 76, 76));
        image->setScaledContents(true);
        name = new QLabel(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(8, 91, 84, 17));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 12px;\n"
"color: #FFFFFF;\n"
"line-height: 17px;"));
        name->setAlignment(Qt::AlignCenter);

        retranslateUi(UserinfoPageMedalItem);

        QMetaObject::connectSlotsByName(UserinfoPageMedalItem);
    } // setupUi

    void retranslateUi(QDialog *UserinfoPageMedalItem)
    {
        UserinfoPageMedalItem->setWindowTitle(QCoreApplication::translate("UserinfoPageMedalItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("UserinfoPageMedalItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserinfoPageMedalItem: public Ui_UserinfoPageMedalItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGEMEDALITEM_H
