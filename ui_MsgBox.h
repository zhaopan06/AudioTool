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
    QSpacerItem *horizontalSpacer_4;
    QPushButton *closeBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *titleLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *msg;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *MsgBox)
    {
        if (MsgBox->objectName().isEmpty())
            MsgBox->setObjectName(QString::fromUtf8("MsgBox"));
        MsgBox->resize(564, 270);
        MsgBox->setMinimumSize(QSize(564, 0));
        MsgBox->setMaximumSize(QSize(564, 16777215));
        MsgBox->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(MsgBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(MsgBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 40));
        widget_2->setMaximumSize(QSize(16777215, 40));
        widget_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background: #222429;\n"
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

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        closeBtn = new QPushButton(widget_2);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(24, 24));
        closeBtn->setMaximumSize(QSize(24, 24));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"border:none;\n"
"}\n"
"QPushButton::hover{\n"
"border-radius: 0px;\n"
"border:none;\n"
"background:#3E3E3E;\n"
"}\n"
"QPushButton::checked {\n"
"border-radius: 0px;\n"
"border:none;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(MsgBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-top:none;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 40);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(40, 0, 40, 20);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(16);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(32, 0));
        label_2->setMaximumSize(QSize(32, 32));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\346\217\220\347\244\272.png")));

        horizontalLayout_4->addWidget(label_2);

        titleLabel = new QLabel(widget_3);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-weight: 500;\n"
"\n"
"font-size: 28px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ffffff;\n"
"\n"
"\n"
""));

        horizontalLayout_4->addWidget(titleLabel);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(44, 0, -1, -1);
        msg = new QLabel(widget_3);
        msg->setObjectName(QString::fromUtf8("msg"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msg->sizePolicy().hasHeightForWidth());
        msg->setSizePolicy(sizePolicy);
        msg->setMinimumSize(QSize(0, 14));
        msg->setMaximumSize(QSize(16777215, 16777215));
        msg->setStyleSheet(QString::fromUtf8("\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 22px;\n"
"color: #FFFFFF;\n"
"line-height: 30px;\n"
"text-align: left;\n"
"\n"
"\n"
""));
        msg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        msg->setWordWrap(true);

        horizontalLayout_5->addWidget(msg);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 44));
        widget_4->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 40, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cancelBtn = new QPushButton(widget_4);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(125, 44));
        cancelBtn->setMaximumSize(QSize(125, 44));
        cancelBtn->setStyleSheet(QString::fromUtf8("font-weight: 500;\n"
"background: #36383B;\n"
"border-radius: 22px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"\n"
""));

        horizontalLayout_2->addWidget(cancelBtn);

        okBtn = new QPushButton(widget_4);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(125, 44));
        okBtn->setMaximumSize(QSize(125, 44));
        okBtn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"color: #FFFFFF;\n"
"font-weight: 500;\n"
"background: #ED525A;\n"
"border-radius: 22px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
""));

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout_2->addWidget(widget_4);


        verticalLayout->addWidget(widget);


        retranslateUi(MsgBox);

        QMetaObject::connectSlotsByName(MsgBox);
    } // setupUi

    void retranslateUi(QDialog *MsgBox)
    {
        MsgBox->setWindowTitle(QCoreApplication::translate("MsgBox", "\346\217\220\347\244\272", nullptr));
        label->setText(QString());
        closeBtn->setText(QString());
        label_2->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MsgBox", "\346\217\220\347\244\272", nullptr));
        msg->setText(QString());
        cancelBtn->setText(QCoreApplication::translate("MsgBox", "\345\217\226\346\266\210", nullptr));
        okBtn->setText(QCoreApplication::translate("MsgBox", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MsgBox: public Ui_MsgBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOX_H
