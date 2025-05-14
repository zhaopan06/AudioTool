/********************************************************************************
** Form generated from reading UI file 'EmotionItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONITEM_H
#define UI_EMOTIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_EmotionItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *name;
    click_label *addSourceBtn_2;
    QLabel *image;

    void setupUi(QDialog *EmotionItem)
    {
        if (EmotionItem->objectName().isEmpty())
            EmotionItem->setObjectName(QString::fromUtf8("EmotionItem"));
        EmotionItem->resize(91, 83);
        EmotionItem->setMinimumSize(QSize(91, 83));
        verticalLayout = new QVBoxLayout(EmotionItem);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(EmotionItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget{	\n"
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
        name = new QLabel(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(1, 66, 89, 17));
        name->setMinimumSize(QSize(0, 17));
        name->setMaximumSize(QSize(16777215, 17));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 12px;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"text-align: center;\n"
"background:transparent;\n"
"border:none;"));
        name->setAlignment(Qt::AlignCenter);
        addSourceBtn_2 = new click_label(widget);
        addSourceBtn_2->setObjectName(QString::fromUtf8("addSourceBtn_2"));
        addSourceBtn_2->setGeometry(QRect(0, 0, 91, 83));
        addSourceBtn_2->setMinimumSize(QSize(91, 83));
        addSourceBtn_2->setMaximumSize(QSize(91, 83));
        addSourceBtn_2->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
"border:none;"));
        image = new QLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(18, 3, 55, 54));
        image->setMinimumSize(QSize(55, 54));
        image->setMaximumSize(QSize(55, 54));
        image->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));
        image->setScaledContents(true);
        name->raise();
        image->raise();
        addSourceBtn_2->raise();

        verticalLayout->addWidget(widget);


        retranslateUi(EmotionItem);

        QMetaObject::connectSlotsByName(EmotionItem);
    } // setupUi

    void retranslateUi(QDialog *EmotionItem)
    {
        EmotionItem->setWindowTitle(QCoreApplication::translate("EmotionItem", "Dialog", nullptr));
        name->setText(QString());
        addSourceBtn_2->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EmotionItem: public Ui_EmotionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONITEM_H
