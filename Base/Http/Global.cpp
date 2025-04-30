#include "Global.h"
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QWidget>
#include <QApplication>
#include <QUdpSocket>
#include <QStandardPaths>

// 全局变量定义
QString g_downloadImages ="";//需要下载图片得地址

// 清空布局
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
    //dir.entryInfoList(QDir::Files)返回文件信息
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        //计算文件大小
        size += fileInfo.size();
    }
    //dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)返回所有子目录，并进行过滤
    foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        //若存在子目录，则递归调用dirFileSize()函数
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

    QFile *tempFile = new QFile;
    if(tempFile->exists(mPath + "/client.ini"))
    {
        qDebug()<<QStringLiteral("文件存在");
    }
    else
    {
        tempFile->setFileName(mPath + "/client.ini");
        if(!tempFile->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qDebug()<<QStringLiteral("打开失败");
        }
        tempFile->close();
    }

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
        if(udpSocket.waitForReadyRead(3000)){
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
