#include "agorartcengineinterface.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QTextCodec>

class AgoraRtcEngineInterfaceEvent : public agora::rtc::IRtcEngineEventHandler
{
    AgoraRtcEngineInterface& m_engine;
public:
    AgoraRtcEngineInterfaceEvent(AgoraRtcEngineInterface& engine)
        :m_engine(engine)
    {
    }
    virtual void onVideoStopped() override
    {

    }
    virtual void onJoinChannelSuccess(const char* channel, uid_t uid, int elapsed) override
    {
        emit m_engine.joinedChannelSuccess(channel, uid, elapsed);
    }
    virtual void onUserJoined(uid_t uid, int elapsed) override
    {
        emit m_engine.userJoined(uid, elapsed);
    }
    virtual void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason) override
    {
        emit m_engine.userOffline(uid);
    }
    virtual void onFirstLocalVideoFrame(int width, int height, int elapsed)
    {

    }
    virtual void onAudioVolumeIndication(const AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume)
    {        
        if(speakers)
            emit m_engine.audioVolumeIndication(speakers->uid,speakers->volume);
    }
    virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed) override
    {

    }
    virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed) override
    {       
    }
    virtual void onRtmpStreamingStateChanged(const char *url, RTMP_STREAM_PUBLISH_STATE state, RTMP_STREAM_PUBLISH_REASON errCode)
    {
        emit m_engine.rtmpStreamingStateChanged(url, state, errCode);
    }
    virtual void onUserMuteVideo(uid_t uid, bool muted)
    {

    }
    virtual void onError(int err, const char* msg) override
    {
        qDebug()<<"err---"<<err<<"msg---"<<QString::fromLatin1(msg);
    }
};


AgoraRtcEngineInterface::AgoraRtcEngineInterface(QObject *parent) : QObject(parent)
    , m_rtcEngine(createAgoraRtcEngine())
    , m_eventHandler(new AgoraRtcEngineInterfaceEvent(*this))
{
}

AgoraRtcEngineInterface::~AgoraRtcEngineInterface()
{
    m_rtcEngine->release();   
}


void AgoraRtcEngineInterface::vInitAgoraSdk()
{
    agora::rtc::RtcEngineContext context;
    context.eventHandler = m_eventHandler.get();
    context.appId = "80df7e5ffd6e468da6b365394c0cb472";

    int code = m_rtcEngine->initialize(context);
    if(code != 0)
    {
        qDebug()<<"initialize error";
    }
    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(m_rtcEngine, AGORA_IID_MEDIA_ENGINE);    

    m_rtcEngine->enableAudioVolumeIndication(300,5,false);
    m_rtcEngine->enableAudio();
    m_rtcEngine->disableVideo();
//    m_rtcEngine->setLogFile("agora.log");

}

int AgoraRtcEngineInterface::joinChannel(const QString& token, const QString& channel, int uid)
{
    ChannelMediaOptions options;
    options.channelProfile = agora::CHANNEL_PROFILE_LIVE_BROADCASTING;  
    options.clientRoleType = CLIENT_ROLE_BROADCASTER;
    options.publishMicrophoneTrack = true;
    options.autoSubscribeAudio = true;

    int r = m_rtcEngine->joinChannel(token.toUtf8().data(), channel.toUtf8().data(), uid, options);
    if (!r)
        emit joiningChannel();

    return r;
}

int AgoraRtcEngineInterface::leaveChannel()
{
    int r = m_rtcEngine->leaveChannel();
    m_rtcEngine->stopPreview();
    if (!r)
        emit leavingChannel();
    return r;
}

void AgoraRtcEngineInterface::enableLoopbackRecording(bool muted)
{
    m_rtcEngine->enableLoopbackRecording(muted);
}

void AgoraRtcEngineInterface::enableLocalAudio(bool muted)
{
    m_rtcEngine->enableLocalAudio(muted);
}

int AgoraRtcEngineInterface::muteLocalAudioStream(bool muted)
{
    return m_rtcEngine->muteLocalAudioStream(muted);
}

