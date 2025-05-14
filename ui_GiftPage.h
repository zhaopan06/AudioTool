/********************************************************************************
** Form generated from reading UI file 'GiftPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFTPAGE_H
#define UI_GIFTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GiftPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_58;
    QHBoxLayout *horizontalLayout_39;
    QPushButton *giftBtn;
    QPushButton *gift1Btn;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *GiftPage)
    {
        if (GiftPage->objectName().isEmpty())
            GiftPage->setObjectName(QString::fromUtf8("GiftPage"));
        GiftPage->resize(488, 500);
        GiftPage->setMinimumSize(QSize(488, 500));
        verticalLayout_2 = new QVBoxLayout(GiftPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GiftPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background: #0B0A2B;\n"
"border-radius: 20px 20px 12px 12px;"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 0, 10, 10);
        widget_58 = new QWidget(widget);
        widget_58->setObjectName(QString::fromUtf8("widget_58"));
        widget_58->setMinimumSize(QSize(0, 56));
        widget_58->setMaximumSize(QSize(16777215, 56));
        widget_58->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border:none;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: rgba(133, 131, 151, 1);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"   border:none;\n"
"\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #CE94FC;\n"
"}\n"
"\n"
""));
        horizontalLayout_39 = new QHBoxLayout(widget_58);
        horizontalLayout_39->setSpacing(25);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalLayout_39->setContentsMargins(5, 0, 5, 1);
        giftBtn = new QPushButton(widget_58);
        buttonGroup = new QButtonGroup(GiftPage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(giftBtn);
        giftBtn->setObjectName(QString::fromUtf8("giftBtn"));
        giftBtn->setMinimumSize(QSize(0, 32));
        giftBtn->setCheckable(true);
        giftBtn->setChecked(true);

        horizontalLayout_39->addWidget(giftBtn);

        gift1Btn = new QPushButton(widget_58);
        buttonGroup->addButton(gift1Btn);
        gift1Btn->setObjectName(QString::fromUtf8("gift1Btn"));
        gift1Btn->setCheckable(true);
        gift1Btn->setChecked(false);

        horizontalLayout_39->addWidget(gift1Btn);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_15);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, -1, -1);
        label = new QLabel(widget_58);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(21, 21));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/jinbi.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget_58);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"font-size: 16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label_2);

        pushButton = new QPushButton(widget_58);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(8, 13));
        pushButton->setMaximumSize(QSize(8, 13));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/nextBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(8, 13));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_39->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget_58);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 458, 434));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_3->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 458, 434));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout_4->addLayout(gridLayout_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollArea_2);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addWidget(widget);


        retranslateUi(GiftPage);

        QMetaObject::connectSlotsByName(GiftPage);
    } // setupUi

    void retranslateUi(QDialog *GiftPage)
    {
        GiftPage->setWindowTitle(QCoreApplication::translate("GiftPage", "Dialog", nullptr));
        giftBtn->setText(QCoreApplication::translate("GiftPage", "\347\244\274\347\211\251", nullptr));
        gift1Btn->setText(QCoreApplication::translate("GiftPage", "\347\244\274\347\233\222", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("GiftPage", "886", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GiftPage: public Ui_GiftPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIFTPAGE_H
