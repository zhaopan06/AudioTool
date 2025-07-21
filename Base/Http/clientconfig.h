#ifndef CLIENTCONFIG_H
#define CLIENTCONFIG_H

#include <QObject>
#include <QSettings>

class ClientConfig : public QObject
{
    Q_OBJECT
public:
    static ClientConfig* getInstance();

public:   
    void writeIniFile(QString strGroup, QString strKey, QString strValue);

    QString readIniFile(QString strGroup, QString strKey);

    void setLoginData(QVariantMap data);
    QVariantMap getLoginData();

signals:

public slots:

private:
    explicit ClientConfig(QObject *parent = nullptr);

private:
    static ClientConfig* pClientConfig;
};

#endif // CLIENTCONFIG_H
