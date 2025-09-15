#include "Global.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QWidget>
#include <QApplication>
#include <QUdpSocket>
#include <QStandardPaths>
#include <QSettings>
#include <QCoreApplication>
#include <QFileInfo>

QString g_downloadImages = "";
QString g_appData = "";
QString g_roomID = "";
QString g_multipleAuthoriation = "";
bool g_isManager = false;
bool g_isHomeowner = false;
MainWindow *g_main = nullptr;

void cleanupLayout(QLayout *targetLayout)
{
    if (nullptr == targetLayout)
    {
        return;
    }

    while (targetLayout->count() > 0)
    {
        QWidget *widget = targetLayout->itemAt(0)->widget();
        if (nullptr != widget)
        {
            widget->setParent(nullptr);
            targetLayout->removeWidget(widget);
            delete widget;
        }
        else
        {
            targetLayout->removeWidget(widget);
        }
    }
}


bool deleteDir(const QString &dirName)
{
    QDir directory(dirName);
    if (!directory.exists())
    {
        return true;
    }


    QString srcPath = QDir::toNativeSeparators(dirName);
    if (!srcPath.endsWith(QDir::separator()))
        srcPath += QDir::separator();


    QStringList fileNames = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
    bool error = false;
    for (QStringList::size_type i = 0; i != fileNames.size(); ++i)
    {
        QString filePath = srcPath + fileNames.at(i);
        QFileInfo fileInfo(filePath);
        if (fileInfo.isFile() || fileInfo.isSymLink())
        {
            QFile::setPermissions(filePath, QFile::WriteOwner);
            if (!QFile::remove(filePath))
            {
                error = true;
            }
        }
        else if (fileInfo.isDir())
        {
            if (!deleteDir(filePath))
            {
                error = true;
            }
        }
    }

    if (!directory.rmdir(QDir::toNativeSeparators(directory.path())))
    {
        error = true;
    }

    return !error;
}


int dirFileSize(const QString &path)
{
    QDir dir(path);
    int size = 0;
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        size += fileInfo.size();
    }
    foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        size += dirFileSize(path + QDir::separator() + subDir);
    }
    return size;
}

QString getCpuId()
{
    QProcess p(0);
    p.start("wmic csproduct get uuid");    p.waitForStarted();
    p.waitForFinished();
    QString cpuID = QString::fromLocal8Bit(p.readAllStandardOutput());
    cpuID = cpuID.remove("UUID").trimmed();
    return cpuID;
}

void CreateDir()
{
    QString roamingPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug() << "Roaming (APPDATA):" << roamingPath;

    QDir mDir;
    QString mPath = roamingPath;
    if(!mDir.exists(mPath))
        mDir.mkpath(mPath);

    if(!mDir.exists(mPath + "/images"))
        mDir.mkpath(mPath + "/images");

    QFile tempFile;
    if(tempFile.exists(mPath + "/client.ini"))
    {

    }
    else
    {
        tempFile.setFileName(mPath + "/client.ini");
        if(!tempFile.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qDebug()<<QStringLiteral("打开失败");
        }
        tempFile.close();
    }
    g_appData = roamingPath;
    g_downloadImages = mPath + "/images";
}


qint32 getWebTime()
{
    QUdpSocket udpSocket;
    udpSocket.connectToHost("time.windows.com", 123);
    if(udpSocket.waitForConnected(300)){
        qint8 LI=0;
        qint8 VN=3;
        qint8 MODE=3;
        qint8 STRATUM=0;
        qint8 POLL=4;
        qint8 PREC=-6;
        QDateTime epoch(QDate(1900,1,1));
        qint32 second=quint32(epoch.secsTo(QDateTime::currentDateTime()));
        qint32 temp=0;
        QByteArray timeRequest(48, 0);
        timeRequest[0]=(LI <<6) | (VN <<3) | (MODE);
        timeRequest[1]=STRATUM;
        timeRequest[2]=POLL;
        timeRequest[3]=PREC & 0xff;
        timeRequest[5]=1;
        timeRequest[9]=1;
        timeRequest[40]=(temp=(second&0xff000000)>>24);
        temp=0;
        timeRequest[41]=(temp=(second&0x00ff0000)>>16);
        temp=0;
        timeRequest[42]=(temp=(second&0x0000ff00)>>8);
        temp=0;
        timeRequest[43]=((second&0x000000ff));
        udpSocket.flush();
        udpSocket.write(timeRequest);
        udpSocket.flush();
        if(udpSocket.waitForReadyRead(3000))
        {
            QByteArray newTime;
            QDateTime epoch(QDate(1900, 1, 1));
            QDateTime unixStart(QDate(1970, 1, 1));
            do
            {
                newTime.resize(udpSocket.pendingDatagramSize());
                udpSocket.read(newTime.data(), newTime.size());
            }while(udpSocket.hasPendingDatagrams());
            QByteArray TransmitTimeStamp ;
            TransmitTimeStamp=newTime.right(8);
            quint32 seconds=TransmitTimeStamp[0];
            quint8 temp=0;
            for(int j=1;j<=3;j++)
            {
                seconds=seconds<<8;
                temp=TransmitTimeStamp[j];
                seconds=seconds+temp;
            }
            quint32 t = seconds-epoch.secsTo(unixStart);
            return t;
        }
    }

    return -1;
}

QString mapDownloadImagePath(QString url)
{
    if(url.size()<5)
        return QString("");

    int ext_len = 5;
    QString storeName = url.left(url.length()-ext_len);
    storeName.replace("://", "_");
    storeName.replace('/', '_');
    storeName.replace('\\', '_');
    storeName.replace(':', '_');
    storeName.replace('.', '_');
    storeName += url.right(ext_len);

    if(storeName.right(1) == ".")
        storeName = storeName.left(storeName.length()-1);

    storeName.replace("?","");
    QString savePath = g_downloadImages + "/" + storeName;
    return savePath;
}

void showMapTojson(QVariantMap data)
{
    QJsonDocument doc(QJsonObject::fromVariantMap(data));
}

QString restoreEmojiTags(const QString &htmlText)
{
    QString result = htmlText;
    QRegularExpression regex(R"(<img[^>]*src=["']images/emotion/vc_emoji_(\d+)\.png["'][^>]*>)");
    int pos = 0;
    QRegularExpressionMatch match;
    while ((match = regex.match(result, pos)).hasMatch())
    {
        int number = match.captured(1).toInt();
        int originalNum = number;

        if(number <= 21)
            originalNum = number - 1;
        else if(number >= 27 && number < 32)
            originalNum = number + 4;
        else if(number == 32)
            originalNum = 43;
        else if(number == 33)
            originalNum = 45;
        else if(number >= 34 && number < 36)
            originalNum = number + 4;

        QString replacement = QString("[vce%1]").arg(originalNum, 3, 10, QLatin1Char('0'));
        result.replace(match.capturedStart(), match.capturedLength(), replacement);
        pos = match.capturedStart() + replacement.length();
    }

    return result;
}

QString replaceEmojiTagsSimple(const QString &text)
{
    QString result = text;
    QRegularExpression regex(R"(\[vce0*(\d+)\])");

    int pos = 0;
    QRegularExpressionMatch match;
    while ((match = regex.match(result, pos)).hasMatch())
    {
        int originalNum = match.captured(1).toInt();
        int number = originalNum;

        if(number <= 20)
            number ++;
        else if(number >= 31 && number < 36)
            number -= 4;
        else if(number == 43)
            number = 32;
        else if(number == 45)
            number = 33;
        else if(number >= 38 && number < 40)
            number -= 4 ;

        if (number > 0)
        {
            QString replacement = QString("<img src=\"images/emotion/vc_emoji_%1.png\" width=16 height=16 style='width:16; height:16; vertical-align:middle; display:inline-block;'/>").arg(number);
            result.replace(match.capturedStart(), match.capturedLength(), replacement);
            pos = match.capturedStart() + replacement.length();
        }
        else
        {
            pos = match.capturedEnd();
        }
    }

    return result;
}

void setAutoStart(bool enable)
{
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    QString appName = QCoreApplication::applicationName();
    QString appPath = QCoreApplication::applicationFilePath();
    appPath = QDir::toNativeSeparators(appPath);
    if (enable)
    {
        settings.setValue(appName, appPath);
    }
    else
    {
        settings.remove(appName);
    }
}

bool isAutoStartEnabled()
{
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    QString appName = QCoreApplication::applicationName();
    return settings.contains(appName);
}

