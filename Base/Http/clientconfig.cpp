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

/**
 * @brief 写文件
 * @param strKey 键
 * @param strValue 键对应的值
 * @date 18-03-15
 * @author zjj
 */
void ClientConfig::writeIniFile(QString strGroup, QString strKey, QString strValue)
{
    QString strDirPath = g_appData + "/client.ini";
    QSettings settings(strDirPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.beginGroup(strGroup);
    settings.setValue(strKey, strValue);
    settings.endGroup();
}

/**
 * @brief 读文件
 * @param strKey 键
 * @param strValue 键对应的值
 * @date 18-03-15
 * @author zjj
 */
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



