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
    //初始化声网
    void vInitAgoraSdk();

    //加入房间
    int joinChannel(const QString& token, const QString& channel, int uid);

    //离开房间
    int leaveChannel();

    //关闭本地声音流
    int muteLocalAudioStream(bool muted);

    //
    void enableLoopbackRecording(bool muted);

    //
    void enableLocalAudio(bool muted);

    //关闭远端音频流
    int muteRemoteAudioStream(uid_t uid, bool muted);
    //关闭所有远端音频流 不接收
    int muteAllRemoteAudioStreams(bool muted);

    //获取麦克风设备列表
    QVariantList getRecordingDeviceList();
    //设置麦克风设备
    int setRecordingDevice(const QString& guid);
    //获取麦克风设备音量
    int getRecordingDeviceVolume();
    //设置麦克风设备音量
    int setRecordingDeviceVolume(int volume);
    //设置麦克风静音
    int setRecordingDeviceMute(bool mute);
    //获取麦克风静音状态
    int getRecordingDeviceMute(bool *mute);
    /**
     * @brief 测试麦克风是否正常
     * @param start true 开始测试; false 停止测试
     * @param interval
     * @return
     */
    int testMicrophone(bool start, int interval);



    //获取扬声器设备列表
    QVariantMap getPlayoutDeviceList();    
    //获取扬声器设备音量
    int getPalyoutDeviceVolume();
    //设置扬声器设备
    int setPlayoutDevice(const QString& guid);
    //设置扬声器设备音量
    int setPalyoutDeviceVolume(int volume);
    //获取扬声器是否静音
    int getPlaybackDeviceMute(bool *mute);
    //设置扬声器静音
    int setPlaybackDeviceMute(bool mute);
    // 测试扬声器是否正常,start true 开始测试; false 停止测试
    int testSpeaker(bool start);


    //设置直播模式
    void setChannelProfile(agora::CHANNEL_PROFILE_TYPE profile);
    //设置角色
    void setClientRole(CLIENT_ROLE_TYPE role);
    //获取版本
    QString getVersion();   
    //启动网络测试
    int enableLastmileTest();

signals:
    void joiningChannel();
    void leavingChannel();

    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void userJoined(unsigned int uid, int elapsed);
    void userOffline(unsigned int uid);

    void audioVolumeIndication(int uid,int value);
    // 推流中断的回调
    void rtmpStreamingStateChanged(const char *url, int state, int errCode);

private:
    friend class AgoraRtcEngineInterfaceEvent;

private:
    IRtcEngine* m_rtcEngine = NULL;
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> m_eventHandler;
    bool m_isPressAI = false;
};

#endif // AGORARTCENGINEINTERFACE_H
