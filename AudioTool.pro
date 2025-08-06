QT       += core gui network websockets webenginewidgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 utf8_source

QMAKE_PROJECT_DEPTH = 0

LIBS += user32.lib
RC_ICONS = lanban.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
        ./Base/Agora \
        ./Base/ImSDK \
        #./SDK/vlc/include \
        #./SDK/vlcLib     \
        ./SDK/Agora/include \
        ./SDK/ImSDK/include \        
        ./Base/Http \
        ./control \
        ./UI


LIBS += \
    -L$$PWD/SDK/Agora/lib   \
    #-L$$PWD/SDK/vlc/lib   \
    #-L$$PWD/SDK/vlcLib    \
    -L$$PWD/SDK/ImSDK/lib

LIBS += \
    -lagora_rtc_sdk.dll \
    #-lVLCQtCore   \
    #-lVLCQtWidgets \
    #-lVlcLib  \
    -limsdk

SOURCES += \
    Base/Agora/agorartcengineinterface.cpp \
    Base/Http/Global.cpp \
    Base/Http/HttpAsyncWorker.cpp \
    Base/Http/HttpInterFace.cpp \
    Base/Http/HttpUserInfo.cpp \
    Base/Http/clientconfig.cpp \
    Base/IMSDK/TimInterface.cpp \
    UI/ChatEmoTionItem.cpp \
    UI/ChatImageItem.cpp \
    UI/ChatImageMyItem.cpp \
    UI/ChatInviteItem.cpp \
    UI/ChatPage.cpp \
    UI/ChatPageC2C.cpp \
    UI/ChatPageC2CMyItem.cpp \
    UI/ChatPageC2CTextItem.cpp \
    UI/ChatPageCommunicationItem.cpp \
    UI/ChatPageLeftItem.cpp \
    UI/ChatTextItem.cpp \
    UI/ChatTextMyItem.cpp \
    UI/ContributeItem.cpp \
    UI/DressUpPage.cpp \
    UI/DressUpPageBKItem.cpp \
    UI/DressUpPageQPItem.cpp \
    UI/GIftItem.cpp \
    UI/GiftPage.cpp \
    UI/GiftPageItem.cpp \
    UI/HotPushHistoryPage.cpp \
    UI/HotPushHistoryPageItem.cpp \
    UI/HotPushPage.cpp \
    UI/HotPushPageItem.cpp \
    UI/LoginPage.cpp \
    UI/ManagementPage.cpp \
    UI/ManagementPageItem.cpp \
    UI/MicInfoItem.cpp \
    UI/MicseQuenceItem.cpp \
    UI/NewUserItem.cpp \
    UI/NewUserPage.cpp \
    UI/OnlineItem.cpp \
    UI/PromoteBusinePage.cpp \
    UI/PromoteBusinePageItem.cpp \
    UI/PromoteBusinePageTopItem.cpp \
    UI/RoomEidtPage.cpp \
    UI/RoomInvitePage.cpp \
    UI/RoomInvitePageItem.cpp \
    UI/RoomItem.cpp \
    UI/SetTingPage.cpp \
    UI/UserinfoPage.cpp \
    UI/UserinfoPageGiftItem.cpp \
    UI/UserinfoPageMedalItem.cpp \
    UI/UserinfoPageSimple.cpp \
    UI/mainwindow.cpp \
    control/AudioValuePage.cpp \
    control/CRoundLabel.cpp \
    control/EmotionItem.cpp \
    control/EmotionPage.cpp \
    control/FramelessDialog.cpp \
    control/ImageDialog.cpp \
    control/MenuHomeownerRight.cpp \
    control/MenuLockRight.cpp \
    control/MenuManagerRight.cpp \
    control/MsgBox.cpp \
    control/PlayerPage.cpp \
    control/SetTingMenu.cpp \
    control/ToastPage.cpp \
    control/WebEngView.cpp \
    control/click_label.cpp \
    control/usermenu.cpp \
    #control/videoplayer.cpp \
    main.cpp


