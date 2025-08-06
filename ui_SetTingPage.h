/********************************************************************************
** Form generated from reading UI file 'SetTingPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPAGE_H
#define UI_SETTINGPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_SetTingPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_45;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *onlineBtn;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *button1_1;
    QPushButton *button1_3;
    QPushButton *button1_2;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *directory;
    QPushButton *pushButton_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QPushButton *audioMsg;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *SetTingPage)
    {
        if (SetTingPage->objectName().isEmpty())
            SetTingPage->setObjectName(QString::fromUtf8("SetTingPage"));
        SetTingPage->resize(777, 629);
        SetTingPage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(SetTingPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetTingPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(32, 0, 32, 0);
        widget_45 = new QWidget(widget);
        widget_45->setObjectName(QString::fromUtf8("widget_45"));
        widget_45->setMinimumSize(QSize(0, 56));
        widget_45->setMaximumSize(QSize(16777215, 56));
        widget_45->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-top-right-radius: 20px;\n"
"border-bottom-right-radius: 0px;\n"
"border-top-left-radius: 20px;\n"
"border-bottom-left-radius: 0px;\n"
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
        horizontalLayout_30 = new QHBoxLayout(widget_45);
        horizontalLayout_30->setSpacing(24);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(0, 0, 16, 1);
        onlineBtn = new QPushButton(widget_45);
        onlineBtn->setObjectName(QString::fromUtf8("onlineBtn"));
        onlineBtn->setCheckable(true);
        onlineBtn->setChecked(true);

        horizontalLayout_30->addWidget(onlineBtn);

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

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(200, 0));
        widget_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #36383B;\n"
"border-radius: 8px;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: #36383B;\n"
"border-radius: 8px;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        button1_1 = new QPushButton(widget_3);
        buttonGroup = new QButtonGroup(SetTingPage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(button1_1);
        button1_1->setObjectName(QString::fromUtf8("button1_1"));
        button1_1->setMinimumSize(QSize(200, 64));
        button1_1->setCheckable(true);
        button1_1->setChecked(true);

        verticalLayout_3->addWidget(button1_1);

        button1_3 = new QPushButton(widget_3);
        buttonGroup->addButton(button1_3);
        button1_3->setObjectName(QString::fromUtf8("button1_3"));
        button1_3->setMinimumSize(QSize(200, 64));
        button1_3->setCheckable(true);
        button1_3->setChecked(false);

        verticalLayout_3->addWidget(button1_3);

        button1_2 = new QPushButton(widget_3);
        buttonGroup->addButton(button1_2);
        button1_2->setObjectName(QString::fromUtf8("button1_2"));
        button1_2->setMinimumSize(QSize(200, 64));
        button1_2->setCheckable(true);
        button1_2->setChecked(false);

        verticalLayout_3->addWidget(button1_2);

        verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_3);

        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(16);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 36));
        widget_4->setMaximumSize(QSize(16777215, 36));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 20, 0);
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;"));

        horizontalLayout_2->addWidget(label);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(65, 36));
        pushButton->setMaximumSize(QSize(65, 36));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"background-image: url(:/images/icon_\345\205\263.png);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #36383B;\n"
"border-radius: 8px;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"background-image: url(:/images/icon_\345\274\200.png);\n"
"}"));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 36));
        widget_5->setMaximumSize(QSize(16777215, 36));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(16);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;"));

        horizontalLayout_3->addWidget(label_2);

        directory = new QLabel(widget_5);
        directory->setObjectName(QString::fromUtf8("directory"));
        directory->setMinimumSize(QSize(303, 36));
        directory->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"padding-left: 12px;"));

        horizontalLayout_3->addWidget(directory);

        pushButton_2 = new QPushButton(widget_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(66, 36));
        pushButton_2->setMaximumSize(QSize(66, 36));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: #ED525A;\n"
"border-radius: 18px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 36));
        widget_6->setMaximumSize(QSize(16777215, 36));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(16);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 20, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;"));

        horizontalLayout_4->addWidget(label_3);

        audioMsg = new QPushButton(widget_6);
        audioMsg->setObjectName(QString::fromUtf8("audioMsg"));
        audioMsg->setMinimumSize(QSize(65, 36));
        audioMsg->setMaximumSize(QSize(65, 36));
        audioMsg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #A8A8A7;\n"
"background-image: url(:/images/icon_\345\205\263.png);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #36383B;\n"
"border-radius: 8px;\n"
"border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"background-image: url(:/images/icon_\345\274\200.png);\n"
"}"));
        audioMsg->setCheckable(true);

        horizontalLayout_4->addWidget(audioMsg);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(widget_6);

        verticalSpacer_2 = new QSpacerItem(20, 398, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(SetTingPage);

        QMetaObject::connectSlotsByName(SetTingPage);
    } // setupUi

    void retranslateUi(QDialog *SetTingPage)
    {
        SetTingPage->setWindowTitle(QCoreApplication::translate("SetTingPage", "Dialog", nullptr));
        onlineBtn->setText(QCoreApplication::translate("SetTingPage", "\350\256\276\347\275\256", nullptr));
        closeBtn->setText(QString());
        button1_1->setText(QCoreApplication::translate("SetTingPage", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        button1_3->setText(QCoreApplication::translate("SetTingPage", "\345\277\253\346\215\267\351\224\256", nullptr));
        button1_2->setText(QCoreApplication::translate("SetTingPage", "\351\200\232\347\237\245\346\217\220\351\206\222", nullptr));
        label->setText(QCoreApplication::translate("SetTingPage", "\345\274\200\346\234\272\345\220\257\345\212\250", nullptr));
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("SetTingPage", "\346\226\207\344\273\266\344\277\235\345\255\230\344\275\215\347\275\256", nullptr));
        directory->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("SetTingPage", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QCoreApplication::translate("SetTingPage", "\350\277\233\345\205\245\346\210\277\351\227\264\345\243\260\351\237\263\346\217\220\351\206\222", nullptr));
        audioMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetTingPage: public Ui_SetTingPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPAGE_H
