#ifndef VIDEORENDERER_IMPL_H
#define VIDEORENDERER_IMPL_H
#include <IAgoraMediaEngine.h>
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include "xvideowidget.h"

class XVideoWidget;

//Instances of VideoRenderImpl is created and destroyed by Agora Media Engine.
//AVideoWidget is created and destroyed by the APP
//VideoRenderImpl must check if the video widget is alive whenever access to the view.
class VideoRenderImpl : public QObject, public agora::media::IExternalVideoRender
{
    Q_OBJECT
public:
    VideoRenderImpl(const agora::media::ExternalVideoRenerContext& context);
    ~VideoRenderImpl();
    virtual void release() override;
    virtual int initialize() override;
    virtual int deliverFrame(const agora::media::IVideoFrame& videoFrame, int rotation, bool mirrored) override;
public slots:
    void handleWidgetInvalidated();
    void handleViewSizeChanged(int width, int height);
private:
    XVideoWidget* m_view;
    agora::media::IExternalVideoRenderCallback* m_renderCallback;
    QMutex m_mutex;
};


#endif // VIDEORENDERER_IMPL_H
