/********************************************************************************
** Form generated from reading UI file 'ImageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "click_label.h"

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    click_label *close;
    QWidget *widget_2;
    QLabel *image;
    click_label *left;
    click_label *right;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->resize(680, 530);
        ImageDialog->setStyleSheet(QString::fromUtf8("background:rgba(255,255,255,1);\n"
"border:1px solid rgba(183,183,183,1);"));
        verticalLayout = new QVBoxLayout(ImageDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(ImageDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 32));
        widget->setMaximumSize(QSize(16777215, 32));
        widget->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgba(229,229,229,1);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close = new click_label(widget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(13, 13));
        close->setMaximumSize(QSize(13, 13));
        close->setPixmap(QPixmap(QString::fromUtf8(":/image/mainUI/closeSearch.png")));

        horizontalLayout->addWidget(close);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ImageDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border:none;"));
        image = new QLabel(widget_2);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 678, 494));
        image->setStyleSheet(QString::fromUtf8("border:none;"));
        image->setPixmap(QPixmap(QString::fromUtf8(":/image/chat/imageDef.png")));
        image->setScaledContents(false);
        image->setAlignment(Qt::AlignCenter);
        left = new click_label(widget_2);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(20, 228, 40, 40));
        left->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent; "));
        left->setPixmap(QPixmap(QString::fromUtf8(":/image/chat/imageLeft.png")));
        right = new click_label(widget_2);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(614, 228, 40, 40));
        right->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: transparent; "));
        right->setPixmap(QPixmap(QString::fromUtf8(":/image/chat/imageRight.png")));

        verticalLayout->addWidget(widget_2);


        retranslateUi(ImageDialog);

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QCoreApplication::translate("ImageDialog", "\345\233\276\347\211\207\346\237\245\347\234\213\345\231\250", nullptr));
        close->setText(QString());
        image->setText(QString());
        left->setText(QString());
        right->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
