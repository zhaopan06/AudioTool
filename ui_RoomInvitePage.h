/********************************************************************************
** Form generated from reading UI file 'RoomInvitePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMINVITEPAGE_H
#define UI_ROOMINVITEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomInvitePage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *onlineBtn;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *copyBtn;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *RoomInvitePage)
    {
        if (RoomInvitePage->objectName().isEmpty())
            RoomInvitePage->setObjectName(QString::fromUtf8("RoomInvitePage"));
        RoomInvitePage->resize(830, 588);
        RoomInvitePage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(RoomInvitePage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RoomInvitePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(16, 0, 32, 20);
        widget_1 = new QWidget(widget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(0, 56));
        widget_1->setMaximumSize(QSize(16777215, 56));
        widget_1->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 0px;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 0px;\n"
"    border-bottom: 1px solid rgba(255,255,255,0.1);\n"
"}\n"
"\n"
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
        horizontalLayout_30 = new QHBoxLayout(widget_1);
        horizontalLayout_30->setSpacing(24);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(0, 0, 0, 1);
        onlineBtn = new QPushButton(widget_1);
        onlineBtn->setObjectName(QString::fromUtf8("onlineBtn"));
        onlineBtn->setCheckable(true);
        onlineBtn->setChecked(true);

        horizontalLayout_30->addWidget(onlineBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_13);

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

        horizontalLayout_30->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget_1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(16);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 36));
        widget_3->setMaximumSize(QSize(16777215, 36));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;\n"
"padding-left: 13px;\n"
"\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(label);

        copyBtn = new QPushButton(widget_3);
        copyBtn->setObjectName(QString::fromUtf8("copyBtn"));
        copyBtn->setMinimumSize(QSize(88, 36));
        copyBtn->setMaximumSize(QSize(88, 36));
        copyBtn->setStyleSheet(QString::fromUtf8("background: #ED525A;\n"
"border-radius: 18px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: center;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(copyBtn);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(16, 0, 16, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 54));
        widget_5->setMaximumSize(QSize(16777215, 54));
        widget_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 25px;   \n"
"}\n"
"\n"
"QPushButton:checked {\n"
"border-radius: 0px;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #ffffff;\n"
"border-bottom: 2px solid #FFFFFF;\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(40);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget_5);
        buttonGroup = new QButtonGroup(RoomInvitePage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 54));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_5);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 54));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(false);

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addWidget(widget_5);

        listWidget = new QListWidget(widget_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_5->addWidget(listWidget);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(RoomInvitePage);

        QMetaObject::connectSlotsByName(RoomInvitePage);
    } // setupUi

    void retranslateUi(QDialog *RoomInvitePage)
    {
        RoomInvitePage->setWindowTitle(QCoreApplication::translate("RoomInvitePage", "\346\210\277\351\227\264\351\202\200\350\257\267", nullptr));
        onlineBtn->setText(QCoreApplication::translate("RoomInvitePage", "\347\274\226\350\276\221\346\210\277\351\227\264", nullptr));
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("RoomInvitePage", "TextLabel", nullptr));
        copyBtn->setText(QCoreApplication::translate("RoomInvitePage", "\345\244\215\345\210\266\351\223\276\346\216\245", nullptr));
        pushButton->setText(QCoreApplication::translate("RoomInvitePage", "\346\234\200\350\277\221\350\201\212\345\244\251", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RoomInvitePage", "\347\262\211\344\270\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomInvitePage: public Ui_RoomInvitePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMINVITEPAGE_H
