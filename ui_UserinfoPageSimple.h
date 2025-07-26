/********************************************************************************
** Form generated from reading UI file 'UserinfoPageSimple.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGESIMPLE_H
#define UI_USERINFOPAGESIMPLE_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "click_label.h"

QT_BEGIN_NAMESPACE

class Ui_UserinfoPageSimple
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    click_label *big_image;
    CRoundLabel *image;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QPushButton *age;
    QLabel *userLevel;
    QLabel *constellation;
    QSpacerItem *horizontalSpacer;
    QLabel *isOnline;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userId;
    QLabel *label_5;
    QLabel *location;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_13;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_10;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *fansNum;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *playDayNum;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_19;
    QSpacerItem *verticalSpacer;
    QWidget *widget_15;
    QVBoxLayout *verticalLayout_6;
    QLabel *intro;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_46;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *sendBtn;
    QPushButton *receiveBtn;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_8;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *gridLayout;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_3;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_5;
    QPushButton *Attention;
    QPushButton *pushButton_3;

    void setupUi(QDialog *UserinfoPageSimple)
    {
        if (UserinfoPageSimple->objectName().isEmpty())
            UserinfoPageSimple->setObjectName(QString::fromUtf8("UserinfoPageSimple"));
        UserinfoPageSimple->resize(464, 726);
        verticalLayout = new QVBoxLayout(UserinfoPageSimple);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UserinfoPageSimple);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-radius: 24px 24px 12px 12px;\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 464, 288));
        widget_2->setMinimumSize(QSize(432, 288));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        big_image = new click_label(widget_2);
        big_image->setObjectName(QString::fromUtf8("big_image"));
        big_image->setScaledContents(false);

        verticalLayout_7->addWidget(big_image);

        image = new CRoundLabel(page);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(16, 214, 100, 100));
        image->setStyleSheet(QString::fromUtf8("background: transparent;"));
        image->setScaledContents(true);
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 264, 464, 362));
        widget_3->setMinimumSize(QSize(432, 362));
        widget_3->setMaximumSize(QSize(16777215, 362));
        widget_3->setStyleSheet(QString::fromUtf8("border-radius: 24px 24px 12px 12px;"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(16, 65, 16, 20);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 55));
        widget_4->setMaximumSize(QSize(16777215, 55));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_11 = new QWidget(widget_4);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMinimumSize(QSize(0, 28));
        widget_11->setMaximumSize(QSize(16777215, 28));
        horizontalLayout = new QHBoxLayout(widget_11);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget_11);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"color: #FFFFFF;"));

        horizontalLayout->addWidget(name);

        age = new QPushButton(widget_11);
        age->setObjectName(QString::fromUtf8("age"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(age->sizePolicy().hasHeightForWidth());
        age->setSizePolicy(sizePolicy);
        age->setMinimumSize(QSize(38, 16));
        age->setMaximumSize(QSize(38, 16));
        age->setFont(font);
        age->setStyleSheet(QString::fromUtf8("background: rgba(128, 220, 255, 0.2);\n"
"border-radius: 8px;\n"
"font-size: 11px;\n"
"color: #FFFFFF;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/live_people_man.png"), QSize(), QIcon::Normal, QIcon::Off);
        age->setIcon(icon);
        age->setIconSize(QSize(12, 13));

        horizontalLayout->addWidget(age);

        userLevel = new QLabel(widget_11);
        userLevel->setObjectName(QString::fromUtf8("userLevel"));
        userLevel->setMinimumSize(QSize(37, 16));
        userLevel->setMaximumSize(QSize(37, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(false);
        font1.setItalic(false);
        userLevel->setFont(font1);
        userLevel->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 10px;\n"
"color: #FFFFFF;\n"
"text-align: right;\n"
"font-style: normal;\n"
"\n"
"background-image: url(:/images/live_lev.png);\n"
"background-position: center;\n"
"padding-right: 6px; \n"
" text-align: right;"));
        userLevel->setPixmap(QPixmap(QString::fromUtf8(":/images/live_lev.png")));
        userLevel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(userLevel);

        constellation = new QLabel(widget_11);
        constellation->setObjectName(QString::fromUtf8("constellation"));
        constellation->setMinimumSize(QSize(46, 20));
        constellation->setMaximumSize(QSize(46, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        constellation->setFont(font2);
        constellation->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 10px;\n"
"color: #FFFFFF;\n"
""));
        constellation->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(constellation);

        horizontalSpacer = new QSpacerItem(184, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        isOnline = new QLabel(widget_11);
        isOnline->setObjectName(QString::fromUtf8("isOnline"));
        isOnline->setMinimumSize(QSize(44, 28));
        isOnline->setMaximumSize(QSize(44, 28));
        isOnline->setFont(font);
        isOnline->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 14px;\n"
"color: #FFFFFF;\n"
"font-size: 14px;\n"
"margin-top: -1px;"));
        isOnline->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(isOnline);


        verticalLayout_4->addWidget(widget_11);

        widget_12 = new QWidget(widget_4);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_2 = new QHBoxLayout(widget_12);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        userId = new QLabel(widget_12);
        userId->setObjectName(QString::fromUtf8("userId"));
        userId->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #A8A8A7;"));

        horizontalLayout_2->addWidget(userId);

        label_5 = new QLabel(widget_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16, 16));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/copy_n.png")));
        label_5->setScaledContents(true);

        horizontalLayout_2->addWidget(label_5);

        location = new QLabel(widget_12);
        location->setObjectName(QString::fromUtf8("location"));
        location->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #A8A8A7;\n"
"text-align: left;"));

        horizontalLayout_2->addWidget(location);

        horizontalSpacer_2 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget_12);


        verticalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 31));
        widget_5->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_13 = new QWidget(widget_5);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMinimumSize(QSize(28, 31));
        widget_13->setMaximumSize(QSize(28, 31));
        label_7 = new QLabel(widget_13);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 28, 31));
        label_7->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\345\205\254\344\274\232.png")));
        label_8 = new QLabel(widget_13);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(14, 0, 14, 31));
        label_8->setStyleSheet(QString::fromUtf8("background: #DCD2FA;"));
        label_8->raise();
        label_7->raise();

        horizontalLayout_3->addWidget(widget_13);

        widget_14 = new QWidget(widget_5);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(100, 0));
        widget_14->setStyleSheet(QString::fromUtf8("background: #DCD2FA;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 14px;\n"
"border-bottom-right-radius: 14px;\n"
"border-bottom-left-radius: 0px;"));
        horizontalLayout_4 = new QHBoxLayout(widget_14);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 2, 1);
        label_9 = new QLabel(widget_14);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-size: 12px;\n"
"color: #222429;\n"
"line-height: 17px;\n"
"text-align: left;"));

        horizontalLayout_4->addWidget(label_9);

        line = new QFrame(widget_14);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(1, 0));
        line->setMaximumSize(QSize(1, 14));
        line->setStyleSheet(QString::fromUtf8("background: rgba(163, 176, 212, 1);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        label_10 = new QLabel(widget_14);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("font-size: 12px;\n"
"color: #222429;\n"
"text-align: left;"));

        horizontalLayout_4->addWidget(label_10);

        pushButton = new QPushButton(widget_14);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(17, 17));
        pushButton->setMaximumSize(QSize(17, 17));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icon_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(17, 17));

        horizontalLayout_4->addWidget(pushButton);


        horizontalLayout_3->addWidget(widget_14);

        horizontalSpacer_3 = new QSpacerItem(202, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 24));
        widget_6->setMaximumSize(QSize(16777215, 24));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(16);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 0, -1);
        fansNum = new QLabel(widget_6);
        fansNum->setObjectName(QString::fromUtf8("fansNum"));
        fansNum->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"color: #FFFFFF;"));

        horizontalLayout_6->addWidget(fansNum);

        label_11 = new QLabel(widget_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgba(168, 168, 167, 1);\n"
"font-size: 14px;\n"
"margin-top: -1px;"));

        horizontalLayout_6->addWidget(label_11);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        playDayNum = new QLabel(widget_6);
        playDayNum->setObjectName(QString::fromUtf8("playDayNum"));
        playDayNum->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"color: #FFFFFF;"));

        horizontalLayout_7->addWidget(playDayNum);

        label_16 = new QLabel(widget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("color: rgba(168, 168, 167, 1);\n"
"font-size: 14px;\n"
"margin-top: -1px;"));

        horizontalLayout_7->addWidget(label_16);


        horizontalLayout_5->addLayout(horizontalLayout_7);

        horizontalSpacer_4 = new QSpacerItem(277, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 20));
        widget_7->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_8 = new QHBoxLayout(widget_7);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #FFFFFF;\n"
"margin-top: -1px;"));

        horizontalLayout_8->addWidget(label_12);

        label_14 = new QLabel(widget_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(65, 18));
        label_14->setMaximumSize(QSize(65, 18));
        label_14->setScaledContents(false);

        horizontalLayout_8->addWidget(label_14);

        horizontalSpacer_5 = new QSpacerItem(324, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_7);

        widget_9 = new QWidget(widget_3);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(0, 100));
        widget_9->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_10 = new QHBoxLayout(widget_9);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_19 = new QLabel(widget_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #FFFFFF;"));

        verticalLayout_5->addWidget(label_19);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_10->addLayout(verticalLayout_5);

        widget_15 = new QWidget(widget_9);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        widget_15->setMinimumSize(QSize(360, 100));
        widget_15->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 6px;"));
        verticalLayout_6 = new QVBoxLayout(widget_15);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(12, 8, 12, 8);
        intro = new QLabel(widget_15);
        intro->setObjectName(QString::fromUtf8("intro"));
        intro->setStyleSheet(QString::fromUtf8("font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));
        intro->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        intro->setWordWrap(true);

        verticalLayout_6->addWidget(intro);


        horizontalLayout_10->addWidget(widget_15);


        verticalLayout_3->addWidget(widget_9);

        stackedWidget->addWidget(page);
        widget_2->raise();
        widget_3->raise();
        image->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_8 = new QVBoxLayout(page_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(16, 0, 6, 0);
        widget_46 = new QWidget(page_2);
        widget_46->setObjectName(QString::fromUtf8("widget_46"));
        widget_46->setMinimumSize(QSize(0, 55));
        widget_46->setMaximumSize(QSize(16777215, 55));
        widget_46->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        horizontalLayout_31 = new QHBoxLayout(widget_46);
        horizontalLayout_31->setSpacing(24);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 10, 1);
        sendBtn = new QPushButton(widget_46);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setCheckable(true);
        sendBtn->setChecked(true);

        horizontalLayout_31->addWidget(sendBtn);

        receiveBtn = new QPushButton(widget_46);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setCheckable(true);

        horizontalLayout_31->addWidget(receiveBtn);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_14);

        widget_17 = new QWidget(widget_46);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        widget_17->setMinimumSize(QSize(120, 28));
        widget_17->setMaximumSize(QSize(120, 28));
        widget_17->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: rgba(255, 255, 255, 0.2);\n"
"border-radius: 14px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        horizontalLayout_12 = new QHBoxLayout(widget_17);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget_17);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 28));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"border:none;\n"
"background: transparent;\n"
"border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border:none;\n"
"border-radius: 14px;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"color: #ffffff;\n"
"}"));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(true);

        horizontalLayout_12->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(widget_17);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 28));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"border:none;\n"
"background: transparent;\n"
"border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border:none;\n"
"border-radius: 14px;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"color: #ffffff;\n"
"}"));
        pushButton_4->setCheckable(true);

        horizontalLayout_12->addWidget(pushButton_4);


        horizontalLayout_31->addWidget(widget_17);


        verticalLayout_8->addWidget(widget_46);

        widget_16 = new QWidget(page_2);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        widget_16->setMinimumSize(QSize(0, 22));
        widget_16->setMaximumSize(QSize(16777215, 22));
        horizontalLayout_13 = new QHBoxLayout(widget_16);
        horizontalLayout_13->setSpacing(3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 20, 2);
        label = new QLabel(widget_16);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 20px;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout_13->addWidget(label);

        label_2 = new QLabel(widget_16);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #ED525A;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        horizontalLayout_13->addWidget(label_2);

        label_3 = new QLabel(widget_16);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 20px;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout_13->addWidget(label_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);


        verticalLayout_8->addWidget(widget_16);

        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 100, 30));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 12, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(12);

        verticalLayout_9->addLayout(gridLayout);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_8->addWidget(scrollArea_2);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_11 = new QVBoxLayout(page_3);
        verticalLayout_11->setSpacing(12);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(16, 18, 6, 0);
        widget_18 = new QWidget(page_3);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        widget_18->setMinimumSize(QSize(0, 22));
        widget_18->setMaximumSize(QSize(16777215, 22));
        horizontalLayout_14 = new QHBoxLayout(widget_18);
        horizontalLayout_14->setSpacing(3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 20, 2);
        label_6 = new QLabel(widget_18);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 20px;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout_14->addWidget(label_6);

        label_13 = new QLabel(widget_18);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #ED525A;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        horizontalLayout_14->addWidget(label_13);

        label_15 = new QLabel(widget_18);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 20px;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout_14->addWidget(label_15);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);


        verticalLayout_11->addWidget(widget_18);

        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 100, 30));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(10);
        gridLayout_3->setVerticalSpacing(12);

        verticalLayout_12->addLayout(gridLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_11->addWidget(scrollArea);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        widget_10 = new QWidget(widget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 80));
        widget_10->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_11 = new QHBoxLayout(widget_10);
        horizontalLayout_11->setSpacing(16);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(16, 0, 16, 0);
        horizontalSpacer_7 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        pushButton_5 = new QPushButton(widget_10);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(125, 44));
        pushButton_5->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 22px;\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"margin-top: -1px;"));

        horizontalLayout_11->addWidget(pushButton_5);

        Attention = new QPushButton(widget_10);
        Attention->setObjectName(QString::fromUtf8("Attention"));
        Attention->setMinimumSize(QSize(125, 44));
        Attention->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 22px;\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"margin-top: -1px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icon_\345\217\226\346\266\210\345\205\263\346\263\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        Attention->setIcon(icon2);
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/HI.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(24, 23));

        horizontalLayout_11->addWidget(pushButton_3);


        verticalLayout_2->addWidget(widget_10);


        verticalLayout->addWidget(widget);


        retranslateUi(UserinfoPageSimple);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserinfoPageSimple);
    } // setupUi

    void retranslateUi(QDialog *UserinfoPageSimple)
    {
        UserinfoPageSimple->setWindowTitle(QCoreApplication::translate("UserinfoPageSimple", "\347\224\250\346\210\267\350\265\204\346\226\231", nullptr));
        big_image->setText(QString());
        image->setText(QString());
        name->setText(QCoreApplication::translate("UserinfoPageSimple", "Rx. \345\207\214\344\271\261", nullptr));
        age->setText(QCoreApplication::translate("UserinfoPageSimple", "8", nullptr));
        userLevel->setText(QString());
        constellation->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\244\204\345\245\263\345\272\247", nullptr));
        isOnline->setText(QCoreApplication::translate("UserinfoPageSimple", "\347\246\273\347\272\277", nullptr));
        userId->setText(QCoreApplication::translate("UserinfoPageSimple", "ID\357\274\2322010590", nullptr));
        label_5->setText(QString());
        location->setText(QCoreApplication::translate("UserinfoPageSimple", "\350\264\265\345\267\236\347\234\201\302\267\350\264\265\351\230\263\345\270\202", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("UserinfoPageSimple", "9\345\244\234\345\267\264\351\273\216\351\223\201\345\241\224 \302\267 \346\210\220\345\221\230 ", nullptr));
        label_10->setText(QCoreApplication::translate("UserinfoPageSimple", "\346\237\245\347\234\213\345\205\254\344\274\232", nullptr));
        pushButton->setText(QString());
        fansNum->setText(QCoreApplication::translate("UserinfoPageSimple", "5", nullptr));
        label_11->setText(QCoreApplication::translate("UserinfoPageSimple", "\347\262\211\344\270\235", nullptr));
        playDayNum->setText(QCoreApplication::translate("UserinfoPageSimple", "5", nullptr));
        label_16->setText(QCoreApplication::translate("UserinfoPageSimple", "\346\270\270\347\216\251\345\244\251\346\225\260", nullptr));
        label_12->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\213\213\347\253\240\357\274\232", nullptr));
        label_14->setText(QString());
        label_19->setText(QCoreApplication::translate("UserinfoPageSimple", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", nullptr));
        intro->setText(QCoreApplication::translate("UserinfoPageSimple", "\350\257\267\345\241\253\345\206\231\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        sendBtn->setText(QCoreApplication::translate("UserinfoPageSimple", "\351\200\201\345\207\272", nullptr));
        receiveBtn->setText(QCoreApplication::translate("UserinfoPageSimple", "\346\224\266\345\210\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\267\262\347\202\271\344\272\256", nullptr));
        pushButton_4->setText(QCoreApplication::translate("UserinfoPageSimple", "\346\234\252\347\202\271\344\272\256", nullptr));
        label->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\205\261\347\202\271\344\272\256", nullptr));
        label_2->setText(QCoreApplication::translate("UserinfoPageSimple", "0", nullptr));
        label_3->setText(QCoreApplication::translate("UserinfoPageSimple", "\344\270\252\347\244\274\347\211\251", nullptr));
        label_6->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\205\261\347\202\271\344\272\256", nullptr));
        label_13->setText(QCoreApplication::translate("UserinfoPageSimple", "262", nullptr));
        label_15->setText(QCoreApplication::translate("UserinfoPageSimple", "\344\270\252\345\213\213\347\253\240", nullptr));
        pushButton_5->setText(QCoreApplication::translate("UserinfoPageSimple", "\350\257\246\347\273\206\350\265\204\346\226\231", nullptr));
        Attention->setText(QCoreApplication::translate("UserinfoPageSimple", "\345\217\226\346\266\210\345\205\263\346\263\250", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UserinfoPageSimple", "\346\211\223\346\213\233\345\221\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserinfoPageSimple: public Ui_UserinfoPageSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGESIMPLE_H
