/********************************************************************************
** Form generated from reading UI file 'ManagementPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTPAGE_H
#define UI_MANAGEMENTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagementPage
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
    QPushButton *button1_4;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ManagementPage)
    {
        if (ManagementPage->objectName().isEmpty())
            ManagementPage->setObjectName(QString::fromUtf8("ManagementPage"));
        ManagementPage->resize(773, 788);
        ManagementPage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(ManagementPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ManagementPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
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
        horizontalLayout->setSpacing(32);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 16, 0, -1);
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
        buttonGroup = new QButtonGroup(ManagementPage);
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

        button1_4 = new QPushButton(widget_3);
        buttonGroup->addButton(button1_4);
        button1_4->setObjectName(QString::fromUtf8("button1_4"));
        button1_4->setMinimumSize(QSize(200, 64));
        button1_4->setCheckable(true);
        button1_4->setChecked(false);

        verticalLayout_3->addWidget(button1_4);

        verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_3);

        listWidget = new QListWidget(widget_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(ManagementPage);

        QMetaObject::connectSlotsByName(ManagementPage);
    } // setupUi

    void retranslateUi(QDialog *ManagementPage)
    {
        ManagementPage->setWindowTitle(QCoreApplication::translate("ManagementPage", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        onlineBtn->setText(QCoreApplication::translate("ManagementPage", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        closeBtn->setText(QString());
        button1_1->setText(QCoreApplication::translate("ManagementPage", "\344\270\273\346\214\201\344\272\272", nullptr));
        button1_3->setText(QCoreApplication::translate("ManagementPage", "\347\256\241\347\220\206\345\221\230", nullptr));
        button1_2->setText(QCoreApplication::translate("ManagementPage", "\347\246\201\350\250\200", nullptr));
        button1_4->setText(QCoreApplication::translate("ManagementPage", "\346\213\211\351\273\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagementPage: public Ui_ManagementPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTPAGE_H
