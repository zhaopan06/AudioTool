/********************************************************************************
** Form generated from reading UI file 'UserinfoPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGE_H
#define UI_USERINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserinfoPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_45;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *onlineBtn;
    QPushButton *squareBtn;
    QPushButton *contributeBtn;
    QSpacerItem *horizontalSpacer_13;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_2;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QWidget *widget_5;
    QWidget *widget_6;
    QWidget *widget_7;
    QWidget *widget_8;
    QWidget *widget_9;
    QWidget *widget_10;
    QWidget *page_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *UserinfoPage)
    {
        if (UserinfoPage->objectName().isEmpty())
            UserinfoPage->setObjectName(QString::fromUtf8("UserinfoPage"));
        UserinfoPage->resize(464, 814);
        verticalLayout = new QVBoxLayout(UserinfoPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UserinfoPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 24px 24px 12px 12px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        widget_45 = new QWidget(widget);
        widget_45->setObjectName(QString::fromUtf8("widget_45"));
        widget_45->setMinimumSize(QSize(0, 56));
        widget_45->setMaximumSize(QSize(16777215, 56));
        widget_45->setStyleSheet(QString::fromUtf8("QWidget#widget_45{\n"
"    border-bottom: 1px solid #383B43;\n"
"\n"
"    }\n"
"\n"
"QPushButton {\n"
"     border:none;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
"QPushButton:checked {\n"
"   border:none;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #ffffff;\n"
"line-height: 25px;   \n"
"}\n"
"\n"
""));
        horizontalLayout_30 = new QHBoxLayout(widget_45);
        horizontalLayout_30->setSpacing(24);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(16, 0, 16, 1);
        onlineBtn = new QPushButton(widget_45);
        buttonGroup = new QButtonGroup(UserinfoPage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(onlineBtn);
        onlineBtn->setObjectName(QString::fromUtf8("onlineBtn"));
        onlineBtn->setCheckable(true);
        onlineBtn->setChecked(true);

        horizontalLayout_30->addWidget(onlineBtn);

        squareBtn = new QPushButton(widget_45);
        buttonGroup->addButton(squareBtn);
        squareBtn->setObjectName(QString::fromUtf8("squareBtn"));
        squareBtn->setCheckable(true);

        horizontalLayout_30->addWidget(squareBtn);

        contributeBtn = new QPushButton(widget_45);
        buttonGroup->addButton(contributeBtn);
        contributeBtn->setObjectName(QString::fromUtf8("contributeBtn"));
        contributeBtn->setCheckable(true);

        horizontalLayout_30->addWidget(contributeBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_13);


        verticalLayout_2->addWidget(widget_45);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 464, 288));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(16, 214, 100, 100));
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 264, 464, 494));
        widget_3->setMinimumSize(QSize(464, 494));
        widget_3->setStyleSheet(QString::fromUtf8("background: #ffffff;\n"
"border-radius: 24px 24px 12px 12px;"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(16, 65, 16, 20);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 55));
        widget_4->setMaximumSize(QSize(16777215, 55));

        verticalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 31));
        widget_5->setMaximumSize(QSize(16777215, 31));

        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 24));
        widget_6->setMaximumSize(QSize(16777215, 24));

        verticalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 20));
        widget_7->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(widget_7);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 20));
        widget_8->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(widget_8);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(0, 100));
        widget_9->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(widget_9);

        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 100));
        widget_10->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(widget_10);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget);


        retranslateUi(UserinfoPage);

        QMetaObject::connectSlotsByName(UserinfoPage);
    } // setupUi

    void retranslateUi(QDialog *UserinfoPage)
    {
        UserinfoPage->setWindowTitle(QCoreApplication::translate("UserinfoPage", "Dialog", nullptr));
        onlineBtn->setText(QCoreApplication::translate("UserinfoPage", "\350\257\246\347\273\206\350\265\204\346\226\231", nullptr));
        squareBtn->setText(QCoreApplication::translate("UserinfoPage", "\347\244\274\347\211\251\345\242\231", nullptr));
        contributeBtn->setText(QCoreApplication::translate("UserinfoPage", "\345\213\213\347\253\240", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserinfoPage: public Ui_UserinfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGE_H
