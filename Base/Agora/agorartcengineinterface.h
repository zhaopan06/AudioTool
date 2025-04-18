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
    //    static AgoraRtcEngineInterface *getInstance();
    explicit AgoraRtcEngineInterface(QObject *parent = 0);
    ~AgoraRtcEngineInterface();

    /**
      初始化声网
    **/
    void vInitAgoraSdk();

    int joinChannel(const QString& token, const QString& channel, int uid);
    /**
     * @brief 离开房间
     * @return
     */
    int leaveChannel();
    /**
     * @brief 关闭本地声音流
     * @param muted
     * @return
     */
    int muteLocalAudioStream(bool muted);

    void enableLoopbackRecording(bool muted);

    void enableLocalAudio(bool muted);

    /**
     * @brief 关闭远端音频流
     * @param uid
     * @param mute
     * @return
     */
    int muteRemoteAudioStream(uid_t uid, bool muted);
    /**
     * @brief 关闭所有远端音频流 不接收
     * @param muted
     * @return
     */
    int muteAllRemoteAudioStreams(bool muted);

    /**
     * @brief 关闭本地视频流
     * @param muted
     * @return
     */
    int muteLocalVideoStream(bool muted);

    /**
     * @brief 关闭所有远端视频流
     * @param muted
     * @return
     */
    int muteAllRemoteVideoStreams(bool muted);

    /**
     * @brief 关闭远端视频流
     * @param uid
     * @param muted
     * @return
     */
    int muteRemoteVideoStream(uid_t uid, bool muted);

    /**
     * @brief 开启本地视频
     * @param muted
     * @return
     */
    int enableLocalVideo(bool muted);
    /**
     * @brief 获取麦克风设备列表
     * @return
     */
    QVariantList getRecordingDeviceList();

    /**
     * @brief 获取扬声器设备列表
     * @return
     */
    QVariantMap getPlayoutDeviceList();

    /**
     * @brief 获取视频采集设备列表
     * @return
     */
    QVariantList getVideoDeviceList();

    /**
     * @brief 设置麦克风设备
     * @param guid 设备guid
     * @return
     */
    int setRecordingDevice(const QString& guid);

    /**
     * @brief 设置扬声器设备
     * @param guid 设备guid
     * @return
     */
    int setPlayoutDevice(const QString& guid);

    /**
     * @brief 设置视频采集设备
     * @param guid 设备guid
     * @return
     */
    int setVideoDevice(const QString& guid);

    /**
     * @brief 获取麦克风设备音量
     * @return
     */
    int getRecordingDeviceVolume();

    /**
     * @brief 获取扬声器设备音量
     * @return
     */
    int getPalyoutDeviceVolume();

    /**
     * @brief 设置麦克风设备音量
     * @param volume 0-255
     * @return
     */
    int setRecordingDeviceVolume(int volume);

    /**
     * @brief 设置扬声器设备音量
     * @param volume 0-255
     * @return
     */
    int setPalyoutDeviceVolume(int volume);

    /**
     * @brief 获取扬声器静音
     * @param mute
     * @return
     */
    int getPlaybackDeviceMute(bool *mute);

    /**
     * @brief 设置扬声器静音
     * @param mute
     * @return
     */
    int setPlaybackDeviceMute(bool mute);

    /**
     * @brief 设置麦克风静音
     * @param mute
     * @return
     */
    int setRecordingDeviceMute(bool mute);

    /**
     * @brief 获取麦克风静音状态
     * @param mute
     * @return
     */
    int getRecordingDeviceMute(bool *mute);

    /**
     * @brief 测试麦克风是否正常
     * @param start true 开始测试; false 停止测试
     * @param interval
     * @return
     */
    int testMicrophone(bool start, int interval);

    /**
     * @brief 测试扬声器是否正常
     * @param start true 开始测试; false 停止测试
     * @return
     */
    int testSpeaker(bool start);

    /**
     * @brief 设置视频质量
     * @param iProfile
     * @return
     */
    int setVideoProfile(int iProfile);

    //设置直播模式
    void setChannelProfile(agora::CHANNEL_PROFILE_TYPE profile);
    //设置角色
    void setClientRole(CLIENT_ROLE_TYPE role);

    //获取版本
    QString getVersion();

    /**
     * @brief 设置本地视频显示模式
     * @param mode
     * @return
     */
    int setLocalRenderMode (int mode);

    /**
     *使用双流/单流模式。
     *该方法设置单流（默认）或者双流模式。
     *发送端开启双流模式后接收端可以选择接收大流还是小流。其中，大流指高分辨率、高码率的视频流，小流指低分辨率、低码率的视频流
     *
     */
    int enableDualStreamMode(bool enabled);

    /**
     * @brief 启动网络测试
     * @return
     */
    int enableLastmileTest();

    /**
     * @brief 获取实例
     * @return
     */
    agora::rtc::IRtcEngine* getRtcEngine() {return m_rtcEngine;}

signals:
    void joiningChannel();
    void leavingChannel();
    void videoStopped();
    void joinedChannelSuccess(const QString& channel, unsigned int uid, int elapsed);
    void userJoined(unsigned int uid, int elapsed);
    void userOffline(unsigned int uid);

    void audioVolumeIndication(int uid,int value);
    /**
     * @brief 本地视频第一帧
     * @param width
     * @param height
     * @param elapsed
     */
    void firstLocalVideoFrame(int width, int height, int elapsed);

    /**
     * @brief 远端第一帧视频开始解码
     * @param uid
     * @param width
     * @param height
     * @param elapsed
     */
    void firstRemoteVideoDecoded(unsigned int uid, int width, int height, int elapsed);

    /**
     * @brief 远端第一帧视频开始绘制
     * @param uid
     * @param width
     * @param height
     * @param elapsed
     */
    void firstRemoteVideoFrameDrawn(unsigned int uid, int width, int height, int elapsed);

    /**
     * @brief 推流中断的回调
     */
    void rtmpStreamingStateChanged(const char *url, int state, int errCode);

public slots:

private:
    friend class AgoraRtcEngineInterfaceEvent;
private:
    IRtcEngine* m_rtcEngine = NULL;
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> m_eventHandler;

    bool m_isPressAI = false;
};

#endif // AGORARTCENGINEINTERFACE_H
