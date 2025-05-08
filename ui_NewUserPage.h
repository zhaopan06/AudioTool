/********************************************************************************
** Form generated from reading UI file 'NewUserPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERPAGE_H
#define UI_NEWUSERPAGE_H

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

class Ui_NewUserPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *updateTime;
    QPushButton *updateBtn;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *listLayout;

    void setupUi(QDialog *NewUserPage)
    {
        if (NewUserPage->objectName().isEmpty())
            NewUserPage->setObjectName(QString::fromUtf8("NewUserPage"));
        NewUserPage->resize(773, 836);
        NewUserPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(NewUserPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 50);
        widget_2 = new QWidget(NewUserPage);
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
        verticalLayout_3->setContentsMargins(32, 0, 32, 0);
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

        minBtn = new QPushButton(widget_1);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setMinimumSize(QSize(24, 24));
        minBtn->setMaximumSize(QSize(24, 24));
        minBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        icon.addFile(QString::fromUtf8(":/images/login_min_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon);
        minBtn->setIconSize(QSize(28, 28));

        horizontalLayout_22->addWidget(minBtn);

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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon1);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout_22->addWidget(closeBtn);


        verticalLayout_3->addWidget(widget_1);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 41));
        widget->setMaximumSize(QSize(16777215, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(24);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 19));
        label->setMaximumSize(QSize(16777215, 19));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"font-style: normal;"));

        verticalLayout_2->addWidget(label);

        updateTime = new QLabel(widget);
        updateTime->setObjectName(QString::fromUtf8("updateTime"));
        updateTime->setMinimumSize(QSize(0, 20));
        updateTime->setMaximumSize(QSize(16777215, 20));
        updateTime->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"font-style: normal;"));

        verticalLayout_2->addWidget(updateTime);


        horizontalLayout->addLayout(verticalLayout_2);

        updateBtn = new QPushButton(widget);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        updateBtn->setMinimumSize(QSize(88, 32));
        updateBtn->setStyleSheet(QString::fromUtf8("background: rgba(245,151,255,0.2);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #F597FF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(updateBtn);

        horizontalSpacer = new QSpacerItem(430, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(widget);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("background: rgba(34, 36, 41, 1);\n"
"border:none;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 657));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        listLayout = new QVBoxLayout();
        listLayout->setObjectName(QString::fromUtf8("listLayout"));

        verticalLayout_5->addLayout(listLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout->addWidget(widget_2);


        retranslateUi(NewUserPage);

        QMetaObject::connectSlotsByName(NewUserPage);
    } // setupUi

    void retranslateUi(QDialog *NewUserPage)
    {
        NewUserPage->setWindowTitle(QCoreApplication::translate("NewUserPage", "Dialog", nullptr));
        label_14->setText(QCoreApplication::translate("NewUserPage", "\350\220\214\346\226\260\345\271\277\345\234\272", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("NewUserPage", "\346\233\264\346\226\260\346\227\266\351\227\264", nullptr));
        updateTime->setText(QCoreApplication::translate("NewUserPage", "2025-01-01  00:00:00", nullptr));
        updateBtn->setText(QCoreApplication::translate("NewUserPage", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewUserPage: public Ui_NewUserPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERPAGE_H
