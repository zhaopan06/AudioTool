﻿#include "HttpUserInfo.h"
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
    m_userID = data["user"].toMap()["userId"].toString();
    m_IMtoken = data["imToken"].toString();
}

QVariantMap HttpUserInfo::getLoginInfo()
{
    return m_loginInfo;
}

QString HttpUserInfo::getUserID()
{
    return m_userID;
}

QString HttpUserInfo::getImgTag()
{
    return m_loginInfo["imgTag"].toString();
}

QString HttpUserInfo::getName()
{
    return m_loginInfo["name"].toString();
}

QString HttpUserInfo::getImToken()
{
    return m_IMtoken;
}

const QString HttpUserInfo::gettoken()
{
    return m_token;
}

void HttpUserInfo::setRoomInfo(QVariantMap data)
{
    m_roomInfo = data;
    m_chatRoomId = data["chatRoomId"].toString();
}

QVariantMap HttpUserInfo::getRoomInfo()
{
    return m_roomInfo;
}

QString HttpUserInfo::getRoomID()
{
    return m_chatRoomId;
}

void HttpUserInfo::setPhoneAreaInfo(QVariant data)
{
    m_phoneAreaInfo = data;
}

QVariant HttpUserInfo::getPhoneAreaInfo()
{
    return m_phoneAreaInfo;
}


