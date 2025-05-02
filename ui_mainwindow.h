/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_16;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_13;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_12;
    CRoundLabel *userImage;
    QLabel *userName;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QFrame *line_3;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_10;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    CRoundLabel *guildImage;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QLabel *guildName;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *IDLabel;
    QPushButton *copyBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *intro;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *updateBtn;
    QFrame *line_2;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *gridLayout;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *msgList;
    QWidget *widget_13;
    QPushButton *createRoom;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *enterRoom;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *emoBtn;
    QLineEdit *msgEdit;
    QToolButton *sendBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1925, 1137);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_16 = new QVBoxLayout(centralwidget);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        widget_14 = new QWidget(centralwidget);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(66, 66));
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

        horizontalSpacer_5 = new QSpacerItem(1140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

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
        userImage = new CRoundLabel(widget_18);
        userImage->setObjectName(QString::fromUtf8("userImage"));
        userImage->setMinimumSize(QSize(36, 36));
        userImage->setMaximumSize(QSize(36, 36));
        userImage->setStyleSheet(QString::fromUtf8("border:none;"));
        userImage->setScaledContents(false);

        horizontalLayout_12->addWidget(userImage);

        userName = new QLabel(widget_18);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_12->addWidget(userName);


        horizontalLayout_13->addWidget(widget_18);

        widget_17 = new QWidget(widget_14);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        widget_17->setMinimumSize(QSize(168, 0));
        widget_17->setMaximumSize(QSize(168, 16777215));
        widget_17->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_11 = new QHBoxLayout(widget_17);
        horizontalLayout_11->setSpacing(24);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(widget_17);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(24, 25));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        icon.addFile(QString::fromUtf8(":/images/top_d.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(24, 25));

        horizontalLayout_11->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget_17);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(24, 25));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        icon1.addFile(QString::fromUtf8(":/images/top_c.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(24, 25));

        horizontalLayout_11->addWidget(pushButton_8);

        pushButton_10 = new QPushButton(widget_17);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(24, 25));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        icon2.addFile(QString::fromUtf8(":/images/top_a.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(24, 25));

        horizontalLayout_11->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(widget_17);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(24, 25));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/top_b.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);
        pushButton_9->setIconSize(QSize(24, 25));

        horizontalLayout_11->addWidget(pushButton_9);


        horizontalLayout_13->addWidget(widget_17);

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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/login_min_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon4);
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon5);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout_10->addWidget(closeBtn);


        horizontalLayout_13->addWidget(widget_16);


        verticalLayout_16->addWidget(widget_14);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("background: #161616;"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(271, 24, 271, 24);
        widget_12 = new QWidget(page);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));

        verticalLayout_2->addWidget(widget_12);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(680, 0));
        widget_2->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout_13 = new QVBoxLayout(widget_2);
        verticalLayout_13->setSpacing(12);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(16, 18, 16, 18);
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_13->addWidget(label_10);

        line = new QFrame(widget_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 1));
        line->setMaximumSize(QSize(16777215, 1));
        line->setStyleSheet(QString::fromUtf8("background: #383B43;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 648, 352));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_13->addWidget(scrollArea);


        horizontalLayout_2->addWidget(widget_2);

        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(12);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 77));
        widget_5->setMaximumSize(QSize(16777215, 77));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(16, 18, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        guildImage = new CRoundLabel(widget_5);
        guildImage->setObjectName(QString::fromUtf8("guildImage"));
        guildImage->setMinimumSize(QSize(47, 47));
        guildImage->setMaximumSize(QSize(47, 47));
        guildImage->setScaledContents(true);

        verticalLayout_4->addWidget(guildImage);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        guildName = new QLabel(widget_5);
        guildName->setObjectName(QString::fromUtf8("guildName"));
        guildName->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_5->addWidget(guildName);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_7->addWidget(label_2);

        IDLabel = new QLabel(widget_5);
        IDLabel->setObjectName(QString::fromUtf8("IDLabel"));
        IDLabel->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_7->addWidget(IDLabel);

        copyBtn = new QPushButton(widget_5);
        copyBtn->setObjectName(QString::fromUtf8("copyBtn"));
        copyBtn->setMinimumSize(QSize(16, 16));
        copyBtn->setMaximumSize(QSize(16, 16));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/copy_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyBtn->setIcon(icon6);

        horizontalLayout_7->addWidget(copyBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_6->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 110));
        widget_6->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_8 = new QHBoxLayout(widget_6);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(16, 0, 16, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_7->addWidget(label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        horizontalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(569, 110));
        widget_7->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        verticalLayout_9 = new QVBoxLayout(widget_7);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_9->setContentsMargins(12, 8, 12, 8);
        intro = new QLabel(widget_7);
        intro->setObjectName(QString::fromUtf8("intro"));
        intro->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));
        intro->setScaledContents(false);
        intro->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        intro->setWordWrap(true);

        verticalLayout_9->addWidget(intro);


        verticalLayout_8->addWidget(widget_7);


        horizontalLayout_8->addLayout(verticalLayout_8);


        verticalLayout_6->addWidget(widget_6);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 142));
        widget_8->setMaximumSize(QSize(16777215, 142));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(16, 0, 16, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_10->addWidget(label_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);


        horizontalLayout_4->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(-1, -1, 50, -1);
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(80, 80));
        widget_9->setMaximumSize(QSize(80, 80));
        widget_9->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        verticalLayout_11 = new QVBoxLayout(widget_9);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_11->addWidget(label_9);


        verticalLayout_12->addWidget(widget_9);

        label_8 = new QLabel(widget_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_8);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);


        horizontalLayout_4->addLayout(verticalLayout_12);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_6->addWidget(widget_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_2->addWidget(widget_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 542));
        widget_3->setMaximumSize(QSize(16777215, 16777215));
        widget_3->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout_14 = new QVBoxLayout(widget_3);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(16, 0, 16, 10);
        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMaximumSize(QSize(16777215, 56));
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, -1, 0, -1);
        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_9->addWidget(label_11);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        updateBtn = new QPushButton(widget_10);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        updateBtn->setStyleSheet(QString::fromUtf8("font-family: \342\200\234\345\276\256\350\275\257\351\233\205\351\273\221\342\200\235;\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/update_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateBtn->setIcon(icon7);
        updateBtn->setIconSize(QSize(24, 24));

        horizontalLayout_9->addWidget(updateBtn);


        verticalLayout_14->addWidget(widget_10);

        line_2 = new QFrame(widget_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 1));
        line_2->setMaximumSize(QSize(16777215, 1));
        line_2->setStyleSheet(QString::fromUtf8("background: #383B43;"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line_2);

        widget_11 = new QWidget(widget_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        verticalLayout_15 = new QVBoxLayout(widget_11);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 16, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_15->addLayout(gridLayout);


        verticalLayout_14->addWidget(widget_11);


        verticalLayout_2->addWidget(widget_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(page_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        msgList = new QListWidget(widget);
        msgList->setObjectName(QString::fromUtf8("msgList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msgList->sizePolicy().hasHeightForWidth());
        msgList->setSizePolicy(sizePolicy);
        msgList->setMinimumSize(QSize(0, 0));
        msgList->setMaximumSize(QSize(16777215, 16777215));
        msgList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	background:rgba(37,51,83,1);\n"
"	border:none;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"	border:none;\n"
"    background:rgba(37,51,83,1);\n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"	border:none;\n"
"    background:rgba(33,60,100,1);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background:rgba(37,51,83,1);\n"
"    padding:0px;\n"
"    margin:0px;\n"
"    border:none;\n"
"}"));
        msgList->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(msgList);

        widget_13 = new QWidget(widget);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMinimumSize(QSize(50, 200));
        createRoom = new QPushButton(widget_13);
        createRoom->setObjectName(QString::fromUtf8("createRoom"));
        createRoom->setGeometry(QRect(630, 70, 75, 23));
        pushButton_2 = new QPushButton(widget_13);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 157, 75, 23));
        pushButton = new QPushButton(widget_13);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(630, 128, 75, 23));
        enterRoom = new QPushButton(widget_13);
        enterRoom->setObjectName(QString::fromUtf8("enterRoom"));
        enterRoom->setGeometry(QRect(630, 99, 75, 23));

        verticalLayout->addWidget(widget_13);

        frame_6 = new QFrame(widget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(0, 70));
        frame_6->setMaximumSize(QSize(16777215, 70));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame#frame_6\n"
"{\n"
"	border-left: 1px solid rgb(40,56,89);\n"
"	background-color: #233251;\n"
"}"));
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        emoBtn = new QToolButton(frame_6);
        emoBtn->setObjectName(QString::fromUtf8("emoBtn"));
        emoBtn->setMinimumSize(QSize(40, 70));
        emoBtn->setMaximumSize(QSize(40, 70));
        emoBtn->setStyleSheet(QString::fromUtf8("background:rgba(41,58,97,1);\n"
"font-size:14px;\n"
"font-family:MicrosoftYaHei;\n"
"color:rgba(255,255,255,1);\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/Live/Live_biaoqing.png"), QSize(), QIcon::Normal, QIcon::Off);
        emoBtn->setIcon(icon8);
        emoBtn->setIconSize(QSize(24, 24));
        emoBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(emoBtn);

        msgEdit = new QLineEdit(frame_6);
        msgEdit->setObjectName(QString::fromUtf8("msgEdit"));
        msgEdit->setMinimumSize(QSize(0, 70));
        msgEdit->setMaximumSize(QSize(16777215, 70));
        msgEdit->setStyleSheet(QString::fromUtf8("background:rgba(23,36,67,1);\n"
"border:none;\n"
"font-size:12px;\n"
"font-family:SimSun;\n"
"font-weight:400;\n"
"color:rgba(83,92,112,1);"));

        horizontalLayout_6->addWidget(msgEdit);

        sendBtn = new QToolButton(frame_6);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setMinimumSize(QSize(60, 70));
        sendBtn->setMaximumSize(QSize(16777215, 16777215));
        sendBtn->setStyleSheet(QString::fromUtf8("background:rgba(41,58,97,1);\n"
"font-size:14px;\n"
"font-family:MicrosoftYaHei;\n"
"color:rgba(255,255,255,1);\n"
""));
        sendBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(sendBtn);


        verticalLayout->addWidget(frame_6);


        verticalLayout_3->addWidget(widget);

        stackedWidget->addWidget(page_2);

        verticalLayout_16->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\223\235\344\274\264\350\257\255\351\237\263", nullptr));
        userImage->setText(QString());
        userName->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\345\215\240\344\275\215", nullptr));
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_10->setText(QString());
        pushButton_9->setText(QString());
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260\345\205\254\345\221\212", nullptr));
        guildImage->setText(QString());
        guildName->setText(QCoreApplication::translate("MainWindow", "\345\205\254\344\274\232\345\220\215\347\247\260\345\215\240\344\275\215\345\205\254\344\274\232\345\220\215\347\247\260\345\215\240\344\275\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        IDLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        copyBtn->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\205\254\344\274\232\347\256\200\344\273\213\357\274\232", nullptr));
        intro->setText(QCoreApplication::translate("MainWindow", "\351\235\242\345\220\221\345\205\250\345\233\275\346\213\233\345\274\200\345\216\205\345\233\242\351\230\237\357\274\214\347\272\277\344\270\212\347\272\277\344\270\213\346\213\233\345\213\237\357\274\214\345\234\272\345\234\260\350\207\252\351\200\211\357\274\214\345\205\254\344\274\232\347\273\231\344\272\210\346\234\200\345\244\247\347\232\204\346\211\266\346\214\201\357\274\214\347\246\217\345\210\251\346\213\211\346\273\241\357\274\201\345\220\210\344\275\234\345\212\240\357\274\23213588888888 18599999999", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\205\254\344\274\232\350\215\243\350\252\211\357\274\232", nullptr));
        label_9->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\233\233\347\272\247\345\205\254\344\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\255\276\347\272\246\345\216\205", nullptr));
        updateBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        createRoom->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\347\276\244\350\201\212", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\351\272\246", nullptr));
        enterRoom->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\346\210\277\351\227\264", nullptr));
        emoBtn->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\203\205", nullptr));
        msgEdit->setText(QString());
        msgEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\222\214\345\244\247\345\256\266\350\201\212\350\201\212\345\244\251", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBtn->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
