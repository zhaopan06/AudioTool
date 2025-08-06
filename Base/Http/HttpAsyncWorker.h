#ifndef HTTPASYNCWORKER_H
#define HTTPASYNCWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>
#include <functional>

class HttpAsyncWorker : public QObject
{
    Q_OBJECT
public:
    enum class RequestMethod {
        GET,
        POST,
        PUT,
        PATCH
    };

    using ResponseCallback = std::function<void(const QVariantMap&)>;
    using ErrorCallback = std::function<void(int, const QString&)>;

    struct RequestTask {
        RequestMethod method;
        QString url;
        QByteArray body;
        ResponseCallback successCallback;
        ErrorCallback errorCallback;
    };

    static HttpAsyncWorker* getInstance();
    ~HttpAsyncWorker();

    void submitRequest(RequestMethod method,
                       const QString& url,
                       const ResponseCallback& successCallback,
                       const ErrorCallback& errorCallback = nullptr,
                       const QVariantMap& body = QVariantMap());

    void setMaxConcurrentRequests(int max);
    void setBaseUrl(const QString& baseUrl);
    void setHeaders();

signals:
    void requestAdded();

private:
    explicit HttpAsyncWorker(QObject* parent = nullptr);
    void processNextRequest();
    QNetworkRequest createRequest(const QString& url);

    QNetworkAccessManager* m_manager;
    QQueue<RequestTask> m_requestQueue;
    QMutex m_queueMutex;
    int m_activeRequests;
    int m_maxConcurrentRequests;
    QString m_baseUrl;
    QThread m_workerThread;
    QMap<QString, QString> m_map;
private slots:
    void handleRequest();
};

#endif // HTTPASYNCWORKER_H
