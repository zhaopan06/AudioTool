/********************************************************************************
** Form generated from reading UI file 'RoomEidtPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMEIDTPAGE_H
#define UI_ROOMEIDTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_RoomEidtPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *onlineBtn;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_8;
    click_label *image;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *RoomEidtPage)
    {
        if (RoomEidtPage->objectName().isEmpty())
            RoomEidtPage->setObjectName(QString::fromUtf8("RoomEidtPage"));
        RoomEidtPage->resize(773, 456);
        RoomEidtPage->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(RoomEidtPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RoomEidtPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(16, 0, 32, 0);
        widget_1 = new QWidget(widget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(0, 56));
        widget_1->setMaximumSize(QSize(16777215, 56));
        widget_1->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 0px;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 0px;\n"
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
        horizontalLayout_30 = new QHBoxLayout(widget_1);
        horizontalLayout_30->setSpacing(24);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(0, 0, 0, 1);
        onlineBtn = new QPushButton(widget_1);
        onlineBtn->setObjectName(QString::fromUtf8("onlineBtn"));
        onlineBtn->setCheckable(true);
        onlineBtn->setChecked(true);

        horizontalLayout_30->addWidget(onlineBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_13);

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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/login_close_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon);
        closeBtn->setIconSize(QSize(28, 28));

        horizontalLayout_30->addWidget(closeBtn);


        verticalLayout_2->addWidget(widget_1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(24);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(186, 0));
        widget_3->setMaximumSize(QSize(186, 16777215));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(12);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 16, 0, 0);
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_7->addWidget(label_8);

        widget_10 = new QWidget(widget_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(186, 186));
        widget_10->setMaximumSize(QSize(16777215, 186));
        verticalLayout_8 = new QVBoxLayout(widget_10);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        image = new click_label(widget_10);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(0, 158));
        image->setScaledContents(true);

        verticalLayout_8->addWidget(image);

        label_9 = new QLabel(widget_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_9);


        verticalLayout_7->addWidget(widget_10);

        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(16);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 16, 0, 0);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMaximumSize(QSize(16777215, 70));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(12);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_4->addWidget(label);

        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 36));
        widget_8->setMaximumSize(QSize(16777215, 36));
        widget_8->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        horizontalLayout_3 = new QHBoxLayout(widget_8);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(12, 6, 12, 6);
        lineEdit = new QLineEdit(widget_8);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"text-align: left;\n"
"font-style: normal;"));
        lineEdit->setMaxLength(15);

        horizontalLayout_3->addWidget(lineEdit);

        label_4 = new QLabel(widget_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"font-style: normal;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        label_3 = new QLabel(widget_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: rgba(168, 168, 167, 1);\n"
"line-height: 20px;\n"
"font-style: normal;"));

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_4->addWidget(widget_8);


        verticalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 134));
        widget_7->setMaximumSize(QSize(16777215, 134));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(12);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: left;\n"
"font-style: normal;"));

        verticalLayout_5->addWidget(label_2);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy);
        widget_9->setMinimumSize(QSize(0, 36));
        widget_9->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 6px;"));
        verticalLayout_6 = new QVBoxLayout(widget_9);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(12, 12, 12, 12);
        textEdit = new QTextEdit(widget_9);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"font-style: normal;"));

        verticalLayout_6->addWidget(textEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_6 = new QLabel(widget_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"font-style: normal;"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_6);

        label_5 = new QLabel(widget_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 14px;\n"
"color: rgba(168, 168, 167, 1);\n"
"line-height: 20px;\n"
"font-style: normal;"));

        horizontalLayout_4->addWidget(label_5);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_5->addWidget(widget_9);


        verticalLayout_3->addWidget(widget_7);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMaximumSize(QSize(16777215, 16777215));
        widget_5->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 40, 0, 40);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cancelBtn = new QPushButton(widget_5);
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

        okBtn = new QPushButton(widget_5);
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


        verticalLayout_3->addWidget(widget_5);


        horizontalLayout->addWidget(widget_4);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);


        retranslateUi(RoomEidtPage);

        QMetaObject::connectSlotsByName(RoomEidtPage);
    } // setupUi

    void retranslateUi(QDialog *RoomEidtPage)
    {
        RoomEidtPage->setWindowTitle(QCoreApplication::translate("RoomEidtPage", "\347\274\226\350\276\221\346\210\277\351\227\264", nullptr));
        onlineBtn->setText(QCoreApplication::translate("RoomEidtPage", "\347\274\226\350\276\221\346\210\277\351\227\264", nullptr));
        closeBtn->setText(QString());
        label_8->setText(QCoreApplication::translate("RoomEidtPage", "\346\210\277\351\227\264\345\220\215\347\247\260", nullptr));
        image->setText(QString());
        label_9->setText(QCoreApplication::translate("RoomEidtPage", "\346\233\264\346\215\242\345\260\201\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("RoomEidtPage", "\346\210\277\351\227\264\345\220\215\347\247\260", nullptr));
        lineEdit->setText(QCoreApplication::translate("RoomEidtPage", "\346\265\252\346\274\253\346\273\241\345\261\213-\344\273\231\345\245\263\351\201\277\351\243\216\346\270\257", nullptr));
        label_4->setText(QCoreApplication::translate("RoomEidtPage", "10", nullptr));
        label_3->setText(QCoreApplication::translate("RoomEidtPage", "/15", nullptr));
        label_2->setText(QCoreApplication::translate("RoomEidtPage", "\346\210\277\351\227\264\345\205\254\345\221\212", nullptr));
        label_6->setText(QCoreApplication::translate("RoomEidtPage", "10", nullptr));
        label_5->setText(QCoreApplication::translate("RoomEidtPage", "/100", nullptr));
        cancelBtn->setText(QCoreApplication::translate("RoomEidtPage", "\345\217\226\346\266\210", nullptr));
        okBtn->setText(QCoreApplication::translate("RoomEidtPage", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomEidtPage: public Ui_RoomEidtPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMEIDTPAGE_H
