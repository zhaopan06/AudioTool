/********************************************************************************
** Form generated from reading UI file 'ChatPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "click_label.h"

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_13;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_3;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_7;
    QLabel *label_3;
    QLabel *label_5;
    click_label *msgPageBtn;
    QWidget *widget_6;
    QLabel *label_2;
    QLabel *label_4;
    click_label *communicationBtn;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget1;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget2;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidget_3;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QString::fromUtf8("ChatPage"));
        ChatPage->resize(1920, 1147);
        ChatPage->setMinimumSize(QSize(74, 70));
        ChatPage->setStyleSheet(QString::fromUtf8("background: #161616;"));
        verticalLayout = new QVBoxLayout(ChatPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_14 = new QWidget(ChatPage);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(66, 66));
        widget_14->setMaximumSize(QSize(16777215, 66));
        widget_14->setStyleSheet(QString::fromUtf8("background: #222429;"));
        horizontalLayout_13 = new QHBoxLayout(widget_14);
        horizontalLayout_13->setSpacing(32);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(32, -1, 32, -1);
        widget_15 = new QWidget(widget_14);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        widget_15->setMinimumSize(QSize(147, 36));
        widget_15->setMaximumSize(QSize(147, 36));
        horizontalLayout = new QHBoxLayout(widget_15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget_15);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(47, 37));
        label_12->setMaximumSize(QSize(47, 37));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));

        horizontalLayout->addWidget(label_12);

        label_13 = new QLabel(widget_15);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 22px;\n"
"color: #FFFFFF;\n"
"line-height: 30px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(label_13);


        horizontalLayout_13->addWidget(widget_15);

        widget_18 = new QWidget(widget_14);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        widget_18->setMinimumSize(QSize(170, 0));
        widget_18->setMaximumSize(QSize(170, 36));
        widget_18->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"\n"
"border-radius: 18px;"));
        horizontalLayout_12 = new QHBoxLayout(widget_18);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 16, 0);

        horizontalLayout_13->addWidget(widget_18);

        horizontalSpacer_5 = new QSpacerItem(1140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        line_3 = new QFrame(widget_14);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(1, 16));
        line_3->setMaximumSize(QSize(1, 16));
        line_3->setStyleSheet(QString::fromUtf8("background: #383B43;"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line_3);

        widget_16 = new QWidget(widget_14);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        widget_16->setMinimumSize(QSize(72, 0));
        widget_16->setMaximumSize(QSize(72, 16777215));
        horizontalLayout_10 = new QHBoxLayout(widget_16);
        horizontalLayout_10->setSpacing(24);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        minBtn = new QPushButton(widget_16);
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

        horizontalLayout_10->addWidget(minBtn);

        closeBtn = new QPushButton(widget_16);
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

        horizontalLayout_10->addWidget(closeBtn);


        horizontalLayout_13->addWidget(widget_16);


        verticalLayout->addWidget(widget_14);

        widget = new QWidget(ChatPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(74, 0));
        widget_2->setMaximumSize(QSize(74, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(74, 70));
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 11, 24, 25));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\346\266\210\346\201\257\346\262\241\346\234\252\350\257\273.png")));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(22, 38, 28, 20));
        label_5->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color:rgba(255,255,255,1);"));
        msgPageBtn = new click_label(widget_7);
        msgPageBtn->setObjectName(QString::fromUtf8("msgPageBtn"));
        msgPageBtn->setGeometry(QRect(0, 0, 68, 70));
        msgPageBtn->setStyleSheet(QString::fromUtf8("background-color: transparent; "));

        verticalLayout_2->addWidget(widget_7);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(74, 70));
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 11, 24, 25));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\351\200\232\350\256\257\345\275\225\346\234\252\351\200\211.png")));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(16, 40, 50, 14));
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:SimSun;\n"
"font-weight:400;\n"
"color:rgba(102,102,102,1);"));
        communicationBtn = new click_label(widget_6);
        communicationBtn->setObjectName(QString::fromUtf8("communicationBtn"));
        communicationBtn->setGeometry(QRect(0, 0, 68, 70));
        communicationBtn->setStyleSheet(QString::fromUtf8("background-color: transparent; "));

        verticalLayout_2->addWidget(widget_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget_2);

        stackedWidget1 = new QStackedWidget(widget);
        stackedWidget1->setObjectName(QString::fromUtf8("stackedWidget1"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_3 = new QHBoxLayout(page_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(page_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(300, 0));
        widget_3->setMaximumSize(QSize(300, 16777215));
        widget_3->setStyleSheet(QString::fromUtf8("background: #36383B;"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 10);
        listWidget = new QListWidget(widget_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:none;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"	border:none;\n"
"    background:rgba(255,255,255,0);\n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"	border:none;\n"
"    background: rgba(255,255,255,0.1);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"	border:none;\n"
"    background: rgba(255,255,255,0.1);\n"
"    padding:0px;\n"
"    margin:0px;\n"
"    border:0px ;\n"
"}"));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(page_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(16, 16, 16, 16);
        stackedWidget2 = new QStackedWidget(widget_4);
        stackedWidget2->setObjectName(QString::fromUtf8("stackedWidget2"));
        stackedWidget2->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));

        verticalLayout_4->addWidget(stackedWidget2);


        horizontalLayout_3->addWidget(widget_4);

        stackedWidget1->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        horizontalLayout_4 = new QHBoxLayout(page_4);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(page_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(300, 0));
        widget_5->setMaximumSize(QSize(300, 16777215));
        widget_5->setStyleSheet(QString::fromUtf8("QWidget{ background: #36383B;}\n"
"\n"
"QPushButton {\n"
"     border:none;\n"
"text-align: left;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 25px;   \n"
"padding-left: 16px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"   border:none;\n"
"text-align: left;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #ffffff;\n"
"padding-left: 16px;\n"
"background: rgba(255,255,255,0.1);\n"
"}\n"
""));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 10);
        pushButton_3 = new QPushButton(widget_5);
        buttonGroup = new QButtonGroup(ChatPage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 70));
        pushButton_3->setCheckable(true);
        pushButton_3->setChecked(true);

        verticalLayout_5->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_5);
        buttonGroup->addButton(pushButton_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 70));
        pushButton_4->setCheckable(true);

        verticalLayout_5->addWidget(pushButton_4);

        pushButton = new QPushButton(widget_5);
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 70));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);

        verticalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_5);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 70));
        pushButton_2->setCheckable(true);

        verticalLayout_5->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_4->addWidget(widget_5);

        listWidget_3 = new QListWidget(page_4);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:none;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"	border:none;\n"
"    background:rgba(255,255,255,0);\n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"	border:none;\n"
"    background: rgba(255,255,255,0.1);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"	border:none;\n"
"    background: rgba(255,255,255,0.1);\n"
"    padding:0px;\n"
"    margin:0px;\n"
"    border:0px ;\n"
"}"));

        horizontalLayout_4->addWidget(listWidget_3);

        stackedWidget1->addWidget(page_4);

        horizontalLayout_2->addWidget(stackedWidget1);


        verticalLayout->addWidget(widget);


        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QDialog *ChatPage)
    {
        ChatPage->setWindowTitle(QCoreApplication::translate("ChatPage", "Dialog", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("ChatPage", "\350\223\235\344\274\264\350\257\255\351\237\263", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label_3->setText(QString());
        label_5->setText(QCoreApplication::translate("ChatPage", "\346\266\210\346\201\257", nullptr));
        msgPageBtn->setText(QString());
        label_2->setText(QString());
        label_4->setText(QCoreApplication::translate("ChatPage", "\351\200\232\350\256\257\345\275\225", nullptr));
        communicationBtn->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("ChatPage", "\346\210\221\347\232\204\345\205\263\346\263\250", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChatPage", "\346\210\221\347\232\204\347\262\211\344\270\235", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatPage", "\346\210\221\347\232\204\345\245\275\345\217\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatPage", "\350\277\221\346\234\237\350\256\277\345\256\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
