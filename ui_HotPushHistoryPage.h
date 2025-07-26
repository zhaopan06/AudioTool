/********************************************************************************
** Form generated from reading UI file 'HotPushHistoryPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPUSHHISTORYPAGE_H
#define UI_HOTPUSHHISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPushHistoryPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_36;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *closeBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *list;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Attention;
    QPushButton *pushButton_3;

    void setupUi(QDialog *HotPushHistoryPage)
    {
        if (HotPushHistoryPage->objectName().isEmpty())
            HotPushHistoryPage->setObjectName(QString::fromUtf8("HotPushHistoryPage"));
        HotPushHistoryPage->resize(773, 628);
        HotPushHistoryPage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(HotPushHistoryPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(HotPushHistoryPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(32, 0, 6, 16);
        widget_36 = new QWidget(widget);
        widget_36->setObjectName(QString::fromUtf8("widget_36"));
        widget_36->setMinimumSize(QSize(0, 56));
        widget_36->setMaximumSize(QSize(16777215, 56));
        widget_36->setStyleSheet(QString::fromUtf8("QWidget#widget_36 {\n"
"    border-bottom: 1px solid #383B43;\n"
"border-radius: 0px;\n"
"    }"));
        horizontalLayout_22 = new QHBoxLayout(widget_36);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 26, 1);
        label_14 = new QLabel(widget_36);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_22->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_7);

        closeBtn = new QPushButton(widget_36);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(24, 24));
        closeBtn->setMaximumSize(QSize(24, 24));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"border:none;\n"
"}\n"
"QPushButton::hover{\n"
"border:none;\n"
"background:#3E3E3E;\n"
"}\n"
"QPushButton::checked {\n"
"border:none;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout_22->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget_36);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 735, 432));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 16, 0);
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 44));
        widget_2->setMaximumSize(QSize(16777215, 44));
        widget_2->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px 6px 0px 0px;"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);


        verticalLayout_4->addWidget(widget_2);

        list = new QVBoxLayout();
        list->setObjectName(QString::fromUtf8("list"));

        verticalLayout_4->addLayout(list);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        widget_10 = new QWidget(widget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 92));
        widget_10->setMaximumSize(QSize(16777215, 92));
        horizontalLayout_11 = new QHBoxLayout(widget_10);
        horizontalLayout_11->setSpacing(16);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        Attention = new QPushButton(widget_10);
        Attention->setObjectName(QString::fromUtf8("Attention"));
        Attention->setMinimumSize(QSize(125, 44));
        Attention->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 22px;\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"margin-top: -1px;"));
        Attention->setIconSize(QSize(24, 25));

        horizontalLayout_11->addWidget(Attention);

        pushButton_3 = new QPushButton(widget_10);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(125, 44));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: #ED525A;\n"
"border-radius: 22px;\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;\n"
"margin-top: -1px;"));
        pushButton_3->setIconSize(QSize(24, 23));

        horizontalLayout_11->addWidget(pushButton_3);


        verticalLayout_2->addWidget(widget_10);


        verticalLayout->addWidget(widget);


        retranslateUi(HotPushHistoryPage);

        QMetaObject::connectSlotsByName(HotPushHistoryPage);
    } // setupUi

    void retranslateUi(QDialog *HotPushHistoryPage)
    {
        HotPushHistoryPage->setWindowTitle(QCoreApplication::translate("HotPushHistoryPage", "\347\203\255\346\216\250\345\215\241\344\275\277\347\224\250\350\256\260\345\275\225", nullptr));
        label_14->setText(QCoreApplication::translate("HotPushHistoryPage", "\347\203\255\346\216\250\345\215\241\344\275\277\347\224\250\350\256\260\345\275\225", nullptr));
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("HotPushHistoryPage", "\344\275\277\347\224\250\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("HotPushHistoryPage", "\347\203\255\346\216\250\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("HotPushHistoryPage", "\347\203\255\346\216\250\344\275\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("HotPushHistoryPage", "\346\266\210\350\200\227\346\225\260\351\207\217", nullptr));
        Attention->setText(QCoreApplication::translate("HotPushHistoryPage", "\345\217\226\346\266\210", nullptr));
        pushButton_3->setText(QCoreApplication::translate("HotPushHistoryPage", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotPushHistoryPage: public Ui_HotPushHistoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPUSHHISTORYPAGE_H
