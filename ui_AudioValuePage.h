/********************************************************************************
** Form generated from reading UI file 'AudioValuePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOVALUEPAGE_H
#define UI_AUDIOVALUEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_AudioValuePage
{
public:
    QSlider *verticalSlider;

    void setupUi(QDialog *AudioValuePage)
    {
        if (AudioValuePage->objectName().isEmpty())
            AudioValuePage->setObjectName(QString::fromUtf8("AudioValuePage"));
        AudioValuePage->resize(36, 160);
        verticalSlider = new QSlider(AudioValuePage);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(1, 1, 36, 160));
        verticalSlider->setStyleSheet(QString::fromUtf8("/* \345\236\202\347\233\264\346\273\221\345\235\227\345\237\272\347\241\200\346\240\267\345\274\217 */\n"
"QSlider:vertical {\n"
"    min-width: 36px;  /* \347\241\256\344\277\235\350\266\263\345\244\237\345\256\275\345\272\246 */\n"
"    background: rgba(255, 255, 255, 0);\n"
"    border-radius: 18px;   /* \345\217\263\344\276\247\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"/* \345\236\202\347\233\264\346\273\221\346\247\275\346\240\267\345\274\217 */\n"
"QSlider::groove:vertical {\n"
"     background: rgba(255, 255, 255, 0);\n"
"    width: 36px;          /* \346\273\221\346\247\275\345\256\275\345\272\24636px */\n"
"    border-radius: 18px;  /* \346\273\221\346\247\275\345\234\206\350\247\22218px */\n"
"    margin: 0px 0;        /* \350\276\271\350\267\235\350\260\203\346\225\264 */   \n"
"}\n"
"\n"
"/* \345\236\202\347\233\264\346\273\221\345\235\227\346\211\213\346\237\204\346\240\267\345\274\217\357\274\210\347\272\242\350\211\262\357\274\211 */\n"
"QSlider::handle:vertical {\n"
"    background: rgba(255, 2"
                        "55, 255, 0);\n"
"    width: 36px;           /* \346\211\213\346\237\204\345\256\275\345\272\24636px */\n"
"    height: 36px;          /* \346\211\213\346\237\204\351\253\230\345\272\24636px */\n"
"    border-radius: 18px;   /* \346\211\213\346\237\204\345\234\206\350\247\22218px */\n"
"    margin: 0px 0px 1px 0px;  /* \350\260\203\346\225\264\346\211\213\346\237\204\345\236\202\347\233\264\345\261\205\344\270\255 */\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\346\264\273\345\212\250\345\214\272\345\237\237\357\274\210\345\267\246\344\276\247\357\274\211 */\n"
"QSlider::add-page:vertical {\n"
"    background: #ED525A;   /* \347\273\277\350\211\262\346\264\273\345\212\250\345\214\272\345\237\237 */\n"
"     border-top-left-radius: 0px;    /* \345\267\246\344\270\212\345\234\206\350\247\222 */\n"
"    border-top-right-radius: 0px;   /* \345\217\263\344\270\212\345\234\206\350\247\222 */\n"
"    border-bottom-left-radius: 18px;  /* \345\267\246\344\270\213\347\233\264\350\247\222 */\n"
"    border-bottom-right-radi"
                        "us: 18px; /* \345\217\263\344\270\213\347\233\264\350\247\222 */\n"
"\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\351\235\236\346\264\273\345\212\250\345\214\272\345\237\237\357\274\210\345\217\263\344\276\247\357\274\211 */\n"
"QSlider::sub-page:vertical {\n"
"    background: #363636;\n"
"    border-top-left-radius: 18px;    /* \345\267\246\344\270\212\345\234\206\350\247\222 */\n"
"    border-top-right-radius: 18px;   /* \345\217\263\344\270\212\345\234\206\350\247\222 */\n"
"    border-bottom-left-radius: 0px;  /* \345\267\246\344\270\213\347\233\264\350\247\222 */\n"
"    border-bottom-right-radius: 0px; /* \345\217\263\344\270\213\347\233\264\350\247\222 */\n"
"\n"
"}\n"
"\n"
"/* \351\232\220\350\227\217\351\273\230\350\256\244\346\214\211\351\222\256 */\n"
"QSlider::add-line:vertical, \n"
"QSlider::sub-line:vertical {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border: none;\n"
"}"));
        verticalSlider->setMaximum(255);
        verticalSlider->setValue(0);
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(AudioValuePage);

        QMetaObject::connectSlotsByName(AudioValuePage);
    } // setupUi

    void retranslateUi(QDialog *AudioValuePage)
    {
        AudioValuePage->setWindowTitle(QCoreApplication::translate("AudioValuePage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioValuePage: public Ui_AudioValuePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOVALUEPAGE_H
