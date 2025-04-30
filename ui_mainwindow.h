/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *enterRoom;
    QPushButton *createRoom;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *emoBtn;
    QLineEdit *msgEdit;
    QToolButton *sendBtn;
    QListWidget *msgList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1093, 811);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        enterRoom = new QPushButton(centralwidget);
        enterRoom->setObjectName(QString::fromUtf8("enterRoom"));
        enterRoom->setGeometry(QRect(280, 470, 75, 23));
        createRoom = new QPushButton(centralwidget);
        createRoom->setObjectName(QString::fromUtf8("createRoom"));
        createRoom->setGeometry(QRect(90, 450, 75, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 460, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 400, 75, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 530, 75, 23));
        frame_6 = new QFrame(centralwidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(740, 660, 301, 70));
        frame_6->setMinimumSize(QSize(0, 70));
        frame_6->setMaximumSize(QSize(16777215, 70));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame#frame_6\n"
"{\n"
"	border-left: 1px solid rgb(40,56,89);\n"
"	background-color: #233251;\n"
"}"));
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        emoBtn = new QToolButton(frame_6);
        emoBtn->setObjectName(QString::fromUtf8("emoBtn"));
        emoBtn->setMinimumSize(QSize(40, 70));
        emoBtn->setMaximumSize(QSize(40, 70));
        emoBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgba(23,36,67,1);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Live/Live_biaoqing.png"), QSize(), QIcon::Normal, QIcon::Off);
        emoBtn->setIcon(icon);
        emoBtn->setIconSize(QSize(24, 24));
        emoBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(emoBtn);

        msgEdit = new QLineEdit(frame_6);
        msgEdit->setObjectName(QString::fromUtf8("msgEdit"));
        msgEdit->setMinimumSize(QSize(0, 70));
        msgEdit->setMaximumSize(QSize(16777215, 70));
        msgEdit->setStyleSheet(QString::fromUtf8("background:rgba(23,36,67,1);\n"
"border:none;\n"
"font-size:12px;\n"
"font-family:SimSun;\n"
"font-weight:400;\n"
"color:rgba(83,92,112,1);"));

        horizontalLayout_6->addWidget(msgEdit);

        sendBtn = new QToolButton(frame_6);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setMinimumSize(QSize(60, 70));
        sendBtn->setMaximumSize(QSize(16777215, 16777215));
        sendBtn->setStyleSheet(QString::fromUtf8("background:rgba(41,58,97,1);\n"
"font-size:14px;\n"
"font-family:MicrosoftYaHei;\n"
"color:rgba(255,255,255,1);\n"
""));
        sendBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(sendBtn);

        msgList = new QListWidget(centralwidget);
        msgList->setObjectName(QString::fromUtf8("msgList"));
        msgList->setGeometry(QRect(740, 180, 301, 481));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msgList->sizePolicy().hasHeightForWidth());
        msgList->setSizePolicy(sizePolicy);
        msgList->setMinimumSize(QSize(0, 0));
        msgList->setMaximumSize(QSize(16777215, 16777215));
        msgList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	background:rgba(37,51,83,1);\n"
"	border:none;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"	border:none;\n"
"    background:rgba(37,51,83,1);\n"
"}\n"
"QListWidget::item:hover\n"
"{\n"
"	border:none;\n"
"    background:rgba(33,60,100,1);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background:rgba(37,51,83,1);\n"
"    padding:0px;\n"
"    margin:0px;\n"
"    border:none;\n"
"}"));
        msgList->setFrameShape(QFrame::NoFrame);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1093, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        enterRoom->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\346\210\277\351\227\264", nullptr));
        createRoom->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\351\272\246", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\347\276\244\350\201\212", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\203\205", nullptr));
        emoBtn->setText(QString());
        msgEdit->setText(QString());
        msgEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\222\214\345\244\247\345\256\266\350\201\212\350\201\212\345\244\251", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBtn->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
