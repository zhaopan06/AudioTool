/********************************************************************************
** Form generated from reading UI file 'ChatEmoTionItem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATEMOTIONITEM_H
#define UI_CHATEMOTIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ChatEmoTionItem
{
public:

    void setupUi(QDialog *ChatEmoTionItem)
    {
        if (ChatEmoTionItem->objectName().isEmpty())
            ChatEmoTionItem->setObjectName(QString::fromUtf8("ChatEmoTionItem"));
        ChatEmoTionItem->resize(425, 100);

        retranslateUi(ChatEmoTionItem);

        QMetaObject::connectSlotsByName(ChatEmoTionItem);
    } // setupUi

    void retranslateUi(QDialog *ChatEmoTionItem)
    {
        ChatEmoTionItem->setWindowTitle(QCoreApplication::translate("ChatEmoTionItem", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatEmoTionItem: public Ui_ChatEmoTionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATEMOTIONITEM_H
