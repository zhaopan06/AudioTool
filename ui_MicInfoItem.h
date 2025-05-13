/********************************************************************************
** Form generated from reading UI file 'MicInfoItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICINFOITEM_H
#define UI_MICINFOITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MicInfoItem
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_33;
    CRoundLabel *image;
    QLabel *name;
    QPushButton *gift;

    void setupUi(QDialog *MicInfoItem)
    {
        if (MicInfoItem->objectName().isEmpty())
            MicInfoItem->setObjectName(QString::fromUtf8("MicInfoItem"));
        MicInfoItem->resize(122, 124);
        MicInfoItem->setMinimumSize(QSize(122, 124));
        MicInfoItem->setMaximumSize(QSize(122, 125));
        verticalLayout = new QVBoxLayout(MicInfoItem);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 2);
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(0);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(-1, -1, -1, 3);
        image = new CRoundLabel(MicInfoItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(60, 60));
        image->setMaximumSize(QSize(60, 60));
        image->setPixmap(QPixmap(QString::fromUtf8(":/images/live_mic_path.png")));
        image->setScaledContents(true);

        horizontalLayout_33->addWidget(image);


        verticalLayout->addLayout(horizontalLayout_33);

        name = new QLabel(MicInfoItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setMaximumSize(QSize(16777215, 22));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 16px;\n"
"color: rgba(240,230,252,0.8);\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(name);

        gift = new QPushButton(MicInfoItem);
        gift->setObjectName(QString::fromUtf8("gift"));
        gift->setMinimumSize(QSize(0, 19));
        gift->setMaximumSize(QSize(16777215, 19));
        gift->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: rgba(210,181,247,0.8);\n"
"line-height: 19px;\n"
"text-align: center;\n"
"font-style: normal;"));

        verticalLayout->addWidget(gift);


        retranslateUi(MicInfoItem);

        QMetaObject::connectSlotsByName(MicInfoItem);
    } // setupUi

    void retranslateUi(QDialog *MicInfoItem)
    {
        MicInfoItem->setWindowTitle(QCoreApplication::translate("MicInfoItem", "Dialog", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("MicInfoItem", "1\345\217\267\351\272\246", nullptr));
        gift->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MicInfoItem: public Ui_MicInfoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICINFOITEM_H
