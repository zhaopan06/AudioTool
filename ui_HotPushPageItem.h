/********************************************************************************
** Form generated from reading UI file 'HotPushPageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPUSHPAGEITEM_H
#define UI_HOTPUSHPAGEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPushPageItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_36;
    QHBoxLayout *horizontalLayout_22;
    QLabel *name;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *consume;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *activateNum;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;

    void setupUi(QDialog *HotPushPageItem)
    {
        if (HotPushPageItem->objectName().isEmpty())
            HotPushPageItem->setObjectName(QString::fromUtf8("HotPushPageItem"));
        HotPushPageItem->resize(228, 129);
        HotPushPageItem->setMinimumSize(QSize(228, 129));
        HotPushPageItem->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        verticalLayout = new QVBoxLayout(HotPushPageItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_36 = new QWidget(HotPushPageItem);
        widget_36->setObjectName(QString::fromUtf8("widget_36"));
        widget_36->setMinimumSize(QSize(0, 46));
        widget_36->setMaximumSize(QSize(16777215, 46));
        widget_36->setStyleSheet(QString::fromUtf8("QWidget#widget_36 {\n"
"    border-bottom: 1px solid #383B43;\n"
"border-radius: 6px;\n"
"    }"));
        horizontalLayout_22 = new QHBoxLayout(widget_36);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 1);
        name = new QLabel(widget_36);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 46));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));
        name->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(name);


        verticalLayout->addWidget(widget_36);

        widget_2 = new QWidget(HotPushPageItem);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 50));
        widget_2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: #FFFFFF;"));

        horizontalLayout->addWidget(label);

        consume = new QLabel(widget_2);
        consume->setObjectName(QString::fromUtf8("consume"));
        consume->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #ED525A;"));

        horizontalLayout->addWidget(consume);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(HotPushPageItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 33));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(33, 0));
        label_5->setMaximumSize(QSize(33, 16777215));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, 18);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: #FFFFFF;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        activateNum = new QLabel(widget);
        activateNum->setObjectName(QString::fromUtf8("activateNum"));
        activateNum->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #ED525A;"));
        activateNum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(activateNum);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(33, 32));
        pushButton->setMaximumSize(QSize(33, 32));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton::checked{\n"
"border:none;\n"
"background-image: url(:/images/icon_hot_click.png);\n"
"\n"
"}\n"
""));
        pushButton->setIconSize(QSize(33, 32));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget);


        retranslateUi(HotPushPageItem);

        QMetaObject::connectSlotsByName(HotPushPageItem);
    } // setupUi

    void retranslateUi(QDialog *HotPushPageItem)
    {
        HotPushPageItem->setWindowTitle(QCoreApplication::translate("HotPushPageItem", "Dialog", nullptr));
        name->setText(QCoreApplication::translate("HotPushPageItem", "\347\203\255\346\216\2501", nullptr));
        label->setText(QCoreApplication::translate("HotPushPageItem", "\346\266\210\350\200\227\357\274\232", nullptr));
        consume->setText(QCoreApplication::translate("HotPushPageItem", "11", nullptr));
        label_3->setText(QCoreApplication::translate("HotPushPageItem", "\345\274\240", nullptr));
        label_5->setText(QString());
        label_2->setText(QCoreApplication::translate("HotPushPageItem", "\345\211\251\344\275\231\357\274\232", nullptr));
        activateNum->setText(QCoreApplication::translate("HotPushPageItem", "1", nullptr));
        label_4->setText(QCoreApplication::translate("HotPushPageItem", "\344\275\215", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HotPushPageItem: public Ui_HotPushPageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPUSHPAGEITEM_H
