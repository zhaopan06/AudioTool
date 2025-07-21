/********************************************************************************
** Form generated from reading UI file 'HotPushHistoryPageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPUSHHISTORYPAGEITEM_H
#define UI_HOTPUSHHISTORYPAGEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPushHistoryPageItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *useTime;
    QLabel *time;
    QLabel *placeName;
    QLabel *count;

    void setupUi(QDialog *HotPushHistoryPageItem)
    {
        if (HotPushHistoryPageItem->objectName().isEmpty())
            HotPushHistoryPageItem->setObjectName(QString::fromUtf8("HotPushHistoryPageItem"));
        HotPushHistoryPageItem->resize(600, 70);
        horizontalLayout_2 = new QHBoxLayout(HotPushHistoryPageItem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(HotPushHistoryPageItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2 {\n"
"    border-bottom: 1px solid #383B43;\n"
"\n"
"    }"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 1);
        useTime = new QLabel(widget_2);
        useTime->setObjectName(QString::fromUtf8("useTime"));
        useTime->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        useTime->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(useTime);

        time = new QLabel(widget_2);
        time->setObjectName(QString::fromUtf8("time"));
        time->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(time);

        placeName = new QLabel(widget_2);
        placeName->setObjectName(QString::fromUtf8("placeName"));
        placeName->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        placeName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(placeName);

        count = new QLabel(widget_2);
        count->setObjectName(QString::fromUtf8("count"));
        count->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        count->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(count);


        horizontalLayout_2->addWidget(widget_2);


        retranslateUi(HotPushHistoryPageItem);

        QMetaObject::connectSlotsByName(HotPushHistoryPageItem);
    } // setupUi

    void retranslateUi(QDialog *HotPushHistoryPageItem)
    {
        HotPushHistoryPageItem->setWindowTitle(QCoreApplication::translate("HotPushHistoryPageItem", "Dialog", nullptr));
        useTime->setText(QCoreApplication::translate("HotPushHistoryPageItem", "\344\275\277\347\224\250\346\227\266\351\227\264", nullptr));
        time->setText(QCoreApplication::translate("HotPushHistoryPageItem", "\344\275\277\347\224\250\346\227\266\351\227\264", nullptr));
        placeName->setText(QCoreApplication::translate("HotPushHistoryPageItem", "\344\275\277\347\224\250\346\227\266\351\227\264", nullptr));
        count->setText(QCoreApplication::translate("HotPushHistoryPageItem", "\344\275\277\347\224\250\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotPushHistoryPageItem: public Ui_HotPushHistoryPageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPUSHHISTORYPAGEITEM_H
