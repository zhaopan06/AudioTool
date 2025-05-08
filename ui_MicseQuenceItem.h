/********************************************************************************
** Form generated from reading UI file 'MicseQuenceItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICSEQUENCEITEM_H
#define UI_MICSEQUENCEITEM_H

#include <CRoundLabel.h>
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

class Ui_MicseQuenceItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    CRoundLabel *image;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *user_lab;
    QSpacerItem *horizontalSpacer;
    QPushButton *micBtn;

    void setupUi(QDialog *MicseQuenceItem)
    {
        if (MicseQuenceItem->objectName().isEmpty())
            MicseQuenceItem->setObjectName(QString::fromUtf8("MicseQuenceItem"));
        MicseQuenceItem->resize(405, 70);
        MicseQuenceItem->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(MicseQuenceItem);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(MicseQuenceItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(22, 0));
        label->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"font-style: normal;"));

        horizontalLayout->addWidget(label);

        image = new CRoundLabel(MicseQuenceItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(47, 46));
        image->setMaximumSize(QSize(47, 46));
        image->setScaledContents(true);

        horizontalLayout->addWidget(image);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 9, -1, 9);
        nameLab = new QLabel(MicseQuenceItem);
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
        pushButton = new QPushButton(MicseQuenceItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(38, 0));
        pushButton->setStyleSheet(QString::fromUtf8("background: rgba(128, 220, 255, 0.2);\n"
"border-radius: 8px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 11px;\n"
"color: #80DCFF;\n"
"line-height: 16px;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/live_people_man.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(pushButton);

        user_lab = new QLabel(MicseQuenceItem);
        user_lab->setObjectName(QString::fromUtf8("user_lab"));
        user_lab->setMinimumSize(QSize(37, 16));
        user_lab->setMaximumSize(QSize(37, 16));
        user_lab->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 10px;\n"
"color: #FFFFFF;\n"
"text-align: right;\n"
"font-style: normal;\n"
"\n"
"background-image: url(:/images/live_lev.png);\n"
"background-position: center;\n"
"padding-right: 6px; \n"
" text-align: right;"));
        user_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(user_lab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        micBtn = new QPushButton(MicseQuenceItem);
        micBtn->setObjectName(QString::fromUtf8("micBtn"));
        micBtn->setMinimumSize(QSize(77, 32));
        micBtn->setMaximumSize(QSize(77, 32));
        micBtn->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 14px;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
""));
        micBtn->setIconSize(QSize(16, 17));

        horizontalLayout->addWidget(micBtn);


        retranslateUi(MicseQuenceItem);

        QMetaObject::connectSlotsByName(MicseQuenceItem);
    } // setupUi

    void retranslateUi(QDialog *MicseQuenceItem)
    {
        MicseQuenceItem->setWindowTitle(QCoreApplication::translate("MicseQuenceItem", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MicseQuenceItem", "1", nullptr));
        image->setText(QString());
        nameLab->setText(QCoreApplication::translate("MicseQuenceItem", "\347\224\250\346\210\267\346\230\265\347\247\260\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\344\275\215\345\215\240\342\200\246", nullptr));
        pushButton->setText(QCoreApplication::translate("MicseQuenceItem", "24", nullptr));
        user_lab->setText(QCoreApplication::translate("MicseQuenceItem", "8", nullptr));
        micBtn->setText(QCoreApplication::translate("MicseQuenceItem", "\344\270\212\351\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MicseQuenceItem: public Ui_MicseQuenceItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICSEQUENCEITEM_H
