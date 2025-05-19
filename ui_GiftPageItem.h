/********************************************************************************
** Form generated from reading UI file 'GiftPageItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFTPAGEITEM_H
#define UI_GIFTPAGEITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_GiftPageItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_17;
    QLabel *name;
    QLabel *image;
    click_label *addSourceBtn_2;
    QPushButton *price;

    void setupUi(QDialog *GiftPageItem)
    {
        if (GiftPageItem->objectName().isEmpty())
            GiftPageItem->setObjectName(QString::fromUtf8("GiftPageItem"));
        GiftPageItem->resize(112, 131);
        verticalLayout = new QVBoxLayout(GiftPageItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_17 = new QWidget(GiftPageItem);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        widget_17->setMinimumSize(QSize(112, 131));
        widget_17->setMaximumSize(QSize(112, 131));
        widget_17->setStyleSheet(QString::fromUtf8("QWidget{	\n"
"border:none;\n"
"}\n"
"\n"
"QWidget::hover{\n"
"\n"
"background: #261D47;\n"
"border-radius: 17px;\n"
"border: 2px solid rgba(240, 150, 242, 1);\n"
"}\n"
""));
        name = new QLabel(widget_17);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(1, 74, 110, 19));
        name->setMinimumSize(QSize(110, 19));
        name->setMaximumSize(QSize(110, 19));
        name->setLayoutDirection(Qt::LeftToRight);
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 13px;\n"
"color: #FFFFFF;\n"
"text-align: center;\n"
"background:transparent;\n"
"border:none;"));
        name->setAlignment(Qt::AlignCenter);
        image = new QLabel(widget_17);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(21, 3, 69, 69));
        image->setMinimumSize(QSize(69, 69));
        image->setMaximumSize(QSize(69, 69));
        image->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
"border:none;"));
        image->setScaledContents(false);
        image->setAlignment(Qt::AlignCenter);
        addSourceBtn_2 = new click_label(widget_17);
        addSourceBtn_2->setObjectName(QString::fromUtf8("addSourceBtn_2"));
        addSourceBtn_2->setGeometry(QRect(0, 0, 112, 131));
        addSourceBtn_2->setMinimumSize(QSize(112, 131));
        addSourceBtn_2->setMaximumSize(QSize(112, 131));
        addSourceBtn_2->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
"border:none;"));
        price = new QPushButton(widget_17);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(1, 96, 110, 20));
        price->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: .\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 13px;\n"
"color: #858397;\n"
"text-align: center;\n"
"font-style: normal;\n"
"background: transparent;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/jinbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        price->setIcon(icon);
        price->setIconSize(QSize(19, 19));
        addSourceBtn_2->raise();
        name->raise();
        image->raise();
        price->raise();

        verticalLayout->addWidget(widget_17);


        retranslateUi(GiftPageItem);

        QMetaObject::connectSlotsByName(GiftPageItem);
    } // setupUi

    void retranslateUi(QDialog *GiftPageItem)
    {
        GiftPageItem->setWindowTitle(QCoreApplication::translate("GiftPageItem", "Dialog", nullptr));
        name->setText(QCoreApplication::translate("GiftPageItem", "\346\267\273\345\212\240\347\233\264\346\222\255\347\264\240\346\235\220", nullptr));
        image->setText(QString());
        addSourceBtn_2->setText(QString());
        price->setText(QCoreApplication::translate("GiftPageItem", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiftPageItem: public Ui_GiftPageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIFTPAGEITEM_H
