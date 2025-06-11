/********************************************************************************
** Form generated from reading UI file 'ChatImageMyItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATIMAGEMYITEM_H
#define UI_CHATIMAGEMYITEM_H

#include <CRoundLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_ChatImageMyItem
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    CRoundLabel *label;
    QSpacerItem *verticalSpacer;
    click_label *image;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ChatImageMyItem)
    {
        if (ChatImageMyItem->objectName().isEmpty())
            ChatImageMyItem->setObjectName(QString::fromUtf8("ChatImageMyItem"));
        ChatImageMyItem->resize(414, 170);
        ChatImageMyItem->setLayoutDirection(Qt::RightToLeft);
        horizontalLayout = new QHBoxLayout(ChatImageMyItem);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, 0, -1);
        label = new CRoundLabel(ChatImageMyItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(46, 46));
        label->setMaximumSize(QSize(46, 46));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        image = new click_label(ChatImageMyItem);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(150, 150));
        image->setMaximumSize(QSize(150, 150));
        image->setStyleSheet(QString::fromUtf8("border-radius: 16px;"));
        image->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(image);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ChatImageMyItem);

        QMetaObject::connectSlotsByName(ChatImageMyItem);
    } // setupUi

    void retranslateUi(QDialog *ChatImageMyItem)
    {
        ChatImageMyItem->setWindowTitle(QCoreApplication::translate("ChatImageMyItem", "Dialog", nullptr));
        label->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatImageMyItem: public Ui_ChatImageMyItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATIMAGEMYITEM_H
