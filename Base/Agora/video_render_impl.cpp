#include "video_render_impl.h"
#include "xvideowidget.h"
#include <QDebug>

using namespace agora::media;

VideoRenderImpl::VideoRenderImpl(const agora::media::ExternalVideoRenerContext& context)
    :m_view(reinterpret_cast<XVideoWidget*>(context.view))
    ,m_renderCallback(context.renderCallback)
{

    m_view->setViewProperties(context.zOrder, context.left, context.top, context.right, context.bottom);
    //connect(m_view, SIGNAL(widgetInvalidated()), this, SLOT(handleWidgetInvalidated()), Qt::DirectConnection);
    //connect(m_view, SIGNAL(viewSizeChanged(int,int)), this, SLOT(handleViewSizeChanged(int,int)), Qt::DirectConnection);
}

VideoRenderImpl::~VideoRenderImpl()
{
    //    qDebug() << "video render " << this << " destroyed";
}

void VideoRenderImpl::release()
{
    delete this;
}

int VideoRenderImpl::initialize()
{
    return 0;
}

void VideoRenderImpl::handleWidgetInvalidated()
{

    //QMutexLocker lock(&m_mutex);
    //std::lock_guard<std::mutex> lock(m_mutex);
    m_view = nullptr;

    if (m_renderCallback)
    {
        m_renderCallback->onViewDestroyed();
    }
}

void VideoRenderImpl::handleViewSizeChanged(int width, int height)
{
    if (m_renderCallback)
    {
        m_renderCallback->onViewSizeChanged(width, height);
    }
}

int VideoRenderImpl::deliverFrame(const agora::media::IVideoFrame& videoFrame, int rotation, bool mirrored)
{
    //std::lock_guard<std::mutex> lock(m_mutex);
    QMutexLocker locker(&m_mutex);

    if (m_view)
    {
        return m_view->deliverFrame(videoFrame, rotation, mirrored);
    }

    return -1;
}
