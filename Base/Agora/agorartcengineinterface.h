#ifndef AGORARTCENGINEINTERFACE_H
#define AGORARTCENGINEINTERFACE_H
#include <QString>
#include <QVariant>
#include <IAgoraRtcEngine.h>

class QWidget;
using namespace agora::rtc;

class AgoraRtcEngineInterface : public QObject
{
    Q_OBJECT
public:

    explicit AgoraRtcEngineInterface(QObject *parent = 0);
    ~AgoraRtcEngineInterface();   
    void vInitAgoraSdk();
    int joinChannel(const QString& token, const QString& channel, int uid);
    int leaveChannel();
    int muteLocalAudioStream(bool muted);
    void enableLoopbackRecording(bool muted);
    void enableLocalAudio(bool muted);
    int muteRemoteAudioStream(uid_t uid, bool muted);
    int muteAllRemoteAudioStreams(bool muted);
    QVariantList getRecordingDeviceList();
    int setRecordingDevice(const QString& guid);
    int getRecordingDeviceVolume();
    int setRecordingDeviceVolume(int volume);
    int setRecordingDeviceMute(bool mute);
    int getRecordingDeviceMute(bool *mute);
    int testMicrophone(bool start, int interval);
    QVariantMap getPlayoutDeviceList();
    int getPalyoutDeviceVolume();
    int setPlayoutDevice(const QString& guid);
    int setPalyoutDeviceVolume(int volume);
    int getPlaybackDeviceMute(bool *mute);
    int setPlaybackDeviceMute(bool mute);
    int testSpeaker(bool start);
    void setChannelProfile(agora::CHANNEL_PROFILE_TYPE profile);
    void setClientRole(CLIENT_ROLE_TYPE role);
    QString getVersion();
    int enableLastmileTest();

signals:
    void joiningChannel();
    void leavingChannel();
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void userJoined(unsigned int uid, int elapsed);
    void userOffline(unsigned int uid);
    void audioVolumeIndication(int uid,int value);
    void rtmpStreamingStateChanged(const char *url, int state, int errCode);
    void reconnect();
private:
    friend class AgoraRtcEngineInterfaceEvent;

private:
    IRtcEngine* m_rtcEngine = NULL;
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> m_eventHandler;
    bool m_isPressAI = false;
};

#endif // AGORARTCENGINEINTERFACE_H
