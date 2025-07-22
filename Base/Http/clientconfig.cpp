#include "clientconfig.h"

#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include "Global.h"
ClientConfig* ClientConfig::pClientConfig = NULL;

ClientConfig::ClientConfig(QObject *parent) : QObject(parent)
{

}

ClientConfig *ClientConfig::getInstance()
{
    if(pClientConfig == NULL)
    {
        pClientConfig = new ClientConfig();
    }

    return pClientConfig;
}

void ClientConfig::writeIniFile(QString strGroup, QString strKey, QString strValue)
{
    QString strDirPath = g_appData + "/client.ini";
    QSettings settings(strDirPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.beginGroup(strGroup);
    settings.setValue(strKey, strValue);
    settings.endGroup();
}

QString ClientConfig::readIniFile(QString strGroup, QString strKey)
{
    QString strDirPath = g_appData+ "/client.ini";
    QString strValue = "";
    QSettings settings(strDirPath, QSettings::IniFormat);
    settings.beginGroup(strGroup);
    strValue = settings.value(strKey).toString();
    settings.endGroup();

    return strValue;
}

void ClientConfig::setLoginData(QVariantMap data)
{
    QString strDirPath = g_appData + "/login.json";

    QJsonObject jsonObject = QJsonObject::fromVariantMap(data);
    QJsonDocument jsonDoc(jsonObject);
    QString jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file(strDirPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(jsonData.toUtf8());
        file.close();
    }
}


QVariantMap ClientConfig::getLoginData()
{
    QString strDirPath = g_appData + "/login.json";
    QFile file(strDirPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString jsonData = file.readAll();
        file.close();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData.toUtf8());
        if (jsonDoc.isObject())
        {
            QJsonObject jsonObject = jsonDoc.object();
            QVariantMap map = jsonObject.toVariantMap();           
            return map;
        }
    }

    return QVariantMap();
}




