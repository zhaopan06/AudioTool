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
    UI/ChatEmoTionItem.cpp \
    UI/ChatImageItem.cpp \
    UI/ChatImageMyItem.cpp \
    UI/ChatTextItem.cpp \
    UI/ChatTextMyItem.cpp \
    UI/ContributeItem.cpp \
    UI/GIftItem.cpp \
    UI/GiftPage.cpp \
    UI/GiftPageItem.cpp \
    UI/LoginPage.cpp \
    UI/MicInfoItem.cpp \
    UI/MicseQuenceItem.cpp \
    UI/NewUserItem.cpp \
    UI/NewUserPage.cpp \
    UI/OnlineItem.cpp \
    UI/RoomItem.cpp \
    UI/UserinfoPage.cpp \
    UI/mainwindow.cpp \
    control/CRoundLabel.cpp \
    control/EmotionItem.cpp \
    control/EmotionPage.cpp \
    control/MsgBox.cpp \
    control/click_label.cpp \
    main.cpp


HEADERS += \
    Base/Agora/agorartcengineinterface.h \
    Base/Http/Global.h \
    Base/Http/HttpInterFace.h \
    Base/Http/HttpUserInfo.h \
    Base/IMSDK/TimInterface.h \
    UI/ChatEmoTionItem.h \
    UI/ChatImageItem.h \
    UI/ChatImageMyItem.h \
    UI/ChatTextItem.h \
    UI/ChatTextMyItem.h \
    UI/ContributeItem.h \
    UI/GIftItem.h \
    UI/GiftPage.h \
    UI/GiftPageItem.h \
    UI/LoginPage.h \
    UI/MicInfoItem.h \
    UI/MicseQuenceItem.h \
    UI/NewUserItem.h \
    UI/NewUserPage.h \
    UI/OnlineItem.h \
    UI/RoomItem.h \
    UI/UserinfoPage.h \
    UI/mainwindow.h \
    control/CRoundLabel.h \
    control/EmotionItem.h \
    control/EmotionPage.h \
    control/MsgBox.h \
    control/click_label.h

FORMS += \
    UI/ChatEmoTionItem.ui \
    UI/ChatImageItem.ui \
    UI/ChatImageMyItem.ui \
    UI/ChatTextItem.ui \
    UI/ChatTextMyItem.ui \
    UI/ContributeItem.ui \
    UI/GIftItem.ui \
    UI/GiftPage.ui \
    UI/GiftPageItem.ui \
    UI/LoginPage.ui \
    UI/MicInfoItem.ui \
    UI/MicseQuenceItem.ui \
    UI/NewUserItem.ui \
    UI/NewUserPage.ui \
    UI/OnlineItem.ui \
    UI/RoomItem.ui \
    UI/UserinfoPage.ui \
    UI/mainwindow.ui \
    control/EmotionItem.ui \
    control/EmotionPage.ui \
    control/MsgBox.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
