/********************************************************************************
** Form generated from reading UI file 'UserinfoPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGE_H
#define UI_USERINFOPAGE_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
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
    QPushButton *closeBtn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *big_image;
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
    QLabel *label_4;
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
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_19;
    QSpacerItem *verticalSpacer;
    QWidget *widget_15;
    QVBoxLayout *verticalLayout_6;
    QLabel *intro;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *Attention;
    QPushButton *pushButton_3;
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
"border-radius: 24px 24px 12px 12px;\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        widget_45 = new QWidget(widget);
        widget_45->setObjectName(QString::fromUtf8("widget_45"));
        widget_45->setMinimumSize(QSize(0, 56));
        widget_45->setMaximumSize(QSize(16777215, 56));
        widget_45->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        closeBtn = new QPushButton(widget_45);
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


        verticalLayout_2->addWidget(widget_45);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 464, 288));
        widget_2->setMinimumSize(QSize(464, 288));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        big_image = new QLabel(widget_2);
        big_image->setObjectName(QString::fromUtf8("big_image"));
        big_image->setScaledContents(true);

        verticalLayout_7->addWidget(big_image);

        image = new CRoundLabel(page);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(16, 214, 100, 100));
        image->setStyleSheet(QString::fromUtf8("background: transparent;"));
        image->setScaledContents(true);
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 264, 466, 507));
        widget_3->setMinimumSize(QSize(464, 494));
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
        age->setStyleSheet(QString::fromUtf8("background: rgba(128, 220, 255, 1);\n"
"border-radius: 8px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/live_people_man.png"), QSize(), QIcon::Normal, QIcon::Off);
        age->setIcon(icon1);
        age->setIconSize(QSize(12, 13));

        horizontalLayout->addWidget(age);

        userLevel = new QLabel(widget_11);
        userLevel->setObjectName(QString::fromUtf8("userLevel"));
        userLevel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(userLevel);

        constellation = new QLabel(widget_11);
        constellation->setObjectName(QString::fromUtf8("constellation"));
        constellation->setMinimumSize(QSize(45, 18));
        constellation->setMaximumSize(QSize(46, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(9);
        constellation->setFont(font);
        constellation->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 8px;\n"
"color: #FFFFFF;"));
        constellation->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(constellation);

        horizontalSpacer = new QSpacerItem(184, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(widget_11);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(44, 28));
        label_4->setMaximumSize(QSize(44, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 14px;\n"
"color: #FFFFFF;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);


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
        horizontalLayout_4->setContentsMargins(10, 0, 2, 0);
        label_9 = new QLabel(widget_14);
        label_9->setObjectName(QString::fromUtf8("label_9"));

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
        label_10->setStyleSheet(QString::fromUtf8("font-size: 12px;\n"
"color: #222429;\n"
"text-align: left;"));

        horizontalLayout_4->addWidget(label_10);

        pushButton = new QPushButton(widget_14);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(17, 17));
        pushButton->setMaximumSize(QSize(17, 17));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icon_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
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
"font-size: 14px;"));

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
"font-size: 14px;"));

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
"color: #FFFFFF;"));

        horizontalLayout_8->addWidget(label_12);

        label_14 = new QLabel(widget_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(65, 18));
        label_14->setMaximumSize(QSize(65, 18));

        horizontalLayout_8->addWidget(label_14);

        horizontalSpacer_5 = new QSpacerItem(324, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_7);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 20));
        widget_8->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(widget_8);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: #FFFFFF;"));

        horizontalLayout_9->addWidget(label_17);

        label_18 = new QLabel(widget_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(55, 18));
        label_18->setMaximumSize(QSize(55, 18));

        horizontalLayout_9->addWidget(label_18);

        horizontalSpacer_6 = new QSpacerItem(340, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(widget_8);

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
        widget_15->setMinimumSize(QSize(362, 100));
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

        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 100));
        widget_10->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_11 = new QHBoxLayout(widget_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_7 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        Attention = new QPushButton(widget_10);
        Attention->setObjectName(QString::fromUtf8("Attention"));
        Attention->setMinimumSize(QSize(125, 44));
        Attention->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 22px;\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icon_\345\217\226\346\266\210\345\205\263\346\263\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        Attention->setIcon(icon3);
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
"font-style: normal;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/HI.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(24, 23));

        horizontalLayout_11->addWidget(pushButton_3);


        verticalLayout_3->addWidget(widget_10);

        stackedWidget->addWidget(page);
        widget_2->raise();
        widget_3->raise();
        image->raise();
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
        closeBtn->setText(QString());
        big_image->setText(QString());
        image->setText(QString());
        name->setText(QCoreApplication::translate("UserinfoPage", "Rx. \345\207\214\344\271\261", nullptr));
        age->setText(QCoreApplication::translate("UserinfoPage", "8", nullptr));
        userLevel->setText(QCoreApplication::translate("UserinfoPage", "10", nullptr));
        constellation->setText(QCoreApplication::translate("UserinfoPage", "\345\244\204\345\245\263\345\272\247", nullptr));
        label_4->setText(QCoreApplication::translate("UserinfoPage", "\347\246\273\347\272\277", nullptr));
        userId->setText(QCoreApplication::translate("UserinfoPage", "ID\357\274\2322010590", nullptr));
        label_5->setText(QString());
        location->setText(QCoreApplication::translate("UserinfoPage", "\350\264\265\345\267\236\347\234\201\302\267\350\264\265\351\230\263\345\270\202", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("UserinfoPage", "9\345\244\234\345\267\264\351\273\216\351\223\201\345\241\224 \302\267 \346\210\220\345\221\230 ", nullptr));
        label_10->setText(QCoreApplication::translate("UserinfoPage", "\346\237\245\347\234\213\345\205\254\344\274\232", nullptr));
        pushButton->setText(QString());
        fansNum->setText(QCoreApplication::translate("UserinfoPage", "5", nullptr));
        label_11->setText(QCoreApplication::translate("UserinfoPage", "\347\262\211\344\270\235", nullptr));
        playDayNum->setText(QCoreApplication::translate("UserinfoPage", "5", nullptr));
        label_16->setText(QCoreApplication::translate("UserinfoPage", "\346\270\270\347\216\251\345\244\251\346\225\260", nullptr));
        label_12->setText(QCoreApplication::translate("UserinfoPage", "\345\213\213\347\253\240\357\274\232", nullptr));
        label_14->setText(QString());
        label_17->setText(QCoreApplication::translate("UserinfoPage", "VIP\357\274\232", nullptr));
        label_18->setText(QString());
        label_19->setText(QCoreApplication::translate("UserinfoPage", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", nullptr));
        intro->setText(QString());
        Attention->setText(QCoreApplication::translate("UserinfoPage", "\345\217\226\346\266\210\345\205\263\346\263\250", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UserinfoPage", "\346\211\223\346\213\233\345\221\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserinfoPage: public Ui_UserinfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGE_H
