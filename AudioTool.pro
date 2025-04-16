QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_PROJECT_DEPTH = 0

LIBS += user32.lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
        ./SDK/Agora/include \
        ./Base/Agora

LIBS += \
    -L$$PWD/SDK/Agora/lib

LIBS += \
    -lagora_rtc_sdk.dll

SOURCES += \
    Base/Agora/agorartcengineinterface.cpp \
    Base/Http/HttpInterFace.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Base/Agora/agorartcengineinterface.h \
    Base/Http/HttpInterFace.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
