/********************************************************************************
** Form generated from reading UI file 'HotPushPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPUSHPAGE_H
#define UI_HOTPUSHPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPushPage
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
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *myCardNum;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *dateBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Attention;
    QPushButton *pushButton_3;

    void setupUi(QDialog *HotPushPage)
    {
        if (HotPushPage->objectName().isEmpty())
            HotPushPage->setObjectName(QString::fromUtf8("HotPushPage"));
        HotPushPage->resize(773, 629);
        HotPushPage->setStyleSheet(QString::fromUtf8("background: #202227;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(HotPushPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(HotPushPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(32, 0, 6, 0);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 735, 557));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 26, 0);
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(709, 70));
        widget_3->setMaximumSize(QSize(16777215, 70));
        widget_3->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(16, 0, 16, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_3->addWidget(label);

        myCardNum = new QLabel(widget_3);
        myCardNum->setObjectName(QString::fromUtf8("myCardNum"));
        myCardNum->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 22px;\n"
"color: #ED525A;\n"
"line-height: 22px;"));

        horizontalLayout_3->addWidget(myCardNum);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"line-height: 22px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icon_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(19, 18));
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(709, 62));
        widget_4->setMaximumSize(QSize(16777215, 62));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 8, 0, 0);
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_3->addWidget(widget_4);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_5->addLayout(gridLayout);


        verticalLayout_3->addWidget(widget_6);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(709, 62));
        widget_5->setMaximumSize(QSize(16777215, 62));
        widget_5->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 8, 0, 0);
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout->addWidget(label_6);


        verticalLayout_3->addWidget(widget_5);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 70));
        widget_8->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_6 = new QVBoxLayout(widget_8);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateBtn = new QPushButton(widget_8);
        dateBtn->setObjectName(QString::fromUtf8("dateBtn"));
        dateBtn->setMinimumSize(QSize(228, 70));
        dateBtn->setMaximumSize(QSize(228, 70));
        dateBtn->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;\n"
"border: 1px solid #ED525A;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        horizontalLayout_4->addWidget(dateBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(widget_8);

        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 124));
        widget_10->setMaximumSize(QSize(16777215, 124));
        horizontalLayout_11 = new QHBoxLayout(widget_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
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


        verticalLayout_3->addWidget(widget_10);


        verticalLayout_4->addWidget(widget_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget);


        retranslateUi(HotPushPage);

        QMetaObject::connectSlotsByName(HotPushPage);
    } // setupUi

    void retranslateUi(QDialog *HotPushPage)
    {
        HotPushPage->setWindowTitle(QCoreApplication::translate("HotPushPage", "\346\210\277\351\227\264\347\203\255\346\216\250", nullptr));
        label_14->setText(QCoreApplication::translate("HotPushPage", "\347\203\255\346\216\250\345\215\241\347\256\241\347\220\206", nullptr));
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("HotPushPage", "\346\210\221\347\232\204\347\203\255\346\216\250\345\215\241\357\274\232", nullptr));
        myCardNum->setText(QCoreApplication::translate("HotPushPage", "11", nullptr));
        label_3->setText(QCoreApplication::translate("HotPushPage", "\345\274\240", nullptr));
        pushButton->setText(QCoreApplication::translate("HotPushPage", "\344\275\277\347\224\250\350\256\260\345\275\225 ", nullptr));
        label_5->setText(QCoreApplication::translate("HotPushPage", "\347\203\255\346\216\250\344\275\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("HotPushPage", "\347\203\255\346\216\250\346\227\266\351\227\264", nullptr));
        dateBtn->setText(QString());
        Attention->setText(QCoreApplication::translate("HotPushPage", "\345\217\226\346\266\210", nullptr));
        pushButton_3->setText(QCoreApplication::translate("HotPushPage", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotPushPage: public Ui_HotPushPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPUSHPAGE_H
