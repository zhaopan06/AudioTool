#ifndef GLOBAL_H
#define GLOBAL_H
#include <QApplication>
#include <QDebug>
#include <QDateTime>
#include <QFontDatabase>
#include <QLayout>

// 全局变量定义
extern QString g_downloadImages;//需要下载图片得地址


// 全局函数定义
void cleanupLayout(QLayout *target);
bool deleteDir(const QString &dirName);
int  dirFileSize(const QString &path);
QString getCpuId();
void CreateDir();//创建文件夹
qint32 getWebTime();
QString mapDownloadImagePath(QString url);
#endif // !GLOBAL_H
