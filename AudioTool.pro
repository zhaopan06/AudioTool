QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 utf8_source

QMAKE_PROJECT_DEPTH = 0

LIBS += user32.lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
        ./Base/Agora \
        ./Base/ImSDK \
        ./SDK/Agora/include \
        ./SDK/ImSDK/include \        
        ./Base/Http \
        ./control \
        ./UI


LIBS += \
    -L$$PWD/SDK/Agora/lib   \
    -L$$PWD/SDK/ImSDK/lib

LIBS += \
    -lagora_rtc_sdk.dll \
    -limsdk

SOURCES += \
    Base/Agora/agorartcengineinterface.cpp \
    Base/Http/Global.cpp \
    Base/Http/HttpInterFace.cpp \
    Base/Http/HttpUserInfo.cpp \
    Base/IMSDK/TimInterface.cpp \
    UI/LoginPage.cpp \
    UI/RoomItem.cpp \
    UI/mainwindow.cpp \
    control/CRoundLabel.cpp \
    control/EmotionWidget.cpp \
    control/click_label.cpp \
    main.cpp


HEADERS += \
    Base/Agora/agorartcengineinterface.h \
    Base/Http/Global.h \
    Base/Http/HttpInterFace.h \
    Base/Http/HttpUserInfo.h \
    Base/IMSDK/TimInterface.h \
    UI/LoginPage.h \
    UI/RoomItem.h \
    UI/mainwindow.h \
    control/CRoundLabel.h \
    control/EmotionWidget.h \
    control/click_label.h

FORMS += \
    UI/LoginPage.ui \
    UI/RoomItem.ui \
    UI/mainwindow.ui \
    control/EmotionWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
