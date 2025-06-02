#ifndef GLOBAL_H
#define GLOBAL_H
#include <QApplication>
#include <QDebug>
#include <QDateTime>
#include <QFontDatabase>
#include <QLayout>
#include <mainwindow.h>

// 全局变量定义
extern QString g_downloadImages;//需要下载图片得地址
extern QString g_appData;
extern QString g_roomID;
extern QString g_multipleAuthoriation;
extern bool g_isManager;//是否管理
extern bool g_isHomeowner;//是否房主
extern MainWindow *g_main;

// 全局函数定义
void cleanupLayout(QLayout *target);
bool deleteDir(const QString &dirName);
int  dirFileSize(const QString &path);
QString getCpuId();
void CreateDir();//创建文件夹
qint32 getWebTime();
QString mapDownloadImagePath(QString url);
void showMapTojson(QVariantMap data);
QString replaceEmojiTagsSimple(const QString &text);
QString restoreEmojiTags(const QString &htmlText);








#endif // !GLOBAL_H
