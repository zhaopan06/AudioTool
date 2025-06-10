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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MicInfoItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QLabel *label;
    CRoundLabel *image;
    QLabel *mic;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *name;
    QPushButton *gift;

    void setupUi(QDialog *MicInfoItem)
    {
        if (MicInfoItem->objectName().isEmpty())
            MicInfoItem->setObjectName(QString::fromUtf8("MicInfoItem"));
        MicInfoItem->resize(122, 138);
        MicInfoItem->setMinimumSize(QSize(122, 138));
        MicInfoItem->setMaximumSize(QSize(122, 138));
        verticalLayout = new QVBoxLayout(MicInfoItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MicInfoItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 0, 86, 86));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        image = new CRoundLabel(widget_2);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(31, 13, 60, 60));
        image->setMinimumSize(QSize(60, 60));
        image->setMaximumSize(QSize(60, 60));
        image->setPixmap(QPixmap(QString::fromUtf8(":/images/live_mic_path.png")));
        image->setScaledContents(true);
        mic = new QLabel(widget_2);
        mic->setObjectName(QString::fromUtf8("mic"));
        mic->setGeometry(QRect(75, 57, 16, 16));
        mic->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_\351\227\255\351\272\246.png")));

        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(MicInfoItem);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 52));
        widget_3->setMaximumSize(QSize(16777215, 52));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        name = new QLabel(widget_3);
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

        verticalLayout_3->addWidget(name);

        gift = new QPushButton(widget_3);
        gift->setObjectName(QString::fromUtf8("gift"));
        gift->setMinimumSize(QSize(0, 24));
        gift->setMaximumSize(QSize(16777215, 24));
        gift->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 12px;\n"
"color: rgba(210,181,247,0.8);\n"
"line-height: 19px;\n"
"text-align: center;\n"
"font-style: normal;"));

        verticalLayout_3->addWidget(gift);


        verticalLayout->addWidget(widget_3);


        retranslateUi(MicInfoItem);

        QMetaObject::connectSlotsByName(MicInfoItem);
    } // setupUi

    void retranslateUi(QDialog *MicInfoItem)
    {
        MicInfoItem->setWindowTitle(QCoreApplication::translate("MicInfoItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
        mic->setText(QString());
        name->setText(QCoreApplication::translate("MicInfoItem", "1\345\217\267\351\272\246", nullptr));
        gift->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MicInfoItem: public Ui_MicInfoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICINFOITEM_H
