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
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    click_label *close;
    QWidget *widget_2;
    QLabel *image;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->resize(680, 530);
        ImageDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(ImageDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(ImageDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 16px;\n"
"border:1px solid rgba(183,183,183,1);"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 32));
        widget->setMaximumSize(QSize(16777215, 32));
        widget->setStyleSheet(QString::fromUtf8("border:none;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close = new click_label(widget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(24, 24));
        close->setMaximumSize(QSize(24, 24));
        close->setPixmap(QPixmap(QString::fromUtf8(":/images/login_close_n.png")));
        close->setScaledContents(true);

        horizontalLayout->addWidget(close);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border:none;"));
        image = new QLabel(widget_2);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 678, 494));
        image->setStyleSheet(QString::fromUtf8("border:none;"));
        image->setPixmap(QPixmap(QString::fromUtf8(":/image/chat/imageDef.png")));
        image->setScaledContents(false);
        image->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget_3);


        retranslateUi(ImageDialog);

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QCoreApplication::translate("ImageDialog", "\345\233\276\347\211\207\346\237\245\347\234\213\345\231\250", nullptr));
        close->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