HEADERS += \
    Base/Agora/agorartcengineinterface.h \
    Base/Http/Global.h \
    Base/Http/HttpAsyncWorker.h \
    Base/Http/HttpInterFace.h \
    Base/Http/HttpUserInfo.h \
    Base/Http/clientconfig.h \
    Base/IMSDK/TimInterface.h \
    UI/ChatEmoTionItem.h \
    UI/ChatImageItem.h \
    UI/ChatImageMyItem.h \
    UI/ChatInviteItem.h \
    UI/ChatPage.h \
    UI/ChatPageC2C.h \
    UI/ChatPageC2CMyItem.h \
    UI/ChatPageC2CTextItem.h \
    UI/ChatPageCommunicationItem.h \
    UI/ChatPageLeftItem.h \
    UI/ChatTextItem.h \
    UI/ChatTextMyItem.h \
    UI/ContributeItem.h \
    UI/DressUpPage.h \
    UI/DressUpPageBKItem.h \
    UI/DressUpPageQPItem.h \
    UI/GIftItem.h \
    UI/GiftPage.h \
    UI/GiftPageItem.h \
    UI/HotPushHistoryPage.h \
    UI/HotPushHistoryPageItem.h \
    UI/HotPushPage.h \
    UI/HotPushPageItem.h \
    UI/LoginPage.h \
    UI/ManagementPage.h \
    UI/ManagementPageItem.h \
    UI/MicInfoItem.h \
    UI/MicseQuenceItem.h \
    UI/NewUserItem.h \
    UI/NewUserPage.h \
    UI/OnlineItem.h \
    UI/PromoteBusinePage.h \
    UI/PromoteBusinePageItem.h \
    UI/PromoteBusinePageTopItem.h \
    UI/RoomEidtPage.h \
    UI/RoomInvitePage.h \
    UI/RoomInvitePageItem.h \
    UI/RoomItem.h \
    UI/SetTingPage.h \
    UI/UserinfoPage.h \
    UI/UserinfoPageGiftItem.h \
    UI/UserinfoPageMedalItem.h \
    UI/UserinfoPageSimple.h \
    UI/mainwindow.h \
    control/AudioValuePage.h \
    control/CRoundLabel.h \
    control/EmotionItem.h \
    control/EmotionPage.h \
    control/FramelessDialog.h \
    control/ImageDialog.h \
    control/ImageDropLineEdit.h \
    control/ImageTextEdit.h \
    control/MenuHomeownerRight.h \
    control/MenuLockRight.h \
    control/MenuManagerRight.h \
    control/MsgBox.h \
    control/PlayerPage.h \
    control/SetTingMenu.h \
    control/ShowPlayer.h \
    control/ToastPage.h \
    control/WebEngView.h \
    control/click_label.h \
    control/usermenu.h
    #control/videoplayer.h

FORMS += \
    UI/ChatEmoTionItem.ui \
    UI/ChatImageItem.ui \
    UI/ChatImageMyItem.ui \
    UI/ChatInviteItem.ui \
    UI/ChatPage.ui \
    UI/ChatPageC2C.ui \
    UI/ChatPageC2CMyItem.ui \
    UI/ChatPageC2CTextItem.ui \
    UI/ChatPageCommunicationItem.ui \
    UI/ChatPageLeftItem.ui \
    UI/ChatTextItem.ui \
    UI/ChatTextMyItem.ui \
    UI/ContributeItem.ui \
    UI/DressUpPage.ui \
    UI/DressUpPageBKItem.ui \
    UI/DressUpPageQPItem.ui \
    UI/GIftItem.ui \
    UI/GiftPage.ui \
    UI/GiftPageItem.ui \
    UI/HotPushHistoryPage.ui \
    UI/HotPushHistoryPageItem.ui \
    UI/HotPushPage.ui \
    UI/HotPushPageItem.ui \
    UI/LoginPage.ui \
    UI/ManagementPage.ui \
    UI/ManagementPageItem.ui \
    UI/MicInfoItem.ui \
    UI/MicseQuenceItem.ui \
    UI/NewUserItem.ui \
    UI/NewUserPage.ui \
    UI/OnlineItem.ui \
    UI/PromoteBusinePage.ui \
    UI/PromoteBusinePageItem.ui \
    UI/PromoteBusinePageTopItem.ui \
    UI/RoomEidtPage.ui \
    UI/RoomInvitePage.ui \
    UI/RoomInvitePageItem.ui \
    UI/RoomItem.ui \
    UI/SetTingPage.ui \
    UI/UserinfoPage.ui \
    UI/UserinfoPageGiftItem.ui \
    UI/UserinfoPageMedalItem.ui \
    UI/UserinfoPageSimple.ui \
    UI/mainwindow.ui \
    control/AudioValuePage.ui \
    control/EmotionItem.ui \
    control/EmotionPage.ui \
    control/ImageDialog.ui \
    control/MenuHomeownerRight.ui \
    control/MenuLockRight.ui \
    control/MenuManagerRight.ui \
    control/MsgBox.ui \
    control/PlayerPage.ui \
    control/SetTingMenu.ui \
    control/WebEngView.ui \
    control/usermenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
