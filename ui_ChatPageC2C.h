/********************************************************************************
** Form generated from reading UI file 'ChatPageC2C.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGEC2C_H
#define UI_CHATPAGEC2C_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImageTextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_ChatPageC2C
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_36;
    QHBoxLayout *horizontalLayout_22;
    QLabel *name;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *Attention;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QWidget *widget_44;
    QVBoxLayout *verticalLayout_34;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *emoBtn;
    QPushButton *imageBtn;
    QSpacerItem *horizontalSpacer_13;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    ImageTextEdit *textEdit;
    QPushButton *sendBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QDialog *ChatPageC2C)
    {
        if (ChatPageC2C->objectName().isEmpty())
            ChatPageC2C->setObjectName(QString::fromUtf8("ChatPageC2C"));
        ChatPageC2C->resize(1335, 773);
        ChatPageC2C->setStyleSheet(QString::fromUtf8("background: #222429;\n"
"border-radius: 12px;"));
        verticalLayout = new QVBoxLayout(ChatPageC2C);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(16, 0, 16, 16);
        widget_36 = new QWidget(ChatPageC2C);
        widget_36->setObjectName(QString::fromUtf8("widget_36"));
        widget_36->setMinimumSize(QSize(0, 56));
        widget_36->setMaximumSize(QSize(16777215, 56));
        widget_36->setStyleSheet(QString::fromUtf8("QWidget#widget_36 {\n"
"    border-bottom: 1px solid #383B43;\n"
"border-radius: 0px;\n"
"    }"));
        horizontalLayout_22 = new QHBoxLayout(widget_36);
        horizontalLayout_22->setSpacing(12);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(20, 0, 16, 1);
        name = new QLabel(widget_36);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 500;\n"
"font-size: 18px;\n"
"color: #FFFFFF;\n"
"line-height: 25px;\n"
"text-align: left;\n"
"font-style: normal;"));

        horizontalLayout_22->addWidget(name);

        pushButton_2 = new QPushButton(widget_36);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 32));
        pushButton_2->setMaximumSize(QSize(16777215, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgba(245,151,255,0.2);\n"
"border-radius: 16px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: 400;\n"
"font-size: 14px;\n"
"color: #F597FF;\n"
"line-height: 20px;\n"
"font-style: normal;\n"
"\n"
" padding-left: 10px; padding-right: 10px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/live_inRoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(16, 17));

        horizontalLayout_22->addWidget(pushButton_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(24);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, -1, -1);
        Attention = new QPushButton(widget_36);
        Attention->setObjectName(QString::fromUtf8("Attention"));
        Attention->setMinimumSize(QSize(88, 32));
        Attention->setStyleSheet(QString::fromUtf8("background: #36383B;\n"
"border-radius: 16px;\n"
"\n"
"\n"
"font-weight: 500;\n"
"font-size: 16px;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"text-align: center;\n"
"font-style: normal;"));
        Attention->setIconSize(QSize(24, 25));

        horizontalLayout->addWidget(Attention);


        horizontalLayout_22->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget_36);

        widget = new QWidget(ChatPageC2C);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("border-radius: 0px;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 16, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setSpacing(6);

        verticalLayout_2->addWidget(listWidget);


        verticalLayout->addWidget(widget);

        widget_44 = new QWidget(ChatPageC2C);
        widget_44->setObjectName(QString::fromUtf8("widget_44"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_44->sizePolicy().hasHeightForWidth());
        widget_44->setSizePolicy(sizePolicy2);
        widget_44->setMinimumSize(QSize(0, 98));
        verticalLayout_34 = new QVBoxLayout(widget_44);
        verticalLayout_34->setSpacing(8);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));
        verticalLayout_34->setContentsMargins(16, 20, 16, 0);
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(-1, 4, -1, -1);
        emoBtn = new QPushButton(widget_44);
        emoBtn->setObjectName(QString::fromUtf8("emoBtn"));
        emoBtn->setMinimumSize(QSize(24, 24));
        emoBtn->setMaximumSize(QSize(24, 24));
        emoBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"border:none;\n"
"background-image: url(:/images/live_em_n.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"border:none;\n"
"background-image: url(:/images/live_em_c.png);\n"
"\n"
"}\n"
""));
        emoBtn->setIconSize(QSize(24, 24));

        horizontalLayout_30->addWidget(emoBtn);

        imageBtn = new QPushButton(widget_44);
        imageBtn->setObjectName(QString::fromUtf8("imageBtn"));
        imageBtn->setMinimumSize(QSize(24, 24));
        imageBtn->setMaximumSize(QSize(24, 24));
        imageBtn->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"border:none;\n"
"background-image: url(:/images/live_image_n.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"border:none;\n"
"background-image: url(:/images/live_image_c.png);\n"
"\n"
"}\n"
""));
        imageBtn->setIconSize(QSize(24, 24));

        horizontalLayout_30->addWidget(imageBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_13);


        verticalLayout_34->addLayout(horizontalLayout_30);

        frame_6 = new QFrame(widget_44);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy2.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy2);
        frame_6->setMinimumSize(QSize(0, 120));
        frame_6->setMaximumSize(QSize(16777215, 16777215));
        frame_6->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border-radius: 21px;\n"
"border: 1px solid #A8A8A7;\n"
"\n"
""));
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(16, 10, 10, 10);
        textEdit = new ImageTextEdit(frame_6);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);
        textEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size: 16px;\n"
"color: #FFFFFF;"));

        horizontalLayout_6->addWidget(textEdit);

        sendBtn = new QPushButton(frame_6);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setEnabled(false);
        sendBtn->setMinimumSize(QSize(66, 28));
        sendBtn->setMaximumSize(QSize(16777215, 16777215));
        sendBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #D197FE, stop:1 #9752ED);\n"
"border-radius: 14px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:none;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"background: qlineargradient(\n"
"    x1:0, y1:0, \n"
"    x2:1, y2:0, \n"
"    stop:0 rgba(209, 151, 254, 0.5),  /* #D197FE 50%\351\200\217\346\230\216\345\272\246 */\n"
"    stop:1 rgba(151, 82, 237, 0.5)    /* #9752ED 50%\351\200\217\346\230\216\345\272\246 */\n"
");\n"
"border-radius: 14px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:none;\n"
"font-size: 14px;\n"
"color: #FFFFFF;\n"
"line-height: 20px;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/live_send_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendBtn->setIcon(icon1);
        sendBtn->setIconSize(QSize(17, 16));

        horizontalLayout_6->addWidget(sendBtn);


        verticalLayout_34->addWidget(frame_6);


        verticalLayout->addWidget(widget_44);

        widget_2 = new QWidget(ChatPageC2C);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 0, 5, 1);

        verticalLayout->addWidget(widget_2);


        retranslateUi(ChatPageC2C);

        QMetaObject::connectSlotsByName(ChatPageC2C);
    } // setupUi

    void retranslateUi(QDialog *ChatPageC2C)
    {
        ChatPageC2C->setWindowTitle(QCoreApplication::translate("ChatPageC2C", "Dialog", nullptr));
        name->setText(QCoreApplication::translate("ChatPageC2C", "\350\277\221\346\234\237\346\264\273\345\212\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatPageC2C", "PushButton", nullptr));
        Attention->setText(QCoreApplication::translate("ChatPageC2C", "\345\217\226\346\266\210\345\205\263\346\263\250", nullptr));
        emoBtn->setText(QString());
        imageBtn->setText(QString());
        textEdit->setPlaceholderText(QCoreApplication::translate("ChatPageC2C", "\350\257\267\350\276\223\345\205\245\345\206\205\345\256\271\357\274\214\346\224\257\346\214\201\347\233\264\346\216\245\347\262\230\350\264\264\345\233\276\347\211\207", nullptr));
        sendBtn->setText(QCoreApplication::translate("ChatPageC2C", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBtn->setShortcut(QCoreApplication::translate("ChatPageC2C", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class ChatPageC2C: public Ui_ChatPageC2C {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGEC2C_H
