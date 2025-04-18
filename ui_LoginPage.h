/********************************************************************************
** Form generated from reading UI file 'LoginPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QWidget *codeWidgetBtn;
    QHBoxLayout *horizontalLayout_12;
    QLabel *code;
    QLabel *label_11;
    QFrame *line_3;
    QLineEdit *cap_mobile;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *next_page_btn;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QPushButton *Btn;
    QLabel *label_7;
    QPushButton *btn1;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *login_status;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page1;
    QPushButton *back_btn;
    click_label *back_label;
    QPushButton *login_btn;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QPushButton *help_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;
    QPushButton *minBtn;
    QPushButton *help_Btn_1;

    void setupUi(QDialog *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->resize(1280, 720);
        horizontalLayout = new QHBoxLayout(LoginPage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(LoginPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(108, 157, 435, 383));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/bg_dianshi.png")));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 12180, 720));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/bg.png")));
        stackedWidget_2 = new QStackedWidget(widget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(688, 62, 432, 593));
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("QWidget#page\n"
"{\n"
"	background: rgba(255,255,255,0.1);\n"
"border-radius: 10px;\n"
"border: 1px solid rgba(255,255,255,0.2);\n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(326, 10, 96, 96));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\344\272\214\347\273\264\347\240\201.png")));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(35, 84, 262, 38));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;\n"
"line-height: 38px;\n"
"text-align: left;\n"
"font-style: normal;\n"
"\n"
""));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(35, 158, 56, 26));
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"color: #7B5AE4;\n"
"line-height: 26px;\n"
"text-align: left;\n"
"font-style: normal;\n"
""));
        widget_6 = new QWidget(page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(36, 200, 360, 48));
        widget_6->setMinimumSize(QSize(360, 48));
        widget_6->setMaximumSize(QSize(360, 48));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget#widget_6\n"
"{\n"
"	background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(15, 1, 10, 1);
        codeWidgetBtn = new QWidget(widget_6);
        codeWidgetBtn->setObjectName(QString::fromUtf8("codeWidgetBtn"));
        codeWidgetBtn->setMinimumSize(QSize(70, 0));
        horizontalLayout_12 = new QHBoxLayout(codeWidgetBtn);
        horizontalLayout_12->setSpacing(8);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        code = new QLabel(codeWidgetBtn);
        code->setObjectName(QString::fromUtf8("code"));
        code->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"\n"
"color: #FFFFFF;\n"
"line-height: 26px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_12->addWidget(code);

        label_11 = new QLabel(codeWidgetBtn);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(22, 22));
        label_11->setMaximumSize(QSize(22, 22));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\344\270\213\346\213\211.png")));

        horizontalLayout_12->addWidget(label_11);


        horizontalLayout_5->addWidget(codeWidgetBtn);

        line_3 = new QFrame(widget_6);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(2, 0));
        line_3->setMaximumSize(QSize(2, 18));
        line_3->setStyleSheet(QString::fromUtf8("border: 2px solid rgba(255,255,255,0.1);\n"
"background-color: rgba(255,255,255,0.1);"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_3);

        cap_mobile = new QLineEdit(widget_6);
        cap_mobile->setObjectName(QString::fromUtf8("cap_mobile"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cap_mobile->sizePolicy().hasHeightForWidth());
        cap_mobile->setSizePolicy(sizePolicy);
        cap_mobile->setStyleSheet(QString::fromUtf8("  font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"  font-size: 18px;\n"
"color: #FFFFFF;\n"
" background: rgba(0,0,0,0);\n"
"\n"
" border:0px;\n"
"\n"
""));

        horizontalLayout_5->addWidget(cap_mobile);

        widget_2 = new QWidget(widget_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border:none;"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_5->addWidget(widget_2);

        next_page_btn = new QPushButton(page);
        next_page_btn->setObjectName(QString::fromUtf8("next_page_btn"));
        next_page_btn->setGeometry(QRect(36, 264, 360, 48));
        next_page_btn->setStyleSheet(QString::fromUtf8("background: #7B5AE4;\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 26px;\n"
"text-align: center;\n"
"font-style: normal;"));
        widget_7 = new QWidget(page);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(36, 348, 388, 22));
        widget_7->setMinimumSize(QSize(0, 22));
        widget_7->setMaximumSize(QSize(16777215, 22));
        widget_7->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"background-color: transparent; "));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget_7);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";	\n"
"font-size:14px;\n"
"color: rgba(255,255,255,0.6);\n"
"}\n"
"\n"
"QRadioButton::indicator { \n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {     \n"
"    image: url(:/images/login_check_n.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked { \n"
"    image: url(:/images/login_check_c.png);\n"
"}\n"
""));
        radioButton->setCheckable(true);
        radioButton->setChecked(true);

        horizontalLayout_3->addWidget(radioButton);

        Btn = new QPushButton(widget_7);
        Btn->setObjectName(QString::fromUtf8("Btn"));
        Btn->setStyleSheet(QString::fromUtf8("color:rgba(228, 90, 126, 1);\n"
"background-color: transparent; \n"
"border:none;"));

        horizontalLayout_3->addWidget(Btn);

        label_7 = new QLabel(widget_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgba(255,255,255,0.45);"));

        horizontalLayout_3->addWidget(label_7);

        btn1 = new QPushButton(widget_7);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setStyleSheet(QString::fromUtf8("color:rgba(228, 90, 126, 1);\n"
"background-color: transparent; \n"
"border:none;"));

        horizontalLayout_3->addWidget(btn1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        widget_8 = new QWidget(page);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(36, 386, 388, 22));
        widget_8->setMinimumSize(QSize(0, 22));
        widget_8->setMaximumSize(QSize(16777215, 22));
        widget_8->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"background-color: transparent; "));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        login_status = new QRadioButton(widget_8);
        login_status->setObjectName(QString::fromUtf8("login_status"));
        login_status->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";	\n"
"font-size:14px;\n"
"color: rgba(255,255,255,0.6);\n"
"}\n"
"\n"
"QRadioButton::indicator { \n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {\n"
"     \n"
"    image: url(:/images/login_check_n.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked { \n"
"    image: url(:/images/login_check_c.png);\n"
"}\n"
""));
        login_status->setCheckable(true);
        login_status->setChecked(true);

        horizontalLayout_4->addWidget(login_status);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        stackedWidget_2->addWidget(page);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        page1->setStyleSheet(QString::fromUtf8("QWidget#page1\n"
"{\n"
"	background: rgba(255,255,255,0.1);\n"
"border-radius: 10px;\n"
"border: 1px solid rgba(255,255,255,0.2);\n"
"}"));
        back_btn = new QPushButton(page1);
        back_btn->setObjectName(QString::fromUtf8("back_btn"));
        back_btn->setGeometry(QRect(36, 34, 22, 22));
        back_btn->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/login_back_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_btn->setIcon(icon);
        back_btn->setIconSize(QSize(22, 22));
        back_label = new click_label(page1);
        back_label->setObjectName(QString::fromUtf8("back_label"));
        back_label->setGeometry(QRect(65, 32, 38, 26));
        back_label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 26px;\n"
"text-align: left;\n"
"font-style: normal;"));
        login_btn = new QPushButton(page1);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));
        login_btn->setEnabled(false);
        login_btn->setGeometry(QRect(38, 491, 360, 48));
        login_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: #7B5AE4;\n"
"border-radius: 8px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"background: rgba(255,255,255,0.2);\n"
"border-radius: 8px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 18px;\n"
"color: rgba(255,255,255,0.5);\n"
" }"));
        label_8 = new QLabel(page1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(36, 84, 210, 38));
        label_8->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;\n"
"line-height: 38px;\n"
"text-align: left;\n"
"font-style: normal;"));
        lineEdit = new QLineEdit(page1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(36, 210, 48, 48));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(page1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(98, 210, 48, 48));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(page1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 210, 48, 48));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(page1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(222, 210, 48, 48));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(page1);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(284, 210, 48, 48));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_6 = new QLineEdit(page1);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(346, 210, 48, 48));
        lineEdit_6->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0.2);\n"
"border-radius: 8px;\n"
"border: 1px solid #7B5AE4;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 26px;\n"
"color: #FFFFFF;"));
        lineEdit_6->setAlignment(Qt::AlignCenter);
        widget_3 = new QWidget(page1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(36, 130, 362, 44));
        widget_3->setMinimumSize(QSize(362, 44));
        widget_3->setMaximumSize(QSize(362, 44));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 7, -1);
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: rgba(255,255,255,0.5);"));

        horizontalLayout_2->addWidget(label_6);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: rgba(255, 255, 255, 1);"));

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: rgba(255,255,255,0.5);"));

        horizontalLayout_2->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: rgba(255,255,255,0.5);"));

        horizontalLayout_6->addWidget(label_12);

        help_btn = new QPushButton(widget_3);
        help_btn->setObjectName(QString::fromUtf8("help_btn"));
        help_btn->setLayoutDirection(Qt::LeftToRight);
        help_btn->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: rgba(228, 90, 126, 1);\n"
"border:none;"));

        horizontalLayout_6->addWidget(help_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);

        stackedWidget_2->addWidget(page1);
        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(1228, 5, 28, 28));
        closeBtn->setMinimumSize(QSize(28, 28));
        closeBtn->setMaximumSize(QSize(28, 28));
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
        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setGeometry(QRect(1184, 5, 28, 28));
        minBtn->setMinimumSize(QSize(28, 28));
        minBtn->setMaximumSize(QSize(28, 28));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/login_min_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon2);
        minBtn->setIconSize(QSize(28, 28));
        help_Btn_1 = new QPushButton(widget);
        help_Btn_1->setObjectName(QString::fromUtf8("help_Btn_1"));
        help_Btn_1->setGeometry(QRect(50, 676, 59, 23));
        help_Btn_1->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: rgba(255,255,255,0.6);\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/login_hlep_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        help_Btn_1->setIcon(icon3);
        help_Btn_1->setIconSize(QSize(18, 19));
        label_2->raise();
        label->raise();
        stackedWidget_2->raise();
        closeBtn->raise();
        minBtn->raise();
        help_Btn_1->raise();

        horizontalLayout->addWidget(widget);


        retranslateUi(LoginPage);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QDialog *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("LoginPage", "\346\254\242\350\277\216\344\275\277\347\224\250\350\223\235\344\274\264\350\257\255\351\237\263\344\274\264\344\276\243", nullptr));
        label_5->setText(QCoreApplication::translate("LoginPage", "\346\211\213\346\234\272\345\217\267", nullptr));
        code->setText(QCoreApplication::translate("LoginPage", "+86", nullptr));
        label_11->setText(QString());
        cap_mobile->setText(QCoreApplication::translate("LoginPage", "13333333333", nullptr));
        cap_mobile->setPlaceholderText(QCoreApplication::translate("LoginPage", "\346\211\213\346\234\272\345\217\267", nullptr));
        next_page_btn->setText(QCoreApplication::translate("LoginPage", "\344\270\213\344\270\200\346\255\245", nullptr));
        radioButton->setText(QCoreApplication::translate("LoginPage", "\347\231\273\345\275\225\345\215\263\345\220\214\346\204\217", nullptr));
        Btn->setText(QCoreApplication::translate("LoginPage", "\343\200\212\347\224\250\346\210\267\346\234\215\345\212\241\345\215\217\350\256\256\343\200\213", nullptr));
        label_7->setText(QCoreApplication::translate("LoginPage", "\345\222\214", nullptr));
        btn1->setText(QCoreApplication::translate("LoginPage", "\343\200\212\351\232\220\347\247\201\345\215\217\350\256\256\343\200\213", nullptr));
        login_status->setText(QCoreApplication::translate("LoginPage", "\350\256\260\345\275\225\346\210\221\347\232\204\347\231\273\345\275\225\347\212\266\346\200\201", nullptr));
        back_btn->setText(QString());
        back_label->setText(QCoreApplication::translate("LoginPage", "\350\277\224\345\233\236", nullptr));
        login_btn->setText(QCoreApplication::translate("LoginPage", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_8->setText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\351\252\214\350\257\201\347\240\201", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        lineEdit_6->setText(QString());
        label_6->setText(QCoreApplication::translate("LoginPage", "\350\257\267\350\276\223\345\205\245\345\217\221\351\200\201 ", nullptr));
        label_9->setText(QCoreApplication::translate("LoginPage", "+86131***03", nullptr));
        label_10->setText(QCoreApplication::translate("LoginPage", " \347\232\2046\344\275\215\351\252\214\350\257\201\347\240\201\357\274\21410\345\210\206\351\222\237\345\206\205\346\234\211\346\225\210\343\200\202", nullptr));
        label_12->setText(QCoreApplication::translate("LoginPage", "\345\246\202\346\234\252\346\224\266\345\210\260\357\274\214\350\257\267\351\207\215\346\226\260\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201\346\210\226 ", nullptr));
        help_btn->setText(QCoreApplication::translate("LoginPage", "\350\216\267\345\217\226\345\270\256\345\212\251", nullptr));
        closeBtn->setText(QString());
        minBtn->setText(QString());
        help_Btn_1->setText(QCoreApplication::translate("LoginPage", " \345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
