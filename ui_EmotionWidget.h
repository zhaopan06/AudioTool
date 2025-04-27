/********************************************************************************
** Form generated from reading UI file 'EmotionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONWIDGET_H
#define UI_EMOTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmotionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;

    void setupUi(QWidget *EmotionWidget)
    {
        if (EmotionWidget->objectName().isEmpty())
            EmotionWidget->setObjectName(QString::fromUtf8("EmotionWidget"));
        EmotionWidget->resize(226, 226);
        EmotionWidget->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(233,233,233,1);\n"
"background-color: transparent; "));
        verticalLayout = new QVBoxLayout(EmotionWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        scrollArea = new QScrollArea(EmotionWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgba(255,255,255,1);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 224, 224));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QScrollBar:vertical\n"
"{\n"
"    width:8px;\n"
"    background:transparent;\n"
"    margin:0px,0px,0px,0px;\n"
"    padding-top:0px;\n"
"    padding-bottom:0px;\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    width:8px;\n"
"    background: rgba(219,219,219,1);\n"
"    border-radius:4px;\n"
"    min-height:50;\n"
"}\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background-color:none;}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"}\n"
"QScrollBar:horizontal {\n"
"        height:0px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        horizontalLayout->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(EmotionWidget);

        QMetaObject::connectSlotsByName(EmotionWidget);
    } // setupUi

    void retranslateUi(QWidget *EmotionWidget)
    {
        EmotionWidget->setWindowTitle(QCoreApplication::translate("EmotionWidget", "EmotionWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmotionWidget: public Ui_EmotionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONWIDGET_H
