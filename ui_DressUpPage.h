/********************************************************************************
** Form generated from reading UI file 'DressUpPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRESSUPPAGE_H
#define UI_DRESSUPPAGE_H

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

class Ui_DressUpPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *closeBtn;
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *listLayout;

    void setupUi(QDialog *DressUpPage)
    {
        if (DressUpPage->objectName().isEmpty())
            DressUpPage->setObjectName(QString::fromUtf8("DressUpPage"));
        DressUpPage->resize(552, 1052);
        DressUpPage->setStyleSheet(QString::fromUtf8("background: #D8D8D8 #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(DressUpPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(DressUpPage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2{\n"
"background: rgba(34, 36, 41, 1);\n"
"border-radius: 12px;\n"
"}\n"
"\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(16);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(32, 0, 32, 16);
        widget_1 = new QWidget(widget_2);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(0, 56));
        widget_1->setMaximumSize(QSize(16777215, 56));
        widget_1->setStyleSheet(QString::fromUtf8("QWidget#widget_36 {\n"
"    border-bottom: 1px solid #383B43;\n"
"border-radius: 0px;\n"
"    }"));
        horizontalLayout_22 = new QHBoxLayout(widget_1);
        horizontalLayout_22->setSpacing(16);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 1);
        label_14 = new QLabel(widget_1);
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

        closeBtn = new QPushButton(widget_1);
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


        verticalLayout_3->addWidget(widget_1);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 387));
        widget->setMaximumSize(QSize(16777215, 387));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(132, 28, 224, 332));
        label->setMinimumSize(QSize(224, 332));
        label->setMaximumSize(QSize(224, 332));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 312, 108, 32));
        pushButton->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.3);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;"));

        verticalLayout_3->addWidget(widget);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 56));
        widget_4->setStyleSheet(QString::fromUtf8("background: #FFFFFF;\n"
"border-radius: 24px;"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 24);
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 56));

        verticalLayout_2->addWidget(widget_3);

        scrollArea = new QScrollArea(widget_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 488, 481));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 16, 0, 0);
        listLayout = new QVBoxLayout();
        listLayout->setObjectName(QString::fromUtf8("listLayout"));

        verticalLayout_5->addLayout(listLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout->addWidget(widget_2);


        retranslateUi(DressUpPage);

        QMetaObject::connectSlotsByName(DressUpPage);
    } // setupUi

    void retranslateUi(QDialog *DressUpPage)
    {
        DressUpPage->setWindowTitle(QCoreApplication::translate("DressUpPage", "\350\220\214\346\226\260\345\271\277\345\234\272", nullptr));
        label_14->setText(QCoreApplication::translate("DressUpPage", "\350\220\214\346\226\260\345\271\277\345\234\272", nullptr));
        closeBtn->setText(QString());
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("DressUpPage", "\347\202\271\345\207\273\346\224\276\345\244\247\351\242\204\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DressUpPage: public Ui_DressUpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRESSUPPAGE_H
