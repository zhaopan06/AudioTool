#include "HttpUserInfo.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCborMap>
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

QReadWriteLock HttpUserInfo::readWriteLock;
QScopedPointer<HttpUserInfo> HttpUserInfo::instance_;

HttpUserInfo::HttpUserInfo(QObject *parent) : QObject(parent)
{
    m_token = "";
}

HttpUserInfo *HttpUserInfo::instance(QObject *parent)
{
    if (instance_.isNull())
    {
        readWriteLock.lockForWrite();
        if (instance_.isNull())
        {
            instance_.reset(new HttpUserInfo(parent));
        }
        readWriteLock.unlock();
    }

    return instance_.data();
}

void HttpUserInfo::setLoginInfo(QVariantMap data)
{
    m_loginInfo = data;
    m_token = data["token"].toString();
    qDebug()<<"m_token---"<<m_token;
}

QVariantMap HttpUserInfo::getLoginInfo()
{
    return m_loginInfo;
}

void HttpUserInfo::setHttpUserInfo(QVariantMap data)
{
    m_HttpUserInfo = data["data"].toMap();
}

QVariantMap HttpUserInfo::getHttpUserInfo()
{
    return m_HttpUserInfo;
}

QString HttpUserInfo::getUserID()
{
    return m_HttpUserInfo["id"].toString();
}

QString HttpUserInfo::getWSPath()
{
    return m_wsPath;
}

void HttpUserInfo::setWSPath(QString path)
{
    m_wsPath = path;
}

const QString HttpUserInfo::gettoken()
{
    return m_token;
}

void HttpUserInfo::setRoomInfo(QVariantMap data)
{
    m_roomInfo = data;
}

QVariantMap HttpUserInfo::getRoomInfo()
{
    return m_roomInfo;
}

QString HttpUserInfo::getRoomID()
{
    return m_roomInfo["id"].toString();
}

void HttpUserInfo::setAreaInfo(QVariant data)
{
    m_areaInfo = data;
}

QVariant HttpUserInfo::getAreaInfo()
{
    return m_areaInfo;
}

void HttpUserInfo::setPhoneAreaInfo(QVariant data)
{
    m_phoneAreaInfo = data;
}

QVariant HttpUserInfo::getPhoneAreaInfo()
{
    return m_phoneAreaInfo;
}

void HttpUserInfo::setCoverInfo(QString path)
{
    m_coverPath = path;
}

QString HttpUserInfo::getCoverInfo()
{
    return m_coverPath;
}

void HttpUserInfo::setClassID(QString id)
{
    m_classID = id;
}

QString HttpUserInfo::getClassID()
{
    return m_classID;
}

void HttpUserInfo::setLiveArea(QString area)
{
    m_areaID = area;
}

QString HttpUserInfo::getLiveArea()
{
    return m_areaID;
}



