/********************************************************************************
** Form generated from reading UI file 'PromoteBusinePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTEBUSINEPAGE_H
#define UI_PROMOTEBUSINEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PromoteBusinePage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *topBtn;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *searchBtn;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QPushButton *updateBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *listWidget;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn_2;
    QLabel *label;
    QWidget *widget_52;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *day_btn;
    QPushButton *week_btn;
    QPushButton *m_btn;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_42;
    QVBoxLayout *contList;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *PromoteBusinePage)
    {
        if (PromoteBusinePage->objectName().isEmpty())
            PromoteBusinePage->setObjectName(QString::fromUtf8("PromoteBusinePage"));
        PromoteBusinePage->resize(773, 836);
        PromoteBusinePage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(PromoteBusinePage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(PromoteBusinePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(31, 0, 32, 31);
        widget_1 = new QWidget(widget);
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

        topBtn = new QPushButton(widget_1);
        topBtn->setObjectName(QString::fromUtf8("topBtn"));
        topBtn->setMinimumSize(QSize(25, 24));
        topBtn->setMaximumSize(QSize(25, 24));
        topBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        icon.addFile(QString::fromUtf8(":/images/icon_\347\275\256\351\241\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        topBtn->setIcon(icon);
        topBtn->setIconSize(QSize(25, 24));

        horizontalLayout_22->addWidget(topBtn);

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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/login_min_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon1);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon2);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout_22->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget_1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2 {\n"
"                      background-image: url(:/images/toolBg.png);\n"
"                      background-position: center;\n"
"                      background-repeat: no-repeat;\n"
"                    }"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(281, 0));
        widget_4->setMaximumSize(QSize(281, 16777215));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"                      background-image: url(:/images/bg_\346\210\277\351\227\264\346\216\250\350\215\220.png);\n"
"                      background-position: center;\n"
"                      background-repeat: no-repeat;\n"
"                    }"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(17, 0, 16, 16);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 69));
        widget_6->setMaximumSize(QSize(16777215, 69));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget#widget_6{\n"
"    background: rgba(255,255,255,0);\n"
"    }\n"
"\n"
"\n"
"QPushButton {\n"
"background: qlineargradient(x1:1, y1:0.5, x2:0, y2:0.5, stop:0 #D197FE, stop:1 #9752ED);\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 22px;   \n"
"}\n"
"\n"
"QPushButton:checked {\n"
"border:none;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 14px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"line-height: 22px;   \n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(widget_6);
        buttonGroup = new QButtonGroup(PromoteBusinePage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(92, 36));
        pushButton->setMaximumSize(QSize(92, 36));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_6);
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(92, 36));
        pushButton_2->setMaximumSize(QSize(92, 36));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(false);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_4->addWidget(widget_6);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 32));
        widget_7->setMaximumSize(QSize(16777215, 32));
        widget_7->setStyleSheet(QString::fromUtf8("background: #624676;\n"
"border-radius: 16px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_7);
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(12, 1, 12, 1);
        lineEdit = new QLineEdit(widget_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_3->addWidget(lineEdit);

        searchBtn = new QPushButton(widget_7);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icon_\346\220\234\347\264\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchBtn->setIcon(icon3);
        searchBtn->setIconSize(QSize(18, 18));

        horizontalLayout_3->addWidget(searchBtn);


        verticalLayout_4->addWidget(widget_7);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 44));
        widget_8->setMaximumSize(QSize(16777215, 44));
        widget_8->setStyleSheet(QString::fromUtf8(" background: rgba(255,255,255,0);"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 20));
        label_16->setMaximumSize(QSize(16777215, 20));
        label_16->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_4->addWidget(label_16);

        updateBtn = new QPushButton(widget_8);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        updateBtn->setMinimumSize(QSize(68, 20));
        updateBtn->setMaximumSize(QSize(68, 20));
        updateBtn->setStyleSheet(QString::fromUtf8("font-family: \342\200\234\345\276\256\350\275\257\351\233\205\351\273\221\342\200\235;\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #A8A8A7;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;\n"
"\n"
"padding-bottom: 2px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/update_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateBtn->setIcon(icon4);
        updateBtn->setIconSize(QSize(23, 24));

        horizontalLayout_4->addWidget(updateBtn);


        verticalLayout_4->addWidget(widget_8);

        scrollArea = new QScrollArea(widget_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 588));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setSpacing(16);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        listWidget = new QVBoxLayout();
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_7->addLayout(listWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        horizontalLayout->addWidget(widget_4);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(16, 0, 16, 16);
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 56));
        widget_5->setMaximumSize(QSize(16777215, 56));
        widget_5->setStyleSheet(QString::fromUtf8("QWidget#widget_5 {\n"
"    border-bottom: 1px solid rgba(255,255,255,0.1);;\n"
"	background: rgba(255,255,255,0);\n"
"border-radius: 0px;\n"
"    }"));
        horizontalLayout_23 = new QHBoxLayout(widget_5);
        horizontalLayout_23->setSpacing(16);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(19, 0, 0, 1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_8);

        label_15 = new QLabel(widget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;\n"
"background: rgba(255,255,255,0);"));

        horizontalLayout_23->addWidget(label_15);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer);

        closeBtn_2 = new QPushButton(widget_5);
        closeBtn_2->setObjectName(QString::fromUtf8("closeBtn_2"));
        closeBtn_2->setMinimumSize(QSize(24, 24));
        closeBtn_2->setMaximumSize(QSize(24, 24));
        closeBtn_2->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
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
        closeBtn_2->setIcon(icon4);
        closeBtn_2->setIconSize(QSize(28, 28));

        horizontalLayout_23->addWidget(closeBtn_2);


        verticalLayout_3->addWidget(widget_5);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 17));
        label->setMaximumSize(QSize(16777215, 17));
        label->setStyleSheet(QString::fromUtf8("background: rgba(255,255,255,0);\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"font-style: normal;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        widget_52 = new QWidget(widget_3);
        widget_52->setObjectName(QString::fromUtf8("widget_52"));
        widget_52->setMinimumSize(QSize(0, 32));
        widget_52->setMaximumSize(QSize(396, 32));
        widget_52->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QWidget#widget_52{\n"
"    background: rgba(255,255,255,0.1);\n"
"border-radius: 14px;\n"
"    }\n"
"\n"
"\n"
"QPushButton {\n"
"background: rgba(255,255,255,0);\n"
"     border:none;\n"
"background: transparent;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: rgba(255, 255, 255, 0.5);\n"
"line-height: 22px;   \n"
"}\n"
"\n"
"QPushButton:checked {\n"
"   border:none;\n"
"\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 14px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"line-height: 22px;   \n"
"}\n"
""));
        horizontalLayout_31 = new QHBoxLayout(widget_52);
        horizontalLayout_31->setSpacing(0);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(2, 2, 2, 2);
        day_btn = new QPushButton(widget_52);
        buttonGroup_2 = new QButtonGroup(PromoteBusinePage);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(day_btn);
        day_btn->setObjectName(QString::fromUtf8("day_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(day_btn->sizePolicy().hasHeightForWidth());
        day_btn->setSizePolicy(sizePolicy);
        day_btn->setStyleSheet(QString::fromUtf8(""));
        day_btn->setCheckable(true);
        day_btn->setChecked(true);

        horizontalLayout_31->addWidget(day_btn);

        week_btn = new QPushButton(widget_52);
        buttonGroup_2->addButton(week_btn);
        week_btn->setObjectName(QString::fromUtf8("week_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(week_btn->sizePolicy().hasHeightForWidth());
        week_btn->setSizePolicy(sizePolicy1);
        week_btn->setCheckable(true);

        horizontalLayout_31->addWidget(week_btn);

        m_btn = new QPushButton(widget_52);
        buttonGroup_2->addButton(m_btn);
        m_btn->setObjectName(QString::fromUtf8("m_btn"));
        sizePolicy1.setHeightForWidth(m_btn->sizePolicy().hasHeightForWidth());
        m_btn->setSizePolicy(sizePolicy1);
        m_btn->setCheckable(true);

        horizontalLayout_31->addWidget(m_btn);


        verticalLayout_3->addWidget(widget_52);

        scrollArea_4 = new QScrollArea(widget_3);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 397, 592));
        verticalLayout_42 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_42->setSpacing(0);
        verticalLayout_42->setObjectName(QString::fromUtf8("verticalLayout_42"));
        verticalLayout_42->setContentsMargins(0, 0, 0, 0);
        contList = new QVBoxLayout();
        contList->setSpacing(11);
        contList->setObjectName(QString::fromUtf8("contList"));

        verticalLayout_42->addLayout(contList);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_3->addWidget(scrollArea_4);


        horizontalLayout->addWidget(widget_3);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(PromoteBusinePage);

        QMetaObject::connectSlotsByName(PromoteBusinePage);
    } // setupUi

    void retranslateUi(QDialog *PromoteBusinePage)
    {
        PromoteBusinePage->setWindowTitle(QCoreApplication::translate("PromoteBusinePage", "\345\261\225\344\270\232\345\260\217\345\212\251\346\211\213", nullptr));
        label_14->setText(QCoreApplication::translate("PromoteBusinePage", "\345\261\225\344\270\232\345\260\217\345\212\251\346\211\213", nullptr));
        topBtn->setText(QString());
        minBtn->setText(QString());
        closeBtn->setText(QString());
        pushButton->setText(QCoreApplication::translate("PromoteBusinePage", "\346\216\250\350\215\220", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PromoteBusinePage", "\345\205\263\346\263\250", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("PromoteBusinePage", "\350\257\267\350\276\223\345\205\245\346\230\265\347\247\260/id", nullptr));
        searchBtn->setText(QString());
        label_16->setText(QCoreApplication::translate("PromoteBusinePage", "\346\210\277\351\227\264\346\216\250\350\215\220", nullptr));
        updateBtn->setText(QCoreApplication::translate("PromoteBusinePage", "\346\215\242\344\270\200\346\211\271", nullptr));
        label_15->setText(QCoreApplication::translate("PromoteBusinePage", "\350\215\243\350\252\211\346\246\234", nullptr));
        closeBtn_2->setText(QString());
        label->setText(QCoreApplication::translate("PromoteBusinePage", "\345\217\214\345\207\273\345\244\264\345\203\217\357\274\214\345\215\263\345\217\257\350\201\212\345\244\251", nullptr));
        day_btn->setText(QCoreApplication::translate("PromoteBusinePage", "\346\227\245\346\246\234", nullptr));
        week_btn->setText(QCoreApplication::translate("PromoteBusinePage", "\345\221\250\346\246\234", nullptr));
        m_btn->setText(QCoreApplication::translate("PromoteBusinePage", "\346\234\210\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromoteBusinePage: public Ui_PromoteBusinePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTEBUSINEPAGE_H
