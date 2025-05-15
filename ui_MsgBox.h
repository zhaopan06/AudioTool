/********************************************************************************
** Form generated from reading UI file 'MsgBox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBOX_H
#define UI_MSGBOX_H

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

class Ui_MsgBox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *closeBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *msg;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *MsgBox)
    {
        if (MsgBox->objectName().isEmpty())
            MsgBox->setObjectName(QString::fromUtf8("MsgBox"));
        MsgBox->resize(300, 215);
        MsgBox->setMinimumSize(QSize(300, 0));
        MsgBox->setMaximumSize(QSize(300, 16777215));
        MsgBox->setStyleSheet(QString::fromUtf8("background: #f6f6f6;\n"
"border-radius: 5px;\n"
""));
        verticalLayout = new QVBoxLayout(MsgBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(MsgBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 45));
        widget_2->setMaximumSize(QSize(16777215, 45));
        widget_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background: #777a8c;\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 5, 15, 5);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(18, 0));
        label->setStyleSheet(QString::fromUtf8("border:none;"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        titleLabel = new QLabel(widget_2);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
"font-size: 16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ffffff;\n"
""));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        closeBtn = new QPushButton(widget_2);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/close14_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(MsgBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"\n"
"border: 1px solid #e1e1e1;\n"
"border-top:none;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 0, 1, 1);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, 20, 50, 20);
        msg = new QLabel(widget_3);
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setMinimumSize(QSize(0, 14));
        msg->setMaximumSize(QSize(16777215, 16777215));
        msg->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:400;\n"
"color:#333333\n"
"\n"
""));
        msg->setAlignment(Qt::AlignCenter);
        msg->setWordWrap(true);

        horizontalLayout_3->addWidget(msg);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 45));
        widget_4->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 25);
        okBtn = new QPushButton(widget_4);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(0, 30));
        okBtn->setMaximumSize(QSize(76, 16777215));
        okBtn->setStyleSheet(QString::fromUtf8("background: #1cd39b;\n"
"border-radius: 5px;\n"
"\n"
"font-size: 14px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"text-align: center;\n"
"color: #ffffff;\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(widget_4);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(0, 30));
        cancelBtn->setMaximumSize(QSize(76, 16777215));
        cancelBtn->setStyleSheet(QString::fromUtf8("\n"
"font-size:14px;\n"
"font-family:SimSun;\n"
"font-weight:400;\n"
"color:rgba(255,255,255,1);\n"
"background:rgba(82,129,228,1);\n"
"border-radius:2px;"));

        horizontalLayout_2->addWidget(cancelBtn);


        verticalLayout_2->addWidget(widget_4);


        verticalLayout->addWidget(widget);


        retranslateUi(MsgBox);

        QMetaObject::connectSlotsByName(MsgBox);
    } // setupUi

    void retranslateUi(QDialog *MsgBox)
    {
        MsgBox->setWindowTitle(QCoreApplication::translate("MsgBox", "\346\217\220\347\244\272", nullptr));
        label->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MsgBox", "\346\217\220\347\244\272", nullptr));
        closeBtn->setText(QString());
        msg->setText(QString());
        okBtn->setText(QCoreApplication::translate("MsgBox", "\347\241\256\350\256\244", nullptr));
        cancelBtn->setText(QCoreApplication::translate("MsgBox", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MsgBox: public Ui_MsgBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOX_H
