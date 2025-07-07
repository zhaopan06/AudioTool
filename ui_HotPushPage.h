/********************************************************************************
** Form generated from reading UI file 'HotPushPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTPUSHPAGE_H
#define UI_HOTPUSHPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotPushPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_36;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *closeBtn;
    QWidget *widget_2;

    void setupUi(QDialog *HotPushPage)
    {
        if (HotPushPage->objectName().isEmpty())
            HotPushPage->setObjectName(QString::fromUtf8("HotPushPage"));
        HotPushPage->resize(773, 629);
        HotPushPage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(HotPushPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(HotPushPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(32, 0, 32, 0);
        widget_36 = new QWidget(widget);
        widget_36->setObjectName(QString::fromUtf8("widget_36"));
        widget_36->setMinimumSize(QSize(0, 56));
        widget_36->setMaximumSize(QSize(16777215, 56));
        widget_36->setStyleSheet(QString::fromUtf8("QWidget#widget_36 {\n"
"    border-bottom: 1px solid #383B43;\n"
"border-radius: 0px;\n"
"    }"));
        horizontalLayout_22 = new QHBoxLayout(widget_36);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 1);
        label_14 = new QLabel(widget_36);
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

        closeBtn = new QPushButton(widget_36);
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

        horizontalLayout_22->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget_36);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(HotPushPage);

        QMetaObject::connectSlotsByName(HotPushPage);
    } // setupUi

    void retranslateUi(QDialog *HotPushPage)
    {
        HotPushPage->setWindowTitle(QCoreApplication::translate("HotPushPage", "Dialog", nullptr));
        label_14->setText(QCoreApplication::translate("HotPushPage", "\350\277\221\346\234\237\346\264\273\345\212\250", nullptr));
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HotPushPage: public Ui_HotPushPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTPUSHPAGE_H