int AgoraRtcEngineInterface::muteRemoteAudioStream(uid_t uid, bool muted)
{
    return m_rtcEngine->muteRemoteAudioStream(uid, muted);
}

int AgoraRtcEngineInterface::muteAllRemoteAudioStreams(bool muted)
{    
    return m_rtcEngine->muteAllRemoteAudioStreams(muted);
}

//设置直播模式
void AgoraRtcEngineInterface::setChannelProfile(agora::CHANNEL_PROFILE_TYPE profile)
{
    m_rtcEngine->setChannelProfile(profile);
}

QVariantList AgoraRtcEngineInterface::getRecordingDeviceList()
{
    QVariantList devices;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return devices;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumerateRecordingDevices());
    if (!spCollection)
        return devices;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            QVariantMap data;
            if (!spCollection->getDevice(i, name, guid))
            {
                data.insert("name", name);
                data.insert("guid", guid);
            }
            devices.append(data);
        }
    }
    return devices;
}

QVariantMap AgoraRtcEngineInterface::getPlayoutDeviceList()
{
    QVariantMap devices;
    QVariantList names, guids;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return devices;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumeratePlaybackDevices());
    if (!spCollection)
        return devices;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (!spCollection->getDevice(i, name, guid))
            {
                names.push_back(name);
                guids.push_back(guid);
            }
        }
        devices.insert("name", names);
        devices.insert("guid", guids);
        devices.insert("length", names.length());
    }
    return devices;
}



int AgoraRtcEngineInterface::setRecordingDevice(const QString& guid)
{
    if (guid.isEmpty())
        return -1;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setRecordingDevice(guid.toUtf8().data());
}

int AgoraRtcEngineInterface::setPlayoutDevice(const QString& guid)
{
    if (guid.isEmpty())
        return -1;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setPlaybackDevice(guid.toUtf8().data());
}

int AgoraRtcEngineInterface::getRecordingDeviceVolume()
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return 0;
    int vol = 0;
    if (audioDeviceManager->getRecordingDeviceVolume(&vol) == 0)
        return vol;
    return 0;
}

int AgoraRtcEngineInterface::getPalyoutDeviceVolume()
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return 0;
    int vol = 0;
    if (audioDeviceManager->getPlaybackDeviceVolume(&vol) == 0)
        return vol;
    return 0;
}

int AgoraRtcEngineInterface::setRecordingDeviceVolume(int volume)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setRecordingDeviceVolume(volume);
}

int AgoraRtcEngineInterface::setPalyoutDeviceVolume(int volume)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setPlaybackDeviceVolume(volume);
}

int AgoraRtcEngineInterface::getPlaybackDeviceMute(bool *mute)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->getPlaybackDeviceMute(mute);
}

int AgoraRtcEngineInterface::setPlaybackDeviceMute(bool mute)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setPlaybackDeviceMute(mute);
}

int AgoraRtcEngineInterface::setRecordingDeviceMute(bool mute)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setRecordingDeviceMute(mute);
}

int AgoraRtcEngineInterface::getRecordingDeviceMute(bool *mute)
{
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->getRecordingDeviceMute(mute);
}

int AgoraRtcEngineInterface::testMicrophone(bool start, int interval)
{
    agora::rtc::AAudioDeviceManager dm(m_rtcEngine);
    if (!dm)
        return -1;
    if (start)
        return dm->startRecordingDeviceTest(interval);
    else
        return dm->stopRecordingDeviceTest();
}

int AgoraRtcEngineInterface::testSpeaker(bool start)
{
    agora::rtc::AAudioDeviceManager dm(m_rtcEngine);
    if (!dm)
        return -1;
    if (start)
        return dm->startPlaybackDeviceTest("");
    else
        return dm->stopPlaybackDeviceTest();
}

void AgoraRtcEngineInterface::setClientRole(CLIENT_ROLE_TYPE role)
{
    m_rtcEngine->setClientRole(role);
}

QString AgoraRtcEngineInterface::getVersion()
{
    int number = 0;
    return m_rtcEngine->getVersion(&number);
}



