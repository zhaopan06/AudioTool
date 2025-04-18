QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_PROJECT_DEPTH = 0

LIBS += user32.lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
        ./Base/Agora \
        ./SDK/Agora/include \
        ./Base/Http \
        ./control \
        ./UI


LIBS += \
    -L$$PWD/SDK/Agora/lib

LIBS += \
    -lagora_rtc_sdk.dll

SOURCES += \
    Base/Agora/agorartcengineinterface.cpp \
    Base/Http/HttpInterFace.cpp \
    Base/Http/HttpUserInfo.cpp \
    UI/LoginPage.cpp \
    UI/mainwindow.cpp \
    control/click_label.cpp \
    main.cpp


HEADERS += \
    Base/Agora/agorartcengineinterface.h \
    Base/Http/HttpInterFace.h \
    Base/Http/HttpUserInfo.h \
    UI/LoginPage.h \
    UI/mainwindow.h \
    control/click_label.h

FORMS += \
    UI/LoginPage.ui \
    UI/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
