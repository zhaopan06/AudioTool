/********************************************************************************
** Form generated from reading UI file 'OnlineItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEITEM_H
#define UI_ONLINEITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OnlineItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *image;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_2;
    QLabel *room_lab;
    QLabel *user_lab;
    QSpacerItem *horizontalSpacer;
    QPushButton *user_btn;
    QPushButton *room_btn;

    void setupUi(QDialog *OnlineItem)
    {
        if (OnlineItem->objectName().isEmpty())
            OnlineItem->setObjectName(QString::fromUtf8("OnlineItem"));
        OnlineItem->resize(397, 70);
        horizontalLayout = new QHBoxLayout(OnlineItem);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, 0, -1);
        image = new QLabel(OnlineItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(47, 46));
        image->setMaximumSize(QSize(47, 46));

        horizontalLayout->addWidget(image);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nameLab = new QLabel(OnlineItem);
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
        room_lab = new QLabel(OnlineItem);
        room_lab->setObjectName(QString::fromUtf8("room_lab"));
        room_lab->setMinimumSize(QSize(38, 16));
        room_lab->setMaximumSize(QSize(38, 16));
        room_lab->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:1, y1:0, x2:0, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 8px;\n"
"\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 11px;\n"
"color: #FFFFFF;\n"
"line-height: 16px;\n"
"font-style: normal;"));
        room_lab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(room_lab);

        user_lab = new QLabel(OnlineItem);
        user_lab->setObjectName(QString::fromUtf8("user_lab"));
        user_lab->setMinimumSize(QSize(36, 16));
        user_lab->setMaximumSize(QSize(36, 16));
        user_lab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 10px;\n"
"color: #FFFFFF;\n"
"text-align: right;\n"
"font-style: normal;"));

        horizontalLayout_2->addWidget(user_lab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        user_btn = new QPushButton(OnlineItem);
        user_btn->setObjectName(QString::fromUtf8("user_btn"));
        user_btn->setMinimumSize(QSize(77, 32));
        user_btn->setMaximumSize(QSize(77, 32));
        user_btn->setStyleSheet(QString::fromUtf8("background: rgba(128,220,255,0.2);\n"
"border-radius: 16px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #80DCFF;\n"
"line-height: 20px;\n"
"font-style: normal;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/live_mic_number.png"), QSize(), QIcon::Normal, QIcon::Off);
        user_btn->setIcon(icon);
        user_btn->setIconSize(QSize(16, 17));

        horizontalLayout->addWidget(user_btn);

        room_btn = new QPushButton(OnlineItem);
        room_btn->setObjectName(QString::fromUtf8("room_btn"));
        room_btn->setMinimumSize(QSize(77, 32));
        room_btn->setMaximumSize(QSize(77, 32));
        room_btn->setStyleSheet(QString::fromUtf8("background: rgba(245,151,255,0.2);\n"
"border-radius: 16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #F597FF;\n"
"line-height: 20px;\n"
"font-style: normal;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/live_inRoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        room_btn->setIcon(icon1);
        room_btn->setIconSize(QSize(16, 17));

        horizontalLayout->addWidget(room_btn);


        retranslateUi(OnlineItem);

        QMetaObject::connectSlotsByName(OnlineItem);
    } // setupUi

    void retranslateUi(QDialog *OnlineItem)
    {
        OnlineItem->setWindowTitle(QCoreApplication::translate("OnlineItem", "Dialog", nullptr));
        image->setText(QString());
        nameLab->setText(QCoreApplication::translate("OnlineItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        room_lab->setText(QCoreApplication::translate("OnlineItem", "\346\210\277\344\270\273", nullptr));
        user_lab->setText(QCoreApplication::translate("OnlineItem", "8", nullptr));
        user_btn->setText(QCoreApplication::translate("OnlineItem", "1\345\217\267\351\272\246", nullptr));
        room_btn->setText(QCoreApplication::translate("OnlineItem", "\345\234\250\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineItem: public Ui_OnlineItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEITEM_H
