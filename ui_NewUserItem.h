/********************************************************************************
** Form generated from reading UI file 'NewUserItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERITEM_H
#define UI_NEWUSERITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    CRoundLabel *image;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *NewUserItem)
    {
        if (NewUserItem->objectName().isEmpty())
            NewUserItem->setObjectName(QString::fromUtf8("NewUserItem"));
        NewUserItem->resize(710, 70);
        horizontalLayout = new QHBoxLayout(NewUserItem);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(NewUserItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(40, 48));
        widget->setMaximumSize(QSize(40, 48));
        image = new CRoundLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 40, 40));
        image->setMinimumSize(QSize(40, 40));
        image->setMaximumSize(QSize(40, 40));
        image->setScaledContents(true);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 32, 40, 16));
        label_2->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 14, -1, 14);
        nameLab = new QLabel(NewUserItem);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setMinimumSize(QSize(0, 22));
        nameLab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        verticalLayout->addWidget(nameLab);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(NewUserItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: #A8A8A7;\n"
"line-height: 17px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(24);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, -1, -1, -1);
        pushButton_2 = new QPushButton(NewUserItem);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(90, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: rgba(245,151,255,0.2);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #F597FF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"border-radius: 16px;\n"
"background: #36383B;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: rgba(255, 255, 255,0.5);\n"
"\n"
"}"));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(false);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(NewUserItem);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(90, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: #36383B;\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #36383B;\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: rgba(255,255,255,0.5);\n"
"\n"
"}"));
        pushButton_3->setCheckable(true);
        pushButton_3->setChecked(false);

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton = new QPushButton(NewUserItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(90, 32));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"background: qlineargradient(x1:0, y1:0.5, x2:1, y2:0.5, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #36383B;\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #ffffff;\n"
"\n"
"}"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);

        horizontalLayout_3->addWidget(pushButton);


        horizontalLayout->addLayout(horizontalLayout_3);


        retranslateUi(NewUserItem);

        QMetaObject::connectSlotsByName(NewUserItem);
    } // setupUi

    void retranslateUi(QDialog *NewUserItem)
    {
        NewUserItem->setWindowTitle(QCoreApplication::translate("NewUserItem", "Dialog", nullptr));
        image->setText(QString());
        label_2->setText(QCoreApplication::translate("NewUserItem", "\345\234\250\346\210\277\351\227\264", nullptr));
        nameLab->setText(QCoreApplication::translate("NewUserItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        label->setText(QCoreApplication::translate("NewUserItem", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NewUserItem", "\346\211\223\346\213\233\345\221\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("NewUserItem", "\346\210\277\351\227\264\351\202\200\350\257\267", nullptr));
        pushButton->setText(QCoreApplication::translate("NewUserItem", "\345\205\263\346\263\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewUserItem: public Ui_NewUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERITEM_H
