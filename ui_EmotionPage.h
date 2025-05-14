/********************************************************************************
** Form generated from reading UI file 'EmotionPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONPAGE_H
#define UI_EMOTIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmotionPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;

    void setupUi(QDialog *EmotionPage)
    {
        if (EmotionPage->objectName().isEmpty())
            EmotionPage->setObjectName(QString::fromUtf8("EmotionPage"));
        EmotionPage->resize(488, 500);
        EmotionPage->setMinimumSize(QSize(488, 500));
        verticalLayout = new QVBoxLayout(EmotionPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(EmotionPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: #0B0A2B;\n"
"border-radius: 20px 20px 12px 12px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(16, 24, 0, 24);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 472, 452));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(24);
        gridLayout->setContentsMargins(0, -1, 0, -1);

        horizontalLayout->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget);


        retranslateUi(EmotionPage);

        QMetaObject::connectSlotsByName(EmotionPage);
    } // setupUi

    void retranslateUi(QDialog *EmotionPage)
    {
        EmotionPage->setWindowTitle(QCoreApplication::translate("EmotionPage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmotionPage: public Ui_EmotionPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONPAGE_H
